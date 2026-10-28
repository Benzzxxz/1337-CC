*This project has been created as part of the 42 curriculum by abenzago.*

# Libft - Your Very First C Library

## Description

**Libft** is a foundational project in the 42 Network curriculum. The objective of this project is to reimplement a selection of standard C library functions (`libc`), as well as additional utility functions for string manipulation, memory management, file descriptor operations, and linked list handling.

Building this library from scratch provides a deep theoretical and practical understanding of memory allocation, pointer arithmetic, data structures, and standard system behavior in C. The resulting static library (`libft.a`) serves as a reusable component for future C programming assignments throughout the 42 curriculum.

## Technical Features & Library Overview

The functions included in `libft.a` are categorized into three main parts:

### 1. Re-implementation of Standard Libc Functions

* **Memory Operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`

* **String Manipulation:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`

* **Character Checks & Conversions:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_atoi`

### 2. Additional Utility Functions

* **String Allocation & Trimming:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`

* **Formatting & Conversion:** `ft_itoa`

* **Mapping & Iteration:** `ft_strmapi`, `ft_striteri`

* **File Descriptor Output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### 3. Linked List Functions (Part 3)

* `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instructions

### Compilation

The project relies on a strictly compliant `Makefile` using the standard flags `-Wall -Wextra -Werror` with `cc`.

To build the static library `libft.a` at the root of the repository:

```
make

```

### Available Rules

* `make` or `make all`: Compiles all C source files (`.c`) into object files (`.o`) and archives them into `libft.a`.

* `make clean`: Removes all compiled object files (`.o`).

* `make fclean`: Removes all compiled object files (`.o`) as well as the compiled library binary (`libft.a`).

* `make re`: Performs a complete re-compilation from scratch (`fclean` followed by `all`).

### Usage in Other Projects

To use `libft.a` in another C project, include the main header file in your source code and link the library during compilation:

```
#include "libft.h"

```

Compile your application with the library:

```
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

```

## Resources & AI Use Disclosure

### References

* [C Data Types and Pointer Arithmetic Documentation](https://en.cppreference.com/w/c)

* Linux / POSIX Programmer's Manual (Manpages: `man 3 malloc`, `man 3 calloc`, `man 3 memset`)

* 42 School Norm Guidelines v4

### AI Usage Disclosure

In alignment with 42 AI policy guidelines, AI tools were utilized during this project as a interactive coding tutor and senior reviewer for the following tasks:

* **Conceptual Clarification:** Deepening understanding of memory segments (Stack vs. Heap vs. Text), pointer dereferencing, and static function scoping.

* **Makefile Optimization:** Reviewing build mechanics, automatic variables (`$<`, `$@`), and standard Makefile target flows.

* **Code Audit & Peer Evaluation Preparation:** Reviewing implementation details against standard C behavior to prepare for peer defense questioning.

### Author Information

* **Student Name:** Amine Benzagour

* **Login:** `abenzago`

* **Campus:** 1337 UM6P (Ben Guerir)