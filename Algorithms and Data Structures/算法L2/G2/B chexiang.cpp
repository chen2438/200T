#include<iostream>
using namespace std;
int main(){
    int n,a[10010],cnt;
    while(cin>>n){
        cnt=0;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
            for(int j=1;j<=n-i;j++)
                if(a[j]>a[j+1]){
                    swap(a[j],a[j+1]);
                    cnt++;
                }
        cout<<cnt<<endl;
    }
    return 0;
}


