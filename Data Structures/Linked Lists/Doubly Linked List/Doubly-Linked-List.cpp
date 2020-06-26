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

int lengthList(Node* head){
	int count=0;
	Node* current = head;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

 
void push_after(Node* prev_node, double new_data){
	if (prev_node == NULL)
		cout << " The Given Previous Node cannot be NULL";

	Node *new_node = new Node();
	
	new_node->data = new_data;

	new_node->next = prev_node->next;
	prev_node->next = new_node;

	new_node->prev = prev_node;
	(new_node->next)->prev = new_node;
}

void append(Node** head_ref, double new_data){
	Node* new_node = new Node();

	new_node->data =  new_data;
	new_node->next = NULL;

	Node* last = *head_ref;

	if (*head_ref == NULL){
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	while(last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;
	return;
}

double deleteNodeIndex(Node** head_ref,int index){
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

	for (int i=0; temp->next!=NULL && temp!=NULL && i<index-1; i++){
		temp = temp->next;
	}

	if (temp->next == NULL){
		cout << "Invalid Index" << endl;
		return DBL_MIN;
	}

	else{

		Node* new_node = new Node();
		if ((temp->next)->next !=NULL){
			new_node = temp->next->next;
			
			value = temp->next->data;
			new_node->prev = (temp->prev)->next;
			cout << value << endl;

			free(temp->next);
			temp->next = new_node;

			return value;
		}

		else
		{
			value = temp->next->data;
			temp->next = NULL;
			return value;
		}
	}
}

int main(){
	Node* head = NULL;

	push(&head, 1);
	push(&head, 3);
	push(&head, 4);
	//printList(head);

	push_after((head->next),2);
	//printList(head);

	append(&head,0);
	printList(head);

	int value = deleteNodeIndex(&head,4);
	printList(head);
}