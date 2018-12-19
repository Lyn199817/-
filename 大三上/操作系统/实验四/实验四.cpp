#include "stdio.h"
#include "string.h"
#define size 1024
#define N 12
typedef struct
{
	int page;
	int flag;
	int block;
	int mark;
}table;

typedef struct
{
	char operation;
	int page;
	int address;
}list;
table table1[7]={
					{0,1,5,0},{1,1,8,0},{2,1,9,0},
					{3,1,12,0},{4,0,0,0},{5,0,0,0},
					{6,0,0,0}
				};
list table2[N]={
					{'+',0,70},{'+',1,50},{'*',2,15},
					{'S',3,21},{'l',0,56},{'-',6,40},
					{'M',4,53},{'+',5,23},{'S',1,37},
					{'L',2,78},{'+',4,10},{'S',6,48}
				};

int vec[5]={0};	
int flg[5]={0};

int main(){
	int m,n;
	int i,j,k=0,pos,page,flag,memaddress;
	int mark;
	for(i=0;i<N;i++)
	{
		mark=0;
		page=table2[i].page;
		flag=table1[page].flag;
		if(i<4)
		{
			for(j=i;j>=0;j--)
			{
				vec[j]=vec[j-1];
			}
			vec[0]=page;
			flag=1;
			if(table2[i].operation=='S')
			{
				table1[page].mark=1;
			}
		}
		else
		{
			for(j=0;j<4;j++)
			{
				if(page==vec[j])
				{
					mark=1;	
					pos=j;
					break;
				}
			}
			if(mark)
			{
				for(j=pos+1;j>=0;j--)
				{
					vec[j]=vec[j-1];
				}
				vec[0]=page;
			}
			else
			{
				for(j=4;j>=0;j--)
				{
					vec[j]=vec[j-1];
				}
				pos=vec[4];
				table1[page].block=table1[pos].block;
				table1[page].flag=table1[pos].flag;
				table1[pos].flag=0;
				table1[pos].mark=0;
				table1[pos].block=0; 
				vec[0]=page;
				
				if(table2[i].operation=='S')
				{
					table1[page].mark=1;
				}

				for(m=0;m<4;m++)
				{
					printf("%d\t",vec[m]);
				}
				printf("\n");
			}
			for(n=0;n<4;n++)
			{
				printf("%d\t",vec[n]);
			}
			printf("");
		}
		if((table2[i].page<7)&&i>3)
		{
			memaddress=table1[page].block*size+table2[i].address;
			printf("页号为%d 的操作是 %c ,它的物理地址为 ：%ld\n",table1[page].page,table2[page].operation,memaddress);
		}
		
	}
	return 0;
}
