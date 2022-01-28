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

int lengthList(Node* head){
	int count=0;
	Node* current = head;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

void push(Node** head_ref, double new_data){
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void push_after(Node* prev_node, double new_data){
	if (prev_node == NULL)
		cout << " The Given Previous Node cannot be NULL";

	Node *new_node = new Node();
	
	new_node->data = new_data;

	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node** head_ref, double new_data){
	Node* new_node = new Node();

	new_node->data =  new_data;
	new_node->next = NULL;

	Node* last = *head_ref;

	if (*head_ref == NULL){
		*head_ref = new_node;
		return;
	}

	while(last->next != NULL)
		last = last->next;

	last->next = new_node;
}

double deleteNode(Node** head_ref,int index){
	if (head_ref==NULL)
		return DBL_MIN;

	Node* temp = new Node();
	temp = *head_ref;

	double value;

	if (index==0){
		value = temp->data;
		*head_ref = temp->next;
		free(temp);
		return value;
	}

	for (int i=0; temp!=NULL && i<index-1; i++){
		temp = temp->next;
	}

	Node* new_node = new Node();
	new_node = temp->next->next;

	value = temp->next->data;

	free(temp->next);

	temp->next = new_node;

	return value;
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

	//Pushing after the element
	push_after((head->next)->next,1.5);
	printList(head);

	// Append element
	append(&head,0);
	printList(head);

	double element = deleteNode(&head,5);
	cout << element << endl;
	printList(head);

	cout << "Length of Singly Linked List: " << lengthList(head) << endl;

	return 0;
}

