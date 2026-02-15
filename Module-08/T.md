# 🧰 CPP Module 08 - The Standard Template Library (STL)

![C++](https://img.shields.io/badge/C++-98-blue.svg)
![Score](https://img.shields.io/badge/Score-100%2F100-success.svg)

## 📖 Overview

This repository contains my solutions for **C++ Module 08** of the 42 Network curriculum. The core objective of this module is to transition from classic C++ arrays and manual memory management into the powerful and highly optimized world of the **Standard Template Library (STL)**.

Throughout this project, I explored templated containers, generic algorithms, and the iterators that bridge them together.

---

## 🏛️ The Big Picture: STL Architecture

The STL is not just a collection of pre-built tools; it is a brilliantly designed architecture built on three decoupled pillars:

1. **Containers:** Data structures used to store collections of data (e.g., `vector`, `list`, `deque`).
2. **Algorithms:** Functions that perform operations on containers (e.g., `sort`, `find`, `min_element`).
3. **Iterators:** The "smart pointers" that act as the bridge. Algorithms do not care about the underlying container type; they only interact with its Iterators.

---

## 🟢 ex00: `easyfind` - The Power of Generic Algorithms

### 📝 Summary

This exercise introduces the `<algorithm>` library, specifically the `std::find` function. The goal is to write a generic template function that can find an integer in **any** container type without writing manual `while` or `for` loops.

### 🔍 Deep Dive

- **Iterators vs Pointers:** An Iterator is not a raw pointer; it is a smart object with overloaded operators (like `++` and `*`) that allows it to safely mimic pointer behavior across complex data structures.
- **The "Not-Found" Condition:** The true power of `std::find` is that it returns `container.end()` if the element is not found. We use this exact condition to safely throw a custom Exception instead of causing a segmentation fault.

### 💻 Syntax Highlight

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception(); // Or a custom NotFoundException
    return it;
}
```

---

## 🟡 ex01: Span - Memory Limits & Advanced Iteration

### 📝 Summary

This exercise focuses on heavy data manipulation using the `std::vector` container. The `Span` class stores a maximum of `N` integers and calculates the shortest and longest distances between any two numbers.

### 🔍 Deep Dive

- **Algorithmic Complexity:** To find the shortest span, comparing every number to every other number results in a sluggish $O(N^2)$ complexity. By sorting a copy of the vector first using `std::sort`, the performance improves to $O(N \log N)$, making the program capable of processing tens of thousands of numbers in milliseconds.
- **Range Insertion (The 10k Trick):** The most powerful feature of a vector is its ability to insert an entire range of data at once using Iterators. This allowed the implementation of an `addNumber` template function that adds 10,000 numbers in a single call without a manual `push_back` loop.

### 💻 Syntax Highlight

```cpp
// 1. Sorting a copy of the vector for shortestSpan
std::vector<int> tmp = _storage;
std::sort(tmp.begin(), tmp.end());

// 2. Inserting a range instantly (Range-based Iterator Insertion)
template <typename Iterator>
void addNumber(Iterator begin, Iterator end) {
    int dist = std::distance(begin, end);
    if (_storage.size() + static_cast<unsigned int>(dist) > _max_size)
        throw FullSpanException();
    _storage.insert(_storage.end(), begin, end);
}
```

---

## 🔴 ex02: MutantStack - Breaking the Adapter Pattern

### 📝 Summary

In C++, `std::stack` is not iterable. It enforces strict **LIFO** (Last-In, First-Out) rules. This exercise requires creating a `MutantStack` that inherits from `std::stack` but hacks into it to expose its iterators, making it iterable like a standard vector or list.

### 🔍 Deep Dive

- **Container Adapters & `std::deque`:** A `std::stack` is not a true container; it is a Container Adapter. Under the hood, it wraps an underlying double-ended queue (`std::deque`) inside a protected variable named `c`. By inheriting from `std::stack`, we gain access to this `c` variable.
- **The `typedef` & `typename` Mystery:** Because our class inherits from a Template, the C++98 compiler gets confused by dependent scopes. We must use the `typename` keyword to explicitly tell the compiler that `container_type::iterator` is a **Type** and not a **Variable**. We then use `typedef` to give it the standard alias `iterator`.

### 💻 Syntax Highlight

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Resolving compiler confusion with typedef and typename
    typedef typename std::stack<T>::container_type::iterator iterator;

    // Accessing the protected underlying container 'c'
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};
```

---

## 🛠️ Compilation & Usage

To compile any of the exercises, navigate to the respective directory and use the provided `Makefile`:

```bash
cd ex00  # or ex01, ex02
make
./<executable_name>
```

### Compiler constraints:

- **Compiled with:** `c++`
- **Flags:** `-Wall -Wextra -Werror -std=c++98`

---

## 📚 Resources

Here are the best resources to deepen your understanding of the Standard Template Library (STL) in C++98:

### 📖 CPP Reference (The Bible)

- [**Standard Template Library (STL) Overview**](https://en.cppreference.com/w/cpp/container) - The full list of containers.
- [**std::vector**](https://en.cppreference.com/w/cpp/container/vector) - Dynamic array documentation.
- [**std::list**](https://en.cppreference.com/w/cpp/container/list) - Doubly linked list documentation.
- [**std::stack**](https://en.cppreference.com/w/cpp/container/stack) - LIFO stack adapter.
- [**std::find**](https://en.cppreference.com/w/cpp/algorithm/find) - Algorithm to find elements in a range.
- [**Iterator Library**](https://en.cppreference.com/w/cpp/iterator) - Understanding Input, Output, Forward, and Random Access iterators.

### 🧠 GeeksforGeeks

- [**The C++ Standard Template Library (STL)**](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/) - Great beginner-friendly introduction.
- [**Vector in C++ STL**](https://www.geeksforgeeks.org/vector-in-cpp-stl/) - Examples and usage of vectors.
- [**List in C++ STL**](https://www.geeksforgeeks.org/list-cpp-stl/) - How and when to use lists.
- [**Stack in C++ STL**](https://www.geeksforgeeks.org/stack-in-cpp-stl/) - Understanding stack operations.
- [**Iterators in C++ STL**](https://www.geeksforgeeks.org/iterators-c-stl/) - Simple explanation of how iterators work.
