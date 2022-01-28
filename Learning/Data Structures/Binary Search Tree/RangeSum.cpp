#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h>
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))

class BST
{
    int data;
    BST *left, *right;

public:
    BST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    };

    BST(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    };

    BST *InsertNode(BST *root, int value)
    {
        if (root == NULL)
            return new BST(value);

        if (value > root->data)
        {
            root->right = InsertNode(root->right, value);
        }

        else if (value < root->data)
        {
            root->left = InsertNode(root->left, value);
        }

        return root;
    };

    BST *minValueNode(BST *node)
    {
        BST *current = node;

        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    BST *DeleteNode(BST *root, int value){
        if (value < root->data)
            root->left = DeleteNode(root->left, value);
        else if (value > root->data)
            root->right = DeleteNode(root->right, value);

        else{
            if (root->left == NULL){
                BST *temp = root->right;
                free(root);
                return temp;
            }

            else if (root->right == NULL){
                BST *temp = root->left;
                free(root);
                return temp;
            }

            BST *temp = minValueNode(root->right);

            root->data = temp->data;
            root->right = DeleteNode(root->right, temp->data);
        }

        return root;
    }

    int find(BST *node, int value)
    {
        if (node->data == value)
            return 1;
        else if (node->data > value && node->left != NULL)
            return find(node->left, value);
        else if (node->data < value && node->right != NULL)
            return find(node->right, value);
        else
            return 0;
    }

    ll rangeSum(BST *node, int x, int y)
    {
        ll sum = 0;
        if (node == NULL)
            return 0;
        if (x <= node->data && node->data <= y)
            sum += node->data;
        if (x < node->data)
            sum += rangeSum(node->left, x, y);
        if (node->data < y)
            sum += rangeSum(node->right, x, y);

        return sum;
    }

    void inOrder(BST *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    };
};

int main()
{
    BST b, *root = NULL;

    int q;
    cin >> q;
    int M = 1000000001;
    ll prevSum = 0;

    fr(i, 0, q - 1)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int x;
            cin >> x;
            x = (x + prevSum) % M;
            root = b.InsertNode(root, x);
        }

        else if (c == '?')
        {
            int x;
            cin >> x;
            x = (x + prevSum) % M;
            if (root != NULL)
            {
                if (b.find(root, x))
                    cout << "Found" << endl;
                else
                    cout << "Not Found" << endl;
            }
            else
                cout << "Not Found" << endl;
        }

        else if (c == 's')
        {
            int x, y;
            cin >> x >> y;
            x = (x + prevSum) % M;
            y = (y + prevSum) % M;
            prevSum = b.rangeSum(root, x, y);
            cout << b.rangeSum(root, x, y) << endl;
        }

        else
        {
            int x;
            cin >> x;
            x = (x + prevSum) % M;

            if (root != NULL){
                if (b.find(root,x)){
                    root = b.DeleteNode(root, x);
                }
            }
        }
    }

    return 0;
}