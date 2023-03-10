#include<cstdio>
#include"Windows.h"
#define MAXN 11100
int ar[MAXN*MAXN],vec[MAXN],result[MAXN];
constexpr int nTimes[]={1,2,4,5,8,11,16,22,32,45,64,90,128,181,256,362,363,512,724,725,1024,1448,2048,2896,3000};
void flowinData(int sz)
{
	for(int i=1;i<=sz;i++)vec[i]=i;
	for(int i=1;i<=sz*sz;i++)ar[i]=i;
}
template<int n>
void QryAvgPerformance_Col_Waste()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	result[i]+=ar[n*(j-1)+i]*vec[j];//���з��ʣ�ƽ���㷨
}
template<int nn>
double colCaller(int&testTimes,double expectedTime,double&totalTime)
{
	colCaller<nn-1>(testTimes,expectedTime,totalTime);
	double time=0.0;//����ʱ
	testTimes=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		//Windowsƽ̨�£���ʼ��ʱ
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		QryAvgPerformance_Col_Waste<nTimes[nn]>();
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windowsƽ̨�£�������ʱ
		time+=(tail-head)*1000.0/freq;//����ʱ��
	}
	totalTime=time;
	return time/testTimes;//����ƽ��ʱ��
}
template<>double colCaller<-1>(int&testTimes,double expectedTime,double&totalTime){return 0;}
template<int n>
void QryAvgPerformance_Row_Cached()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	result[j]+=ar[n*(i-1)+j]*vec[i];//���з��ʣ�cache�Ż�
}
template<int nn>
double rowCaller(int&testTimes,double expectedTime,double&totalTime)
{
	rowCaller<nn-1>(testTimes,expectedTime,totalTime);
	double time=0.0;
	testTimes=0;
	while(time<expectedTime)
	{
	    testTimes++;
		long long head,tail,freq;
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		QueryPerformanceCounter((LARGE_INTEGER*)&head);
		QryAvgPerformance_Row_Cached<nTimes[nn]>();
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		time+=(tail-head)*1000.0/freq;//����ʱ��
	}
	totalTime=time;
	return time/testTimes;//����ƽ��ʱ��
}
template<>double rowCaller<-1>(int&testTimes,double expectedTime,double&totalTime){return 0;}
int Cases=25,testTimes;
double ExpectedTime=100.0,totalT;
int main()
{
	flowinData(3030);
	colCaller<24>(testTimes,ExpectedTime,totalT);
	rowCaller<24>(testTimes,ExpectedTime,totalT);
	return 0;
}
