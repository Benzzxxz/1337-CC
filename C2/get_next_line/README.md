*This project has been created as part of the 42 curriculum by abenzago.*

# get_next_line

## Description

**get_next_line** is a C function, `char *get_next_line(int fd)`, that returns
one line at a time from a file descriptor each time it is called.

- The returned line includes the trailing `\n`, unless the end of the file is
  reached and the file does not end with one.
- It returns `NULL` when there is nothing left to read or when an error occurs.
- It works on regular files as well as on standard input.

The goal of the project is to learn about **static variables**, **file
descriptors**, **buffered reading with `read()`**, and **dynamic memory
management** in C. The only allowed external functions are `read`, `malloc`
and `free`. Global variables, `lseek()` and `libft` are forbidden.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` defines the number of bytes requested by each call to `read()`.
It can be changed at compile time with `-D BUFFER_SIZE=n`. If the flag is
omitted, a default value of `42` is used.

### Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Each returned line is allocated with `malloc`, so the caller must `free` it.

### Files

| File | Role |
|------|------|
| `get_next_line.c` | Main function `get_next_line` and its internal steps |
| `get_next_line_utils.c` | String helpers (length, search for `\n`, join, duplicate) |
| `get_next_line.h` | Prototypes, includes and default `BUFFER_SIZE` |

## Algorithm

### Chosen approach

The function keeps a **static string (the "stash")** that survives between
calls. It holds the characters that were already read from the file
descriptor but not yet returned to the caller.

Each call to `get_next_line(fd)` does the following:

1. **Check for invalid input.** If `fd` is negative or `BUFFER_SIZE` is not
   positive, return `NULL`.
2. **Read until a line is available.** While the stash does not contain a
   `\n`, call `read()` with a buffer of `BUFFER_SIZE` bytes and append what
   was read to the stash. Stop when a `\n` appears in the stash or when
   `read()` returns `0` (end of file).
3. **Extract the line.** Copy everything from the start of the stash up to
   and including the first `\n` (or up to the end of the stash if there is no
   `\n`) into a new