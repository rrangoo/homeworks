# Bus.py - description bus functions.
import random


# Filling bus objects with values from file.
def file_convert(bus_arr, command):
    # Get line from file and split it.
    str_arr = command.split(' ')

    # Add type of vehicle.
    bus_arr.append("Bus")

    # Add common parameters.

    # Gaz tank capacity.
    bus_arr.append(int(str_arr[2]))

    # Fuel spending.
    bus_arr.append(float(str_arr[3]))

    # Add personal parameters.

    # Number of passenger seats.
    bus_arr.append(int(str_arr[1]))

    # Add parameter to compare objects.
    bus_arr.append(compare_to(bus_arr))


# Filling truck object with random values.
def random_generate(bus_arr):
    # Add type of vehicle.
    bus_arr.append("Bus")

    # Add common parameters.

    # Gaz tank capacity.
    bus_arr.append(random.randint(1, 100))

    # Fuel spending.
    bus_arr.append(float(random.random() + random.randint(0, 20)))

    # Add personal parameters.

    # Number of passenger seats.
    bus_arr.append(random.randint(1, 20))

    # Add parameter to compare objects.
    bus_arr.append(compare_to(bus_arr))


# Comparison parameter for sorting.
def compare_to(bus_arr):
    return bus_arr[1] / bus_arr[2] * 100
