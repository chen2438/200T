#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
string as,bs,cs,input;
int lena,lenb,lenc,lenmax;
char o;
inline string StringRead(){//快读
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
inline void StringWrite(std::string str){//快写
    int i=0;
    while(str[i]!='\0'){
        putchar(str[i]),i++;
    }
}
void init_out(){//打印算式前两行（通用） 
	for(int i=0;i<lenmax-lena;i++)putchar(' ');
	StringWrite(as);
	putchar('\n');
	for(int i=0;i<lenmax-lenb-1;i++)putchar(' ');
	putchar(o);
	StringWrite(bs);
	putchar('\n');
}
string prec_minus(string minus_s1,string minus_s2){//高精度加法 
	int minus_i1[1010],minus_i2[1010];
	int l1=minus_s1.length(),l2=minus_s2.length();
	string ans="";
	int len=max(l1,l2);
	
	memset(minus_i1,0,sizeof(minus_i1));
	memset(minus_i2,0,sizeof(minus_i2));

	for(int i=l1-1;i>=0;i--)//倒序赋值 char->int 
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
		len--;//去0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(minus_i1[i]+'0');
	return ans;
}
string prec_plus(string plus_s1,string plus_s2){//高精度减法 
	int plus_i1[1010],plus_i2[1010];
	int l1=plus_s1.length(),l2=plus_s2.length();
	string ans="";
	int len=max(l1,l2);
	
	memset(plus_i1,0,sizeof(plus_i1));
	memset(plus_i2,0,sizeof(plus_i2));

	for(int i=l1-1;i>=0;i--)//倒序赋值 char->int 
		plus_i1[l1-i-1]=plus_s1[i]-'0';
	for(int i=l2-1;i>=0;i--)
		plus_i2[l2-i-1]=plus_s2[i]-'0';
	for(int i=0;i<len;i++){
		plus_i1[i]+=plus_i2[i];
		plus_i1[i+1]+=plus_i1[i]/10;//进位
		plus_i1[i]%=10;
	}
	if(plus_i1[len]!=0) len++;//判断首位是否进位 

	while(plus_i1[len-1]==0 and len>1)
		len--;//去0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(plus_i1[i]+'0');
	return ans;
}
string prec_multiply(string multiply_s1,string multiply_s2){//高精度乘法 
	int multiply_i1[1010],multiply_i2[1010],multiply_i3[1010];
	int l1=multiply_s1.length(),l2=multiply_s2.length();
	string ans="";
	int len=(l1+l2);
	
	memset(multiply_i1,0,sizeof(multiply_i1));
	memset(multiply_i2,0,sizeof(multiply_i2));
	memset(multiply_i3,0,sizeof(multiply_i3));
	
	for(int i=l1-1;i>=0;i--)//倒序赋值 char->int 
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
		len--;//去0 
		
	for(int i=len-1;i>=0;i--)
		ans=ans+char(multiply_i3[i]+'0');
	return ans;
}
void Plus_Minus(){//加减法 
	init_out();
	for(int i=0;i<lenmax-max(lenb+1,lenc);i++)putchar(' ');
	for(int i=0;i<max(lenb+1,lenc);i++)putchar('-');
	putchar('\n');
	
	for(int i=0;i<lenmax-lenc;i++)putchar(' ');
	StringWrite(cs);
	putchar('\n');
}
void Multiply(){//乘法 
	init_out();
	string t;
	
	t=bs[lenb-0-1];
	t=prec_multiply(t,as);
	for(int i=0;i<lenc-max(lenb+1,(int)t.length());i++)putchar(' ');
	for(int i=0;i<max(lenb+1,(int)t.length());i++)putchar('-');
	putchar('\n');
	
	for(int i=0;i<lenb;i++){
		t=bs[lenb-i-1];
		t=prec_multiply(t,as);
		for(int j=0;j<lenmax-t.length()-i;j++)putchar(' ');
		StringWrite(t);
		putchar('\n');
	}
	if(lenb>1){
		for(int i=0;i<lenmax-lenc;i++)putchar(' ');
		for(int i=0;i<lenc;i++)putchar('-');
		putchar('\n');
		for(int i=0;i<lenmax-lenc;i++)putchar(' ');
		StringWrite(cs);
		putchar('\n');
	}
}
void init(){//初始化两个算数as,bs 
	as="";bs="";cs="";
	int i,j;
    for(i=0;i<input.length();i++){
    	if(input[i]=='+' or input[i]=='-' or input[i]=='*'){
    		o=input[i];
    		break;
		}
	}
	for(j=0;j<i;j++)
    	as+=input[j];
	for(j=i+1;j<input.length();j++)
    	bs+=input[j];
	lena=as.length();
	lenb=bs.length();
}
int main(){
	int t,a,b;
	cin>>t;
    while(t--){
    	input=StringRead();
    	init();
    	if(o=='+'){
    		cs=prec_plus(as,bs);
			lenc=cs.length();
    		lenmax=max(lena,max(lenb+1,lenc));
    		Plus_Minus();
    		putchar('\n');
		}
		if(o=='-'){
			cs=prec_minus(as,bs);
			lenc=cs.length();
			lenmax=max(lena,max(lenb+1,lenc));
			Plus_Minus();
			putchar('\n');
		}
		if(o=='*'){
			cs=prec_multiply(as,bs);
			lenc=cs.length();
			lenmax=max(lena,max(lenb+1,lenc));
			Multiply();
			putchar('\n');
		}
	}
    return 0;
}

