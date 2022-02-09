#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int f=0;
	int base[10];
	int get[10];
}pla[100010];
int main(){
	int n;
	cin>>n;
	int a[10];
	for(int i=0;i<7;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<7;j++){
			cin>>pla[i].base[j];
		}
		for(int j=0;j<7;j++){
			cin>>pla[i].get[j];
		}
	}

//	cout<<1<<endl;
	int f2=0,sum=0;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			f2=0;
			if(pla[i].f==0){
				for(int j=0;j<7;j++){
					if(a[j]<pla[i].base[j]){
						f2=1;
						break;
					}
				}
			}
			if(f2==0 and pla[i].f==0){
				pla[i].f=1;
				sum++;
				for(int j=0;j<7;j++){
					a[j]+=pla[i].get[j];
				}
			}
		}
		if(sum>=n or sum==0)break;
	}
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
