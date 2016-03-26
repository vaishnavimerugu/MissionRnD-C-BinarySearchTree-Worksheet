/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void getInorder(struct node *root, int *arr, int *index)
{
	if (root == NULL)
		return;
	getInorder(root->left, arr, index);
	arr[*index] = root->data;
	printf("%d\t %d\t %d\n", root->data, arr[*index], *index);
	*index += 1;
	getInorder(root->right, arr, index);
}
void getPreorder(struct node *root, int *arr, int *index)
{
	if (root == NULL)
		return;
	arr[*index] = root->data;
	printf("%d\t %d\t %d\n", root->data, arr[*index], *index);
	*index += 1;
	getPreorder(root->left, arr, index);
	getPreorder(root->right, arr, index);
}
void getPostorder(struct node *root, int *arr, int *index)
{
	if (root == NULL)
		return;
	getPostorder(root->left, arr, index);
	getPostorder(root->right, arr, index);
	arr[*index] = root->data;
	printf("%d\t %d\t %d\n", root->data, arr[*index], *index);
	*index += 1;

}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int index = 0;
	getInorder(root, arr, &index);
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int index = 0;
	getPreorder(root, arr, &index);
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL)
		return;
	int index = 0;
	getPostorder(root, arr, &index);
}


