#include<iostream>
#include<cstdio>
using namespace std;

//sort(a,a+n,greater <int> () );

//priority_queue<int,vector<int>,greater<int> > a;

bool cmp_str(string x1,string x2){
	if(x1==x2) return true;
	else if(x1.length()!=x2.length()) return x1.length()>x2.length();
	else return x1>x2;
}

void qsort(int a[10010],int l,int r){
    int mid=a[(l+r)/2];
    int i=l,j=r;
    while(i<j){
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(l<j) qsort(a,l,j);
    if(r>i) qsort(a,i,r);
}
/*
void merge_sort(int a[], int l, int r) {
	if(l >= r) return;
	int mid=(l+r)/2;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	int i=l,j=mid+1,k=1;
	while(i<=mid&&j<=r) {
		if(a[i]<=a[j]) tmp[k++]=a[i++];
		else tmp[k++]=a[j++];
	}
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	for(i=l,j=1;i<=r;i++,j++)
		a[i]=tmp[j];
}
*/
