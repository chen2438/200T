//#pragma GCC optimize(2)
//clock_t st=clock();
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=(b);--i)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

string prec_plus(string plus_s1,string plus_s2){
	int plus_i1[10100],plus_i2[10100];
	int l1=plus_s1.length(),l2=plus_s2.length();
	string ans="";
	int len=max(l1,l2);
	memset(plus_i1,0,sizeof(plus_i1));
	memset(plus_i2,0,sizeof(plus_i2));
	for(int i=l1-1;i>=0;i--)
		plus_i1[l1-i-1]=plus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		plus_i2[l2-i-1]=plus_s2[i]-'0';
	for(int i=0;i<len;i++){
		plus_i1[i]+=plus_i2[i];
		plus_i1[i+1]+=plus_i1[i]/10;
		plus_i1[i]%=10;
	}
	if(plus_i1[len]!=0) len++;
	while(plus_i1[len-1]==0 and len>1)
		len--;
	for(int i=len-1;i>=0;i--)
		ans=ans+char(plus_i1[i]+'0');
	return ans;
}

string prec_minus(string minus_s1,string minus_s2){ 
	int minus_i1[10100],minus_i2[10100];
	int l1=minus_s1.length(),l2=minus_s2.length();
	string ans="";
	int len=max(l1,l2);
	memset(minus_i1,0,sizeof(minus_i1));
	memset(minus_i2,0,sizeof(minus_i2));
	for(int i=l1-1;i>=0;i--)
		minus_i1[l1-i-1]=minus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		minus_i2[l2-i-1]=minus_s2[i]-'0';
	for(int i=0;i<len;i++){
		minus_i1[i]-=minus_i2[i];
		if(minus_i1[i]<0){
			minus_i1[i]+=10;
			minus_i1[i+1]--;
		}
	}
	while(minus_i1[len-1]==0 and len>1)
		len--;
	for(int i=len-1;i>=0;i--)
		ans=ans+char(minus_i1[i]+'0');
	return ans;
}

string prec_multiply(string multiply_s1,string multiply_s2){ 
	int multiply_i1[1010],multiply_i2[1010],multiply_i3[1010];
	int l1=multiply_s1.length(),l2=multiply_s2.length();
	string ans="";
	int len=(l1+l2);
	memset(multiply_i1,0,sizeof(multiply_i1));
	memset(multiply_i2,0,sizeof(multiply_i2));
	memset(multiply_i3,0,sizeof(multiply_i3));
	for(int i=l1-1;i>=0;i--)
		multiply_i1[l1-i-1]=multiply_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		multiply_i2[l2-i-1]=multiply_s2[i]-'0';
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++){
			multiply_i3[i+j]+=multiply_i1[i]*multiply_i2[j];
			multiply_i3[i+j+1]+=multiply_i3[i+j]/10;
			multiply_i3[i+j]%=10;
		}
	}
	while(multiply_i3[len-1]==0 and len>1)
		len--;
	for(int i=len-1;i>=0;i--)
		ans=ans+char(multiply_i3[i]+'0');
	return ans;
}

bool cmp_str(string x1,string x2){//x1>=x2
	if(x1==x2) return true;
	else if(x1.length()!=x2.length()) return x1.length()>x2.length();
	else return x1>x2;
}

//ans=2^q+n,2^q>=n-1

int main(){
	string n;
	cin>>n;
	if(n=="1") {cout<<1;exit(0);}
	string m=prec_minus(n,"1");//m=n-1
	string num="1";//num=2^0=1
	while(!cmp_str(num,m)){
		num=prec_multiply(num,"2");
	}//num=2^q
	string ans=prec_plus(num,n);
	cout<<ans;
	return 0;
}