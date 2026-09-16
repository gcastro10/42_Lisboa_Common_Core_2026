import elements
from .elements import create_air, create_earth


def healing_potion() -> str:
    """Brew a healing potion from earth and air."""
    earth: str = create_earth()
    air: str = create_air()
    return f"Healing potion brewed with '{earth}' and '{air}'"


def strength_potion() -> str:
    """Brew a strength potion from fire and water."""
    fire: str = elements.create_fire()
    water: str = elements.create_water()
    return f"Strength potion brewed with '{fire}' and '{water}'"
