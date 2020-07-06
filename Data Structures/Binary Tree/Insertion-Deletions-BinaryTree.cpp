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

    Node (double x){
        data = x;
        left = right = NULL;
    }
};

void inOrder(Node* node){
    if (!node)
        return ;

    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void InsertNode(Node* node, int value){
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty()){
        Node* temp = Q.front();
        Q.pop();

        if (!temp->left){
            temp->left  = new Node(value);
            break;
        }

        else
            Q.push(temp->left);

        if (!temp->right){
            temp->right  = new Node(value);
            break;
        }

        else
            Q.push(temp->right);
    }
}

void DeleteDeepestNode(Node* node, Node* remove){
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty()){
        Node* temp = Q.front();
        Q.pop();

        if (temp == remove){
            temp = NULL;
            delete (remove);
            return;
        }

        if (temp->right){
            if (temp->right == remove){
                temp->right = NULL;
                delete (remove);
                return;
            }
            else{
                Q.push(temp->right);
            }
        }

        if (temp->left){
            if (temp->left == remove){
                temp->left = NULL;
                delete (remove);
                return;
            }
            else{
                Q.push(temp->left);
            }
        }
    }
}

Node* DeleteNode(Node* node, int value){
    if (node == NULL){
        return NULL;
    }

    if (node->left == NULL && node->right == NULL){
        if (node->data = value)
            return NULL;
        else{
            return node;
        }        
    }

    queue<Node*> Q;

    Node* remove = NULL;
    Node* temp;

    Q.push(node);

    while(!Q.empty()){
        temp = Q.front();
        Q.pop();

        // Finding Node to be Deleted
        if (temp->data == value){
            remove = temp;
        }

        // Finding Deepest Node
        if (temp->left)
            Q.push(temp->left);

        if (temp->right)
            Q.push(temp->right);
    }

    if (remove != NULL){
        double rightmostvalue = temp->data;
        DeleteDeepestNode(node, temp);
        remove->data = rightmostvalue;
    }

    return node;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    inOrder(root);
    cout << endl;

    InsertNode(root,5);
    inOrder(root);
    cout << endl;

    DeleteNode(root,4);    
    inOrder(root);
    cout << endl;

    return 0;
}
