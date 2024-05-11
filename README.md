# Performance Testing of Sorting Algorithms in C

This project aims to evaluate the performance of various sorting algorithms implemented in C programming language. The sorting algorithms tested include:

- Bubble Sort
- Insertion Sort
- Selection Sort

## Overview

The main objective of this project is to compare the efficiency of different sorting algorithms under various input conditions. The program allows the user to choose the type of data arrangement for testing, including:

1. Ascending Order
2. Descending Order
3. Positive Values After Negative Values

The performance of each sorting algorithm is measured in terms of execution time, which is recorded for different sizes of input arrays.

## Usage

To run the performance tests, follow these steps:

1. Compile the program using a C compiler. For example:
```bash
  gcc main.c functions.c -o sorting_performance
```
2. Execute the compiled binary:
```bash
 ./sorting_performance
```
3. Follow the on-screen instructions to select the type of data arrangement for testing.
4. The program will then generate performance metrics for each sorting algorithm and display the results in a graphical format.

## Dependencies

This project depends on the following libraries:

- Standard C Library (`stdio.h`, `stdlib.h`)
- Time Library (`time.h`)

Ensure that these libraries are available in your C environment.

## Configuration

You can configure the size of the input array and the step size for increasing the array size by modifying the following constants defined in the `main.c` file:

- `N`: Size of the input array (default: 10000)
- `PAS`: Step size for increasing the array size (default: 1000)
- `nl`: Number of sorting algorithms tested (default: 3)
- `nc`: Number of data points for each algorithm (default: 10)

## Authors

- [Your Name]

## License

This project is licensed under the [MIT License](LICENSE).
