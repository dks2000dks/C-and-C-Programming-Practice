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

class Queue{
public:
	int front, rear, size;
	unsigned capacity;
	int* array;
};

Queue* createQueue(unsigned capacity){
	Queue* queue = new Queue();
	queue->capacity = capacity;

	queue->front = queue->size = 0;
	queue->rear = capacity-1;

	queue->array = new int[(queue->capacity * sizeof(int))];

	return queue;
}

int isFull(Queue* queue){
	return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue){
	return (queue->size == 0);
}

void EnQueue(Queue* queue, int element){
	if (isFull(queue)){
		cout << "Queue is Full" << endl;
		return;
	}

	queue->rear = (queue->rear + 1)%(queue->capacity);
	queue->array[queue->rear] = element;
	queue->size += 1;

	return;
}

int DeQueue(Queue* queue){
	if (isEmpty(queue)){
		cout << "Queue is Empty" << endl;
		return INT_MIN;
	}

	int element = queue->array[queue->front];
	queue->front = (queue->front + 1)%(queue->capacity);
	queue->size -= 1;
	return element;
}

int frontElement(Queue* queue){
	if (isEmpty(queue)){
		cout << "Queue is Empty" << endl;
		return INT_MIN;
	}
	return queue->array[queue->front];
}

int rearElement(Queue* queue){
	if (isEmpty(queue)){
		cout << "Queue is Empty" << endl;
		return INT_MIN;
	}
	return queue->array[queue->rear];
}

int main(){
	
	Queue* queue = createQueue(5);

	EnQueue(queue,10);
	EnQueue(queue,20);
	EnQueue(queue,30);
	EnQueue(queue,40);
	EnQueue(queue,50);

	EnQueue(queue,60);
	DeQueue(queue);

	cout << frontElement(queue) << endl;
	cout << rearElement(queue) << endl;
}

