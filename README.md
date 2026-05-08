# C - Sorting Algorithms & Big O

A complete C project focused on implementing fundamental and advanced sorting algorithms while studying and analyzing Big O time complexity.

This repository was completed as part of the **Holberton School / Tuwaiq Academy** curriculum. The goal of the project is not only to write working sorting algorithms, but also to deeply understand how each algorithm behaves in terms of speed, memory usage, recursion, comparisons, swaps, scalability, and efficiency.

The project includes sorting algorithms for arrays of integers, sorting methods for doubly linked lists, and a full card deck sorting implementation using custom structures and pointer manipulation.

Throughout the implementation process, several important computer science concepts are practiced, including:

* Pointer manipulation
* Dynamic memory allocation
* Recursive algorithms
* Array traversal
* Linked list traversal
* Partitioning techniques
* Divide and conquer strategies
* Stability of sorting algorithms
* In-place sorting techniques
* Big O notation analysis
* Memory optimization concepts
* Efficient function decomposition
* Working with helper functions
* Modular programming in C

This project is designed to strengthen understanding of low-level programming and algorithmic thinking while following strict coding standards using the GCC compiler and Betty style guidelines.

---

# Table of Contents

1. Introduction
2. Learning Objectives
3. General Requirements
4. Data Structures
5. Repository Structure
6. Project Files
7. Implemented Algorithms
8. Detailed Algorithm Explanations
9. Big O Complexity Analysis
10. Compilation Instructions
11. Usage Examples
12. Sample Outputs
13. Key Concepts Learned
14. Challenges Faced During Development
15. Possible Improvements
16. Authors
17. Acknowledgements

---

# Introduction

Sorting algorithms are one of the most important topics in computer science. They are used in operating systems, databases, networking applications, search engines, machine learning systems, compilers, and many other software systems.

A sorting algorithm rearranges elements in a specific order, usually ascending or descending. Different algorithms use different strategies to organize data.

Some algorithms focus on simplicity and educational value, while others focus on speed and efficiency for very large datasets.

Understanding sorting algorithms helps developers:

* Improve problem-solving skills
* Understand algorithm optimization
* Analyze time complexity
* Learn memory management techniques
* Practice recursion and iteration
* Compare algorithm performance
* Write efficient programs

This project covers both simple algorithms like Bubble Sort and advanced algorithms like Merge Sort, Heap Sort, and Bitonic Sort.

---

# Learning Objectives

This project reinforces many important programming and algorithmic concepts.

After completing this project, students should be able to:

## C Programming Fundamentals

* Understand advanced C syntax
* Use pointers efficiently
* Work with arrays and linked lists
* Organize programs using header files
* Write modular and reusable code
* Compile programs using GCC
* Handle memory safely

## Sorting Algorithms

* Understand how sorting works internally
* Compare different sorting strategies
* Identify stable and unstable sorts
* Understand in-place sorting
* Use recursive and iterative approaches
* Analyze swaps and comparisons

## Big O Complexity

* Analyze algorithm efficiency
* Compare best, average, and worst cases
* Understand scalability
* Evaluate memory consumption
* Measure algorithm performance

## Data Structures

* Work with doubly linked lists
* Traverse nodes correctly
* Manipulate pointers safely
* Use custom structures
* Build and sort complex structures like card decks

## Software Engineering Skills

* Organize large repositories
* Document projects professionally
* Write maintainable code
* Follow coding standards
* Create reusable helper functions

---

# General Requirements

The project follows strict development requirements.

| Requirement      | Details                           |
| ---------------- | --------------------------------- |
| Language         | C                                 |
| Compiler         | GCC                               |
| Operating System | Ubuntu Linux                      |
| Coding Style     | Betty Style                       |
| Allowed Editors  | vi, vim, emacs                    |
| Compiler Flags   | `-Wall -Wextra -Werror -pedantic` |
| Standard         | GNU89                             |

Additional rules followed during development:

* No global variables
* No memory leaks
* All files end with a new line
* Function prototypes included in header files
* Programs compiled without warnings
* Code separated into logical modules
* Helper functions used when necessary

---

# Data Structures

The repository mainly uses arrays and doubly linked lists.

## Doubly Linked List Structure

The primary linked list structure is defined inside `sort.h`.

```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element
 * @next: Pointer to the next element
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
```

This structure allows traversal in both directions.

Advantages of doubly linked lists:

* Easier insertion and deletion
* Backward traversal support
* Efficient node swapping
* Better flexibility for sorting operations

The linked list structure is mainly used in:

* Insertion Sort List
* Cocktail Shaker Sort

---

## Deck Structures

The deck sorting task uses additional structures defined in `deck.h`.

These structures represent:

* Card suits
* Card values
* Deck nodes
* Card ordering

The deck sorting algorithm sorts cards first by suit and then by card value.

---

# Repository Structure

The repository is divided into multiple files to improve readability and maintainability.

Each algorithm has:

* Its own source file
* Independent helper functions
* Complexity documentation
* Test cases
* Supporting utility functions

The repository also includes:

* Header files
* Printing functions
* Main testing files
* Complexity analysis files
* Documentation files

---

# Project Files

| File            | Purpose                            |
| --------------- | ---------------------------------- |
| `sort.h`        | Contains prototypes and structures |
| `deck.h`        | Defines card deck structures       |
| `print_array.c` | Prints arrays of integers          |
| `print_list.c`  | Prints doubly linked lists         |
| `0-main.c`      | Testing file for Bubble Sort       |
| `1-main.c`      | Testing file for Insertion Sort    |
| `README.md`     | Project documentation              |

Additional files exist for each sorting task and complexity analysis.

---

# Implemented Algorithms

The repository includes both beginner and advanced sorting algorithms.

| Task | File                       | Function              | Description                       |
| ---- | -------------------------- | --------------------- | --------------------------------- |
| 0    | `0-bubble_sort.c`          | `bubble_sort`         | Bubble Sort                       |
| 1    | `1-insertion_sort_list.c`  | `insertion_sort_list` | Insertion Sort for linked lists   |
| 2    | `2-selection_sort.c`       | `selection_sort`      | Selection Sort                    |
| 3    | `3-quick_sort.c`           | `quick_sort`          | Quick Sort using Lomuto partition |
| 100  | `100-shell_sort.c`         | `shell_sort`          | Shell Sort using Knuth sequence   |
| 101  | `101-cocktail_sort_list.c` | `cocktail_sort_list`  | Cocktail Shaker Sort              |
| 102  | `102-counting_sort.c`      | `counting_sort`       | Counting Sort                     |
| 103  | `103-merge_sort.c`         | `merge_sort`          | Merge Sort                        |
| 104  | `104-heap_sort.c`          | `heap_sort`           | Heap Sort                         |
| 105  | `105-radix_sort.c`         | `radix_sort`          | Radix Sort                        |
| 106  | `106-bitonic_sort.c`       | `bitonic_sort`        | Bitonic Sort                      |
| 107  | `107-quick_sort_hoare.c`   | `quick_sort_hoare`    | Quick Sort using Hoare partition  |
| 1000 | `1000-sort_deck.c`         | `sort_deck`           | Deck sorting algorithm            |

---

# Detailed Algorithm Explanations

# Bubble Sort

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order.

Main characteristics:

* Simple to understand
* Easy to implement
* Inefficient for large datasets
* Performs many swaps

Advantages:

* Beginner friendly
* In-place sorting
* Stable sorting algorithm

Disadvantages:

* Poor scalability
* Slow for large arrays
* High time complexity

---

# Insertion Sort

Insertion Sort builds the sorted section one element at a time.

The algorithm takes one value and inserts it into the correct position.

Advantages:

* Efficient for small datasets
* Stable sorting algorithm
* Adaptive for nearly sorted arrays

Disadvantages:

* Slow for large datasets
* Quadratic time complexity

This repository implements insertion sort for doubly linked lists.

---

# Selection Sort

Selection Sort repeatedly selects the minimum value and places it at the beginning.

Advantages:

* Simple implementation
* Performs fewer swaps
* Memory efficient

Disadvantages:

* Poor performance on large datasets
* Always performs quadratic comparisons

---

# Quick Sort

Quick Sort is a divide and conquer algorithm.

The algorithm:

1. Selects a pivot
2. Partitions the array
3. Recursively sorts subarrays

Advantages:

* Very fast in practice
* Efficient average performance
* Widely used

Disadvantages:

* Worst case can be slow
* Recursive stack overhead

This project includes:

* Lomuto partition scheme
* Hoare partition scheme

---

# Shell Sort

Shell Sort improves insertion sort by comparing distant elements.

The implementation uses the Knuth sequence.

Advantages:

* Faster than insertion sort
* Efficient for medium-sized arrays

Disadvantages:

* Complexity depends on gap sequence
* Not stable

---

# Cocktail Shaker Sort

Cocktail Shaker Sort is a bidirectional variation of Bubble Sort.

The algorithm moves:

* Large elements to the end
* Small elements to the beginning

Advantages:

* Slightly better than Bubble Sort
* Bidirectional traversal

Disadvantages:

* Still inefficient for large datasets

---

# Counting Sort

Counting Sort is a non-comparison sorting algorithm.

It counts occurrences of values and reconstructs the sorted array.

Advantages:

* Linear time complexity
* Very fast for limited ranges

Disadvantages:

* Requires extra memory
* Limited use cases

---

# Merge Sort

Merge Sort uses recursion and divide-and-conquer techniques.

The algorithm:

1. Splits arrays into halves
2. Recursively sorts halves
3. Merges sorted sections

Advantages:

* Guaranteed O(n log n)
* Stable sorting algorithm
* Excellent scalability

Disadvantages:

* Requires extra memory
* Recursive overhead

---

# Heap Sort

Heap Sort uses a binary heap structure.

Main steps:

1. Build max heap
2. Extract largest element repeatedly
3. Rebuild heap after extraction

Advantages:

* Guaranteed O(n log n)
* In-place sorting
* Memory efficient

Disadvantages:

* Not stable
* More complex implementation

---

# Radix Sort

Radix Sort sorts numbers digit by digit.

The implementation uses Least Significant Digit (LSD) processing.

Advantages:

* Linear complexity for specific inputs
* Fast for integers

Disadvantages:

* Limited to certain data types
* Requires extra processing

---

# Bitonic Sort

Bitonic Sort is mainly used in parallel computing.

It works by building bitonic sequences and merging them.

Advantages:

* Efficient for parallel systems
* Structured recursive behavior

Disadvantages:

* Complex implementation
* Rarely used in normal applications

---

# Deck Sort

The deck sorting task sorts cards by:

1. Suit
2. Card value

This task strengthens understanding of:

* Custom structures
* Linked lists
* Comparison logic
* Pointer manipulation

---

# Big O Complexity Analysis

The following complexities are included in the repository.

| Task           | Best Case     | Average Case  | Worst Case    |
| -------------- | ------------- | ------------- | ------------- |
| Bubble Sort    | `O(n)`        | `O(n^2)`      | `O(n^2)`      |
| Insertion Sort | `O(n)`        | `O(n^2)`      | `O(n^2)`      |
| Selection Sort | `O(n^2)`      | `O(n^2)`      | `O(n^2)`      |
| Quick Sort     | `O(nlog(n))`  | `O(nlog(n))`  | `O(n^2)`      |
| Counting Sort  | `O(n+k)`      | `O(n+k)`      | `O(n+k)`      |
| Merge Sort     | `O(nlog(n))`  | `O(nlog(n))`  | `O(nlog(n))`  |
| Heap Sort      | `O(nlog(n))`  | `O(nlog(n))`  | `O(nlog(n))`  |
| Bitonic Sort   | `O(log^2(n))` | `O(log^2(n))` | `O(log^2(n))` |

---

# Compilation Instructions

Example compilation command:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 2-selection_sort.c print_array.c -o selection
```

The compiler flags help ensure:

* Cleaner code
* Fewer hidden bugs
* Better coding practices
* Strict warning handling

---

# Usage Example

Example code:

```c
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
selection_sort(array, n);
print_array(array, n);
```

Run the executable:

```bash
./selection
```

---

# Example Output

```text
19, 48, 99, 71, 13, 52, 96, 73, 86, 7
7, 48, 99, 71, 13, 52, 96, 73, 86, 19
7, 13, 99, 71, 48, 52, 96, 73, 86, 19
7, 13, 19, 71, 48, 52, 96, 73, 86, 99
7, 13, 19, 48, 71, 52, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 96, 73, 86, 99
7, 13, 19, 48, 52, 71, 73, 96, 86, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

---

# Key Concepts Learned

During this project, several important concepts were strengthened:

* Recursive thinking
* Pointer management
* Efficient swapping methods
* Array indexing
* Dynamic memory handling
* Performance analysis
* Complexity evaluation
* Algorithm comparison
* Linked list traversal
* Divide and conquer strategies
* In-place sorting methods
* Stability analysis

---

# Challenges Faced During Development

Some algorithms were more difficult than others.

Common challenges included:

* Managing recursion correctly
* Preventing segmentation faults
* Updating linked list pointers safely
* Implementing partition logic
* Debugging heap operations
* Handling edge cases
* Maintaining clean code structure

Debugging techniques used:

* Manual tracing
* Print debugging
* Valgrind memory checking
* Step-by-step testing

---

# Possible Improvements

Future improvements could include:

* Adding visualization tools
* Benchmark performance comparisons
* Supporting generic data types
* Implementing multithreaded sorting
* Adding graphical demonstrations
* Creating unit tests
* Improving modularity

Additional algorithms that could be added:

* Tim Sort
* Intro Sort
* Comb Sort
* Tree Sort
* Bucket Sort
* Flash Sort

---

# Authors

* Fahad Almidaj
* Shouq Alqarni

---

# Acknowledgements

This project was completed as part of the **Holberton School / Tuwaiq Academy** curriculum.

Special appreciation goes to:

* Holberton School
* Tuwaiq Academy
* Open source contributors
* Computer science educators
* The C programming community

The project helped build a stronger understanding of algorithms, data structures, optimization, and low-level programming concepts.

---

Original uploaded README reference: fileciteturn0file0
