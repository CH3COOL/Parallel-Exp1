#include<cstdio>
#include"Windows.h"
int ar[1000010];
void flowinData(int sz)
{
	for(int i=0;i<sz;i++)ar[i]=i;
}
inline void paraadd(int n)
{
	for(int m=n;m>1;m=(m+1)>>1)
	{
   	 	for(int i=0;i<(m>>1);i++)
       	ar[i]+=ar[m-i-1];
    }
	int res=ar[0];
}
void link_Test(int n,int&testTimes,double expectedTime,double&totalTime)
{
	paraadd(n);
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
