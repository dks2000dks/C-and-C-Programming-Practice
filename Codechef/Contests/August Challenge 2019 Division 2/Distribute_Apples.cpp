#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		long long int n,k;
		cin >> n >> k;
		n = n /pow(10,6);
		k = k/pow(10,3);
		long long int c = pow(k,2);

		if (n%c == 0 || k == 0.001)
		{
			cout << "No" << endl;
		}

		else
		{
			cout << "Yes" << endl;
		}
	}
}

"""
T = int(input())
while T > 0:
	n, k = input().split(" ")
	n = int(n)
	k = int(k)
	l = k*k
	
	if n%l == 0:
		print ("No")
	else:
		print ("Yes")
	
	T = T - 1
"""




