#include <bits/stdc++.h>
using namespace std;

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} node;
node *root = NULL;
/*    Start of Non_Recursive    */
node *NewNode(int key) {
  node *ptr = new node;
  ptr->val = key;
  ptr->left = ptr->right = NULL;
  return ptr;
}
bool search_non_recursive(node *root, int key) {
  while (root != NULL) {
    if (key > root->val)
      root = root->right;
    else if (key < root->val)
      root = root->left;
    else
      return 1;
  }
  return 0;
}
node *insert_non_recursive(node *root, int key) {
  node *temp = root;
  node *current = NULL;
  while (temp != NULL) {
    current = temp;
    if (key < temp->val)
      temp = temp->left;
    else
      temp = temp->right;
  }
  if (current == NULL)
    current = NewNode(key);
  else if (key < current->val)
    current->left = NewNode(key);
  else
    current->right = NewNode(key);
  return current;
}
node *min(node *root) {
  node *current = root;
  while (current->left != NULL) {
    current = current->left;
  }
  return current;
}
node *max(node *root) {
  node *current = root;
  while (current->right != NULL) {
    current = current->right;
  }
  return current;
}

void inorder_non_recursive(node *root) {
  stack<node *> s;
  node *curr = root;

  while (curr != NULL || s.empty() == false) {
    while (curr != NULL) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();

    cout << curr->val << " ";
    curr = curr->right;
  }
}

node *inorder_succ(node *root, node *n) {
  if (n->right != NULL)
    return min(n->right);
  node *succ = NULL;
  while (root != NULL) {
    if (root->val < n->val) {
      succ = root;
      root = root->left;
    } else if (n->val > root->val) {
      root = root->right;
    } else
      break;
  }
  return succ;
}
/* End of non-recursive */
void deleteTree(node *node) {
  if (node == NULL)
    return;
  deleteTree(node->left);
  deleteTree(node->right);
  free(node);
}
node *insert(node *node, int key) {
  if (node == NULL)
    return NewNode(key);
  if (key < node->val)
    node->left = insert(node->left, key);
  else if (key > node->val)
    node->right = insert(node->right, key);
  return node;
}
node *search_recursive(node *root, int key) {
  if (root == NULL or root->val == key)
    return root;
  if (key > root->val)
    return search_recursive(root->right, key);
  return search_recursive(root->left, key);
}
/* Tree Traversals*/
void inorder(node *temp) {
  if (temp == NULL)
    return;
  inorder(temp->left);
  cout << temp->val << " ";
  inorder(temp->right);
}
void preorder(node *temp) {
  if (temp == NULL)
    return;
  cout << temp->val << " ";
  preorder(temp->left);
  preorder(temp->right);
}
void postorder(node *temp) {
  if (temp == NULL)
    return;
  postorder(temp->left);
  postorder(temp->right);
  cout << temp->val << " ";
}
node *deleteNode(node *root, int key) {
  if (root == NULL)
    return root;
  if (key < root->val)
    root->left = deleteNode(root->left, key);
  else if (key > root->val)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    node *temp = min(root->right);
    root->val = temp->val;
    root->right = deleteNode(root->right, temp->val);
  }
  return root;
}
/*Function to check whether the given tree is bst*/
bool isBSTfunc(node *node, int min, int max) {
  if (node == NULL)
    return 1;
  if (node->val < min || node->val > max)
    return 0;
  return isBSTfunc(node->left, min, node->val - 1) &&
         isBSTfunc(node->right, node->val + 1, max);
}
int isBST(node *node) { return (isBSTfunc(node, INT_MIN, INT_MAX)); }
int main() {
  root = NewNode(10);
  root->left = NewNode(5);
  root->right = NewNode(20);
  root->left->left = NewNode(2);
  root->left->right = NewNode(6);
  root->right->left = NewNode(12);
  root->right->right = NewNode(50);
  inorder_non_recursive(root);
  insert_non_recursive(root, 100);
  cout << endl;
  inorder_non_recursive(root);
  cout << endl;
  cout << bool(search_non_recursive(root, 5)) << endl;
  cout << max(root)->val << endl;
  cout << min(root)->val << endl;
  cout << (inorder_succ(root, (root->left))->val) << endl;
  deleteTree(root);
  node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  inorder_non_recursive(root);
  cout << endl;
  node *x = search_recursive(root, 40);
  (x == NULL) ? cout << "Not Found" << endl : cout << "Found" << endl;
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
  postorder(root);
  cout << endl;
  root = deleteNode(root, 70);
  inorder(root);
  cout << endl;
  cout << isBST(root) << endl;
  return 0;
}
