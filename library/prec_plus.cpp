#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define abss(x) ((x)>(0)?(x):(-1)*(x))
#define maxs(a,b) ((a)>(b)?(a):(b))
#define mins(a,b) ((a)<(b)?(a):(b))
#define FOR(i,a,b) for(register int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(register int i=(a);i>=(b);i--)
#define mem(a) memset(a,0,sizeof(a))
const int INF (1<<30);
const int inf (-1<<30);
using namespace std;

void prec_minus(string minus_s1,string minus_s2){ 
	int minus_i1[101000],minus_i2[101000];
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
		printf("%d",minus_i1[i]);

}

inline string StringRead(){
    string str;
    char s=getchar();
    while(s==' ' || s=='\n' || s=='\r'){
        s=getchar();
    }
    while(s!=' ' && s!='\n' && s!='\r'){
        str+=s;
        s=getchar();
    }
    return str;
}

inline void StringWrite(std::string str){
    int i=0;
    while(str[i]!='\0'){
        putchar(str[i]),i++;
    }
}

bool cmp(string x1,string x2){
	if(x1==x2) return true;//ÏàµÈ·µ»Øtrue
	else if(x1.length()!=x2.length()) return x1.length()>x2.length();
	else return x1>x2;
}


int main(){
	string s1,s2,s3;
	s1=StringRead();
	s2=StringRead();
	if(!cmp(s1,s2)){
		putchar('-');
		prec_minus(s2,s1);
	}
	else prec_minus(s1,s2);

	return 0;
}

