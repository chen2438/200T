#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[1000];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j]) swap(a[i],a[j]);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
