"""Validate space-station reports with a Pydantic model."""

from datetime import datetime

from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    """Vital statistics reported by one space station."""

    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


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


def print_station(station: SpaceStation) -> None:
    """Print the valid-station block from the subject."""
    if station.is_operational:
        status = "Operational"
    else:
        status = "Not Operational"
    print("Space Station Data Validation")
    print("=" * 40)
    print("Valid station created:")
    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    print(f"Status: {status}")
    print("=" * 40)


def main() -> None:
    """Show one valid station and one crew-size failure."""
    # The timestamp arrives as text; Pydantic converts it to datetime.
    station = SpaceStation.model_validate({
        "station_id": "ISS001",
        "name": "International Space Station",
        "crew_size": 6,
        "power_level": 85.5,
        "oxygen_level": 92.3,
        "last_maintenance": "2024-06-01T12:00:00",
    })
    print_station(station)
    print("Expected validation error:")
    try:
        SpaceStation.model_validate({
            "station_id": "ISS001",
            "name": "International Space Station",
            "crew_size": 21,
            "power_level": 85.5,
            "oxygen_level": 92.3,
            "last_maintenance": "2024-06-01T12:00:00",
        })
    except ValidationError as error:
        print(validation_messages(error))


if __name__ == "__main__":
    main()
