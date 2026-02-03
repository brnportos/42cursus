*This project has been created as part of the 42 curriculum by brportos.*

# Libft

## Description
Libft is the first project in the 42 curriculum. The primary goal of this project is to create a custom C library containing a collection of general-purpose functions. These functions will be reused in future C projects throughout the curriculum. The project involves recoding standard C library functions from headers like `<string.h>`, `<stdlib.h>`, and `<ctype.h>`. By manually reimplementing these functions, I gained a deeper understanding of memory management, pointers, data structures, and the internal workings of the C standard library.

## Library Overview
The library is divided into three main categories:

### 1. **Libc Functions**
These are standard C functions, re-implemented to understand their mechanics and improve my coding skills. The functions included are primarily from the following headers: `<string.h>`, `<ctype.h>`, and `<stdlib.h>`. Some of the key functions implemented include:

- **ft_isalpha**: Checks if a character is alphabetic.
- **ft_isdigit**: Checks if a character is a digit.
- **ft_isalnum**: Checks if a character is alphanumeric.
- **ft_isascii**: Checks if a character is an ASCII character.
- **ft_isprint**: Checks if a character is printable.
- **ft_strlen**: Calculates the length of a string.
- **ft_memset**: Fills a block of memory with a particular value.
- **ft_bzero**: Sets the first `n` bytes of a memory block to zero.
- **ft_memcpy**: Copies memory from one location to another.
- **ft_memmove**: Moves memory from one location to another, even if the memory blocks overlap.
- **ft_strlcpy**: Copies a string and ensures null termination.
- **ft_strlcat**: Concatenates a string and ensures null termination.
- **ft_toupper**: Converts a character to uppercase.
- **ft_tolower**: Converts a character to lowercase.
- **ft_strchr**: Finds the first occurrence of a character in a string.
- **ft_strrchr**: Finds the last occurrence of a character in a string.
- **ft_strncmp**: Compares two strings up to `n` characters.
- **ft_memchr**: Searches for a character in a block of memory.
- **ft_memcmp**: Compares two blocks of memory.
- **ft_strnstr**: Finds the first occurrence of a substring in a string, up to `n` characters.
- **ft_atoi**: Converts a string to an integer.
- **ft_calloc**: Allocates memory for an array and initializes it to zero.
- **ft_strdup**: Duplicates a string by allocating memory and copying the string into it.

### 2. **Additional Functions**
These are utility functions that do not exist in the standard C library but are commonly useful for many projects. They include:

- **ft_substr**: Extracts a substring from a given string.
- **ft_strjoin**: Joins two strings into one.
- **ft_strtrim**: Removes leading and trailing whitespace from a string.
- **ft_split**: Splits a string into an array of substrings based on a delimiter.
- **ft_itoa**: Converts an integer to a string.
- **ft_strmapi**: Applies a function to each character in a string and returns a new string.
- **ft_striteri**: Applies a function to each character in a string with its index.
- **ft_putchar_fd**: Outputs a character to a file descriptor.
- **ft_putstr_fd**: Outputs a string to a file descriptor.
- **ft_putendl_fd**: Outputs a string followed by a newline to a file descriptor.
- **ft_putnbr_fd**: Outputs an integer to a file descriptor.


### 3. **Linked List Functions**
These functions facilitate the manipulation of singly linked lists. They are important for understanding dynamic memory allocation and pointer manipulation. The functions implemented are:

- **ft_lstnew**: Creates a new list element.
- **ft_lstadd_front**: Adds a new element to the front of the list.
- **ft_lstsize**: Returns the size (number of elements) of the list.
- **ft_lstlast**: Returns the last element of the list.
- **ft_lstadd_back**: Adds a new element to the end of a linked list.
- **ft_lstdelone**: Deletes a specific list element and frees its memory.
- **ft_lstclear**: Clears the memory of a linked list.
- **ft_lstiter**: Iterates over the list and applies a function to each element.
- **ft_lstmap**: Iterates over the list and applies a function to each element, creating a new list with the results.

## Instructions
1. Compile the library using:
   make
   This will generate the libft.a file.
   - Available Makefile rules:
    make clean   : removes object files
    make fclean  : removes object files and libft.a
    make re      : rebuilds the library
2. To use the library in your project, include the header:
   #include "libft.h"
3. Compile your program with libft:
   cc -Wall -Wextra -Werror main.c libft.a
## Resources
man
Google
Peer-to-peer discussions
AI
AI Usage:
AI tools were used only for explanations of concepts and function specifications. No code was copied directly from AI-generated output.

## Additional Information
For this project:
**Technical choices**: implemented all functions manually without using forbidden functions.
**Features**: full set of libc functions, extra utility functions, and linked list functions.
**Usage examples**: create main.c for function usage demonstrations.

## Required Additions
As per the project requirements, the following elements are integrated into this repository:
    **libft.h**: A header file containing all function prototypes and necessary structures.
    **Source Files**: All .c files are organized and follow the Norm coding standard.

