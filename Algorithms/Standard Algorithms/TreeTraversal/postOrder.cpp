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

    void postOrder(BST* root){
        if (!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    };
};

int main(){
    BST b, *root = NULL;

    root = b.InsertNode(root,50);
    b.postOrder(root);
    cout << endl;

    b.InsertNode(root,100);
    b.postOrder(root);
    cout << endl;

    b.InsertNode(root,10);
    b.postOrder(root);
    cout << endl;

    b.InsertNode(root,20);
    b.postOrder(root);
    cout << endl;

    b.InsertNode(root,40);
    b.postOrder(root);
    cout << endl;

    b.DeleteNode(root,10);
    b.postOrder(root);
    cout << endl;

    return 0;
}