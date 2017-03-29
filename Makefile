all:
	gcc -Wall -Werror -Wextra -pedantic ocarina.c add_history.c helper.c oc_args.c oc_commands.c oc_time.c print_list.c oc_exec.c ocarina_command.c -o ocarina
