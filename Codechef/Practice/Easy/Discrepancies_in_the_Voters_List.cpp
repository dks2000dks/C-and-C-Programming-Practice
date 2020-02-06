#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void Input_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int max2(int a,int b)
{
	if (a > b)
	{
		return a;
	}

	else
	{
		return b;
	}
}

int max3(int a, int b, int c)
{
	int k = max2(a,b);
	int o = max2(c,k);
	return k;
}

int main()
{
	int l,m,n;
	cin >> l;
	cin >> m;
	cin >> n;

	int input1[l];
	int input2[m];
	int input3[n];

	Input_Array(input1,l);
	Input_Array(input2,m);
	Input_Array(input3,n);

	int u = max3(l,m,n);

	std::vector<int> v1(u);
	std::vector<int> v2(u);
	std::vector<int> v3(u);
	std::vector<int>::iterator it;


	it=std::set_intersection (input1, input1+l, input2, input2+m, v1.begin());
	v1.resize(it - v1.begin());
	int p = v1.size();

	it=std::set_intersection (input2, input2+m, input3, input3+n, v2.begin());
	v2.resize(it - v2.begin());
	int q = v2.size();

	
	it=std::set_intersection (input1, input1+l, input3, input3+n, v3.begin());
	v3.resize(it - v3.begin());
	
	std::vector<int> vt(p+q);

	it = std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vt.begin());
	vt.resize(it - vt.begin());
	int k = vt.size();
	std::vector<int> output(u + k);


	it = std::set_union(vt.begin(), vt.end(), v3.begin(), v3.end(), output.begin());
	output.resize(it - output.begin());

	int s = output.size();
	cout << s << endl;

	for (int i = 0;i < s;i++)
	{
		cout << output[i] << endl;
	}

}