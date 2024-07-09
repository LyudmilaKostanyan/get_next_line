# Get Next Line

**Get Next Line** is a C programming project aimed at implementing a function that reads a line from a file descriptor (fd). This project will not only allow us to add a very convenient function to our collection,
but it will also make us learn a highly interesting new concept in C programming: static variables.

## Usage

Function Prototype:

```c
char *get_next_line(int fd);
```

Add this option to your compiler call: **-D BUFFER_SIZE=n**
It will define the buffer size for read(). Replace **n** with the number you need for BUFFER_SIZE.

### Return value

Read line: correct behavior

NULL: there is nothing else to read, or an error occurred
