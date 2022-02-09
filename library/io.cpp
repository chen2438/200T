#include<iostream>
using namespace std;

inline int IntRead(){
    char ch=getchar();
    int s=0,w=1;
    while(ch<'0' || ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        s=s*10+ch-'0',
        ch=getchar();
    }
    return s*w;
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

inline double DoubleRead(){
    long long s=0,w=1,k=0,n=0,m=0;
    char ch=getchar(); 
    while(ch<'0' || ch>'9'){
        if(ch=='-') w=-1;
        ch=getchar();
    }
    while((ch>='0' && ch<='9') || ch=='.'){
        if(ch=='.') n=1;
        else if(n==0) s=s*10+ch-'0';
			 else k=k*10+ch-'0',m++;
        ch=getchar();
    }
    return(pow(0.1,m)*k+s)*w;
}

inline void IntWrite(int s){
    int k=0,len=0;
    if(s==0) putchar('0');
    while(s){
        k=k*10+s%10;
        s/=10,len++;
    }
    for(int i=0;i<len;i++){
        putchar(k%10+'0');
        k/=10;
    }
}

inline void StringWrite(std::string str){
    int i=0;
    while(str[i]!='\0'){
        putchar(str[i]),i++;
    }
}

inline void DoubleWrite(double a){
    int mi=0,s[100];
    if (a==0) putchar('0');
    while(a!=(long long int)a){
        a*=10,mi++;
    }
    long long int k=a,len=0;
    while(k!=0){
        s[len]=k%10,len++,k/=10;
    }
    for(len-=1;len>=0;len--){
        if(len==mi-1) putchar('.');
        putchar(s[len]+'0');
    }
}

