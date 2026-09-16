from alchemy.potions import strength_potion
from elements import create_fire
from ..elements import create_air


def lead_to_gold() -> str:
    """Transmute lead into gold using air, strength potion, and fire."""
    air: str = create_air()
    potion: str = strength_potion()
    fire: str = create_fire()
    return (
        f"Recipe transmuting Lead to Gold: brew '{air}' and '{potion}' "
        f"mixed with '{fire}'"
    )
