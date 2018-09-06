
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));

	if (x==NULL)
	{
		printf("out of memory\n");
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
	NODE temp;
	temp=getnode();
	temp->info=item;

	temp->link=head->link;
	head->link=temp;
	head->info+=1;

return head;
}
/*
NODE delete_rear(NODE first)
{
	NODE cur,prev;
	if (first==NULL)
	{
		printf("list empty cannot delete\n");
		return first;
	}

	if (first->link==NULL)
	{
		printf("item to be deleted is %d \n",first->info);
		freenode(first);
	
		first=NULL;
		return first;
}
	prev=NULL;
	cur=first;

	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("deleted item %d \n",cur->info);
	freenode(cur);
	prev->link=NULL;
	return first;
}

NODE delete_front(NODE first)
{
	NODE temp=NULL;
	if (first==NULL){ printf("list empty \n"); exit(0); }
 temp=first;
first=first->link;
printf("deleted item %d\n",temp->info);
freenode(temp);
return first;
}
*/
NODE insert_rear(int item, NODE head)
{
	NODE temp,cur; 
	temp=getnode();
	temp->info=item;   

	// obtain address of last node 
	cur=head->link;


	while(cur->link!=head)
	cur=cur->link;

	// insert at the end
	cur->link=temp;	
	temp->link=head;
	head->info+=1;

	return head;
}


void display(NODE head)
{
	NODE temp;
	
	if (head->link==head)
	{
		printf("list is empty \n");
		return ;
	}
	printf("contents of list are \n");
	for(temp=head->link; temp!=head; temp=temp->link)
	printf("%d-> ",temp->info);

	temp=temp->link;
	printf("%d",temp->info);
	printf("\n");
}	



NODE delete_item(int item,NODE head)
{
	NODE prev,cur;
	if (head->link==head)
	{
		printf("list empty \n");
		return NULL;
	}

	prev=head;
	cur=head->link;
	
	while(cur!=head && item!=cur->info)
	{
		prev=cur;
		cur=cur->link;
	}
	if (cur==head)
	{
		printf("item not found \n");
		return head;
	}
	// delete the node 
	prev->link=cur->link;
	freenode(cur);
	head->info-=1;
	return head;
}

NODE insert_position(int item, int pos, NODE head)
{
	NODE prev,cur,temp;
	int i;
	if ((pos>head->info+1) ||(pos<1))
	{
		printf("invalid position\n");
		return head;
	}
	prev=head;  cur=head->link;
	for(i=1;i<pos;i++)
	{
		prev=cur;
		cur=cur->link;
	}

	temp=getnode();
	temp->info=item;

	prev->link=temp;
	temp->link=cur;
	

	head->info+=1;

	return head;
}

NODE delete_position(int pos, NODE head)
{
	NODE cur,prev;
	int i;
	
	if (head->link==head)
	{
		printf("list empty\n ");
		return head;
	}
	if (pos>head->info || pos<1)
	{
		
		printf("invalid position \n");
		return head;
	}
	prev=cur=head;
	for(i=1;i<=pos;i++)
	{
		prev=cur;
		cur=cur->link;
	}

	// establish link between prev and cur & delete node
	prev->link=cur->link;
	freenode(cur);
	head->info=1;
	
	return head;
}

int main()
{
	NODE head;
	int choice,item,pos;

	head=getnode();
	head->info=0;
	head->link=head;

	
	for(;;)
	{
	printf("1-insert front \
		2-insert@ pos  \
		3-delete item  \
		4-delete @ pos \
		5: display     \
		6: exit        \
		7: delete rear \
		8: delete front \n");
	printf("enter choice : ");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("enter item to be inserted \n");
				scanf("%d",&item); head=insert_front(item,head); break;

			case 2:  printf("enter item to be inserted \n");
 				scanf("%d",&item); printf("\n at pos "); scanf("%d",&pos); 
				head=insert_position(item,pos,head); break;

			case 3: printf("enter item to be deleted \n"); scanf("%d",&item);
				head=delete_item(item,head); break;
			
			case 4: printf("enter position of node to be deleted \n");
				scanf("%d",&pos); head=delete_position(pos,head); break;  


			case 5: display(head); break;

			case 6: exit(0); break;

//			case 7:

//			case 8:
				
		}
	}
return 0;
}
