# LIBFT

libft - first project in 42 school in which i should implement
some standart function from libc library

# Installation

```bash
git clone https://github.com/aunth/libft
```

# Usage

```bash
cd libft
```
Run the Makefile 
```bash
make 
```
Delete all object files
```bash
make clean
```
Create C file in which include libft header
```C
#include <stdio.h>
#include "libft.h"

int main(void) {
	char c = 'a';
	printf("Result of ft_toupper(%c) = %c\n", c, ft_toupper(c));
	return (0);
}
```
After run this command where main.c is the name of your C file
```bash
gcc main.c libft.a
```