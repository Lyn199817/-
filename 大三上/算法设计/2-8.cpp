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
//���÷����㷨��ÿ��ѡ����С��������л�λ
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
	printf("���������С\n");
	scanf("%d",&n);
	printf("����������ȫ������\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("����kֵ����kǰ�ͺ�����黻λ\n");
	scanf("%d",&k);
	patition(a,0,k-1,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}

}