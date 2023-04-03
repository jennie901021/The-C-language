#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
	long long int point;
	char name[6];
	struct node *next;
};
typedef struct node Node;
main()
{	
	int N = 1,i,j,k,m,n,p,q,r,s,time = 0;
	long long int temp = 0;
	char ans[7];
	Node *first,*current,*previous,*last,*before;
	while(1)
	{
		current=(Node *) malloc(sizeof(Node));
		printf("Please input name #%d:",N);
		scanf(" %s",&ans);
		if (ans[0] == '0')
		{
			break;
		}
		if ((strlen(ans)) != 5)
		{
			printf("Input Error\n");
			continue;
		}
		N += 1;
		for (i=0;i<=4;i++)
		{
			current->name[i] = ans[i];
		}
		for (j=0;j<=4;j++)
		{
			if (isupper(ans[j]) == 0)
			{
				ans[j] =  toupper(ans[j]);
			}
		}
		for (m=0;m<=4;m++)
		{
			temp = temp * 100;
			temp += ans[m];
		}
		current->point = temp;
		if (time == 0)
		{
			first = current;  //�p�G�O�Ĥ@�Ӧ��������first���V�ثe���I�I
			last = current; 
			before = current;
			current->next = NULL; //��ثe���I�I��next���VNULL
			previous = current; //��e�@�Ӹ`�I�]���ثe���I�I 	
		}
		else
		{
			if (current->point <= first->point)
			{
				current->next = first;
				first = current;
				before = first;
				previous = first;
			}	
			else if (current->point > last->point)
			{
				last->next = current;
				last = current;
				last->next = NULL;
			}
			else
			{
				while(1)
				{
					previous = previous->next;
					if (current->point <= previous->point)
					{
						current->next = previous;
						before->next = current;
						break;
					}
					before = before->next;
				}
			}
			previous = first;
			before = first;			
		}		
		time += 1;
		temp = 0;
	//	printf("\n");
		continue;
	}
	printf("����\n");
	for (k=0;k<=4;k++)
	{
		printf("-");
	}
	printf("\n");
	current=first;
	while(current!=NULL)
	{
		printf("%s \n",current->name); //�L�X���� 
		current = current->next;
	}
	for (k=0;k<=4;k++)
	{
		printf("-");
	}
	printf("\n");
	printf("�˧�\n");
	for (k=0;k<=4;k++)
	{
		printf("-");
	}
	printf("\n");
	current = first;
	n = N-2;
	char back[N][6];
	for (p=0;p<=n;p++)
	{
		for (q=0;q<=4;q++)
		{
			back[p][q] = current->name[q];
		}
		current = current->next;
	}
	for (r=n;r>=0;r--)
	{
		for (s=0;s<=4;s++)
		{
			printf("%c",back[r][s]);
		}
		printf("\n");
	}
	for (k=0;k<=4;k++)
	{
		printf("-");
	}
}
