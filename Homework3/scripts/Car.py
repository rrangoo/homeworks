# Car.py - description car functions.
import random


# Filling bus objects with values from file.
def file_convert(car_arr, command):
    # Get line from file and split it.
    str_arr = command.split(' ')

    # Add type of vehicle.
    car_arr.append("Car")

    # Add common parameters.

    # Gaz tank capacity.
    car_arr.append(int(str_arr[2]))

    # Fuel spending.
    car_arr.append(float(str_arr[3]))

    # Add personal parameters.

    # Max speed.
    car_arr.append(int(str_arr[1]))

    # Add parameter to compare objects.
    car_arr.append(compare_to(car_arr))


# Filling car object with random values.
def random_generate(car_arr):
    # Add type of vehicle.
    car_arr.append("Car")

    # Add common parameters.

    # Gaz tank capacity.
    car_arr.append(random.randint(1, 100))

    # Fuel spending.
    car_arr.append(float(random.random() + random.randint(0, 20)))

    # Add personal parameters.

    # Max speed.
    car_arr.append(random.randint(1, 200))

    # Add parameter to compare objects.
    car_arr.append(compare_to(car_arr))


# Comparison parameter for sorting.
def compare_to(bus_arr):
    return bus_arr[1] / bus_arr[2] * 100
