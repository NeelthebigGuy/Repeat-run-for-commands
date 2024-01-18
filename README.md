# Repeat-run-for-commands
A simple c program that will run commands until it reaches the passed repeat amount. 

# how to build:
While in the directory with the makefile and main.c, type "make" or "Make" in terminal or cmd. 
This will create two output files, one named "main.o" and another named "repeatedly_run", you can ignore the main.o and only use the repeatedly_run.

# how to use:
While still in the directory with the newly made "repeatedly_run" file, start the command with "./repeatedly_run", this will execute the program.
To pass arguments to the program, the format is:

./repeatedly_run *How many seconds to wait in between each loop* *How many loops* *command to run*
