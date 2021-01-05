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

struct Bracket{
    char bracket;
    int position;
};

bool Match(char type, char c) {
    if (type == '[' && c == ']')
        return true;
    if (type == '{' && c == '}')
        return true;
    if (type == '(' && c == ')')
        return true;
    return false;
}

int main() {
    std::string text;
    getline(std::cin, text);
    int answer=-1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket s;
            s.bracket = next;
            s.position = position+1;
            opening_brackets_stack.push(s);
        }

        if (next == ')' || next == ']' || next == '}') {            
            if (!opening_brackets_stack.empty()){
                Bracket s = opening_brackets_stack.top();
                if (Match(s.bracket,next)){
                    opening_brackets_stack.pop();
                }
                else{
                    answer = position+1;
                    break;
                }
            }

            else{
                answer = position+1;
                break;
            }
        }
    }

    if (opening_brackets_stack.empty() && answer==-1)
        cout << "Success" << endl;
    else{
        if (!opening_brackets_stack.empty() && answer==-1)
            answer = opening_brackets_stack.top().position;
        cout << answer << endl;
    }

    return 0;
}
