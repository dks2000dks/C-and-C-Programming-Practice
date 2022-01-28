#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<string> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Input_Matrix(vector<vector<char>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int isvalid(int x, int y, int r, int c){
    return (x>=0 && x<r && y>=0 && y<c);
}

int Find(string s,vector<vector<char>> Chars, int r, int c){
    vector<pair<int,int>> points;
    fr(i,0,r-1){
        fr(j,0,c-1){
            if (Chars[i][j] == s[0]){
                points.push_back(make_pair(i,j));
            }
        }
    }

    if (points.size() == 0)
        return 0;

    else{

        fr(p,0,points.size()){
            
            pair<int,int> rep = points[p];
            int x = rep.first;
            int y = rep.second;
            
            string output = "";
            output += s[0];
            Chars[x][y] = '#';

            fr(i,1,s.length()-1){
            
                fr(l,-1,1){
                    fr(m,-1,1){
                        int p = x+l;
                        int q = y+m;

                        int b = l||m;

                        if (isvalid(p,q,r,c) && b != 0){
                            if (s[i] == Chars[p][q]){
                                x = p;
                                y = q;
                                //cout << x << " " << y << endl;
                                output += s[i];
                                Chars[p][q] = '#';
                                l = 2;
                                m = 2;
                                break;
                            }
                        }
                    }
                }
            }

            if (output == s)
                return 1;
        }
    }
    return 0;
}

void Print_Vector(vector<string> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(words,string,n,"");
        Input_Vector(words,n);
        vector<string>output;

        int r,c;
        cin >> r >> c;
        vec2d(Chars,char,r,c,'0');
        Input_Matrix(Chars,r,c);

        fr(i,0,n-1){
            if (Find(words[i],Chars,r,c))
                output.push_back(words[i]);
        }

        if (output.size())
            Print_Vector(output,output.size());
        else
            cout << -1 << endl;
    }
}