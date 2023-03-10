#include<cstdio>
#include"Windows.h"
int ar[1000010];
void flowinData(int sz)
{
	for(int i=0;i<sz;i++)ar[i]=i;
	ar[sz]=0; 
}
inline void linkadd2(int n)
{
	int res=0,tr=0;
	for(int i=0;i<n;i+=2)
	{
		res+=ar[i];//��· 
		tr+=ar[i+1];
	}
	res+=tr;
}
void link_Test(int n,int&testTimes,double expectedTime,double&totalTime)
{
	linkadd2(n);
}
int Cases[40];
int main()
{
	flowinData(8888);
	for(int i=0;i<40;i++)
	{
		if(i<32)
		Cases[i]=i+1;
		else
		Cases[i]=32<<(i-31);
	}
	for(int i=0;i<40;i++)
	{
		int testTimes;
		double expTime=100,totalTime;
		link_Test(Cases[i],testTimes,100,totalTime);
	}
	return 0;
}
