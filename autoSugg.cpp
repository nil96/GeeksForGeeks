#include<bits/stdc++.h>
#define lli long long  int
using namespace std;
struct node 
{
   struct node *children[260];
   int flag;
};
struct node* newNode()
{
	struct node * x=(struct node *)malloc(sizeof(struct node));
    for(int i='a';i<='z';i++)
    	x->children[i]=NULL;
    x->flag=false;
}
void insert(struct node *root,char const *str)
{
   int l=strlen(str);
   struct node *pcrawl=root;
   for(int i=0;i<l;i++)
   {
       int ind=str[i]-'a';
       if(pcrawl->children[ind]==NULL)
       	  pcrawl->children[ind]=newNode();
       pcrawl=pcrawl->children[ind];
   }
   pcrawl->flag=1;
}
int search(struct node *root,const char *str)
{
	int l=strlen(str);
	struct node *pcrawl=root;
	for(int i=0;i<l;i++)
	{
		int ind=str[i]-'a';
		if(pcrawl->children[ind]==NULL)
			return 0;
		pcrawl=pcrawl->children[ind];
	}
	return pcrawl->flag;
}
void printSugg(struct node *root,char *str,int n)
{

	if(root->flag==1)
	{
		for(int i=0;i<n;i++)
			printf("%c",str[i]);
		printf("\n");
	}
	for(int i=0;i<=26;i++)
	{
		if(root->children[i]!=NULL)
		{
          str[n]=(char)(i+'a');
          //printf("%c\n",char(i));
		  printSugg(root->children[i],str,n+1);	
		}
	}

}
int Suggestion(struct node *root,char const *str)
{
   struct node *pcrawl=root;
   int l=strlen(str),flag=1;
   for(int i=0;i<l;i++)
   {
      int ind=str[i]-'a';
      if(pcrawl->children[ind]==NULL)
      {
      	flag=0;
      	return 0;
      }
      //printf("%c\n",str[i]);
      pcrawl=pcrawl->children[ind];
   }
   char arr[100];
   strcpy(arr,str);
   printSugg(pcrawl,arr,l);


}
int main()
{
	struct node* root = newNode();
    insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");
    Suggestion(root,"hel");
    int x=search(root,"hello");
    /*if(x==1)
    	printf("hello\n");
    else
    	printf("No hello\n");*/
   /* int comp = printAutoSuggestions(root, "hel");
 
    if (comp == -1)
        cout << "No other strings found with this prefix\n";
 
    else if (comp == 0)
        cout << "No string found with this prefix\n";*/
 
    return 0;
     
}