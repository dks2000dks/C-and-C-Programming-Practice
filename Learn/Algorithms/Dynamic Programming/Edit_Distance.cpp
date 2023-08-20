// https://www.geeksforgeeks.org/edit-distance-dp-5/?ref=lbp

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

int Edit_Distance_resursion(const string &str1, const string &str2, int m, int n){
	if (m==0)
		return n;
	if (n==0)
		return m;

	if (str1[m-1] == str2[n-1])
		return Edit_Distance(str1, str2, m-1 ,n-1);

	// Insert : So, recursion is performed on 'm' elements of str1 and 'n-1' elements of str2
	int a = Edit_Distance(str1, str2, m ,n-1);

	// Remove : So, recursion is performed on 'm-1' elements of str1 and 'n' elements of str2
	int b = Edit_Distance(str1, str2, m-1 ,n);

	// Replace : So, recursion is performed on 'm-1' elements of str1 and 'n-1' elements of str2
	int c = Edit_Distance(str1, str2, m-1 ,n-1);

	return 1+min(min(a,b),c);
}

int Edit_Distance(const string &str1, const string &str2, int m, int n){
	int table[m+1][n+1];

	fr(i,0,m){
		fr(j,0,n){
			if (i==0)
				table[i][j] = j;
			else if (j==0)
				table[i][j] = i;
			else if (str1[i-1] == str2[j-1])
				table[i][j] = table[i-1][j-1];
			else
				table[i][j] = 1 + min(min(table[i-1][j],table[i][j-1]),table[i-1][j-1]);
		}
	}

	return table[m][n];
}

int main(){
	string str1;
	string str2;
	cin >> str1 >> str2;

	int m = str1.length();
	int n = str2.length();

	cout << "Recursion:" << endl;
	cout << Edit_Distance_resursion(str1, str2, m ,n) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << Edit_Distance(str1, str2, m ,n) << endl;
}