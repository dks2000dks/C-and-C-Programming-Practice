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
	Node* prev;
	Node* next;
};

void printList(Node* n){
	Node* last = NULL;
	cout << "Forward Traversal" << endl;
	while (n != NULL){
		cout << n->data << " ";
		last = n;
		n = n->next;
	}
	cout << endl;

	
	cout << "Backward Traversal" << endl;
	while (last != NULL){
		cout << last->data << " ";
		last = last->prev;
	}
	cout << endl;
}

void push(Node** head_ref, double new_data){
	Node *new_node = (Node*)malloc(sizeof(Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref)!= NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void reverse(Node** head_ref){
	Node* current = (*head_ref);
	Node* temp = NULL;

	while (current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current=current->prev;
	}

	if (temp!=NULL)
		*head_ref = temp->prev;
}

int main(){
	Node* head = NULL;

	push(&head, 1);
	push(&head, 3);
	push(&head, 4);
	printList(head);

	reverse(&head);
	printList(head);

}