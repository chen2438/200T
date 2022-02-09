#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define LL long long

int n;
int a[100010],b[100010];
int A0[100010],A[100010];
	multiset<int> s1;
	multiset<int> s2;
void outs(){
	cout<<endl;
	for (multiset<int>::iterator ptr = s1.begin(); ptr != s1.end(); ptr++)
	{
		cout << *ptr<< " ";
	}
	cout<<"   ";
	for (multiset<int>::iterator ptr = s2.begin(); ptr != s2.end(); ptr++)
	{
		cout << *ptr<< " ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		A[i]=b[i];
	}
	sort(A+1,A+n+1);
	LL sums1=0,sums2=0;
	for(int i=1;i<=n/2;i++){
		s1.insert(A[i]);
		sums1+=A[i];
	}
	for(int i=n/2+1;i<=n;i++){
		s2.insert(A[i]);
		sums2+=A[i];
	}

	LL sum=(1<<30);
	
	for(int i=1;i<=n;i++){
		
		if(s1.count(b[i])>0){
			s1.erase(s1.find(b[i]));
			sums1-=b[i];
		}
		else{
			s2.erase(s2.find(b[i]));
			sums2-=b[i];
		}
		
		multiset<int>::iterator ptr1 = s2.begin();
		if(*ptr1>a[i]){
			s1.insert(a[i]);
			sums1+=a[i];
		}
		else{
			s2.insert(a[i]);
			sums2+=a[i];
		}
		cout<<i<<endl;
		if(s1.size()-s2.size()>1){
			
			multiset<int>::reverse_iterator ptr2 = s1.rbegin();
		//	cout<<i<<1<<endl;
		//	multiset<int>::iterator ptr2 = --s1.end();
			sums1-=*ptr2;
			sums2+=*ptr2;
		//	cout<<i<<1<<endl;
			outs();
			if(s1.count(*ptr2)>1){
				s1.erase(*ptr2);
				s1.insert(*ptr2);
			}
			else s1.erase(*ptr2);
			s2.insert(*ptr2);
		}
		else if(s2.size()-s1.size()>1){
			cout<<i<<2<<endl;
			multiset<int>::iterator ptr3 = s2.begin();
			sums1+=*ptr3;
			sums2-=*ptr3;
			s1.insert(*ptr3);
			s2.erase(s2.find(*ptr3));
		}
		cout<<i<<endl;
		LL sumt=0;
		if(s1.size()==s2.size()){
			sumt=-sums1+sums2;
		}
		else if(s1.size()>s2.size()){
			multiset<int>::reverse_iterator ptr2 = s1.rbegin();
		//	multiset<int>::iterator ptr2 = --s1.end();
		//	ptr2--;
			sumt=-(sums1-*ptr2)+sums2;
		}
		else if(s1.size()<s2.size()){
			multiset<int>::iterator ptr3 = s2.begin();
			sumt=-sums1+(sums2-*ptr3);
		}
		sum=min(sum,sumt);
	//	cout<<sumt<<endl;
	}
	cout<<sum;
} 
