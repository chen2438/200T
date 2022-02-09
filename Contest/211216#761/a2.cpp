#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
 
void Permutation(char* pStr, int length)
{
	sort(pStr,pStr+length);
	do 
	{
		cout << pStr <<endl;
	} while ( next_permutation(pStr,pStr+length) );
}
 
int main()
{
	char str[10];
	cout << "Input the string:";
	cin >> str;
	int lengh = strlen(str);
	cout << "Permutation is :"<<endl;
	
	Permutation(str,lengh);
	return 0;
}
