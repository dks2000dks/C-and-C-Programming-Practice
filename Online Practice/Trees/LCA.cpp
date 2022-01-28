#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

class Node{
public:
    double data;
    Node* left;
    Node* right;
};

Node* newNode(double data){
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* LCA(Node* root, int a, int b){
    if (root == NULL || root->data == a || root->data == b)
        return root;
    Node* left = LCA(root->left,a,b);
    Node* right = LCA(root->right,a,b);

    if (right && left)
        return root;
    else if (left == NULL)
        return right;
    else
        return left;
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->left->right = newNode(7);
    root->left->left->left = newNode(8);
    root->right->right->right = newNode(9);

    int a = 9;
    int b = 5;

    Node* o = LCA(root, a, b);

    cout << o->data << endl;
}
