#include<bits/stdc++.h>
#define lli long long int
using namespace std;
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
struct Node* SortedMerge(struct Node*a, struct Node*b)
{
	struct Node* root = (struct Node*) malloc(sizeof(struct Node));
	struct Node* pcrawl = root;
	while(1)
	{
		if(a==NULL)
		{
			pcrawl->next=b;
			break;
		}
		else if(b==NULL)
		{
            pcrawl->next=a;
            break;
		}
		else
		{
			if(a->data < b->data)
			{
				pcrawl->next=a;
				pcrawl=a;
				a=a->next;
				pcrawl->next=NULL;
			}
			else
		    {
		    	pcrawl->next=b;
				pcrawl=b;
				b=b->next;
				pcrawl->next=NULL;
		    }
		}	
	}
	return root->next;
}
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    //push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);
 
    printf("Merged Linked List is: \n");
    printList(res);
 
    return 0;
}