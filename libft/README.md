*This project has been created as part of the 42 curriculum by brportos.*
# Libft
## Description
Libft is the first project in the 42 curriculum. The primary goal of this project is to create a custom C library containing a collection of general-purpose functions. These functions will be reused in future C projects throughout the curriculum. The project involves recoding standard C library functions from headers like `<string.h>`, `<stdlib.h>`, and `<ctype.h>`. By manually reimplementing these functions, I gained a deeper understanding of memory management, pointers, data structures, and the internal workings of the C standard library.
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
## Detail description of the library
libft is a custom static C library (libft.a) that reimplements essential functions from the C standard library, along with additional utility functions.
The goal of this project is to build a solid foundation of reusable, well-tested functions that can be used in future C projects without relying on external libraries.
This library is organized into four main categories:
1. Character and Type Checking Functions
   These functions analyze or transform individual characters.
      - Check character types: alphabetic, digit, alphanumeric, ASCII, printable
      - Convert characters between uppercase and lowercase
2. String and Memory Manipulation Functions
   These functions handle low-level memory operations and string processing.
      - Memory management: Fill, zero, copy, move, search, and compare memory blocks
      - String handling: Measure string length, Copy and concatenate strings safely, and Search characters or substrings
      - Compare strings: Duplicate, join, trim, split, and extract substrings
3. Conversion and Allocation Functions
   These functions convert between data types and manage dynamic memory.
      - Convert strings to integers and integers to strings
      - Allocate memory dynamically and initialize it
      - Create new strings using allocated memory
4. Linked List Utility Functions
   These functions manage singly linked lists using a custom t_list structure.
      - Create new list nodes
      - Add elements to the front or back
      - Retrieve list size and last element
      - Delete elements and clear entire lists
      - Iterate over lists and apply functions
      - Map a list into a new list
