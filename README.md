<p align="center">

  <img src="ghostintheshell.png" width="350\"/>

<br>

<h1><p align="center">Ghost Shell- A simple shell</h1></p></font>

<br>

<h2><p>Projects:</p></h2>

# GSH
Ghost Shell also known as the shell is a simple command line prompt that takes the most basics of commands that are present in the bash shell and runs them. This shell was built as a project for Holberton School.

`the shell` works like the bash and other basic shells. 

The shell works by being compiled using GCC 4.8.5 compiler or later versions. The shell can compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *c -o shell. 

## Example of how to launch the shell after compiling:
`./shell`

* Output: prompt to terminal: `$ `

## Syntax
The shell works by using commands given by the user input. The shell commands take in the following syntax: `command name {arguments}`. The shell executes a command after it is written by user using the command followed by the arguments. 

`cat holberton.h` 
The above example takes in a command by the user followed with the arguments. In this case the command is `cat` (to view file without opening file) followed by argument the file name in this case `holberton.h`.

For more information on cat, you can use the `man` command which will show a manual of the given command or any command you wish to know more information on. It contains system calls, libraries and other important files.

The shell also contains two builtins which are commands that are within the shell itself. The two builtins are `exit` and `env`. You can also use `help` command to know which builtins are provided by the shell. The `help` command works similarly to the manual where it provides further detail or information on given builtin.

### Commands

### Command Seperation


### Compilation
All files will be compiled with the following: `$ gcc -Wall -Werror -Wextra -pedantic *.c`

### Flags
Flags are arguments of commands given that are supported by the shell. 


### List of useful commands
`cat` - prints and concatenates files to the standard output
`cp` -copies a file into another file
`grep` - helps to search for a file in a specific pattern
`less` - will let you go backward and forward in the files
`ls` - will list all files and directories in current working directory
`mv` - helps to move one file into another file
`pwd` - given you the current working directory


### Comments


### Builtins


### cd

### help

### exit


### Exiting commands and the shell


## Files
* `README.md` : Current file, contains information about this project
* `holberton.h` : Header file, contains all prototypes for funcitons used, as well as libriaries.
* `_printf.c` : Contains the code for `_printf`
* `_putchar.c`: File for function that prints a character
* `pf_funcs.c`: File containing the specific functions for conversion specifiers
* `man_3_printf`: man page for our `_printf`
* `testing`: folder for test files
