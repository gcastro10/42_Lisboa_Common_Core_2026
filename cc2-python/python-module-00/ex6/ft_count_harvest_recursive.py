def ft_count_harvest_recursive():
    days = int(input("Days until harvest: "))

    def helper(current):
        if current > days:
            return
        print(f"Day {current}")
        helper(current + 1)

    helper(1)
    print("Harvest time!")
