#pragma once

struct node
{
	struct node* edge;
	int val;
};

//returns NULL if fails else new node with val and NULL as edge
struct node* makenode(int val) {
	struct node* newNode = malloc(sizeof(struct node));

	if (newNode) {
		newNode->edge = NULL;
		newNode->val = val;
		return newNode;
	}
	else
		return NULL;
}

//returns NULL if fails else root
struct node* connectnodes(struct node* root, struct node* leaf) {
	if (root == NULL || leaf == NULL) {
		return NULL;
	}
	else
	{
		root->edge = leaf;
		return root;
	}
}