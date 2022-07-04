#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    getchar();
	char a[10000];
    while(t--){
        memset(a,'\0',sizeof(a));
        cin.getline(a,10000);
        a[strlen(a)]=' ';
        stack<int> k;
        for(int i=0;i<strlen(a);i++){
            if(a[i]!=' ') k.push(a[i]);
            else{
                while(!k.empty()){
                    cout<<char(k.top());
                    k.pop();
                }
                cout<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
