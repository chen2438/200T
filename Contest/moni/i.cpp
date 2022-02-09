#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	float a=n*1.0/2+2.5;
	int aa=(int)(a),i,j;
	
	for(i=0;i<aa-1;i++) putchar(' ');
	putchar('*');
	for(i=0;i<aa-1;i++) putchar(' ');
	putchar(' ');putchar(' ');
	for(i=0;i<n;i++) putchar('*');
	putchar('\n');
	
	int aat=aa;
	for(j=1;j<=aa-3;j++){
		for(i=0;i<aat-2;i++) putchar(' ');
		aat--;
		putchar('*');
		for(i=0;i<2*j-1;i++) putchar(' ');
		putchar('*');
		for(i=0;i<aat-1;i++) putchar(' ');
		putchar(' ');
		putchar('*');
		putchar('\n');
	}
	putchar(' ');
	
	for(i=0;i<n+2;i++) putchar('*');
	putchar(' ');
	putchar(' ');
	putchar('*');
	putchar('\n');
	
	putchar('*');
	for(i=0;i<n+2;i++) putchar(' ');
	putchar('*');
	putchar(' ');
	putchar(' ');
	for(i=0;i<n;i++) putchar('*');
	return 0;
}
