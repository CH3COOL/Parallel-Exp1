#include<cstdio>
#include"Windows.h"
#define MAXN 11100
int ar[MAXN*MAXN],vec[MAXN],result[MAXN];
void flowinData(int sz)
{
	for(int i=1;i<=sz;i++)vec[i]=i;
	for(int i=1;i<=sz*sz;i++)ar[i]=i;
}
double QryAvgPerformance_Col_Waste(int n,int&testTimes,double expectedTime,double&totalTime)
//TODO:给定输入规模n，测试次数testTimes，返回值为算法平均用时
//totalTime返回运行testTimes次的算法的总用时
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
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		result[i]+=ar[n*(j-1)+i]*vec[j];//逐列访问，平凡算法
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windows平台下，结束计时
		time+=(tail-head)*1000.0/freq;//计算时间
	}
	totalTime=time;
	return time/testTimes;//计算平均时间
}
double QryAvgPerformance_Row_Cached(int n,int&testTimes,double expectedTime,double&totalTime)
//TODO:给定输入规模n，测试次数testTimes，返回算法平均用时
//totalTime返回运行testTimes次的算法的总用时
{
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
		result[j]+=ar[n*(i-1)+j]*vec[i];//逐行访问，cache优化
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		time+=(tail-head)*1000.0/freq;//计算时间
	}
	totalTime=time;
	return time/testTimes;//计算平均时间
}
int Cases=25,testTimes;
double ExpectedTime=100.0,totalT;
int nTimes[]={1,2,4,5,8,11,16,22,32,45,64,90,128,181,256,362,363,512,724,725,1024,1448,2048,2896,3000};
char fileName[50];
int main()
{
	flowinData(3033);
    sprintf(fileName,"Report_Waste_Test_ms_1lize.txt");
	freopen(fileName,"w",stdout);
	for(int i=1;i<=3000;i++)
	{
        int currentCaseN=i;
		double t=QryAvgPerformance_Col_Waste(currentCaseN,testTimes,ExpectedTime,totalT);
		printf("%d %.10lf %d %lf\n",currentCaseN,t,testTimes,totalT);
	}
	sprintf(fileName,"Report_Cached_Test_ms_1lize.txt");
	freopen(fileName,"w",stdout);
    for(int i=1;i<=3000;i++)
	{
	    int currentCaseN=i;//数据规模依次为：256,362,363,512,724,725,1448,2048,3000
		double t=QryAvgPerformance_Row_Cached(currentCaseN,testTimes,ExpectedTime,totalT);//测量数据
		printf("%d %.10lf %d %lf\n",currentCaseN,t,testTimes,totalT);//输出测试结果（文件读写）
	}
	return 0;
}
