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
	
}
struct node seg(struct node *head)
{
	struct node *last=NULL,*newHead=NULL,cur=NULL;
    WrapSeg(&head,&last,&newHead,head);
    return newHead->next;
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
 
    head=seg(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}