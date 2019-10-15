#include<bits/stdc++.h>
using namespace std;

void Input_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][k + 1]; 
    int i, j; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
  
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 
int main()
{
	int T;
	cin >> T;
	
	while (T--)
	{
		int N,K,f=1,e=1;
		cin >> N >> K;
		int i=0,ans;
		int input[N];
		vector<int>sum;
		Input_Array(input,N);
		sort(input,input+N);
		map<int,int>a;
		for(int i=0;i<N;i++)
			a[input[i]]++;
		for(auto x:a)
			sum[i++]+=x.second;
		if(k<=sum[0])	ans=binomialCoeff(sum[0],k);
		else{
		for(int i=1;i<sizeof(sum);i++){
			if(k>=sum[i] and k<sum[i+1]){
				int flag = sum[i+1]-sum[i];
				int flag2=k-sum[i];
				ans = binomialCoeff(flag,flag2);
				break;
			}
		}

		}
		cout<<ans<<endl;

	}
}