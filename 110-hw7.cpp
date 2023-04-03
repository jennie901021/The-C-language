#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
	int time;
	char name[46];
	struct node *next;
};
typedef struct node Node;
int main()
{
	FILE *fp1, *fpans;
	int L, i, j=0, k, m, a=0, start=0, end=0, x=0, y=0, space;
	char word[46], num[3];	
	Node *first,*current,*previous,*last;
	fp1 = fopen("TTG.txt","r");
	fpans = fopen("TTGans.txt","w");
	while(fscanf(fp1,"%s",&word) != EOF)
	{
		current=(Node *) malloc(sizeof(Node));		
		L = strlen(word);	
		for (i=0;i<L;i++)
		{
			if (isalpha(word[i]) != 0 || isdigit(word[i]) != 0)
			{
				a += 1;
				end = i;
			}
			if (a == 1)
			{
				start = i;
				a += 1;
			}
		}
		a = 0;
		memset(current->name,'\0',sizeof(current->name));
		for (k=start;k<=end;k++)
		{
			current->name[j] = word[k];
			j += 1;
		}
		j = 0;
		current->next = NULL;
		if (x == 0)
		{	
			current->time = 1;				
			first = current;  
			last = current; 
			previous = current;  
		}
		else
		{
			while(previous != NULL)
			{
				if (strcmpi(previous->name,current->name) == 0)
				{
					previous->time += 1;
					y += 1;	
					break;
				}
				previous = previous->next;
			}
			previous = first;			
			if (y == 1)  
			{
				y = 0;		
				memset(word,'\0',sizeof(word));
				continue;				
			}				
			current->time = 1;
			last->next = current;
			last = last->next;
		}
		x += 1;
		memset(word,'\0',sizeof(word));		
	}
	current = first;
	while(current!=NULL)
	{
		L = strlen(current->name);
		space = 46 - L;
		itoa(current->time,num,10);
		printf("%-46s",current->name);
		printf("%d\n",current->time); 
		fputs(current->name,fpans);
		for (m=0;m<=space;m++)
		{
			fputs(" ",fpans);
		}
		fputs(num,fpans);
		fputs("\n",fpans);		
		current = current->next;
	}
	fclose(fp1);
	fclose(fpans);
}
