<img src="https://www.holbertonschool.com/assets/holberton-logo-1cc451260ca3cd297def53f2250a9794810667c7ca7b5fa5879a569a457bf16f.png" alt="Holberton logo">

# ocarina
## Author: Bobby Yang (Batch 2)

## Build Status
Master: [![Build Status](https://travis-ci.org/glyif/ocarina.svg?branch=master)](https://travis-ci.org/glyif/ocarina)

Dev: [![Build Status](https://travis-ci.org/glyif/ocarina.svg?branch=dev)](https://travis-ci.org/glyif/ocarina)

## Synopsis
Ocarina is simple implementation of a doubly linked list built on top of a simple shell. Ocarina takes in commands and stores each command into a doubly linked list. So you can go back and access previous commands. I chose a doubly linked list instead of a singly linked list because then ocarina is able to retrieve commands relatively. For example I can retrieve a command that's `4` previous, then I can find commands relative to that command such as the command previous to that command.

Ocarina is made to only for implementing a doubly linked list. It's not able to run any actual commands besides the command to retrieve previous commands.

## File Breakdown
### link.h
This file contains two structs, one is a basic struct for a doubly linked list, the other is for the router to route a command to the correct function to process said command.

```c
typedef struct link
{
	char *command;
	int index;

	struct link *prev;
	struct link *next;
} link
```
This struct is for a doubly linked list used by ocarina. Every command is stored in a doubly linked list. So it can be recalled. Also, unlike a normal shell, all the arguments are also stored in a doubly linked list of it's own.

For example, when running the command:
```bash
ocarina > ocarina prev
```
The whole command gets stored in a linked list, then the command gets parsed out and every work gets seperated into nodes into a local doubly linked lists that can then get processed by function that matches the first word to a list of commands that passes the precedding nodes of the list into another function that actually executes the command.

```c
typedef struct router
{
	char *command;

	int (*f)();
} router;
```
For you Holberton School Students, you should be familiar with this struct. Here, I'm storing a command and grouping it with a function that processes a specific command.

### ocarina.h
This file contains all the prototypes for this project.

### ocarina.c
This file contains the `main` function of the program. Within this function, it just runs a loop called `oc_time` which is the function that runs ocarina.

### oc_time.c
This file contains a function called `oc_time`. This function is the function that puts all the parts together.

```c
void oc_time(void);
```

In this file, multiple commands are called that process everything put into the command linke.

### oc_commands.c
This file contains a function called `oc_command`.

```c
char *oc_commands(void);
```

This function grabs input data from the command line of ocarina and stores it into a buffer. This function uses `getchar()` to get every character inputer and then places it into the buffer.

### oc_args.c
This file contains a function called `oc_args`.

```c
void oc_args(link *head, char *command);
```
- `@head` is the pointer of the head that will contain the tokenized sections of a command.
- `@command` is the buffer that has the command.

oc_args is a function that basically separates our the a command out into tokens. In my implementation, every token gets stored into a new node.

For example:
```bash
ocarina > ocarina prev
```
is stored as.

```bash
tokenized arguments
----------------

          head
           |
           |
  +------+-----------+--+    +--+-----+--++------+
  |      |           |o------>  |        |      |
  | NULL |  ocarina  |          |  prev  | NULL |
  |      |           |  <------o|        |      |
  +------+-----------+--+    +--+-----+--+------+
```

What this diagram doesn't show that is the string "ocarina" and "prev" aren't actually stored in the node. It's the pointer to the strings that's store, but due to complexity's sake, the diagram doesn't show that.

### oc_exec.c
This file has a function called `oc_exec`.

```c
int oc_exec(link *ocarina, link *history);
```
- `@ocarina` is the pointer to the head of the linked lists of tokenized commands.
- `@history` is the pointer to the head of the linked list that has all of the commands stored for `ocarina`.

This function basically matches up the first part of the command with a struct array that then executes a command that matches.

### ocarina_command.c
This file has a function called `ocarina_command`.

```c
int ocarina_command(link *ocarina, list *history);
```
- `@ocarina` is the pointer to the head of the linked lists of tokenized commands.
- `@history` is the pointer to the head of the linked list that has all of the commands stored for `ocarina`.

This function processes what happens when you type the command `ocarina`.

### add_history.c
This file contains a function called `add_history`.

```c
void add_history(link **head, char *command);
```

This function is the function that creates the doubly linked list for both the ocarina command recall and the tokenization of the arguments.

### print_list.c
This file contains a function called `print_list`.

```c
void print_list(link *head);
```

This function isn't actually used in `ocarina`. It was just written for debugging the linked lists during development.

### helper.c
This file has a many helper functions, most of them are rewrites of standard library functions, but there are a few custom functions as well.

## Using
`Ocarina` is still under development so the use is still very minimal.

To build the project, you'll need to run:
```bash
$ make all
$ ./ocarina
```

Then inside of the `ocarina` shell, the only command that does anything at the moment is `ocarina`.

Currently ocarina is `able` to pull up the command of the index you pass in after it.

Here's an example:
```c
ocarina > hello
ocarina > hi there
ocarina > how are you
ocarina > I asked you first
ocarina > nope, i did
ocarina > ocarina 2
how are you
```

In this case, `ocarina` will fetch the command of index 2 of the list which is `how are you` and print it.


## TODO
- [x] Be able to pass in arguments like `prev` and `next` to navigate up and down the list.
- [ ] Be able to use the up and down arrows to navigate up and down the list
- [ ] Have the command get actually brought up into the command line instead of just printing it so it can be run again.
- [ ] Get [@Julien Barbier](https://github.com/jbarbier) to say I did a good job ;)


