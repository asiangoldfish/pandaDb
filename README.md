# PandaDB

A simple document based DBMS (Database Management System). All data are stored
as text files on a chosen disk location as a CSV file, allowing further data
processing and analysis.

# System Requirements
- BSD, Linux, OSX and Windows
- CMake
- G++ (BSD and Linux), Clang (OSX) and Microsoft Visual Studio 2017 (Windows)

# Example
Currently, only the interactive mode has been implemented. Execute the program
to enter this mode.
```
./pandaDB
```

To list all files:
```
Command: show files

users
domains
blogs
images
```

To select a file to access and manipulate:
```
Command: select file blog
```
When showing all files again, `blog` is highlighted in green.

Display all data in `blog`:
```
Command: show data
-------------------------------------------------------------------------------------
| id:int32                  | userid:int32              | content:varchar(2048)     | 
-------------------------------------------------------------------------------------
| 2919372                   | 828836162                 | "Hello!"                  | 
| 2789173                   | 89716372801               | "Hello world!"            | 
-------------------------------------------------------------------------------------
```

# Build Instructions
## Linux
- Install CMake and Git.
- A build system must be installed. By default, CMake configures Makefile's.

```
git clone https://github.com/asiangoldfish/pandaDb --depth 1
cd pandaDb
```

- A handy Bash script is provided to run CMake commands:
```
chmod u+x util.sh
./util -b
```

The executable is at `build/bin/Linux64/Debug/pandaDb`. Move this to a location in PATH. Example:

```
sudo mv build/bin/Linux64/Debug/pandaDb /usr/local/bin
```

# Development
- Install CMake and Git.
- A build system must be installed. By default, CMake configures
  Makefile's.

  ```
  git clone https://github.com/asiangoldfish/pandaDb
  cd pandaDb
  ```

- Install Visual Studio Code
- Install the following extensions:
    - C/C++
    - Clang-Format
    - CMake Tools

  Code must be formatted using the included `.clang-format` 
  in the project root directory before it's committed.
