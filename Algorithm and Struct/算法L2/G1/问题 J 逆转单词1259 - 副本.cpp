#include<bits/stdc++.h>
#include<cstring>
#include<stack>
using namespace std;
int main(){
    int t;
    cin>>t;
    getchar();
    while(t--){
        stack<int> k;
        char a,b;
        a=getchar();
        if(a!=' ' and a!='\n'){
            k.push(a);
        }
        if(a==' '){
            while(!k.empty()){
                b=k.top();
                putchar(b);
                k.pop();
            }
            putchar(' ');
        }
        if(a=='\n'){
            putchar('\n');
        }
        
        
    }
    return 0;
}

