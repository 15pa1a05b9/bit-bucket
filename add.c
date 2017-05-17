#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<ctype.h>
struct lnode
{
	int data;
	struct lnode *ptr;
};
typedef struct lnode node;
node *create(node *head,int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	if(head==NULL)
	head=temp;
	else
	{
		temp->ptr=head;
		head=temp;
	}
	return head;
}
node *add(node *n1,node *n2,node *n3)
{
	int carry=0,sum=0;
	while(n1||n2)
	{
		if(n1==NULL)
		{
			sum=n2->data+carry;
			n3=create(n3,sum%10);
			carry=sum/10;
			n2=n2->ptr;
		}
		else if(n2==NULL)
		{
			sum=n1->data+carry;
			n3=create(n3,sum%10);
			carry=sum/10;
			n1=n1->ptr;
		}
		else
		{
			sum=n1->data+n2->data;
			n3=create(n3,sum%10);
			carry=sum/10;
			n1=n1->ptr;
			n2=n2->ptr;
			
		}
	}
	if(carry!=0)
	n3=create(n3,carry);
	return n3;
}
void display(node *head)
{
	while(head)
	{
		printf("%d->",head->data);
		head=head->ptr;
	}
}
main()
{
	int c;
	node *n1=NULL,*n2=NULL,*n3=NULL;
	FILE *fp1=fopen("num1.data","r");
	FILE *fp2=fopen("num2.data","r");
	while((c=fgetc(fp1))!=EOF);
	n1=create(n1,c-'0');
	while((c=fgetc(fp2))!=EOF)
	n2=create(n2,c-'0');
	display(n1);
	printf(" ");
	display(n2);
	printf(" ");
	n3=add(n1,n2,n3);
	display(n3);
	fclose(fp1);
	fclose(fp2);
}
