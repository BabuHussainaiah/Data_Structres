#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start=NULL;
void add_node_at_mid(int val);
void create_list_at_end(int *,int);
void display();
int list_count();
#define A_ELE 4
int count=0;
void main()
{
	int num,val;
	int lal=10;
	int arr[A_ELE],i;
	while(1)
	{
		printf("enter array element  (0 FOR EXIT)\n");
		scanf("%d",&num);
		if(num==0)
			exit(0);
		if(start == NULL)
		{
			printf("enter array elements\n");
			for(i=0;i<A_ELE;i++)
				scanf("%d",&arr[i]);
			create_list_at_end(arr,A_ELE);
		}
		printf("enter number to add :\n");
		scanf("%d",&num);
		add_node_at_mid(num);
		display();
	}
}
int list_count()
{
	int count=0;
	struct node *temp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return count;
	}
	temp=start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	return count;
}

void add_node_at_mid(int val)
{
	int i,j;
	struct node *temp,*ptr,*prev;
	j=count/2;
	prev=temp=start;
	if(start==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(start->link==NULL)
	{
		printf("list contains only single node\n");
		return;
	}
	if(count%2==0)
	{
	for(i=0;i<j;i++)
	{
		prev=temp;
		temp=temp->link;
	}
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=val;
	ptr->link=prev->link;
	prev->link=ptr;
	count=list_count();
	}
	else
	{
		j++;
	for(i=0;i<j;i++)
	{
		prev=temp;
		temp=temp->link;
	}
	ptr=(struct node *)malloc(1*sizeof(struct node));
	ptr->data=val;
	ptr->link=prev->link;
	prev->link=ptr;
	count=list_count();
	}
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
void create_list_at_end(int *iptr,int n)
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
		count=list_count();
		return;
	}
	temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=l_start;
	count=list_count();
}



