# Truck.py - description truck functions.
import random


# Filling truck objects with values from file.
def file_convert(truck_arr, command):
    # Get line from file and split it.
    str_arr = command.split(' ')

    # Add type of vehicle.
    truck_arr.append("Truck")

    # Add common parameters.

    # Gaz tank capacity.
    truck_arr.append(int(str_arr[2]))

    # Fuel spending.
    truck_arr.append(float(str_arr[3]))

    # Add personal parameters.

    # Carrying capacity.
    truck_arr.append(int(str_arr[1]))

    # Add parameter to compare objects.
    truck_arr.append(compare_to(truck_arr))


# Filling truck object with random values.
def random_generate(truck_arr):
    # Add type of vehicle.
    truck_arr.append("Truck")

    # Add common parameters.

    # Gaz tank capacity.
    truck_arr.append(random.randint(1, 100))

    # Fuel spending.
    truck_arr.append(float(random.random() + random.randint(0, 20)))

    # Add personal parameters.

    # Carrying capacity.
    truck_arr.append(random.randint(1, 1000))

    # Add parameter to compare objects.
    truck_arr.append(compare_to(truck_arr))


# Comparison parameter for sorting.
def compare_to(truck_arr):
    return truck_arr[1] / truck_arr[2] * 100
