// Source: https://www.geeksforgeeks.org/introduction-to-binary-tree-data-structure-and-algorithm-tutorials/

#include <bits/stdc++.h>
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

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    return 0;
}
