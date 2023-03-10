#include<cstdio>
#include"Windows.h"
int ar[8000010];
void flowinData(int sz)
{
	for(int i=0;i<sz;i++)ar[i]=i;
	ar[sz]=0; 
}
void link2(int n)
{
	int res=0,tr=0;
	for(int i=0;i<n;i+=2)
	{
		res+=ar[i];//��· 
		tr+=ar[i+1];
	}
	res+=tr;
}
double link_Test2(int n)
{
	long long head,tail,freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	link2(n);
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	return (tail-head)*1000.0/freq;//����ʱ��
}
void link1(int n)
{
	int res=0;
	for(int i=0;i<n;i++)
		res+=ar[i];
}
double link_Test1(int n)
{
	long long head,tail,freq;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
	QueryPerformanceCounter((LARGE_INTEGER*)&head);
	link1(n);
	QueryPerformanceCounter((LARGE_INTEGER*)&tail);
	return (tail-head)*1000.0/freq;//����ʱ��
}
int main()
{
	flowinData(8000010);
	printf("%.10lf ms\n",link_Test1(8000000));
	printf("%.10lf ms",link_Test2(8000000));
	return 0;
}
