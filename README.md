# SimpleCatCommand

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

# Table Of Contents
<p align="center">
  <a href="#Setup">Setup</a> •
  <a href="#Description">Description</a> •
  <a href="#Objectifs">Objectifs</a> •
  <a href="#Key-learnings">Key learnings</a> •
  <a href="#Installation">Installation</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

# Setup
[(Back to top)](#table-of-contents)

* __Prerequisites__
    * The library is supported on Linux, macOS, FreeBSD, and Windows.
    * The following compilers are supported to compile both the library and the tests:
        * GCC 4.9+ (Can be relaxed to GCC 4.6+ when not using C++)
        * Clang 3.4+
        * MSVC 14+ (Included in Visual Studio 2015 or later)
* __Building from source__
    * First, install dependencies:
        * C/C++ compiler
        * Meson, Ninja
        * CMake (for subprojects)
        * pkg-config
        * libffi (libffi-dev)
        * libgit2 (libgit2-dev)
        * Other runtime dependencies will be bundled if they are not available on the system (BoxFort, debugbreak, klib, nanomsg, nanopb).
    * Clone this repository:
        * ```bash
            $ git clone --recursive https://github.com/Snaipe/Criterion
    * Then, run the following commands to build Criterion:
        * ```bash
            $ meson build
            $ ninja -C build
    * Installing the library and language files (Linux, macOS, FreeBSD)
Run with an elevated shell:
        * ```bash
            $ ninja -C build install
    * On Linux systems, update the dynamic linker runtime bindings:
        * ```bash
            $ ldconfig
    * Usage
        * To compile your tests with Criterion, you need to make sure to:
            * Add the include directory to the header search path
            * Install the library to your library search path
            * Link Criterion to your executable.

This should be all you need.
# Description
[(Back to top)](#table-of-contents)

* Cat(concatenate) command is very frequently used in Linux. It reads data from the file and gives their content as output. It helps us to create, view, concatenate files.
# Objectifs
[(Back to top)](#table-of-contents)

* Write a simplified cat(1) command.
* Executable must take one or several files as parameters, and does not need to handle the special case
of the standard input.
* Upon error (file not found, permission denied, etc.), you must write the following message to the error
output:
<br>`my_cat : file : No such file or directory`<br>
* file` must be replaced with the name of the file for which the error was encountered.
* If no parameter is passed to your program, you must write the following message to the error output:
<br>`my_cat : Usage : ./my_cat file [...]`<br>

# Key learnings
[(Back to top)](#table-of-contents)
### The fstream Library
* __The fstream library__ provides C++ programmers with three classes for working with files. These classes include:
    * __ofstream__ This class represents an output stream. It’s used for creating files and writing information to files.
    * __ifstream__ This class represents an input stream. It’s used for reading information from data files.
    * __fstream__ This class generally represents a file stream. It comes with ofstream/ifstream capabilities. This means it’s capable of creating files, writing to files, reading from data files.

fstream | fstream | fstream |
------- | ------- | ------- |
ofstream| ifstream| fstream |
For creating files / writing information to files | For reading information from data file | For creating files, writing and reading from files |

* We used __fstream__

### How open files
[(Back to top)](#table-of-contents)

* Before performing any operation on a file, you must first open it. If you need to write to the file, open it using __fstream__ or ofstream objects. If you only need to read from the file, open it using the ifstream object.

* The three objects, that is, fstream, ofstream, and ifstream, have the open() function defined in them. The function takes this syntax:
    * ```
        #include <fstream>
	    fstream my_file;
	    my_file.open(file_name, mode);
        ```
        * The file_name parameter denotes the name of the file to open.
        * The mode parameter is optional. It can take any of the following values:
            * Value | Description |
              ----- | ----------- |
              std::fstream::app | The Append mode. The output sent to the file is appended to it. |
              std::fstream::ate | It opens the file for the output then moves the read and write control to file’s end. |
              std::fsteram::in | It opens the file for a read. |
              std::fsteram::out | It opens the file for a write. |
              std::fstream::trunc | If a file exists, the file elements should be truncated prior to its opening. |
### How to close files
[(Back to top)](#table-of-contents)
* Once a C++ program terminates, it automatically
    * flushes the streams
    * releases the allocated memory
    * closes opened files.
    * However, as a programmer, you should learn to close open files before the program terminates.

* The fstream, ofstream, and ifstream objects have the close() function for closing files. The function takes this syntax:
    * ```
        #include <fstream>
	    fstream my_file;
	    my_file.close();
        ```

### How to read files
[(Back to top)](#table-of-contents)

* For our use case, there’s little point in processing every character separately — after all, we want to print every line from our shopping list to the screen one by one. This calls for getline(), another member function, which reads in the text until it encounters a line break.
* Here’s how we would modify our code:
    * ```
        #include <fstream>

	    fstream my_file;
	    my_file.open(file_name, mode);

        std::string my_line;
        if (my_file.is_open()) {
            while (my_file) {
                std::getline (fstream, buffer, delimiter); //fstream = my_file, buffer = my_line, delimiter = '\0'
                std::cout << myline << std::endl;
            }
        }
        my_file.close();
        ```
# Installation
[(Back to top)](#table-of-contents)

* After downloaded the project and gone to the root path SimpleCatCommand repository you can use the __Makefile__ for compile the program or the units tests and generate a bynary:
    * ```
        make
        ```
    or for the unit_tests :
    * ```
        make tests_run
        ```
## How To Use
[(Back to top)](#table-of-contents)

* To clone and run this application from your command line : 

```bash
# Clone this repository
$ git clone https://github.com/P4r4dis/SimpleCatCommand.git

# Go into the repository
$ cd SimpleCatCommand

# start Makefile for compilation and generate binary
$ make
# Or start Makefile for unit_tests
$ make tests_run


# Use binary
$ ./my_cat file1 [...]

```
