#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashline.h"
enum KindOfEntry {Legitimate,Empty,Deleted};
struct HashEntry
{
	ElementType Element;
	enum KindOfEntry info;
};
typedef struct HashEntry Cell;
struct HashTabl
{
	int TableSize;
	Cell *TheCells;
};

static void FatalError(char *string);
static void Error(char *string);


static void FatalError(char *string)
{
	fputs(string,stderr);
	putchar('\n');
	exit(EXIT_FAILURE);
}
static void Error(char *string)
{
	puts(string);
}
