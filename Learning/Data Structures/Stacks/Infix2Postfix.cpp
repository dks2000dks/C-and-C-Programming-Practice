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
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

void Infix2Postfix(string &s){
    stack<char> st;
    st.push('N');
    string ns;

    fr(i,0,s.length()-1){
        if (!isOperation(s[i]))
            ns+=s[i];
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

    s = ns;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        Infix2Postfix(s);
        cout << s << endl;
    }
}