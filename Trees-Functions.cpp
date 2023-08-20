#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>
#include <math.h>
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

// Node
class Node{
public:
    int data;
    Node* left;
    Node* right;
};

// inOrder Traversal
vector<int> inOrder(Node *root){
    if (!root)
        return {};
        
    vector<int> left = inOrder(root->left);
    left.push_back(root->data);
    vector<int> right = inOrder(root->right);
    
    left.insert(left.end(), right.begin(), right.end());
    
    return left;
}

int CountNodes(Node *root){
    if (!root)
        return 0;
        
    int count = CountNodes(root->left);
    count++;
    count += CountNodes(root->right);

    return count;
}

void Mirror(Node* node) {
     
     if (node == NULL)
        return;
        
     Mirror(node->right);
     Mirror(node->left);
     
     Node* leftpart = node->left;
     
     node->left = node->right;
     node->right = leftpart;
     
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

// Check if Tree is a Binary Search Tree
int isBSTUntil(Node* node, int min, int max){
    if (node==NULL)
        return 1;

    if (node->data < min || node->data > max)
        return 0;
        
    return (isBSTUntil(node->left, min, node->data -1) && isBSTUntil(node->right, node->data +1, max));
}

// Level Order Traversal with Queues
vector<int> levelOrder(Node* root){
    if (root == NULL)  return {}; 
  
    queue<Node *> q; 
    vector<int> o;
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        Node *node = q.front(); 
        o.push_back(node->data); 
        q.pop(); 
  
        if (node->left != NULL) 
            q.push(node->left); 
  
        if (node->right != NULL) 
            q.push(node->right); 
    } 
    
    return o;
}  

// Level Order Traversal without Queues
int height(Node *node){
    if (node == NULL)
        return 0;
    else{
        return 1+max(height(node->left), height(node->right));
    }
}

void traverseLevel(Node* node, int level){
    if (node == NULL)
        return;
    
    if (level == 1){
        cout << node->data << " ";
    }
    else if (level > 1){
        traverseLevel(node->left, level-1);
        traverseLevel(node->right, level-1);
    }
}

void levelOrder(Node* root)
{
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
    { 
        traverseLevel(root, i); 
        cout << "$" << " "; 
    }
}
