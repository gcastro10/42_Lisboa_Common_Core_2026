def light_spell_allowed_ingredients() -> list[str]:
    """Return ingredients allowed for light magic."""
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    """Record a light spell after validating its ingredients."""
    from .light_validator import validate_ingredients

    verdict: str = validate_ingredients(ingredients)
    if verdict.endswith("INVALID"):
        return f"Spell rejected: {spell_name} ({verdict})"
    return f"Spell recorded: {spell_name} ({verdict})"
