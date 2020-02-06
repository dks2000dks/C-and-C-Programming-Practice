#include<bits/stdc++.h>
using namespace std;

void Input_Array(long long int *array, long long int size)
{
	for (long long int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

long double distance(long long int x1,long long int y1, long long int x2, long long int y2)
{
	long double d = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	return d;
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		long long int x,y,n,m,k;
		cin >> x >> y;
		cin >> n >> m >> k;

		long long int input1[2*n];
		long long int input2[2*m];
		long long int input3[2*k];

		Input_Array(input1,2*n);
		Input_Array(input2,2*m);
		Input_Array(input3,2*k);

		long double a1[n],a2[m],td1[m],td2[n];
		long double t;



		for (long long int i=0;i<n;i++)
		{
			a1[i] = distance(x,y,input1[2*i],input1[2*i+1]);			
		}

		fill(a2,a2+m,numeric_limits<double>::max());
		fill(td1,td1+m,numeric_limits<double>::max());

		for (long long int i=0;i<m;i++)
		{
			for (long long int j=0;j<k;j++)
			{
				t = distance(input2[2*i],input2[2*i+1],input3[2*j],input3[2*j+1]);
				if (t < a2[i])
					a2[i] = t;
			}	
		}

		for (long long int i=0;i<m;i++)
		{
			for (long long int j=0;j<n;j++)
			{
				t = distance(input2[2*i],input2[2*i+1],input1[2*j],input1[2*j+1]) + a1[j];
				if(td1[i] > t+a2[i])
					td1[i] = t+a2[i];
			}
		}



		for (long long int i=0;i<m;i++)
		{
			a2[i] = distance(x,y,input2[2*i],input2[2*i+1]);			
		}

		fill(a1,a1+n,numeric_limits<double>::max());
		fill(td2,td2+n,numeric_limits<double>::max());

		for (long long int i=0;i<n;i++)
		{
			for (long long int j=0;j<k;j++)
			{
				t = distance(input1[2*i],input1[2*i+1],input3[2*j],input3[2*j+1]);
				if (t < a1[i])
					a1[i] = t;
			}	
		}

		for (long long int i=0;i<n;i++)
		{
			for (long long int j=0;j<m;j++)
			{
				t = distance(input1[2*i],input1[2*i+1],input2[2*j],input2[2*j+1]) + a2[j];
				if (td2[i] > t+a1[i])
					td2[i] = t+a1[i];
			}
		}
		
		sort(td1,td1+m);
		sort(td2,td2+n);

		long double o = min(td1[0],td2[0]);

		cout << setprecision(10) << o << endl;
	}

	return 0;
}