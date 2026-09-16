from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    """Return ingredients allowed for dark magic."""
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    """Record a dark spell after validating its ingredients."""
    verdict: str = validate_ingredients(ingredients)
    if verdict.endswith("INVALID"):
        return f"Spell rejected: {spell_name} ({verdict})"
    return f"Spell recorded: {spell_name} ({verdict})"
