# push_swap

`push_swap` is a project developed at 42 School that consists of implementing a sorting algorithm using a limited set of stack operations. The goal is to sort stack `a` using the smallest possible number of operations, temporarily using stack `b` to help rearrange the values.

---

## 📦 Project Overview

The project features:

- A **circular doubly linked list** implementation for both stacks
- Primitive stack operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- Optimized sorting strategies:
  - Hardcoded solutions for small input sizes (3 and 5 numbers)
  - **Radix sort** based on bitwise operations for large inputs
  - **Chunk-based sorting** to enhance performance in mid-sized inputs (100, 500+ numbers)
- Input normalization to simplify index-based sorting

---

## 🚀 Compilation

```
make
```

This will produce the executable: `./push_swap`

---

## 📈 Usage

```
./push_swap 3 2 1
```

Example output:

```
sa
rra
```

The program outputs the list of operations (one per line) required to sort the stack in ascending order.

---

## 🧠 Algorithms

### 1. Normalization

Before sorting, input values are transformed into normalized indices (ranging from 0 to N-1), allowing more efficient bit-based sorting.

```
void normalize(t_stack *stack);
```

### 2. Radix Sort

Uses the bitwise representation of normalized indices to sort elements efficiently, especially for large input sizes.

```
void radix_sort(t_stack *a, t_stack *b);
```

### 3. Chunk-Based Sort

Elements are divided into logical chunks and sorted incrementally, optimizing the number of push/rotate operations during reinsertion.

| Elements | Chunks |
|----------|--------|
| ≤ 100    | 5      |
| ≤ 500    | 10     |
| > 500    | 16     |

```
void chunk_sort(t_stack *a, t_stack *b);
```

---

## 🛠 Operations Implemented

| Operation | Description                          |
|----------:|--------------------------------------|
| `sa`      | Swap top two elements of stack A     |
| `sb`      | Swap top two elements of stack B     |
| `ss`      | `sa` and `sb` simultaneously         |
| `pa`      | Push top of B to A                   |
| `pb`      | Push top of A to B                   |
| `ra`      | Rotate stack A upwards               |
| `rb`      | Rotate stack B upwards               |
| `rr`      | `ra` and `rb` simultaneously         |
| `rra`     | Reverse rotate stack A               |
| `rrb`     | Reverse rotate stack B               |
| `rrr`     | `rra` and `rrb` simultaneously       |

---

## 🎯 Scoring Goals

| Input Size | Maximum Operations (for full score) |
|-----------:|-------------------------------------:|
| 3 elements | ≤ 3 operations                       |
| 5 elements | ≤ 12 operations                      |
| 100 elems  | ≤ 700 operations                     |
| 500 elems  | ≤ 5500 operations                    |

---

## 🧪 Testing

### With 3 elements:

```
./push_swap 2 1 3
```

### With 100 random elements:

```
ARG=$(shuf -i 0-99 | tr '\n' ' ')
./push_swap $ARG | wc -l
```

---

## 📂 Project Structure

```
push_swap/
│
├── src/
│   ├── main.c
│   ├── stack_utils.c
│   ├── normalize.c
│   ├── radix_sort.c
│   ├── chunk_sort.c
│   └── operations.c
│
├── include/
│   └── push_swap.h
│
├── Makefile
└── README.md
```

---

## 📜 License

This project is part of the 42 School curriculum. It is intended for educational and evaluation purposes only.

---

## 🤝 Contributions

Contributions are disabled for this repository as per 42 School's rules regarding individual projects.

---

## 📧 Contact

Developed by **Mohamed**  
[LinkedIn](https://www.linkedin.com/in/mohaamedl/) 
