#include<cstdio>
int ar[1000010]={1,2,3,4,5,6,7,8,9,10},res,n=10;
template<int i>
inline void redu(int m)
{
	redu<i-1>(m);
	ar[i]+=ar[m-i-1];
}
template<>
inline void redu<-1>(int m){}
int main()
{
	for(int m=n;m>1;m=(m+1)>>1)
	{
		redu<m>>1-1>(m);
    }
	res=ar[0];
	printf("%d",res);
	return 0;
}
