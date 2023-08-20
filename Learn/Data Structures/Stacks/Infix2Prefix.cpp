// Source: https://www.geeksforgeeks.org/convert-infix-prefix-notation/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

bool isOperation(char c){
	if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%' || c=='(' || c==')')
		return true;
	return false;
}

int prec(char c) { 
	if(c == '+' || c == '-') 
		return 1;
	else if(c == '*' || c == '/') 
		return 2; 
	else if(c == '^') 
		return 3;
	else
		return -1; 
} 

void Infix2Prefix(string &s){

	reverse(s.begin(), s.end());
	fr(i,0,s.length()-1){
		if (s[i] == '(')
			s[i] = ')';
		else if (s[i] == ')')
			s[i] = '(';
		else
			continue;
	}

	stack<char> st;
	st.push('N');
	string ns;

	fr(i,0,s.length()-1){
		if (!isOperation(s[i]))
			ns += s[i];
		else if (s[i] == '(')
			st.push('(');
		else if (s[i] == ')'){
			while(st.top() != 'N' && st.top() != '('){
				char c = st.top();
				st.pop();
				ns += c;
			}
			if (st.top() == '('){
				char c = st.top();
				st.pop();
			}
		}
		else{
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){
				char c = st.top();
				st.pop();
				ns += c;
			}
			st.push(s[i]);
		}
	}

	while (st.size() > 1){
		ns += st.top();
		st.pop();
	}
	
	s = ns;

	reverse(s.begin(),s.end());
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		Infix2Prefix(s);
		cout << s << endl;
	}
}