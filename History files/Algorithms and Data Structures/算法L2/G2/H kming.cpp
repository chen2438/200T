#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int id;
	float score;
}a[110];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i].id>>a[i].score;
	sort(a,a+n,cmp);
	cout<<a[k-1].id<<" "<<a[k-1].score;
	return 0;
}
