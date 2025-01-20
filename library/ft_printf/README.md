# ft_printf

<p align="center">
  <img src="https://github.com/mbah24-dev/mbah24-dev/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
</p>

For the ft_printf project of the 42 school cursus, we must recreate the famous C library printf function. This project teaches us about variadic arguments as well as structures if we plan to implement printf's extra flags.

- Supported conversions: %, c, s, p, i, d, u, x, X

## Status
Finished: 2024-11-27. Grade: 100/100.

## Usage

``make`` to compile.

### Basic Usage
For example, let's create a ``main.c`` file.

```c
// Include the header
#include "ft_printf.h"

int main(void)
{
      // Call the function
      ft_printf("Testing ft_printf! %d", 42);
      ft_printf("Testing ft_printf! %X", 255);
      return (0);
}
```

Compile the ``main.c`` file with the ft_printf library and run the program:
```bash
gcc main.c libftprintf.a && ./a.out
```
Output should be:
```
Testing ft_printf! 42
Testing ft_printf! FF
```

### Advanced Usage: Format Specifiers

The table below lists supported format specifiers:
<table>
    <thead>
        <tr>
            <th colspan=3><h4>Specifiers</h4></th>
        </tr>
        <tr>
            <th>Format Specifier</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
	</thead>
        <tr>
            <td align="center">%</td>
            <td>% followed by another % character writes % to the screen.</td>
        </tr>
        <tr>
            <td align="center">c</td>
            <td>writes a single character.</td>
        </tr>
        <tr>
            <td align="center">s</td>
            <td>writes a character string.</td>
        </tr>
        <tr>
            <td align="center">p</td>
            <td>writes an implementation-defined character sequence defining a pointer address.</td>
        </tr>
        <tr>
            <td align="center">d or i</td>
            <td>writes a signed integer to decimal representation.</td>
        </tr>
        <tr>
            <td align="center">u</td>
            <td>writes an unsigned integer to decimal representation.</td>
        </tr>
        <tr>
            <td align="center">x or X</td>
            <td>writes an unsigned integer to hexadecimal representation.</td>
        </tr>
    </tbody>
</table>



---
Made by mbah: mbah@student.42.fr
