"""Validate alien-contact reports with cross-field rules."""

from datetime import datetime
from enum import Enum

from pydantic import BaseModel, Field, ValidationError, model_validator


class ContactType(str, Enum):
    """How an alien contact was observed."""

    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    """One alien-contact report and its business rules."""

    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode="after")
    def check_business_rules(self) -> "AlienContact":
        """Apply rules that depend on more than one field."""
        if not self.contact_id.startswith("AC"):
            raise ValueError(
                'Contact ID must start with "AC" (Alien Contact)'
            )
        if (
            self.contact_type is ContactType.PHYSICAL
            and not self.is_verified
        ):
            raise ValueError("Physical contact reports must be verified")
        if (
            self.contact_type is ContactType.TELEPATHIC
            and self.witness_count < 3
        ):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
            )
        message = self.message_received
        has_message = message is not None and message.strip() != ""
        if self.signal_strength > 7.0 and not has_message:
            raise ValueError(
                "Strong signals (> 7.0) should include received messages"
            )
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


def print_contact(contact: AlienContact) -> None:
    """Print the valid-contact block from the subject."""
    print("Alien Contact Log Validation")
    print("=" * 38)
    print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    print(f"Message: '{contact.message_received}'")
    print("=" * 38)


def main() -> None:
    """Show one valid radio contact and one telepathic failure."""
    contact = AlienContact.model_validate({
        "contact_id": "AC_2024_001",
        "timestamp": "2024-03-15T22:10:00",
        "location": "Area 51, Nevada",
        "contact_type": ContactType.RADIO,
        "signal_strength": 8.5,
        "duration_minutes": 45,
        "witness_count": 5,
        "message_received": "Greetings from Zeta Reticuli",
    })
    print_contact(contact)
    print("Expected validation error:")
    try:
        AlienContact.model_validate({
            "contact_id": "AC_2024_002",
            "timestamp": "2024-03-16T01:00:00",
            "location": "Atacama Desert",
            "contact_type": ContactType.TELEPATHIC,
            "signal_strength": 4.0,
            "duration_minutes": 10,
            "witness_count": 1,
        })
    except ValidationError as error:
        print(validation_messages(error))


if __name__ == "__main__":
    main()
