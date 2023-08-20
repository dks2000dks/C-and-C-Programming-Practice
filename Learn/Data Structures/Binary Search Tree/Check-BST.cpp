// Source: https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

class BST{
public:

	int data;
	BST *left,*right;

	BST(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};

int isBSTUntil(BST* node, int min, int max){
	if (node==NULL)
		return 1;

	if (node->data < min || node->data > max)
		return 0;

	return (isBSTUntil(node->left, min, node->data -1) && isBSTUntil(node->right, node->data +1, max));

	// If there are duplicates
	// return (isBSTUntil(node->left, min, node->data) && isBSTUntil(node->right, node->data, max));
}

int main(){
	BST *root = new BST(4);  
	root->left = new BST(2);  
	root->right = new BST(5);  
	root->left->left = new BST(1);  
	root->left->right = new BST(3);
	root->left->right->right = new BST(4);

	if (isBSTUntil(root,INT_MIN,INT_MAX))
		cout << "Tree is a BST" << endl;
	else
		cout << "Tree is not a BST" << endl;
}