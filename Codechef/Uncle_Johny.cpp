#include<iostream>
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

void Print_Array(int *array, int size)
{
	for (int i = 0;i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int Find_Index(int *array, int size,int find)
{
	int o;
	for (int i = 0;i < size; i++)
	{
		if (find == array[i])
		{
			o = i;
			i = size;
		}
	}

	return o;
}
int main()
{
	int t=0,T;
	cin >> T;

	while (t < T)
	{
		int n,p,s;
		cin >> n;
		int Playlist[n];
		Input_Array(Playlist,n);

		cin >> p;
		s = Playlist[p-1];
		std::sort(Playlist,Playlist + n);

		int o = Find_Index(Playlist,n,s);
		cout << o + 1 << endl;

		t++;
	}
}