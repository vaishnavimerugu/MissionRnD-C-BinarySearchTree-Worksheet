/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node(struct node *root, int data){
	if (root == NULL) 
		return newNode(data);
	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);
	return root;
}
int main()
{
	struct node *root = NULL;
	int arr[3] = {10,5,15};
	for (int i = 0; i < 3; i++)
		root = add_node(root,arr[i]);
	printf(" height is %d\n left-sum is %d\n right-sum is %d\n", get_height(root),get_left_subtree_sum(root),get_right_subtree_sum(root));
	getchar();
}
