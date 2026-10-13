"""Validate a mission crew with nested Pydantic models."""

from datetime import datetime
from enum import Enum

from pydantic import BaseModel, Field, ValidationError, model_validator


class Rank(str, Enum):
    """Crew rank, from cadet up to commander."""

    CADET = "cadet"
    OFFICER = "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    """One person assigned to a space mission."""

    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    """A mission and the crew that must satisfy launch rules."""

    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def check_safety_rules(self) -> "SpaceMission":
        """Apply launch rules that look at the whole crew."""
        if not self.mission_id.startswith("M"):
            raise ValueError('Mission ID must start with "M"')
        has_lead = any(
            member.rank in (Rank.CAPTAIN, Rank.COMMANDER)
            for member in self.crew
        )
        if not has_lead:
            raise ValueError(
                "Mission must have at least one Commander or Captain"
            )
        if self.duration_days > 365:
            experienced = 0
            for member in self.crew:
                if member.years_experience >= 5:
                    experienced += 1
            if experienced / len(self.crew) < 0.5:
                raise ValueError(
                    "Long missions (> 365 days) need 50% experienced "
                    "crew (5+ years)"
                )
        if any(not member.is_active for member in self.crew):
            raise ValueError("All crew members must be active")
        return self


def validation_messages(error: ValidationError) -> str:
    """Return error text without Pydantic's value-error prefix."""
    prefix = "Value error, "
    messages: list[str] = []
    for detail in error.errors():
        message = str(detail["msg"])
        if message.startswith(prefix):
            message = message[len(prefix):]
        messages.append(message)
    return "\n".join(messages)


def sample_crew() -> list[CrewMember]:
    """Return the three crew members from the subject sample."""
    return [
        CrewMember(
            member_id="SC001",
            name="Sarah Connor",
            rank=Rank.COMMANDER,
            age=42,
            specialization="Mission Command",
            years_experience=15,
        ),
        CrewMember(
            member_id="JS001",
            name="John Smith",
            rank=Rank.LIEUTENANT,
            age=36,
            specialization="Navigation",
            years_experience=8,
        ),
        CrewMember(
            member_id="AJ001",
            name="Alice Johnson",
            rank=Rank.OFFICER,
            age=29,
            specialization="Engineering",
            years_experience=2,
        ),
    ]


def print_mission(mission: SpaceMission) -> None:
    """Print the valid-mission block from the subject."""
    print("Space Mission Crew Validation")
    print("=" * 41)
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:
        print(
            f"- {member.name} ({member.rank.value}) - "
            f"{member.specialization}"
        )
    print("=" * 41)


def main() -> None:
    """Show one valid Mars mission and one crew with no lead rank."""
    mission = SpaceMission.model_validate({
        "mission_id": "M2024_MARS",
        "mission_name": "Mars Colony Establishment",
        "destination": "Mars",
        "launch_date": "2024-11-01T08:00:00",
        "duration_days": 900,
        "budget_millions": 2500.0,
        "crew": sample_crew(),
    })
    print_mission(mission)
    print("Expected validation error:")
    crew_without_lead = [
        CrewMember(
            member_id="SC001",
            name="Sarah Connor",
            rank=Rank.LIEUTENANT,
            age=42,
            specialization="Mission Command",
            years_experience=15,
        ),
        CrewMember(
            member_id="JS001",
            name="John Smith",
            rank=Rank.LIEUTENANT,
            age=36,
            specialization="Navigation",
            years_experience=8,
        ),
        CrewMember(
            member_id="AJ001",
            name="Alice Johnson",
            rank=Rank.OFFICER,
            age=29,
            specialization="Engineering",
            years_experience=2,
        ),
    ]
    try:
        SpaceMission.model_validate({
            "mission_id": "M2024_MARS",
            "mission_name": "Mars Colony Establishment",
            "destination": "Mars",
            "launch_date": "2024-11-01T08:00:00",
            "duration_days": 900,
            "budget_millions": 2500.0,
            "crew": crew_without_lead,
        })
    except ValidationError as error:
        print(validation_messages(error))


if __name__ == "__main__":
    main()
