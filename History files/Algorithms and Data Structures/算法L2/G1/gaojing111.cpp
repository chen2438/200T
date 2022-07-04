#include <iostream>
#include <cstdio>
#include <cstring>
 
using namespace std;
 
#define MAXN	500
#define MAXLEN	110
#define LAST MAXLEN-2
 
char store[MAXN][MAXLEN];	//�洢MAXN��쳲�������
char *Fibs[MAXN];		//�洢ÿ��쳲����������׵�ַ
 
//���������
char* IntAddition(char *a, char *b, char *sum)
{
	int i, j, k, first;
 
	//��ĩλ��ʼ����a��b��Ӧλ�ĺʹ���sum�У��ݲ������λ
	for (i = strlen(a)-1, j = LAST; i >= 0; i--, j--)
	{
		sum[j] = a[i] - '0';
	}
	for (i = strlen(b)-1, k = LAST; i >= 0; i--, k--)
	{
		sum[k] += b[i] - '0';
	}
 
	//��ȡsum�н������λλ��
	first = j < k ? j : k;
 
	//�����λ
	for (i = LAST; i >= first; i--)
	{
		sum[i-1] += sum[i] / 10;
		sum[i] = sum[i] % 10 + '0';
	}
	//ȥ��ǰ��'0'
	while (sum[first] == '0' && first < LAST)
	{
		first++;
	}
	//����sum����λ��ַ
	return &sum[first];
}
 
//����485��쳲�������
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
		//�ֱ��ҳ�a��b��쳲��������е�λ��
		//�����ҵ�������쳲�������ʱ�����ֲ��ҷ��ص�λ���ǵ�һ���������쳲���������λ��
		int left = BinarySearch(a, flagLeft);
		int right = BinarySearch(b, flagRight);
 
		//��bҲ��쳲�������ʱ��Ҫ����λ�õĲ�ֵ��1
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
