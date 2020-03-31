#ifndef BINTREE_H
#define BINTREE_H

typedef struct bnode {
	struct bnode* left;
	struct bnode* right;
	int val;
}BNODE;

extern BNODE* createTree(int val); // creates tree
extern BNODE* insertNode(BNODE* tree, int val); // inserts node in existing tree
extern BNODE* searchNode(BNODE* tree, int val); // searches node
extern void inorderPrint(BNODE* tree); //prints vals of tree inorder
extern void preorderPrint(BNODE* tree);
extern void postorderPrint(BNODE* tree);
extern BNODE* findMinNode(BNODE* tree);
extern BNODE* deleteNode(BNODE* tree, int val); // deletes single node in tree
extern int sumOfNodes(BNODE* tree); // calculates and returns sum of vals of nodes in tree


#endif // !BINTREE_H
