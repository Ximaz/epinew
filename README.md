# EPINEW
**EPINEW** is a project that, once compiled, create some files with the required EPITECH's header for you. You just have to specify the name of the file and it's ``kind``.

# Kinds
The program will handle several kinds of file defined as following :
```c
typedef enum kind_e
{
    PROGRAM = 0,
    SOURCE,
    HEADER,
} kind_t;

static char const *kinds[] = {
    "The program",
    "The function",
    "The header",
};
```

Which can be used as following :
- ``epinew -P my_file.c`` : header + main function,
- ``epinew -S my_file.c`` : header only,
- ``epinew -H my_file.h`` : header + header guard.

According to the specified kind, the program will generate an EPITECH header that will be placed at the top of the created file. It is formated as the following :
```c
/*
** EPITECH PROJECT, <YEAR>
** <FILENAME>
** File description:
** <KINDS[KIND]> <FILENAME>
*/
```

# Build
If you want to build the project, it's pretty easy :
```bash
make build
```

If you want to install the project, it's quite the same :
```bash
make install
```

If for any reason you would like to remove the project :
```bash
make uninstall
```

# Roadmap
- [x] C source files
- [x] C program files
- [x] H header files
- [ ] Makefile files

# Contributing
Feel free to either open a pull request if you have an idea to improve the project or an issue if you're running through a problem.