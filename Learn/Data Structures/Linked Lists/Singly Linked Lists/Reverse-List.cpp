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
	Node* next;
};

void printList(Node* n){
	while (n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

void push(Node** head_ref, double new_data){
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void reverse(Node** head_ref){
	Node* current = (*head_ref);
	Node* prev = NULL;
	Node* next = NULL;

	while (current != NULL){
		next = current->next;
		current->next = prev;

		prev = current;
		current = next;
	}
	*head_ref = prev;
}

int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 3;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 1;
	third->next = NULL;

	printList(head);

	// Pushing Element to Linked List
	push(&head,4);
	printList(head);

	reverse(&head);
	printList(head);

	return 0;
}