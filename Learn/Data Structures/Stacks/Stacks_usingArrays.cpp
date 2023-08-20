// Source: https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

#define MAX 1000

class Stack{
	int topElement;
public:
	int Data[MAX];
	Stack() {topElement=-1;}

	bool push(int x){
		if (topElement >= MAX-1){
			cout << "Stack Overflow" << endl;
			return false;
		}
		else{
			Data[++topElement] = x;
			cout << x << " is pushed into stack" << endl;
			return true;
		}
	}

	int pop(){
		if (topElement < 0){
			cout << "Stack Underflow" << endl;
		}
		else{
			int x = Data[topElement--];
			return x;
		}
	}

	int peek(){
		if (topElement < 0){
			cout << "Stack Underflow" << endl;
		}
		else{
			int x = Data[topElement];
			return x;
		}
	}

	bool isEmpty(){
		return (topElement<0);
	}
};

int main(){
	class Stack s;
	fr(i,0,5){
		s.push(10*i);
	}

	s.pop();
	cout << s.peek() << endl;
	cout << s.isEmpty() << endl;
}