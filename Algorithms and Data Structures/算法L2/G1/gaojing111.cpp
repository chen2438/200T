#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
#define MAXN	500
#define MAXLEN	110
#define LAST MAXLEN-2
 
char store[MAXN][MAXLEN];	//存储MAXN个斐波那契数
char *Fibs[MAXN];		//存储每个斐波那契数的首地址
 
//大整数相加
char* IntAddition(char *a, char *b, char *sum)
{
	int i, j, k, first;
 
	//从末位开始，把a与b对应位的和存入sum中，暂不处理进位
	for (i = strlen(a)-1, j = LAST; i >= 0; i--, j--)
	{
		sum[j] = a[i] - '0';
	}
	for (i = strlen(b)-1, k = LAST; i >= 0; i--, k--)
	{
		sum[k] += b[i] - '0';
	}
 
	//获取sum中结果的首位位置
	first = j < k ? j : k;
 
	//处理进位
	for (i = LAST; i >= first; i--)
	{
		sum[i-1] += sum[i] / 10;
		sum[i] = sum[i] % 10 + '0';
	}
	//去除前导'0'
	while (sum[first] == '0' && first < LAST)
	{
		first++;
	}
	//返回sum的首位地址
	return &sum[first];
}
 
//计算485个斐波那契数
void Fibonacci(void)
{
	memset(store, 0, sizeof(store));
	memset(Fibs, NULL, sizeof(Fibs));
 
	strcpy(store[1], "1");
	strcpy(store[2], "2");
	Fibs[1] = store[1];
	Fibs[2] = store[2];
 
	int i;
	for (i = 3; i < 485; i++)
	{
		Fibs[i] = IntAddition(Fibs[i-2], Fibs[i-1], store[i]);
	}
}
 
int Compare(char *a, char *b)
{
	int lenA = strlen(a);
	int lenB = strlen(b);
 
	if (lenA == lenB)
	{
		return strcmp(a, b);
	}
	return lenA > lenB ? 1 : -1;
}
 
int BinarySearch(char *num, bool &flag)
{
	int low = 1;
	int high = 480;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		
		int res = Compare(num, Fibs[mid]);
		if (res == 0)
		{
			flag = true; return mid;
		}
		else if (res < 0)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}
 
int main(void)
{
	Fibonacci();
 
	char a[MAXLEN], b[MAXLEN];
	while (scanf("%s %s", a, b) != EOF)
	{
		if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0)
		{
			break;
		}
 
		bool flagLeft = false;
		bool flagRight = false;
		//分别找出a和b在斐波那契数中的位置
		//当查找的数不是斐波那契数时，二分查找返回的位置是第一个比它大的斐波那契数的位置
		int left = BinarySearch(a, flagLeft);
		int right = BinarySearch(b, flagRight);
 
		//当b也是斐波那契数时，要把两位置的差值加1
		if (flagRight)
		{
			printf("%d\n", right - left + 1);
		}
		else
		{
			printf("%d\n", right - left);
		}
	}
	return 0;
}
