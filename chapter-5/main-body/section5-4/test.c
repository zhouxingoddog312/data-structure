#include <stdio.h>
#include "hashquad.h"
char *S_gets(char *string,int n);
int main(void)
{
	HashTable H;
	H=InitializeTable(6);
	char string[20];
	fputs("input:",stdout);
	while(S_gets(string,20)!=NULL)
	{
		puts(string);
		H=Insert(string,H);
		puts("continue.");
	}	
	Travel(H);
	return 0;
}
char *S_gets(char *string,int n)
{
	char *ret_val;
	int i=0;
	ret_val=fgets(string,n,stdin);
	if(ret_val)
	{
		while(string[i]!='\n'&&string[i]!='\0')
			i++;
		if(string[i]=='\n')
			string[i]='\0';
		else
			while(getchar()!='\n')
				continue;
	}
	return ret_val;
}

