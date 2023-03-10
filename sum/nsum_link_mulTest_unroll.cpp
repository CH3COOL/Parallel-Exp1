#include<cstdio>
#include"Windows.h"
int ar[1000010];
void flowinData(int sz)
{
	for(int i=0;i<sz;i++)ar[i]=i;
}
template<int i>
inline void linkUnitadd(int&res)
{
	linkUnitadd<i-1>(res);
	res+=ar[i];
}
template<>
inline void linkUnitadd<-1>(int&res){}

constexpr int Cases[40]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,64,128,256,512,1024,2048,4096,8192};

template<int casei>
void link_Test(int&testTimes,double expectedTime,double&totalTime)
{
	link_Test<casei-1>(testTimes,expectedTime,totalTime);
	double time=0.0;//总用时
	testTimes=0;
	int res=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		//Windows平台下，开始计时
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		linkUnitadd<Cases[casei]-1>(res);
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windows平台下，结束计时
		time+=(tail-head)*1000.0/freq;//计算时间
	}
	totalTime=time;
	printf("%d %.10lf %d %lf\n",Cases[casei],time/testTimes,testTimes,totalTime);
}
template<>void link_Test<-1>(int&testTimes,double expectedTime,double&totalTime){}
int main()
{
	flowinData(8888);
	freopen("link_out_ms_unroll.txt","w",stdout);
	int testTimes;
	double expTime=100,totalTime;
	link_Test<39>(testTimes,100,totalTime);
	return 0;
}
