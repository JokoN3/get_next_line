*This project has been created as part
of the 42 curriculum by yoneshev.*


# **Get Next Line**

### Description
An implementation of a function that reads a line from a file descriptor ending with a newline character. This project explores the use of static variables, memory allocation, and buffer management in C.

### Instructions
To use this function in your project, clone the repository:
```bash
git clone https://github.com/JokoN3/get_next_line.git
```
Include the header in your code:
```C
#include "get_next_line.h"
```
Compile the Get_next_line files along with your own source files. You can define the BUFFER_SIZE at compile time using the -D flag:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o program_name
```
Note: If no BUFFER_SIZE is specified, it will default to the value defined in the header.

### Resources
* [`Static variables`](https://www.geeksforgeeks.org/c/static-variables-in-c/)
* [`man 2 read`](https://man7.org/linux/man-pages/man2/read.2.html)
* [`man 3 errno`](https://man7.org/linux/man-pages/man3/errno.3.html)