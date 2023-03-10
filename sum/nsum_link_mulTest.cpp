#include<cstdio>
#include"Windows.h"
int ar[8000010];
void flowinData(int sz)
{
	for(int i=0;i<sz;i++)ar[i]=i;
}
inline void linkadd(int n)
{
	int res=0;
	for(int i=0;i<n;i++)
		res+=ar[i];//ƽ�� 
}
double link_Test(int n,int&testTimes,double expectedTime,double&totalTime)
{
	double time=0.0;//����ʱ
	testTimes=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		//Windowsƽ̨�£���ʼ��ʱ
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		//linkadd(n);
		int res=0;
	for(int i=0;i<n;i++)
		res+=ar[i];//ƽ�� 
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windowsƽ̨�£�������ʱ
		time+=(tail-head)*1000.0/freq;//����ʱ��
	}
	totalTime=time;
	return time/testTimes;//����ƽ��ʱ��
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
	freopen("link_out_ms.txt","w",stdout);
	for(int i=0;i<40;i++)
	{
		int testTimes;
		double expTime=100,totalTime;
		double avg_time=link_Test(Cases[i],testTimes,100,totalTime);
		printf("%d %.10lf %d %lf\n",Cases[i],avg_time,testTimes,totalTime);
	}
	return 0;
}
