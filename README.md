# Sorting Algorithms

A command-line tool for benchmarking and comparing 12 sorting algorithms.
Measures execution time and comparison counts across different input patterns.

This project was built for the **Data Structures & Algorithms** course
at **HCMUS** and scored **9.42/10**.

## Build

### Prerequisites

- g++ with C++17 support (GCC 7+ or Clang 5+)
- GNU Make

### Compile

```
make
```

### Clean

```
make clean
```

## Usage

The program operates in two modes: **Algorithm Mode** (`-a`) and **Compare Mode** (`-c`).

### Algorithm Mode (-a)

**Command 1** -- Sort from file:

```
./sorting -a <algorithm> <input-file> <output-param>
```

Example:

```
./sorting -a radix-sort input.txt -both
```

**Command 2** -- Sort generated data with specific order:

```
./sorting -a <algorithm> <size> <input-order> [output-param]
```

Example:

```
./sorting -a selection-sort 50000 -rand -time
```

**Command 3** -- Sort generated data with ALL orders:

```
./sorting -a <algorithm> <size> [output-param]
```

Example:

```
./sorting -a binary-insertion-sort 70000 -comp
```

### Compare Mode (-c)

**Command 4** -- Compare two algorithms on file input:

```
./sorting -c <algorithm1> <algorithm2> <input-file>
```

Example:

```
./sorting -c heap-sort merge-sort input.txt
```

**Command 5** -- Compare two algorithms on generated data:

```
./sorting -c <algorithm1> <algorithm2> <size> <input-order>
```

Example:

```
./sorting -c quick-sort merge-sort 100000 -nsorted
```

### Parameters

**Algorithm names:**

`selection-sort`, `insertion-sort`, `binary-insertion-sort`, `bubble-sort`,
`shaker-sort`, `shell-sort`, `heap-sort`, `merge-sort`, `quick-sort`,
`counting-sort`, `radix-sort`, `flash-sort`

**Input orders:**

| Flag       | Description                         |
|------------|-------------------------------------|
| `-rand`    | Randomized data                     |
| `-sorted`  | Sorted in ascending order           |
| `-nsorted` | Nearly sorted (10 random swaps)     |
| `-rev`     | Sorted in descending (reverse) order|

**Output parameters:**

| Flag    | Description                      |
|---------|----------------------------------|
| `-time` | Show execution time only         |
| `-comp` | Show comparison count only       |
| `-both` | Show both time and comparisons   |

## Algorithms

| Algorithm             | Best       | Average    | Worst      | Space   | Stable |
|-----------------------|------------|------------|------------|---------|--------|
| Selection Sort        | O(n^2)     | O(n^2)     | O(n^2)     | O(1)    | No     |
| Insertion Sort        | O(n)       | O(n^2)     | O(n^2)     | O(1)    | Yes    |
| Binary Insertion Sort | O(n log n) | O(n^2)     | O(n^2)     | O(1)    | Yes    |
| Bubble Sort           | O(n^2)     | O(n^2)     | O(n^2)     | O(1)    | Yes    |
| Shaker Sort           | O(n)       | O(n^2)     | O(n^2)     | O(1)    | Yes    |
| Shell Sort            | O(n log n) | O(n^4/3)   | O(n^3/2)   | O(1)    | No     |
| Heap Sort             | O(n log n) | O(n log n) | O(n log n) | O(1)    | No     |
| Merge Sort            | O(n log n) | O(n log n) | O(n log n) | O(n)    | Yes    |
| Quick Sort            | O(n log n) | O(n log n) | O(n^2)     | O(log n)| No     |
| Counting Sort         | O(n + k)   | O(n + k)   | O(n + k)   | O(k)   | Yes    |
| Radix Sort            | O(d(n+k))  | O(d(n+k))  | O(d(n+k))  | O(n+k) | Yes    |
| Flash Sort            | O(n)       | O(n)       | O(n^2)     | O(n)    | No     |

## Design Patterns

### Why These Patterns?

The core design goal was **adherence to SOLID principles** -- in particular
the **Open/Closed Principle**: adding a new sorting algorithm should not
require modifying any existing code. At the same time, every algorithm needs
a **unified interface** so client code can treat them interchangeably
(`sort(int arr[], int n)`), and internal bookkeeping like comparison counting
should be **encapsulated** so subclasses cannot forget to reset it.

These constraints naturally led to three patterns working together:

### Strategy Pattern

`SortingStrategy` defines a common interface for all sorting algorithms.
Each algorithm implements `sortImp()` and `getName()`. Client code works
with the `SortingStrategy*` pointer, unaware of which concrete algorithm
is being used.

**Why Strategy?** The problem is a textbook fit -- multiple interchangeable
algorithms behind one interface. Each concrete class (e.g. `QuickSort`,
`MergeSort`) encapsulates its own logic and can add private helpers
(like `QuickSort::partition` or `MergeSort::merge`) without affecting
anything else.

### Template Method Pattern

`SortingStrategy::sort()` is the non-virtual public method that acts as
the template method. It resets the comparison counter, then delegates to
the virtual `sortImp()` implemented by each subclass. This ensures
consistent setup without subclasses needing to remember it.

**Why Template Method?** The `count_compare` counter must be reset to zero
before every sort. Without Template Method, every subclass would need to
remember to call `count_compare = 0` at the top of its sort -- a fragile
pattern that invites bugs. By making `sort()` non-virtual and having it
call `sortImp()`, the base class owns the reset logic and subclasses only
implement the algorithm itself.

### Registry Pattern (Factory)

`SortingAlgorithmRegistry` maps CLI algorithm names (e.g. `"heap-sort"`)
to factory functions. Each algorithm self-registers via a
`REGISTER_ALGORITHM` macro in its `.cpp` file. Adding a new algorithm
requires zero changes to existing code -- just create the new class and
register it.

**Why Registry over a simple factory?** The original version used an
if-chain factory function (`createSortingAlgorithm`). This worked, but
violated Open/Closed -- every new algorithm required editing the factory.
The Registry with self-registration macro closes the code for modification:
a new algorithm only needs its own `.h/.cpp` files with `REGISTER_ALGORITHM`
at the bottom. Nothing else changes.

### Pattern Summary

| Concern | Pattern | Benefit |
|---------|---------|---------|
| Interchangeable algorithms | Strategy | Client code is algorithm-agnostic |
| Automatic counter reset | Template Method | Subclasses can't forget bookkeeping |
| Algorithm instantiation | Registry | Adding algorithms requires zero changes to existing code |

## Project Structure

```
src/
  main.cpp                       -- CLI entry point, command handlers
  SortingStrategy.h              -- Abstract base class
  SortingAlgorithmRegistry.h/.cpp -- Algorithm factory/registry
  DataGenerator.h/.cpp           -- Test data generation
  algorithms/                    -- One file pair per algorithm
    [AlgorithmName].h/.cpp
  utils/                         -- Utility classes
    FileHandler.h/.cpp           -- File I/O
    OutputFormatter.h/.cpp       -- Console output formatting
```

### Class Diagram
[Plantuml: Class Diagram](/docs/classdiagram.plantuml)

![class-diagram-img](/docs/ClassDiagram.png)

## Fun Facts

- **Score: 9.42/10** (see [docs/comment.png](/docs/comment.png)).

