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
//TODO:���������ģn�����Դ���testTimes������ֵΪ�㷨ƽ����ʱ
//totalTime��������testTimes�ε��㷨������ʱ
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
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		result[i]+=ar[n*(j-1)+i]*vec[j];//���з��ʣ�ƽ���㷨
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		//Windowsƽ̨�£�������ʱ
		time+=(tail-head)*1000.0/freq;//����ʱ��
	}
	totalTime=time;
	return time/testTimes;//����ƽ��ʱ��
}
double QryAvgPerformance_Row_Cached(int n,int&testTimes,double expectedTime,double&totalTime)
//TODO:���������ģn�����Դ���testTimes�������㷨ƽ����ʱ
//totalTime��������testTimes�ε��㷨������ʱ
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
		result[j]+=ar[n*(i-1)+j]*vec[i];//���з��ʣ�cache�Ż�
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);
		time+=(tail-head)*1000.0/freq;//����ʱ��
	}
	totalTime=time;
	return time/testTimes;//����ƽ��ʱ��
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
	    int currentCaseN=i;//���ݹ�ģ����Ϊ��256,362,363,512,724,725,1448,2048,3000
		double t=QryAvgPerformance_Row_Cached(currentCaseN,testTimes,ExpectedTime,totalT);//��������
		printf("%d %.10lf %d %lf\n",currentCaseN,t,testTimes,totalT);//������Խ�����ļ���д��
	}
	return 0;
}
