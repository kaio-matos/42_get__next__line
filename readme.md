# get_next_line

The second project of the 42 school consists in creating a function that reads a line from a file descriptor, but if you call again the same function using the same file descriptor it automatically reads the next line of the file, you can use as was used inside the main.c file where I used a while loop for read an entire file.

## Execution
The steps to execute are inside the Makefile. But with Make intalled just run `make` in the terminal.


## Variables
Case you want to change the file to read just change the `FILE` variable inside the Makefile, if you want you can change too the `BUFFER_SIZE` that changes how much bytes each call of the open syscall will read.

### Note
I'm uploading too the files to debug inside vscode, because I don't want to lose the configuration.