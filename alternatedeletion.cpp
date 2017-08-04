#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node* next;
};
struct node* newnode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->next=NULL;
	return node;
}
struct node* insert(struct node* head,int data)
{
	struct node* temp=newnode(data);
	if(head==NULL)
		{
			head=temp;
			return head;
		}
	struct node* temp2;
	temp2=head;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	return head;
}
struct node* alternatedeletion(struct node* head)
{
	struct node* temp=head;
	struct node* temp2=NULL;
	while(temp!=NULL&&temp->next!=NULL)
	{
		temp2=temp->next;
		temp->next=temp2->next;
		free (temp2);
		temp=temp->next;
	}
	return head;
}
void print(struct node*head)
{
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
int main()
{
	struct node* list=NULL;
	int s;
	for(int i=0 ;i<6;i++)
	{
		scanf("%d",&s);
		list=insert(list,s);
	}
	list=alternatedeletion(list);
	print(list);
}
