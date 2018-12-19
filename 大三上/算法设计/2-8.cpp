#include<stdio.h>
void swap(int a[],int low1,int high1,int low2,int high2)
{
	int temp;
	while(low1<=high1)
	{
		temp=a[low1];
		a[low1]=a[low2];
		a[low2]=temp;
		low1++;
		low2++;
	}
}
//利用分治算法，每次选择最小的数组进行换位
void patition(int a[],int low,int k,int high)
{
	if(low<high)
	{
		if((k-low+1)==(high-k))
			swap(a,low,k,k+1,high);
		else if((k-low+1)<(high-k))
		{
			swap(a,low,k,low+high-k,high);
			patition(a,low,k,low+high-k-1);
		}
		else
		{
            swap(a,low,high+low-k-1,k+1,high);
			patition(a,high+low-k,k,high);
		}
	}
}
int main()
{
	int i,n,k,a[100];
	printf("输入数组大小\n");
	scanf("%d",&n);
	printf("输入数组内全部数字\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("输入k值，将k前和后的数组换位\n");
	scanf("%d",&k);
	patition(a,0,k-1,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

}