#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void create_list_at_beg(int *,int);
void display();
#define A_ELE 4
int count=0;
void main()
{
	int num,n;
	int lal=10;
	int arr[A_ELE],i;
	while(1)
	{
		printf("If You Want to exit from this code 'enter 0 : ");
		scanf("%d",&n);
		if(n==0)
			exit(0);
		printf("enter array elements\n");
		for(i=0;i<A_ELE;i++)
			scanf("%d",&arr[i]);

		create_list_at_beg(arr,A_ELE);
		display();
	}
}

void create_list_at_beg(int *iptr,int n)
{
	int i;
	struct node *l_start,*temp;
	struct node *ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=iptr[0];
	ptr->link=NULL;
	l_start=temp=ptr;
	for(i=1;i<n;i++)
	{
		ptr=(struct node *)malloc(1*sizeof(struct node));
		ptr->data=iptr[i];
		ptr->link=temp->link;
		temp->link=ptr;
		temp=ptr;
	}
	if(start==NULL)
	{
		start=l_start;
		return;
	}
	temp->link=start;
	start=l_start;
}

void display()
{
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	printf("Array Elements Are : \n");
	temp=start;
	while(temp!=NULL)
	{
		printf("%d \n",temp->data);
		temp=temp->link;
	}
}
