from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    """Return ingredients tagged VALID or INVALID for dark magic."""
    lowered: str = ingredients.lower()
    allowed: list[str] = dark_spell_allowed_ingredients()
    is_valid: bool = any(item in lowered for item in allowed)
    status: str = "VALID" if is_valid else "INVALID"
    return f"{ingredients} - {status}"
