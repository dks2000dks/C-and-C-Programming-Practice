#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* ptr;
}node;
node *head=NULL;
node *tail=NULL;

void insert_at_begin(int x)
{
	node *p=(node*)malloc(sizeof(node));
	if(p==NULL)
	{
		printf("malloc failed");
		return;
	}
	
	p->val=x;
	if(head==NULL)
	{
		//no nodes earlier
		p->ptr=NULL;
		head=tail=p;
	}
	else
	{
		
		p->ptr=head;
		head=p;
	}
	
		
}
void insert_at_end(int x)
{
	node *p=(node*)malloc(sizeof(node));
	p->val=x;
	if(tail==NULL)
	{
		p->ptr=NULL;
		head=tail=p;
	}
	else
	{
		tail->ptr=p;
		p->ptr=NULL;
		tail=p;
	}
}
void insert_after(int key,int x)
{
	node *p=(node*)malloc(sizeof(node));
	for(p=head;p!=NULL;p=p->ptr)
	{
		if(p->val==key)
		break;
	}
	node *q=(node*)malloc(sizeof(node));
	if(p->ptr==NULL)
	{
		tail->ptr=q;
		q->val=x;
		q->ptr=NULL;
		tail=q;
	}
	else
	{
		q->ptr=p->ptr;
		q->val=x;
		p->ptr=q;
	}
}
void insert_before(int key,int x)
{
	node *p=(node*)malloc(sizeof(node));
	node *prev=(node*)malloc(sizeof(node));
	prev=NULL;
	for(p=head;p!=NULL;p=p->ptr)
	{
		if(p->val==key)
		break;
	    prev=p;
	}
	node *q=(node*)malloc(sizeof(node));
	if(prev==NULL)
	{
		q->val=x;
		q->ptr=head;
		head=q;
	}
	else
	{
		q->val=x;		
		q->ptr=prev->ptr;
		prev->ptr=q;
	}
}
void delete_node(int key)
{
	node *p=(node*)malloc(sizeof(node));
	node *prev=(node*)malloc(sizeof(node));
	prev=NULL;
	for(p=head;p!=NULL;p=p->ptr)
	{
		if(p->val==key)
		break;
	    prev=p;
	}
	prev->ptr=p->ptr;
	free(p);


}
void clear_all()	
{
	node *p=(node*)malloc(sizeof(node));
	node *nd=(node*)malloc(sizeof(node));
	for(p=head;p!=NULL;)
	{
		nd=p->ptr;		
		free(p);
		p=nd;
	}


}	
	
void traverse()
{
	node *p=(node*)malloc(sizeof(node));
	for(p=head;p!=NULL;p=p->ptr)
	{
		printf("\nnode=%X,val=%d,ptr=%X",p,p->val,p->ptr);
	}
}
void main()
{
		
	insert_at_begin(10);
	traverse();
	insert_at_begin(20);
	insert_at_begin(30);
	traverse();
	insert_at_end(40);
	traverse();
	insert_after(30,50);
	traverse();
	insert_after(40,60);
	traverse();
	insert_before(10,70);
	traverse();
	delete_node(70);
	traverse();
	clear_all();
	traverse();
}

	
