#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

bool isOperation(char c){
    if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%')
        return true;
    return false;
}

int Eval(int a, int b, char o){
    if (o=='+')
        return a+b;
    else if (o=='-')
        return a-b;
    else if (o=='*')
        return a*b;
    else if (o=='/')
        return a/b;
    else if (o=='%')
        return a%b;
    else
        return pow(a,b);
}

int EvalPostfix(vector<char> s){
    stack<int> st;
    string e;

    fr(i,0,s.size()-1){
        if (!isOperation(s[i])){
            e = s[i];
            st.push(stoi(e));
        }
        else{
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            int o = Eval(a,b,s[i]);
            cout << o << endl;
            st.push(o);
        }
    }
    return st.top();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char> s(n,'0');
        fr(i,0,n-1) cin >> s[i];
       
        cout << EvalPostfix(s) << endl;
    }
}