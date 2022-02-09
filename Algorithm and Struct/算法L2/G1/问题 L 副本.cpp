#include<iostream>  
#include<cstdio>  
#include<cstring> 
#define MAX 500
using namespace std;

char aaa1[MAX],aaa2[MAX];
string ans[MAX];
char t1[MAX],t2[MAX],t3[MAX];

void sp(char a1[MAX],char b1[MAX]){  
    int a[MAX],b[MAX],c[MAX];  
    int a1_len,b1_len,lenc,i,x;  
    memset(a,0,sizeof(a));   
    memset(b,0,sizeof(b));   
    memset(c,0,sizeof(c));  
    a1_len=strlen(a1);   
    b1_len=strlen(b1);   
    for(i=0;i<=a1_len-1;i++)   
    	a[a1_len-i]=a1[i]-48;
    for(i=0;i<=b1_len-1;i++)  
        b[b1_len-i]=b1[i]-48; 
    lenc=1;
    x=0;
    while(lenc <=a1_len || lenc <=b1_len){   
        c[lenc]=a[lenc]+b[lenc]+x; 
        x=c[lenc]/10;
        c[lenc]=c[lenc]%10;
        lenc++;
    }  
    c[lenc]=x;  
    if(c[lenc]==0) lenc--; 
    int dd=0;
    memset(t3,0,sizeof(t3));  
    for (i=lenc;i>=1;i--)
       	t3[dd++]=char(c[i])+'0';
}
void str2char_t1(string x){
	for(int k=0;k<x.length();k++)
		t1[k]=x[k];
}
void str2char_t2(string x){
	for(int k=0;k<x.length();k++)
		t2[k]=x[k];
}
bool cmp(string x1,string x2){
	if(x1==x2) return true;
	else if(x1.length()!=x2.length()) return x1.length()>x2.length();
	else return x1>x2;
}
int main(){
	ans[1]="1";ans[2]="1";
	for(int i=3;i<MAX;i++){
		str2char_t1(ans[i-1]);
		str2char_t2(ans[i-2]);
		sp(t1,t2);
		ans[i]=t3;
	}
	string m,n;
	int cnt;
	while(cin>>m>>n){
		if(m=="0" and n=="0") break;
		cnt=0;
		for(int j=1;j<MAX;j++)
			if(cmp(ans[j],m) and cmp(n,ans[j])) cnt++;
		if(m=="1" or m=="0") cnt--;
		cout<<cnt<<endl;
	}
	return 0;
}
