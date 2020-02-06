#include<bits/stdc++.h>
using namespace std;

int main(){
	long long int T;
	cin >> T;
	int r[60];
	r[0] = 0;
	r[1] = 1;
	for(int i=2;i<60;i++)
		r[i] = (r[i-1] + r[i-2])%10;
	while (T--)
	{
		long long int N;
		cin >> N;
		long long int p=1;
		while (N>1){
			N = N/2;
			p = p*2;
		}
		p = p%60;
		p=(p-1)%60;
		cout << r[p] << endl;		
	}
}