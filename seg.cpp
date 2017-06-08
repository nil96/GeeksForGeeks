#// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
void _seg(struct node **head,struct node **last,struct node **newHead,struct node *cur)
{
	if(cur==NULL)
		return;
	if(cur->next==NULL)
	{
		*last=cur;
		//*newHead=cur;
		//return;
	}
	_seg(head,last,newHead,cur->next);
	if( (*head)->data%2==1)
	{
	 	if(*newHead == *head )
	 	    *newHead =(*head)->next;
		(*last)->next=*head;
		(*head)->next=NULL;
		*last=*head;
		*head=(*newHead);
		
	}
	else
	{
		*head=(*head)->next;
	}
	
}
struct node* seg(struct node *head)
{
	struct node *last=NULL,*newHead=head,*cur=NULL;
    _seg(&head,&last,&newHead,head);
    return newHead;
}




/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Let us create a sample linked list as following
      0->2->4->6->8->10->11 */
 
    push(&head, 11);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
    push(&head, 0);
 
    printf("\nOriginal Linked list \n");
    printList(head);
 
    head=seg(head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}