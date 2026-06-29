import sys


def main() -> None:
    """Parse command-line parameters to build, analyze, and update an RPG inventory."""
    print("=== Inventory System Analysis ===")

    raw_args: list[str] = sys.argv[1:]
    inventory: dict[str, int] = {}

    # 1. Parse and validate arguments
    for arg in raw_args:
        if ":" not in arg:
            print(f"Error - invalid parameter '{arg}'")
            continue

        # Split at the first colon only (standard defensive practice)
        parts: list[str] = arg.split(":", 1)
        item: str = parts[0]
        qty_str: str = parts[1]

        if item in inventory:
            print(f"Redundant item '{item}' - discarding")
            continue

        try:
            quantity: int = int(qty_str)
            inventory[item] = quantity
        except ValueError as val_err:
            print(f"Quantity error for '{item}': {val_err}")

    # Display initial parsed state
    print(f"Got inventory: {inventory}")

    # Quick exit guard if no items were valid
    if not inventory:
        return

    # 2. Extract item list using the authorized list() constructor
    # dict.keys() returns a view object, list() turns it into a standard list
    item_list: list[str] = list(inventory.keys())
    print(f"Item list: {item_list}")

    # 3. Total quantity using the authorized sum() and dict.values()
    total_qty: int = sum(inventory.values())
    print(f"Total quantity of the {len(inventory)} items: {total_qty}")

    # 4. Display percentage breakdown per item
    for item, qty in inventory.items():
        # Avoid division by zero safely if total_qty happens to be 0
        pct: float = (qty / total_qty) * 100 if total_qty > 0 else 0.0
        print(f"Item {item} represents {round(pct, 1)}%")

    # 5. Determine most and least abundant items
    # Because insertion order is guaranteed, we grab the first item as the initial benchmark
    most_abundant_item: str = item_list[0]
    least_abundant_item: str = item_list[0]

    for item, qty in inventory.items():
        if qty > inventory[most_abundant_item]:
            most_abundant_item = item
        if qty < inventory[least_abundant_item]:
            least_abundant_item = item

    print(
        f"Item most abundant: {most_abundant_item} "
        f"with quantity {inventory[most_abundant_item]}"
    )
    print(
        f"Item least abundant: {least_abundant_item} "
        f"with quantity {inventory[least_abundant_item]}"
    )

    # 6. Update inventory using the authorized dict.update()
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
