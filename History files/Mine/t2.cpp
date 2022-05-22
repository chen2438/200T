#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main(){
	char a[1000];
	stack<int> k;
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='(' or a[i]=='[') k.push(a[i]);
		else if( (a[i]==')' or a[i]==']') and k.empty() ){
			cout<<"Wrong";return 0;
		}
		else if(a[i]==')' and k.top()=='(') k.pop();
		else if(a[i]==']' and k.top()=='[') k.pop();
		else{
			cout<<"Wrong";return 0;
		}
	}
	if(!k.empty()) cout<<"Wrong";
	else cout<<"OK";
	return 0;
} 
