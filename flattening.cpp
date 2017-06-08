#include<bits/stdc++.h>
#define lli long long int
using namespace std;
// Macro to find number of elements in array
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
 
// A linked list node has data, next pointer and child pointer
struct Node
{
    int data;
    struct Node *next;
    struct Node *child;
};
struct Node *createList(int *arr, int n)
{
    struct Node *head = NULL;
    struct Node *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct Node *)malloc(sizeof(*p));
        else {
            p->next = (struct Node *)malloc(sizeof(*p));
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}
 
// A utility function to print all nodes of a linked list
void printList(struct Node *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node *createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
 
    /* create 8 linked lists */
    struct Node *head1 = createList(arr1, SIZE(arr1));
    struct Node *head2 = createList(arr2, SIZE(arr2));
    struct Node *head3 = createList(arr3, SIZE(arr3));
    struct Node *head4 = createList(arr4, SIZE(arr4));
    struct Node *head5 = createList(arr5, SIZE(arr5));
    struct Node *head6 = createList(arr6, SIZE(arr6));
    struct Node *head7 = createList(arr7, SIZE(arr7));
    struct Node *head8 = createList(arr8, SIZE(arr8));
 
 
    /* modify child pointers to create the list shown above */
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;
 
 
    /* Return head pointer of first linked list.  Note that all nodes are
       reachable from head1 */
    return head1;
}
struct Node *merge1(struct Node *a,struct Node *b)
{
    struct Node *root=b;
    if(a==NULL)
      return b;
    if(b==NULL)
      return a;
    while(b->next!=NULL)
        b=b->next;
    b->next=a;
    return root;
}
struct Node *flattenList(struct Node *head)
{
    if(head==NULL)
        return NULL;
    struct Node *x= merge1(flattenList(head->child),head);
    head->child=NULL;
    return x;
}
struct Node *_flattenList(struct Node *head)
{
    struct Node *root=head;
    int c=0;
    while(head->next!=NULL)
    {
       
       
        flattenList(head);
        head=head->next;
    }
    return root;
}

int main(void)
{
    struct Node *head = NULL;
    head = createList();
    printf("%d\n",head->data );
    head=_flattenList(head);
    printList(head);
    return 0;
}