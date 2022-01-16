# Container.py - Functions of container.

import random
import Bus
import Car
import Truck


# Input data from file.
def file_input(cont, vehicle_data):
    # Convert each string to vehicle array.
    for vehicle in vehicle_data:
        # Check type.
        type_of_vehicle = vehicle.split(" ")[0]

        # Create truck.
        if type_of_vehicle == '1':
            truck_arr = []
            Bus.file_convert(truck_arr, vehicle)
            cont.append(truck_arr)

        # Create bus.
        if type_of_vehicle == '2':
            bus_arr = []
            Car.file_convert(bus_arr, vehicle)
            cont.append(bus_arr)

        # Create car.
        if type_of_vehicle == '3':
            car_arr = []
            Truck.file_convert(car_arr, vehicle)
            cont.append(car_arr)


# Random filling container.
def random_input(cont, size):
    for i in range(size):

        # Check type.
        vehicle_type = random.randint(1, 3)

        # Create bus.
        if vehicle_type == 1:
            bus_arr = []
            Bus.random_generate(bus_arr)
            cont.append(bus_arr)

        # Create car.
        if vehicle_type == 2:
            car_arr = []
            Car.random_generate(car_arr)
            cont.append(car_arr)

        # Create truck.
        if vehicle_type == 3:
            truck_arr = []
            Truck.random_generate(truck_arr)
            cont.append(truck_arr)


# Output in file.
def out(cont, out_stream):
    out_stream.write(f"Container contains {len(cont)} elements:\n")
    count = 0
    for vehicle in cont:
        count += 1
        out_stream.write(f"{count}: {vehicle[0]}, ")

        if vehicle[0] == "Truck":
            out_stream.write(f"fuel tank capacity = {vehicle[1]}, "
                             f"fuel spending = {vehicle[2]}, "
                             f"carrying capacity = {vehicle[3]}, ")
        elif vehicle[0] == "Bus":
            out_stream.write(f"fuel tank capacity = {vehicle[1]}, "
                             f"fuel spending = {vehicle[2]}, "
                             f"passenger seats = {vehicle[3]}, ")
        elif vehicle[0] == "Car":
            out_stream.write(f"fuel tank capacity = {vehicle[1]}, "
                             f"fuel spending = {vehicle[2]}, "
                             f"max speed = {vehicle[3]}, ")

        out_stream.write(f"comparison parameter = {vehicle[len(vehicle) - 1]}\n")


# Generate heap.
def heapify(vehicle_arr, n, i):
    # Initialize largest as root.
    largest = i

    # left = 2*i + 1.
    left = 2 * i + 1

    # right = 2*i + 2.
    right = 2 * i + 2

    # See if left child of root exists and is greater than root.
    if left < n and vehicle_arr[i][4] < vehicle_arr[left][4]:
        largest = left

    # See if right child of root exists and is greater than root.
    if right < n and vehicle_arr[largest][4] < vehicle_arr[right][4]:
        largest = right

    # Change root, if needed.
    if largest != i:
        t = vehicle_arr[i]
        vehicle_arr[i] = vehicle_arr[largest]
        vehicle_arr[largest] = t

        # Heapify the root.
        heapify(vehicle_arr, n, largest)


# Heap sorting.
def heap_sort(cont):
    n = len(cont)

    # Convert array to heap.
    for i in range(n // 2 - 1, -1, -1):
        heapify(cont, n, i)

    # One by one extract elements
    for i in range(n - 1, 0, -1):
        cont[i], cont[0] = cont[0], cont[i]
        heapify(cont, i, 0)
