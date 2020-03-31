/*==========================================================
|	Assignment:		SWE02_HUE02KR
|	File:			bintree.c
|	Author:			Maximilian Erlmoser
|	University:		FH Salzburg
|	Semester:		ITS-B SS20
|	Date:			31.03.2020
|-----------------------------------------
|	Description:	Implements functions to build a binary
					tree and to print the tree.
*=========================================================*/

#include "stdio.h"
#include "stdlib.h"
#include "bintree.h"

BNODE* createTree(int val) {
	BNODE* tmp = (BNODE*)malloc(sizeof(BNODE));
	tmp->val = val;
	tmp->left = tmp->right = NULL;
	return tmp;
}

BNODE* insertNode(BNODE* tree, int val) {

	if ((tree) == NULL)
		return createTree(val);
	else if ((tree)->val >= val)
		(tree)->left = insertNode((tree)->left, val);
	else if ((tree)->val < val)
		(tree)->right = insertNode((tree)->right, val);

	return (tree);
}

BNODE* searchNode(BNODE* tree, int val) {
	if (tree == NULL || tree->val == val)
		return tree;

	if (tree->val < val)
		return searchNode(tree->right, val);

	return searchNode(tree->left, val);
}

void inorderPrint(BNODE* tree) {
	if (tree) {
		inorderPrint(tree->left);
		printf("%d ", tree->val);
		inorderPrint(tree->right);
	}
}

void preorderPrint(BNODE* tree) {
	if (tree) {
		printf("%d ", tree->val);
		preorderPrint(tree->left);
		preorderPrint(tree->right);
	}
}

void postorderPrint(BNODE* tree) {
	if (tree) {
		postorderPrint(tree->left);
		postorderPrint(tree->right);
		printf("%d ", tree->val);
	}
}

BNODE* findMinNode(BNODE* tree) {
	if (tree->left == NULL)
		return tree;

	return findMinNode(tree->left);
}

BNODE* deleteNode(BNODE* tree, int val) {
	if (tree == NULL)
		return tree;

	if (val < tree->val)
		tree->left = deleteNode(tree->left, val);
	else if (val > tree->val)
		tree->right = deleteNode(tree->right, val);
	else {
		if (tree->left == NULL) {
			BNODE* temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->right == NULL) {
			struct BNODE* temp = tree->left;
			free(tree);
			return temp;
		}
		
		BNODE* temp = findMinNode(tree->right);

		tree->val = temp->val;

		tree->right = deleteNode(tree->right, temp->val);
	}
	return tree;
}

int sumOfNodes(BNODE* tree) {
	int suml, sumr, sum;
	suml = sumr = sum = 0;
	
	if (tree == NULL)
		return 0;
	else {
		if (tree->left != NULL)
			suml = sumOfNodes(tree->left);

		if (tree->right != NULL)
			sumr = sumOfNodes(tree->right);

		sum = tree->val + suml + sumr;
		return sum;
	}
}