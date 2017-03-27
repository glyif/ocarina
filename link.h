#ifndef LINK
#define LINK
typedef struct link
{
	char *command;
	int index;

	struct link *prev;
	struct link *next;

} link;

typedef struct router
{
	char *command;
	
	char **(*f)();
} router;
#endif
