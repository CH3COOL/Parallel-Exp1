#include<cstdio>
int ar[1000010]={1,2,3,4,5,6,7,8,9,10},res,n=10;
int main()
{
	for(int m=n;m>1;m=(m+1)/2)
	{
    	for(int i=0;i<(m+1)/2;i++)
        ar[i]=ar[i*2]+ar[i*2+1];
        ar[(m+1)/2]=0;
    }
	res=ar[0];
	printf("%d",res);
	return 0;
}
