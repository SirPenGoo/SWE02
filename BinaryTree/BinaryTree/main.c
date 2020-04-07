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

int main() {

	struct BNODE* root = NULL;
	root = createTree(50);
	insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 70);
	insertNode(root, 60);
	insertNode(root, 80);
	inorderPrint(root);
	printf("\n");
	deleteNode(root, 20);
	deleteNode(root, 30);
	deleteNode(root, 50);
	inorderPrint(root);
	printf("\n");
	preorderPrint(root);
	printf("\n");
	postorderPrint(root);
	printf("\n\n");
	printf("%d", sumOfNodes(root));

	return 0;
}