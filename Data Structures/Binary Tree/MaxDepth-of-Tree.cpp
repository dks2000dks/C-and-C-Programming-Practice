#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
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

int MaxDepth(Node* node){
    if (node ==NULL)
        return 0;
    else{
        return 1+max(MaxDepth(node->left),MaxDepth(node->right));
    }
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->left = newNode(5);

    cout << "Max Depth of Binary Tree is " << MaxDepth(root) << endl;

    return 0;
}
