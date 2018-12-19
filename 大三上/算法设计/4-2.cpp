#include<stdio.h>
#include<fstream>
#include<algorithm>
using namespace std;
int n;
int cmp(int a,int b)
{
	return a>b;
}
int minsum(int a[],int m)
{
    int b[20];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	while(m>1)
	{
		sort(b,b+m);
		b[0]=b[0]+b[1];
		sum+=b[0];
		for(int i=1;i<m-1;i++)
		{
			b[i]=b[i+1];
		}
		m--;
	}
	return sum-n+1;
}
int maxsum(int a[],int m)
{
	int b[20];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	while(m>1)
	{
       sort(b,b+m,cmp);
	   b[0]=b[0]+b[1];
	   sum+=b[0];
	   for(int i=1;i<m-1;i++)
	   {
		   b[i]=b[i+1];
	   }
	   m--;
	}
	return sum-n+1;
}
int main()
{
    ifstream infile("input.txt",ios::in);
	infile>>n;
    int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		infile>>a[i];
	}
	infile.close();

	printf("%d\n",maxsum(a,n));
	printf("%d",minsum(a,n));
	
	ofstream outfile("output.txt",ios::out);
	outfile<<maxsum(a,n)<<"\t"<<minsum(a,n);
	outfile.close();
}