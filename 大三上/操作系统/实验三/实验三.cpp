#include <stdio.h>  
#define N 4
typedef struct table
{    
	int address;//��ʼ
	int length; //����
	int state;  //��־ 
}table;
table tables[N]={{14,12,0},{32,96,0},{0,0,-1},{0,0,-1}};   

//����ҵ��������ռ亯�� 
int fenpei()  
{    
	int i,flag=0; 
	int Xk;
	printf("\n\t\tplease input the length:");//��������һ��Xk��С����
	scanf("%d",&Xk);
	for(i=0;i<N;i++)  //ѭ������������С�ڻ��ߵ��ڿ��б���
	{ 
		if(tables[i].state==0 && tables[i].length>Xk) //��������С�ڿ��б���     
		{     
			tables[i].address=tables[i].address+Xk;   //��ʼ��ַ�����������      
			tables[i].length=tables[i].length-Xk;     //�¿��п��С    
			flag=1;    
			return tables[i].address-Xk;    //���ؿ��б���ʼ��ַ   
		}    
		if(tables[i].state==0 && tables[i].length==Xk)  //����������ڿ��б��� 
		{      
			tables[i].state=-1;        //�ǿձ����ƣ�ɾ���ձ�Ŀ 
			flag=1;   
			return tables[i].address;    
		}        
	} 
	if(flag==0)       
		return -1;  
}
//�ͷ�ռ�õĿռ�
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
			//����R��F2֮��
			if(tables[i-1].address+tables[i-1].length>=loc){
				//����R��F1֮��
				if(tables[i].address<=loc+size){
					if(tables[i].address<loc+size){
						printf("\n\t\tallocation !\n");
						return ;
					}
					//����R��F1������
					else{
						//�޸�F1�ĳ���Ϊԭ��F1+F2�ĳ��ȣ�F1�ĵ�ַΪԭ��F2�ĵ�ַ
						tables[i].length = tables[i].address + tables[i].length - tables[i-1].address;
						tables[i].address = tables[i-1].address;
						tables[i-1].address=0;
						tables[i-1].length=0;
						tables[i-1].state=0;
					}
				}
				//����R��F2������
				else if(tables[i-1].address+tables[i-1].length<=loc){
					//����F2�ĳ��ȼ��Ϸ���R�ĳ���
					tables[i-1].length+=size;
					tables[i-1].state=0;
				}
				//����R��F1֮�ϣ�F2֮�£���F2��ĩ��ַ���ڵ���R��ĩ��ַ
				else if((tables[i-1].address<=loc)&&(tables[i-1].address+tables[i-1].length>=loc+size)){
					printf("\n\t\tallocation !\n");
				}
				//����R��F2��
				else{
					tables[i-1].length = loc+size - tables[i-1].address; //F2�ĳ��ȵ���R������F2������С֮��
					tables[i-1].state=0;
				}
			}
			//����R��F1֮��
			else if((tables[i].address>loc)&&(tables[i].address>loc+size)){
				//���б�ɾ��F1
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
			//����R��F1֮��
			else if(tables[i].address<=loc+size){
				if(tables[i].address<loc+size){
					printf("aladdressated !\n");
					return ;
				}
				//����R��F1������
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

//��ӡ���з����� 
void print() 
{ 
	int i; 
	printf("\n\n\t     start(ʼַ)     length�����ȣ�    state����־λ��      \n");  
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

