*This project has been created as part of the 42 curriculum by <abenzago>.*

# get_next_line

## Description

`get_next_line` is a C function that returns, one call at a time, the next
line of text read from a file descriptor.

```c
char *get_next_line(int fd);
```

**Goal:** read a file (or standard input) line by line, whatever the size of
the lines and whatever the value of `BUFFER_SIZE`, using only `read`,
`malloc` and `free`. The project introduces **static variables**, the
lifetime of heap memory, and how `read` consumes a file descriptor.

**Overview:**
- Each call returns one line, including its terminating `\n`, except when
  the end of the file is reached and the file does not end with `\n`.
- It returns `NULL` when there is nothing left to read or when an error occurs.
- It works on regular files and on standard input.
- Bonus, handles several file descriptors at the same time, with a
  single static variable

## Instructions

**Files:**

| File | Content |
|---|---|
| `get_next_line.c` | main function |
| `get_next_line_utils.c` | helper functions |
| `get_next_line.h` | prototypes, includes, `BUFFER_SIZE` default |
| `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h` |

**Compilation** (the buffer size is defined with `-D`):

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Without the flag, the default value defined in `get_next_line.h` is used
(<default value>).

**Usage example:**

```c
int   fd = open("file.txt", O_RDONLY);
char  *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

The caller owns each returned line and must free it. Standard input works
the same way with `fd = 0`.

## Algorithm

<Write this section in your own words. Cover these points:>

1. **Data structure chosen:** <a static string or a static linked list?>
   What does the static variable hold between two calls, and why does it
   need to be static?
2. **Main loop:** <what you do on each iteration, and the stop conditions:
   `\n` found, `read` returns 0, `read` returns -1.>
3. **Extracting the line:** <how you compute the length, copy it, and what
   remains after the `\n`.>
4. **Updating the stored leftover:** <what is freed, what is kept, and what
   the static variable is set to when nothing remains.>
5. **Edge cases:** empty file, last line without `\n`, `BUFFER_SIZE` of 1
   and very large, invalid fd, `read` error, `malloc` failure.
6. **Justification:** why this structure over the alternative (copying cost,
   number of allocations, simplicity, Norm constraints).
7. **Complexity or limits worth mentioning:** <for example, repeated copying
   with very small buffers.>

## Resources

**References:**
- `man 2 read`, `man 2 open`, `man 3 malloc`, `man 3 free`

**Use of AI:**
- Claude was used to explain concepts: file descriptors, how `read` and the offset work,
  static variables, heap versus stack, wrapper functions, and to prepare
  for the evaluation with questions.
