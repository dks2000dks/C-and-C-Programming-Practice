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

void NodesBelow(Node *root, int k, vector<int> &o){
    if (root==NULL || k<0)
        return ;
    
    if (k==0){
        o.push_back(root->data);
        return;
    }

    NodesBelow(root->left, k-1, o);
    NodesBelow(root->right,k-1, o);
}

int NodesKdistance(Node* root, Node* target, int k, vector<int> &o){
    if (root==NULL)
        return -1;
    
    if (root == target){
        NodesBelow(root,k,o);
        return 0;
    }

    int dl = NodesKdistance(root->left,target,k,o);

    if (dl != -1){
        if (dl + 1 == k)
            o.push_back(root->data);
        else
            NodesBelow(root->right, k-dl-2,o);
        return 1+dl;
    }

    int dr = NodesKdistance(root->right,target,k,o);

    if (dr != -1){
        if (dr + 1 == k)
            o.push_back(root->data);
        else
            NodesBelow(root->left, k-dr-2,o);
        return 1+dr;
    }

    return -1;
}

int main(){
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14);

    Node* target = root->left; 

    int k = 2;
    vector<int> o;

    NodesKdistance(root,target,k,o);
    fr(i,0,o.size()-1) cout << o[i] << " ";
    cout << endl;
}
