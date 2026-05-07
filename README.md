# C - Sorting algorithms & Big O

A C project implementing basic and advanced sorting algorithms, with Big O
time complexity files for the required tasks.

This project was completed as part of the **Holberton School / Tuwaiq Academy**
curriculum. It focuses on sorting arrays of integers, sorting doubly linked
lists, and sorting a deck of cards using C structures, pointers, helper
functions, recursion, and dynamic memory allocation where needed.

---

## Table of Contents

- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [Data Structures](#data-structures)
- [Project Files](#project-files)
- [Implemented Algorithms](#implemented-algorithms)
- [Big O Complexity](#big-o-complexity)
- [Compilation and Usage](#compilation-and-usage)
- [Example Output](#example-output)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)

---

## Learning Objectives

This project helps reinforce:

- C programming fundamentals
- Sorting algorithm implementation
- Big O time complexity analysis
- Working with arrays and doubly linked lists
- Using structs, header files, and function prototypes
- Managing dynamically allocated memory where needed
- Understanding recursive sorting algorithms

---

## Requirements

| Requirement | Details |
| --- | --- |
| Language | C |
| Compiler | `gcc` |
| Recommended flags | `-Wall -Wextra -Werror -pedantic` |

---

## Data Structures

The main doubly linked list structure is defined in `sort.h`:

```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
```

The deck sorting task also uses `kind_t`, `card_t`, and `deck_node_t`, which are
defined in `deck.h`.

---

## Project Files

| File | Purpose |
| --- | --- |
| `sort.h` | Function prototypes and the `listint_t` structure |
| `deck.h` | Card and deck structures used by `sort_deck` |
| `print_array.c` | Prints an array of integers |
| `0-main.c` | Test file that calls `selection_sort` |
| `README.md` | Project documentation |

---

## Implemented Algorithms

The table below covers every sorting task implemented in this repository.

| Task | File | Function | Algorithm or Purpose |
| --- | --- | --- | --- |
| 0 | `0-bubble_sort.c` | `bubble_sort` | Bubble sort |
| 1 | `1-insertion_sort_list.c` | `insertion_sort_list` | Insertion sort for a doubly linked list |
| 2 | `2-selection_sort.c` | `selection_sort` | Selection sort |
| 3 | `3-quick_sort.c` | `quick_sort` | Quick sort using Lomuto partition |
| 100 | `100-shell_sort.c` | `shell_sort` | Shell sort using the Knuth sequence |
| 101 | `101-cocktail_sort_list.c` | `cocktail_sort_list` | Cocktail shaker sort for a doubly linked list |
| 102 | `102-counting_sort.c` | `counting_sort` | Counting sort |
| 103 | `103-merge_sort.c` | `merge_sort` | Merge sort |
| 104 | `104-heap_sort.c` | `heap_sort` | Heap sort |
| 105 | `105-radix_sort.c` | `radix_sort` | LSD radix sort |
| 106 | `106-bitonic_sort.c` | `bitonic_sort` | Bitonic sort |
| 107 | `107-quick_sort_hoare.c` | `quick_sort_hoare` | Quick sort using Hoare partition |
| 1000 | `1000-sort_deck.c` | `sort_deck` | Sorts deck nodes by suit, then by value |

---

## Big O Complexity

The following values are taken directly from the `-O` files included in this
repository. Each file lists the best, average, and worst case in that order.

| Task | Big O File | Best Case | Average Case | Worst Case |
| --- | --- | --- | --- | --- |
| 0 | `0-O` | `O(n)` | `O(n^2)` | `O(n^2)` |
| 1 | `1-O` | `O(n)` | `O(n^2)` | `O(n^2)` |
| 2 | `2-O` | `O(n^2)` | `O(n^2)` | `O(n^2)` |
| 3 | `3-O` | `O(nlog(n))` | `O(nlog(n))` | `O(n^2)` |
| 101 | `101-O` | `O(n)` | `O(n^2)` | `O(n^2)` |
| 102 | `102-O` | `O(n+k)` | `O(n+k)` | `O(n+k)` |
| 103 | `103-O` | `O(nlog(n))` | `O(nlog(n))` | `O(nlog(n))` |
| 104 | `104-O` | `O(nlog(n))` | `O(nlog(n))` | `O(nlog(n))` |
| 106 | `106-O` | `O(log^2(n))` | `O(log^2(n))` | `O(log^2(n))` |
| 107 | `107-O` | `O(nlog(n))` | `O(nlog(n))` | `O(n^2)` |

---

## Compilation and Usage

The included `0-main.c` file creates an integer array, prints it, calls
`selection_sort`, and prints the sorted result.

Compile the example with:

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 2-selection_sort.c print_array.c -o selection
```

Run it:

```bash
./selection
```

Example from `0-main.c`:

```c
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
size_t n = sizeof(array) / sizeof(array[0]);

print_array(array, n);
selection_sort(array, n);
print_array(array, n);
```

---

## Example Output

Because `selection_sort` prints the array after each swap, running the included
example produces:

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

## Authors

- Fahad
- Shouq

---

## Acknowledgements

This project was completed as part of the **Holberton School / Tuwaiq Academy**
curriculum.
