#include<cstdio>
#include"Windows.h"
int ar[8000010];
void flowinData(int sz)
{
	for(int i=0;i<sz;i++)ar[i]=i;
	ar[sz]=0; 
}
inline void linkadd2(int n)
{
	int res=0,tr=0;
	for(int i=0,j=1;i<n;i+=2,j+=2)
	{
		res+=ar[i];//二路 
		tr+=ar[j];
	}
	res+=tr;
}
double link_Test(int n,int&testTimes,double expectedTime,double&totalTime)
{
	double time=0.0;//总用时
	testTimes=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		//Windows平台下，开始计时
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		//linkadd2(n);
		int res=0,tr=0;
	for(int i=0,j=1;i<n;i+=2,j+=2)
	{
		res+=ar[i];//二路 
		tr+=ar[j];
	}
	res+=tr;
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windows平台下，结束计时
		time+=(tail-head)*1000.0/freq;//计算时间
	}
	totalTime=time;
	return time/testTimes;//计算平均时间
}
int Cases[40];
int main()
{
	flowinData(8000010);
	for(int i=0;i<40;i++)
	{
		if(i<32)
		Cases[i]=i+1;
		else
		Cases[i]=32<<(i-31);
	}
	Cases[38]=100000;
	Cases[39]=8000000;
	freopen("link2_out_ms.txt","w",stdout);
	for(int i=0;i<40;i++)
	{
		int testTimes;
		double expTime=100,totalTime;
		double avg_time=link_Test(Cases[i],testTimes,100,totalTime);
		printf("%d %.10lf %d %lf\n",Cases[i],avg_time,testTimes,totalTime);
	}
	return 0;
}
