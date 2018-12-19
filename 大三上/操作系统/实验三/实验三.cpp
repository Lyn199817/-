#include <stdio.h>  
#define N 4
typedef struct table
{    
	int address;//起始
	int length; //长度
	int state;  //标志 
}table;
table tables[N]={{14,12,0},{32,96,0},{0,0,-1},{0,0,-1}};   

//给作业分配主存空间函数 
int fenpei()  
{    
	int i,flag=0; 
	int Xk;
	printf("\n\t\tplease input the length:");//输入申请一个Xk大小分区
	scanf("%d",&Xk);
	for(i=0;i<N;i++)  //循环到申请区域小于或者等于空闲表长度
	{ 
		if(tables[i].state==0 && tables[i].length>Xk) //申请区域小于空闲表长度     
		{     
			tables[i].address=tables[i].address+Xk;   //起始地址加上申请表长度      
			tables[i].length=tables[i].length-Xk;     //新空闲块大小    
			flag=1;    
			return tables[i].address-Xk;    //返回空闲表起始地址   
		}    
		if(tables[i].state==0 && tables[i].length==Xk)  //申请区域等于空闲表长度 
		{      
			tables[i].state=-1;        //非空表上移，删除空表目 
			flag=1;   
			return tables[i].address;    
		}        
	} 
	if(flag==0)       
		return -1;  
}
//释放占用的空间
void huishou()  
{    
	int loc,size;
	int i,j,count=0;
	int mark = 1;
	printf("\n\t\tplease input loc:");
	scanf("%d",&loc);
	printf("\n\t\tplease input size:");
	scanf("%d",&size);
	for(i=0; i<N; i++){
		if(tables[i].address>=loc)
		{	
			mark = 0;
			//分区R在F2之下
			if(tables[i-1].address+tables[i-1].length>=loc){
				//分区R在F1之上
				if(tables[i].address<=loc+size){
					if(tables[i].address<loc+size){
						printf("\n\t\tallocation !\n");
						return ;
					}
					//分区R与F1上相邻
					else{
						//修改F1的长度为原来F1+F2的长度，F1的地址为原来F2的地址
						tables[i].length = tables[i].address + tables[i].length - tables[i-1].address;
						tables[i].address = tables[i-1].address;
						tables[i-1].address=0;
						tables[i-1].length=0;
						tables[i-1].state=0;
					}
				}
				//分区R与F2下相邻
				else if(tables[i-1].address+tables[i-1].length<=loc){
					//更新F2的长度加上分区R的长度
					tables[i-1].length+=size;
					tables[i-1].state=0;
				}
				//分区R在F1之上，F2之下，且F2的末地址大于等于R的末地址
				else if((tables[i-1].address<=loc)&&(tables[i-1].address+tables[i-1].length>=loc+size)){
					printf("\n\t\tallocation !\n");
				}
				//分区R在F2中
				else{
					tables[i-1].length = loc+size - tables[i-1].address; //F2的长度等于R分区和F2分区大小之和
					tables[i-1].state=0;
				}
			}
			//分区R在F1之上
			else if((tables[i].address>loc)&&(tables[i].address>loc+size)){
				//空闲表删除F1
				for(j=N-1; j>=i; j--){
					tables[j+1] = tables[j];
				}
				tables[i].address =loc;
				tables[i].length = size;
				tables[i].state=0;
			}
			else if((tables[i].address>=loc)&&(tables[i].address>loc+size)){
				size = tables[i].address-loc;
				tables[i].length = size + tables[i].length;
				tables[i].address = loc;	
				tables[i].state=0;
				}
			//分区R在F1之下
			else if(tables[i].address<=loc+size){
				if(tables[i].address<loc+size){
					printf("aladdressated !\n");
					return ;
				}
				//分区R与F1下相邻
				else{
			  		size = tables[i].address-loc;
					tables[i].length = size + tables[i].length;
					tables[i].address=loc;
					tables[i].state=0;
				}
			}
			else {
				printf("\n\t\t\tallocation !\n");
				return ;
			}		
			printf("\t\t\tsucceeds.\n");
			break;
		}
	}
	if(mark==1){
		for(i=0; i<N; i++){
			if((tables[i].address!=0)&&(tables[i].length!=0)&&(tables[i].state==0))
				continue;
			else{
				tables[i].address = loc;
				tables[i].length = size;
				tables[i].state = 0;
				printf("\n\t\tsucceeds.\n");
				break;
			}
		}
	}
}    

//打印空闲分区表 
void print() 
{ 
	int i; 
	printf("\n\n\t     start(始址)     length（长度）    state（标志位）      \n");  
	for(i=0;i<N;i++)  
	{ 
	  printf("\t     %8d        %8d         %8d            \n",tables[i].address,tables[i].length,tables[i].state);  
	} 
} 
main() 
{ 
	int m;
	print();
	while(1)
	{
		printf("\n\n\t\t************table*********\n");
		printf("\t\t1.fenpei\n");
		printf("\t\t2.huishou\n");
		printf("\t\t************end***********\n");
		printf("\t\tinput your choice:");
		scanf("%d",&m);

		switch(m)
		{
		case 1:fenpei();print();break;
		case 2:huishou();print();break;
		}
	}
}

