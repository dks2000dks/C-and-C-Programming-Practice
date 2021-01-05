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

class BST{
    int data;
    BST *left,*right;

public:

    BST(){
        data = 0;
        left = NULL;
        right = NULL;
    };

    BST(int value){
        data = value;
        left = NULL;
        right = NULL;
    };

    BST* InsertNode(BST* root, int value){
        if (!root)
            return new BST(value);

        if (value > root->data){
            root->right = InsertNode(root->right,value);
        }

        else{
            root->left = InsertNode(root->left,value);
        }

        return root;
    };

    BST* minValueNode(BST* node){
        BST* current = node;

        while(current && current->left != NULL)
            current = current->left;

        return current;
    }

    BST* DeleteNode(BST* root, int value){
        if (root == NULL) return root;

        if (value < root->data)
            root->left = DeleteNode(root->left, value);
        else if (value > root->data)
            root->right = DeleteNode(root->right, value);

        else{
            if (root->left == NULL){
                BST* temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL){
                BST* temp = root->left;
                free(root);
                return temp;
            }

            BST* temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }

        return root;
    }

    void inOrder(BST* root){
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    };

    vector<int> levelOrder(BST* root){
    if (root == NULL)  return {}; 
  
    queue<BST*> q; 
    vector<int> o;
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        BST *node = q.front(); 
        o.push_back(node->data); 
        q.pop(); 
  
        if (node->left != NULL) 
            q.push(node->left); 
  
        if (node->right != NULL) 
            q.push(node->right); 
    } 
    return o;
    };  
};

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
    BST b, *root = NULL;

    root = b.InsertNode(root,50);
    b.InsertNode(root,100);
    b.InsertNode(root,10);
    b.InsertNode(root,20);
    b.InsertNode(root,40);

    vector<int> v = b.levelOrder(root);
    Print_Vector(v,v.size());
    return 0;
}