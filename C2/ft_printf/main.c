#include "ft_printf.h" //! s d u x p

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "ft_printf.h"

#define TMP_FILE "/tmp/ft_printf_test.txt"
#define BUF_SIZE 16384

static int	g_saved_fd;
static int	g_total;
static int	g_passed;

static void	start_capture(void)
{
	int	fd;

	fflush(stdout);
	g_saved_fd = dup(1);
	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
}

static int	stop_capture(char *buf)
{
	int	fd;
	int	n;

	fflush(stdout);
	dup2(g_saved_fd, 1);
	close(g_saved_fd);
	fd = open(TMP_FILE, O_RDONLY);
	n = read(fd, buf, BUF_SIZE - 1);
	close(fd);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	return (n);
}

static void	report(const char *name, char *real, int lreal, int rreal,
				char *mine, int lmine, int rmine)
{
	int	same_out;
	int	same_ret;

	same_out = (lreal == lmine && memcmp(real, mine, lreal) == 0);
	same_ret = (rreal == rmine);
	g_total++;
	if (same_out && same_ret)
	{
		g_passed++;
		printf("✅ %s\n", name);
		return ;
	}
	printf("❌ %s\n", name);
	if (!same_out && lreal < 200 && lmine < 200)
		printf("      output -> real: |%s|\n                mine: |%s|\n",
			real, mine);
	else if (!same_out)
		printf("      output differs (real %d bytes, mine %d bytes)\n",
			lreal, lmine);
	if (!same_ret)
		printf("      return -> real: %d   mine: %d\n", rreal, rmine);
}

#define T(name, ...) do { \
	static char	b1[BUF_SIZE]; \
	static char	b2[BUF_SIZE]; \
	int			r1; \
	int			r2; \
	int			l1; \
	int			l2; \
	start_capture(); \
	r1 = printf(__VA_ARGS__); \
	l1 = stop_capture(b1); \
	start_capture(); \
	r2 = ft_printf(__VA_ARGS__); \
	l2 = stop_capture(b2); \
	report(name, b1, l1, r1, b2, l2, r2); \
} while (0)

static int	read_ret(int fd)
{
	int	r;

	r = 12345;
	if (read(fd, &r, sizeof(r)) != (ssize_t)sizeof(r))
		r = 12345;
	return (r);
}

/* E: both functions run in a child process whose fd 1 is closed.
   Only the RETURN VALUES are compared. */
#define E(name, ...) do { \
	int	pa[2]; \
	int	pb[2]; \
	int	ra; \
	int	rb; \
	fflush(stdout); \
	if (pipe(pa) || pipe(pb)) \
		return (1); \
	if (fork() == 0) \
	{ \
		int	r; \
		setvbuf(stdout, NULL, _IONBF, 0); \
		close(1); \
		r = printf(__VA_ARGS__); \
		if (write(pa[1], &r, sizeof(r)) < 0) \
			_exit(1); \
		_exit(0); \
	} \
	wait(NULL); \
	if (fork() == 0) \
	{ \
		int	r; \
		close(1); \
		r = ft_printf(__VA_ARGS__); \
		if (write(pb[1], &r, sizeof(r)) < 0) \
			_exit(1); \
		_exit(0); \
	} \
	wait(NULL); \
	close(pa[1]); \
	close(pb[1]); \
	ra = read_ret(pa[0]); \
	rb = read_ret(pb[0]); \
	close(pa[0]); \
	close(pb[0]); \
	g_total++; \
	if (ra == rb) \
	{ \
		g_passed++; \
		printf("✅ %s\n", name); \
	} \
	else \
		printf("❌ %s\n      return -> real: %d   mine: %d\n", name, ra, rb); \
} while (0)

int	main(void)
{
	static char	big[3001];
	int			x = 42;
	int			i;

	for (i = 0; i < 3000; i++)
		big[i] = 'a' + (i % 26);
	big[3000] = '\0';

	printf("=== %%c ===\n");
	T("c letter", "%c", 'A');
	T("c space", "%c", ' ');
	T("c percent char", "%c", '%');
	T("c nul byte", "%c", 0);
	T("c three in a row", "%c%c%c", 'a', 'b', 'c');
	T("c negative char", "%c", (char)-5);

	printf("=== %%s ===\n");
	T("s normal", "%s", "hello");
	T("s empty", "%s", "");
	T("s NULL", "%s", (char *)NULL);
	T("s NULL twice", "%s|%s", (char *)NULL, (char *)NULL);
	T("s percent inside", "%s", "100%");
	T("s percent d inside", "%s", "%d %s %%");
	T("s two strings", "%s%s", "foo", "bar");
	T("s 3000 chars", "%s", big);
	T("s with newline", "%s", "a\nb\tc");

	printf("=== %%d / %%i ===\n");
	T("d zero", "%d", 0);
	T("d one", "%d", 1);
	T("d minus one", "%d", -1);
	T("d 9", "%d", 9);
	T("d 10", "%d", 10);
	T("d -10", "%d", -10);
	T("d 99", "%d", 99);
	T("d 100", "%d", 100);
	T("d 12345", "%d", 12345);
	T("d -12345", "%d", -12345);
	T("d INT_MAX", "%d", INT_MAX);
	T("d INT_MIN", "%d", INT_MIN);
	T("d INT_MIN+1", "%d", INT_MIN + 1);
	T("d zero then neg", "%d %d", 0, -5);
	T("i zero", "%i", 0);
	T("i negative", "%i", -123);
	T("i INT_MIN", "%i", INT_MIN);
	T("d and i together", "%d|%i", -7, 7);

	printf("=== %%u ===\n");
	T("u zero", "%u", 0);
	T("u one", "%u", 1);
	T("u INT_MAX", "%u", INT_MAX);
	T("u INT_MAX+1", "%u", (unsigned int)INT_MAX + 1);
	T("u UINT_MAX", "%u", UINT_MAX);
	T("u of -1", "%u", -1);
	T("u of INT_MIN", "%u", INT_MIN);
	T("u 10", "%u", 10);

	printf("=== %%x / %%X ===\n");
	T("x zero", "%x", 0);
	T("x 1", "%x", 1);
	T("x 9", "%x", 9);
	T("x 10", "%x", 10);
	T("x 15", "%x", 15);
	T("x 16", "%x", 16);
	T("x 255", "%x", 255);
	T("x 256", "%x", 256);
	T("x deadbeef", "%x", 0xdeadbeef);
	T("x UINT_MAX", "%x", UINT_MAX);
	T("x of -1", "%x", -1);
	T("x of INT_MIN", "%x", INT_MIN);
	T("x INT_MAX", "%x", INT_MAX);
	T("X zero", "%X", 0);
	T("X 255", "%X", 255);
	T("X deadbeef", "%X", 0xdeadbeef);
	T("X of -1", "%X", -1);
	T("X UINT_MAX", "%X", UINT_MAX);
	T("x and X together", "%x %X", 48879, 48879);

	printf("=== %%p (including top-bit addresses) ===\n");
	T("p stack address", "%p", &x);
	T("p NULL", "%p", (void *)0);
	T("p small: 1", "%p", (void *)1);
	T("p small: 0x1234", "%p", (void *)0x1234);
	T("p LONG_MAX", "%p", (void *)LONG_MAX);
	T("p LONG_MIN (top bit)", "%p", (void *)LONG_MIN);
	T("p ULONG_MAX", "%p", (void *)ULONG_MAX);
	T("p UINTPTR_MAX", "%p", (void *)UINTPTR_MAX);
	T("p 0x8000000000000000", "%p", (void *)0x8000000000000000UL);
	T("p 0xf000000000000000", "%p", (void *)0xf000000000000000UL);
	T("p 0x7fffffffffffffff", "%p", (void *)0x7fffffffffffffffUL);
	T("p two addresses", "%p %p", &x, (void *)0);

	printf("=== %%%% ===\n");
	T("percent alone", "%%");
	T("percent in text", "100%%");
	T("two percents", "%%%%");
	T("three percents", "%%%%%%");
	T("percent then d text", "%%d");
	T("percent then number", "%%%d", 5);
	T("number then percent", "%d%%", 5);

	printf("=== bookmark: each conversion eats exactly one arg ===\n");
	T("d d", "%d %d", 10, 20);
	T("adjacent dd", "%d%d", 10, 20);
	T("s d s", "%s %d %s", "a", 1, "b");
	T("all types", "%c %s %p %d %i %u %x %X %%",
		'z', "str", &x, -1, 2, 3u, 255, 255);
	T("all types glued", "%c%s%p%d%i%u%x%X%%",
		'z', "str", &x, -1, 2, 3u, 255, 255);
	T("12 ints (stack args)", "%d %d %d %d %d %d %d %d %d %d %d %d",
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	T("10 strings", "%s%s%s%s%s%s%s%s%s%s",
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9");
	T("mixed 14 args", "%d%s%c%x%u%d%s%c%x%u%d%s%c%X",
		1, "a", 'b', 255, 2u, 3, "c", 'd', 16, 4u, 5, "e", 'f', 171);
	T("u then d then x", "%u %d %x", UINT_MAX, INT_MIN, UINT_MAX);
	T("p then d", "%p %d", &x, 9);
	T("s NULL then d", "%s %d", (char *)NULL, 77);
	T("p NULL then s", "%p %s", (void *)0, "after");
	T("d then p NULL then d", "%d %p %d", 1, (void *)0, 2);

	printf("=== plain text and format edges ===\n");
	T("empty format", "");
	T("plain text", "just text");
	T("text with newline", "line1\nline2\n");
	T("text before conv", "value: %d", 5);
	T("text after conv", "%d apples", 5);
	T("text around conv", "[%d]", 5);
	T("long plain text", "%s", big);

	printf("=== write failure (fd 1 closed): return values ===\n");
	E("closed: plain text", "hello");
	E("closed: %c", "%c", 'a');
	E("closed: %s", "%s", "hi");
	E("closed: %s NULL", "%s", (char *)NULL);
	E("closed: %d", "%d", 42);
	E("closed: %d negative", "%d", -42);
	E("closed: %u", "%u", 42u);
	E("closed: %x", "%x", 255);
	E("closed: %p", "%p", &x);
	E("closed: %%", "%%");
	E("closed: text then %d", "abc%d", 5);

	printf("\n%d / %d tests passed\n", g_passed, g_total);
	return (g_passed != g_total);
}