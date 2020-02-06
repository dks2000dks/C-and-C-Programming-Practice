#include <iostream>
#include <string>
using namespace std;

int main()
{
	long int a,b;
	long int s;

	cin >> a;
	cin >> b;

	if ((a - b)%10 == 9)
		s = a - b - 1;
	else
		s = a - b + 1;


	cout << s << endl;
}