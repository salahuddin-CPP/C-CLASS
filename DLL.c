#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *llink,*rlink;
};

typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));

	if (x==NULL)
	{
		printf("out of memory \n");
		exit(0);
	}
	return x;
}


void freenode(NODE x)
{

free(x);

}




NODE insert_front(int item, NODE head)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;

	cur=head->rlink;

	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;

	return head;
}


NODE insert_rear(int item,NODE head)
{
	NODE temp,cur;
	temp=getnode();
	temp->info=item;

	cur=head->llink;

	head->llink=temp;
	temp->rlink=head;
	temp->llink=cur;
	cur->rlink=temp;

	return head;
}


NODE delete_front(NODE head)
{
	NODE cur,next;
	if (head->rlink==head)
	{
		printf("queue is empty \n");
		return head;
	}
	cur=head->rlink; // first node is known
	next=cur->rlink; // 2nd node which will be 1st node
	
	// adjust pointers and delete the node
	head->rlink=next;
	next->llink=head;

	printf("the node to be deleted %d \n",cur->info);
	freenode(cur);
	return head;
}
NODE delete_rear(NODE head)
{
	NODE cur,prev;
	
	if(head->llink==head)
	{
		printf("dequeue is empty \n");
		return head;
	}
	// obtain addresses of last and last but one node 
	cur=head->llink;
	prev=cur->llink;
	
	// adjust links in both directions
	head->llink=prev;
	prev->rlink=head;
	
	// delete the node 
	printf("the node to be deleted is %d \n",cur->info);
	freenode(cur);

	return head;
}

NODE insert_left(int item, NODE head)
{
	NODE temp,cur,prev;
	if(head->rlink==head)
	{
		printf("list empty \n");
		return head;
	}
	// search for key
	cur=head->rlink;
	while(cur!=head && item!=cur->info)
	{
		cur=cur->rlink;
	}
	if (cur==head)
	{
		printf("key not found \n");
	}
	prev=cur->llink;

	temp=getnode();
	scanf("%d",&temp->info);

	prev->rlink=temp;
	temp->llink=prev;
	cur->llink=temp;
	temp->rlink=cur;

	return head;


}


NODE insert_right(int item, NODE head)
{
	NODE temp,cur,prev,next;
	if(head->rlink==head)
	{
		printf("list empty \n");
		return head;
	}

	cur=head->rlink;
	while(cur!=head && item!=cur->info)
	{
		cur=cur->rlink;
	}
	
	if (cur==head)
	{
		printf("key not found \n");
	}
	next=cur->rlink;


	temp=getnode();
	scanf("%d",&temp->info);


	cur->rlink=temp;
	temp->llink=cur;
	next->llink=temp;
	temp->rlink=next;

	return head;

}

NODE delete_item(int item, NODE head)
{
	NODE prev,cur,next;
	if (head->rlink==head)
	{	
		printf("list empty\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head && item!=cur->info)
	cur=cur->rlink;
	
	if (cur==head)
	{
		printf("item not found \n");

		return head;	
	}
	
	prev=cur->llink;
	next=cur->rlink;

	prev->rlink=next;
	next->llink=prev;

	freenode(cur);
	return head;
}

void display(NODE head)
{
	NODE temp;
	if (head->rlink==head)
	{
		printf("dequeue is empty\n");
		return;
	}
	printf("\n\ncontents of DLL are \n\n");
	for(temp=head->rlink;temp!=head;temp=temp->rlink)
	printf("%d->",temp->info);
	printf("\n\n\n");
}

NODE delete_all(int item,NODE head)
{
	NODE prev,cur,next;
	int count;
	if (head->rlink==head)
	{	
		printf("\nlist empty\n");
		return head;
	}
	count=0;
	// find address of node to be deleted
	cur=head->rlink;
	while(cur!=head)
	{
		if (item!=cur->info)
		cur=cur->rlink;
		
		else
		{
			count++;
			prev=cur->llink;
			next=cur->rlink;
		
			prev->rlink=next;
			next->llink=prev;
		
			freenode(cur);
		}
	}
	if (count==0)
	printf("\nkey not found \n");

	else
	printf("key found at %d positions and are deleted \n",count);

	return head;
}






void main()
{
	NODE head;
	int choice,item;
	head=getnode();
	head->rlink=head;

	for(;;)
	{
		printf(" 1-insert front 2-insert rear  3-delete front 4-delete rear 5-display 6-delete info \n");
		printf(" 8- insert after 9- insert before 10-exit \n");
		printf("enter choice \n");
		scanf("%d",&choice);
	
 	   switch(choice)
		{

		case 1: printf("enter item to be inserted @ front \n"); scanf("%d",&item); head=insert_front(item,head); break;

		case 2: printf("enter item to be inserted @ rear \n"); scanf("%d",&item); head=insert_rear(item,head); break;

		case 3: head=delete_front(head); break;
		
		case 4: head=delete_rear(head); break;

		case 5: display(head); break;

		case 6: printf("enter the item to be deleted\n"); scanf("%d",&item); head=delete_item(item,head); break;

		//case 7 : printf("enter key to delete all \n"); scanf("%d",&item); head=delete_all(item,head); break;

		case 8 : printf("after which item u want to enter  \n"); scanf("%d",&item); head=insert_right(item,head); break;
	
		case 9 : printf("before which item u want to enter \n"); scanf("%d",&item); head=insert_left(item,head); break;


		default : exit(0);
		}
	}
}


