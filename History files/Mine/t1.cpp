#include<iostream>
#include<stack>
using namespace std;
int main(){
	char o;
	stack<int> k;
	bool flag=true;
	while(cin>>o){
		if(o=='('){
			k.push(o);
		}
		if(o==')'){
			if(k.empty()){
				flag=false;
			}
			else{
				k.pop();
			}
		}
		if(o=='@'){
			if(!k.empty()){
				flag=false;
			}
			break;
		}
	}
	if(flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}
