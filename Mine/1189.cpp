#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int k;
    cin>>k;
    if(k==1)cout<<m+n;
    if(k==2)cout<<m-n;
    if(k==3)cout<<m*n;
    if(k==4)cout<<int(m/n);
}
