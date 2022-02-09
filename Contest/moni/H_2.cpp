#include<iostream>
#include<set>
using namespace std;
int main(){
	multiset<int> s1;
	s1.insert(2);
	s1.insert(6);
	s1.insert(-1);
	s1.insert(9);
	s1.erase(s1.find(9));
	
	
	for (multiset<int>::iterator ptr = s1.begin(); ptr != s1.end(); ptr++)
	{
		int a=*ptr;
		cout << a<< " ";
	}
	return 0;
}
