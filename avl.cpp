#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
//DECLARATIONS
using namespace std;
struct node* insert(int x);
int exists(struct node *root,int x);
int max(int a, int b);
int height(struct node *n);
int xsmallestnum(struct node *,int x);
int tree_size(struct node* root);
//CREATION OF STRUCTURE OF NODE IN AVL TREE
struct node
{
    int countleft;
    struct node *lc;
    int value;
    int height;
    struct node *rc;
    int countright;
    
};


//PRINTING MAX OF TWO INTEGERS
int max(int a, int b)
{
    if(a>b)
        return a;
    else 
        return b;
}
//PRINTING HEIGHT OF PRESENT NODE (LEAF NODE HAS HEIGHT 1)
int height(struct node *n)
{
    if (n == NULL)
        return 0;
    return (n->height);
}
//GETTING THE BALANCE FACTOR OF EACH NODE
int getBF(struct node *n)
{
    if (n == NULL)
        return 0;
    return (height(n->lc) - height(n->rc));
}
//PERFORMING THE RIGHT ROTATION
 struct node *RR(struct node *r)
{
    struct node *l = r->lc;
    struct node *T2 = l->rc;

    l->rc = r;
    r->lc = T2;
 
    // Update heights and Counts of left and right children
    r->height = max(height(r->lc), height(r->rc))+1;
    r->countleft = tree_size(r->lc);
    r->countright = tree_size(r->rc);
    l->height = max(height(l->lc), height(l->rc))+1;
    l->countleft = tree_size(l->lc);
    l->countright = tree_size(l->rc);
 
    // Return new root
    return l;
}
 

//PERFORMING THE LEFT ROTATION
struct node *LR(struct node *l)
{
    struct node *r = l->rc;
    struct node *T2 = r->lc;
    r->lc = l;
    l->rc = T2;
    l->height = max(height(l->lc), height(l->rc))+1;
    l->countleft = tree_size(l->lc);
    l->countright = tree_size(l->rc);

    r->height = max(height(r->lc), height(r->rc))+1;
    r->countleft = tree_size(r->lc);
    r->countright = tree_size(r->rc);
    return r;
}
 //CREATES A NEW NODE
struct node * createNode(int value)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->countleft=temp->countright=temp->height=0;
    temp->value = value;
    temp->lc = temp->rc = NULL;
    temp->height=1;
    return temp;
    
}
//RETURNS THE NUMBER OF ELEMENTS IN THE SUBTREE

int tree_size(struct node* root)
{
    if(root == NULL) return 0;

    return 1 + root->countleft + root->countright;
}
//FUNCTION TO INSERT AN ELEMENT IN AVL TREE
struct node* insert(struct node* root, int value)
{
   
    if (root == NULL) 
    {  
        return createNode(value);
        
    } 
    
    if (value < root->value)
    {       
        root->lc  = insert(root->lc, value);
       
    }
    else if (value > root->value)
    {
        root->rc = insert(root->rc, value);
    }
    else 
        return root;
    root->height =1+max(height(root->lc),height(root->rc));
    root->countleft = tree_size(root->lc);
    root->countright = tree_size(root->rc);
    int BF = getBF(root);
    
    //Balancing conditions
    //L-L CASE
    if((BF>1) && (value<(root->lc->value)))
        return(RR(root));
    //R-R CASE
    if((BF<-1) && value>(root->rc->value))
        return(LR(root));
    //L-R CASE
    if((BF>1) && (value>(root->lc->value)))
    {
        root->lc=LR(root->lc);
        return(RR(root));
    }
    //R-L CASE
     if((BF<-1) && (value<(root->rc->value)))
    {
        root->rc=RR(root->rc);
        return(LR(root));
    }
    
    return root;
    
}
//PERFORMS THE INORDER TRAVERSAL OF TREE USED FOR DEBUGGING
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lc);
        printf("%d \n", root->value);
        inorder(root->rc);
    }
}
//PERFORMS THE PREORDER TRAVERSAL OF TREE USED FOR DEBUGGING
void preorder(struct node *root)
{
    if (root != NULL)
    {
        
        printf("%d \n", root->value);
        preorder(root->lc);
        preorder(root->rc);
    }
}
//CHECKS WHETHER A PARTICULAR VALUE EXISTS IN THE AVL TREE
int exists(struct node *root,int x)
{
    if(root != NULL)
    {
        if (x > root->value)
        {
            return exists(root->rc, x);
        }
        else if (x < root->value)
        {
            return exists(root->lc, x);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
//RETURNS THE Xth SMALLEST NUMBER
int xsmallestnum(struct node *root,int x)
{
    if(root->countleft + 1 == x)
        return (root->value);
    if(root->countleft > x - 1)
       return xsmallestnum(root->lc, x);
    return xsmallestnum(root->rc, x - (1 + root->countleft));
}

//FINDS THE INORDER PREDECESSOR OF THE ELEMENT PASSED
int findpredecessor(struct node * root)
{
     	root = root->lc;
     	while(root && root->rc != NULL)
	{
	    root = root->rc;
	}
    
    return root->value;
}
//USED TO DELETE AN ELEMENT FROM THE AVL TREE
struct node * remove(struct node *root,int value)
{
    //Return when leaf node
    if (root == NULL) 
    {  
        return NULL;
    } 
   
    if (value < root->value)
    {       
        root->lc  = remove(root->lc, value);
    }
    else if (value > root->value)
    {
        root->rc = remove(root->rc, value);
    }
    else
    {
        if((root->rc==NULL)&&(root->lc==NULL))
        { 
            free(root);
            return NULL;
        }
        
        if((root->rc!=NULL) && (root->lc!=NULL))
        {
           int x=findpredecessor(root);
	   root->value=x;
	   root->lc=remove(root->lc,x);
        }
        else
        {
            struct node * temp= (root->rc!=NULL) ? root->rc : root->lc;
            *root=*temp;
            free(temp);
        }
    }
    
    root->height =1+max(height(root->lc),height(root->rc));
    root->countleft = tree_size(root->lc);
    root->countright = tree_size(root->rc);
    int BF = getBF(root);

    //Balancing conditions AFTER DELETION
    
    //L-L CASE
    if( (BF>1) && getBF(root->lc) >= 0)
        return(RR(root));
    //R-R CASE
    if(( BF<-1) && getBF(root->rc) <= 0)
        return(LR(root));
    //L-R CASE
    if(( BF>1) && getBF(root->lc) < 0)
    {
        root->lc=LR(root->lc);
        return(RR(root));
    }
    //R-L CASE
    if(( BF<-1) && getBF(root->rc) > 0)
    {
        root->rc=RR(root->rc);
        return(LR(root));
    }
    return root;
}






//DRIVER PROGRAM
int main()
{
    int m, n;
    cin>>n;
    cin>>m;
    int arr[n];
    int query,x;
    struct node* root=NULL;
 
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        root=insert(root,arr[i]);
    }
    
    while(m--)
    {
        cin>>query;
        cin>>x;
        //To take and handle queries as desired
        switch(query)
        {
            case 1:
                root=insert(root,x);
                break;
            case 2:
                int isthere;
                isthere = exists(root,x);
                cout << isthere << endl;
                break;
            case 3:
                int elem = xsmallestnum(root,x);
                cout << elem << endl;
                root=remove(root, elem);
                break;
        }
    }
    
    return 0;

}


