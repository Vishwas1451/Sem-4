// Name:VISHWAS M
// SRN: PES2UG20CS390
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
*/

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root = NULL ;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
static node_t* createnode(int key){
    node_t *t=(node_t*)malloc(sizeof(node_t));
    t->key=key;
    t->left=NULL;
    t->right=NULL;
    return t;
}
static node_t* ins(node_t *root,int key,int *count_ptr){
     node_t *t= NULL;
    // *count_ptr +=1;
    if(++*count_ptr && root == NULL){
        t = createnode(key);
        return t;
    }
    if(++*count_ptr && key < root->key){
        root->left = ins(root->left,key,count_ptr);
    }
     else if(++*count_ptr && key > root->key){
        root->right = ins(root->right,key,count_ptr);
    }
    return root;

}
void insert(bst_t *tree, int key, int *count_ptr)
{
    tree->root = ins(tree->root,key,count_ptr);

}
static int Height(node_t *p){
    int x,y;
    if(p==NULL)
       return 0;
    x=Height(p->left);
    y=Height(p->right);
    return x>y?x+1:y+1;
}

static node_t* InSucc(node_t *p){
    while(p && p->left!=NULL)
        p=p->left;
    return p;    
}

// Delete key from the BST
// Replaces node with in-order successor
static node_t* PreNode(node_t *p)
{
	if (p == NULL)
		return NULL;
	else if (p->left != NULL)
		return PreNode(p->left);
	return p;
}
static node_t* del(node_t *root, int key, int *count_ptr)
{
	if (root == NULL)
	{
		return root;
		++*(count_ptr);
	}
	if (++*(count_ptr) && key < root->key)
	   root->left = del(root->left, key, count_ptr);
	else if (++*(count_ptr) && key > root->key)
		root->right = del(root->right, key, count_ptr);
	else
	{
		if (++*(count_ptr) && root->left == NULL)
		{
			node_t *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{++*(count_ptr);
			node_t *temp = root->left;
			free(root);
			return temp;
		}
		node_t *temp = PreNode(root->right);
		++*(count_ptr);
		root->key = temp->key;
		root->right = del(root->right, temp->key, count_ptr);
	}
	return root;

}
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root = del(tree->root,key,count_ptr);
}

// Searches for the element key in the bst
// Returns the element if found, else -1
static int ser(node_t *root, int key, int *count_ptr)
{
    if (++(*count_ptr ) && root == NULL)
	   return -1;
	else if (++*(count_ptr) && key > root->key)
	   return ser(root->right, key, count_ptr);
	else if(++*(count_ptr) && key < root->key)
		return ser(root->left, key, count_ptr);
	else
		return key;
}

int search(const bst_t *tree, int key, int *count_ptr)
{  
   return ser(tree->root,key,count_ptr);
}

// Returns the maximum element in the BST
static int max(node_t *root, int *count_ptr)
{
    if(root==NULL)
    	return -1;
	if(root->right==NULL)
    {
        (*count_ptr)++;
        return root->key;
    }
    else
    {
        (*count_ptr)++;
        return max(root->right, count_ptr);
    }
}
    
        
int find_max(const bst_t *tree, int *count_ptr)
{
  return max(tree->root, count_ptr);  
}
// Deletes all the elements of the bst
static void free_node(node_t* root){
     if(root == NULL)
       return;
    free_node(root->left);
    free_node(root->right);
    free(root);
   
}
void free_bst(bst_t *bst) 
{
    free_node(bst->root);
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    free_node(bst->root);
	bst->root = 0;
}
