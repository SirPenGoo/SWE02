#include <stdio.h>
#include <stdlib.h>
//#include "yourheader.h" // Bitte anpassen!!!

int main(int argc, char* argv[])
{
	struct node* root = makenode(100);
	if (root)
	{
		struct node* child = makenode(10);
		if (child)
		{
			root->edge = child;
			printf("%d\n", root->edge->val);
		}
		printf("%d\n", root->val);
	}
	return 0;
}