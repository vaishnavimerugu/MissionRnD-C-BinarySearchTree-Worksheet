/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int power(int base,int exp)
{
	int res = 1;
	for (int i = 0; i < exp; i++)
	{
		res *= base;
	}
	return res;
}
int get_height1(struct node *root){
	if (root == NULL)
		return 0;
	int height1 = get_height1(root->right);
	int height2 = get_height1(root->left);
	return height1 > height2 ? height1 + 1 : height2 + 1;
}
void bstRows(struct node *root, int *arr, int ht,int *index)
{
	if (root == NULL)
		return;
	if (ht == 1)
	{
		arr[*index] = root->data;
		*index += 1;
	}
	bstRows(root->right, arr, ht - 1, index);
	bstRows(root->left, arr, ht - 1, index);
}

int * BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int ht = get_height1(root),index=0;
	int *arr = (int *)malloc(power(2, ht + 1)*sizeof(int));
	for (int i = 0; i <= ht; i++)
		bstRows(root, arr, i,&index);
	return arr;
}
