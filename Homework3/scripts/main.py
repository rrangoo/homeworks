# main.py - contains main function for testing functional.

import sys
import time
import Container


# Error message.
def error_message():
    print("Incorrect input!\n"
          "Please enter:\n"
          "python main -f <infile> <outfile1> <outfile2>\n"
          "Or:\n"
          "python main -n <number> <outfile1> <outfile2>\n"
          "<number> - integer between 1 and 10000\n"
          "<outfile1> - unsorted data\n"
          "<outfile2> - sorted data")


# Check command line args.
if __name__ == '__main__':

    # Check arguments.
    if len(sys.argv) != 5:
        error_message()
        exit(1)

    # Start timer.
    time_start = time.time()
    print("Working. . .")

    # Array of container.
    cont = []

    # Choose way to input data.

    # If "from file".
    if sys.argv[1] == '-f':
        print("Start load data. . .")
        # Open source file.
        in_file = open(sys.argv[2], 'r')

        # Read strings.
        vehicles_array = in_file.read().split("\n")

        # Close stream.
        in_file.close()

        print("Data have loaded successfully!")
        print("Start conversion data to object arrays. . .")

        # Convert data to arrays of objects.
        Container.file_input(cont, vehicles_array)

        print("Conversion end successfully!")

    # If container is randomly generated.
    elif sys.argv[1] == '-n':
        print("Generation start. . .")

        # Read number of elements.
        size = int(sys.argv[2])

        # Check borders of element numbers.
        if size < 1 or size > 10000:
            error_message()
            exit(3)

        # Generate arrays.
        Container.random_input(cont, size)
        print("Generation end successfully.")

    # If incorrect argument.
    else:
        error_message()
        exit(2)

    # Print results in output file.
    unsorted_file = open(sys.argv[3], 'w+')

    print(f"Start filling file \"{sys.argv[3]}\". . .")

    # Write data in file.
    Container.out(cont, unsorted_file)

    # Close stream.
    unsorted_file.close()

    print(f"File \"{sys.argv[3]}\" successfully filled!")

    # Heap sort.
    print("Start sorting. . .")
    Container.heap_sort(cont)
    print("Sort successfully end!")

    # Print results in output file.
    print(f"Start filling file \"{sys.argv[4]}\". . .")

    sorted_file = open(sys.argv[4], 'w+')

    # Write data in file.
    Container.out(cont, sorted_file)

    # Close stream.
    sorted_file.close()

    print(f"File \"{sys.argv[4]}\" successfully filled!")

    # Stop timer.
    time_end = time.time()
    print("Time used: " + str(time_end - time_start) + " sec.")
    print('Finish!')
