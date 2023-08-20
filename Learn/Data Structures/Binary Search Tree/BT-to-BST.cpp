// Source: https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};

void BT_Traversal(Node* node, vector<int> &v){
	if (node == NULL)
		return;

	BT_Traversal(node->left,v);
	v.push_back(node->data);
	BT_Traversal(node->right,v);    
}

void CreateBST(Node* node, vector<int> &v){
	if (node==NULL)
		return;
	CreateBST(node->left,v);
	node->data = v.back();
	v.pop_back();
	CreateBST(node->right, v);
}

void inOrder(Node* root){
	if (!root)
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

int isBSTUntil(Node* node, int min, int max){
	if (node==NULL)
		return 1;

	if (node->data < min || node->data > max)
		return 0;
		
	return (isBSTUntil(node->left, min, node->data -1) && isBSTUntil(node->right, node->data +1, max));
}

int main(){
	Node* root = new Node(10);  
	root->left = new Node(20);  
	root->right = new Node(30);  
	root->left->left = new Node(40);  
	root->left->right = new Node(50);

	if (isBSTUntil(root,INT_MIN,INT_MAX))
		cout << "Tree is a BST" << endl;
	else
		cout << "Tree is not a BST" << endl;

	vector<int> v;

	BT_Traversal(root,v);

	Print_Vector(v,v.size());
	sort(v.begin(),v.end(),greater<int>());

	CreateBST(root,v);
	inOrder(root);
	cout << endl;

	if (isBSTUntil(root,INT_MIN,INT_MAX))
		cout << "Tree is a BST" << endl;
	else
		cout << "Tree is not a BST" << endl;
}