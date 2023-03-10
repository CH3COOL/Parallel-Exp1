#include<cstdio>
#include"Windows.h"
#define MAXN 11100
int ar[MAXN][MAXN],vec[MAXN],result[MAXN];
constexpr int nTimes[]={1,2,4,5,8,11,16,22,32,45,64,90,128,181,256,362,363,512,724,725,1024,1448,2048,2896,3000};
void flowinData(int sz)
{
	for(int i=1;i<=sz;i++)vec[i]=i;
	for(int i=1;i<=sz;i++)
	for(int j=1;j<=sz;j++)ar[i][j]=i+j;
}
template<int nn>
double QryAvgPerformance_Col_Waste(int&testTimes,double expectedTime,double&totalTime)
//TODO:给定输入规模n，测试次数testTimes，返回值为算法平均用时
//totalTime返回运行testTimes次的算法的总用时
{
	int n=nTimes[nn];
	QryAvgPerformance_Col_Waste<nn-1>(testTimes,expectedTime,totalTime);
	double time=0.0;//总用时
	testTimes=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		//Windows平台下，开始计时
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		result[i]+=ar[j][i]*vec[j];//逐列访问，平凡算法
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windows平台下，结束计时
		time+=(tail-head)*1000.0/freq;//计算时间
	}
	totalTime=time;
	return time/testTimes;//计算平均时间
}
template<>
double QryAvgPerformance_Col_Waste<-1>(int&testTimes,double expectedTime,double&totalTime)
{
	return 0;
}
template<int nn>
double QryAvgPerformance_Row_Cached(int&testTimes,double expectedTime,double&totalTime)
//TODO:给定输入规模n，测试次数testTimes，返回算法平均用时
//totalTime返回运行testTimes次的算法的总用时
{
	int n=nTimes[nn];
	QryAvgPerformance_Row_Cached<nn-1>(testTimes,expectedTime,totalTime);
	double time=0.0;
	testTimes=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		result[j]+=ar[i][j]*vec[i];//逐行访问，cache优化
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		time+=(tail-head)*1000.0/freq;//计算时间
	}
	totalTime=time;
	return time/testTimes;//计算平均时间
}
template<>
double QryAvgPerformance_Row_Cached<-1>(int&testTimes,double expectedTime,double&totalTime)
{
	return 0;
}
int Cases=25,testTimes;
double ExpectedTime=100.0,totalT;
int main()
{
	flowinData(3030);
	QryAvgPerformance_Col_Waste<24>(testTimes,ExpectedTime,totalT);
	QryAvgPerformance_Row_Cached<24>(testTimes,ExpectedTime,totalT);
	return 0;
}
