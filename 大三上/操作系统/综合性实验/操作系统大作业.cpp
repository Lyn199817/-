#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cipan[100]={1,1,1,1,1,1,1,1,1,1};
struct user
{
	char name[20];
	char password[20];
	int id;
}user[10]={{"abc","123",0},{"xyz","123",1}};
//主文件目录
struct MFD
{
	char filename[20]; //文件名
	char mode;   //文件存取权限
	int length;  //文件长度
	int address[4];  //文件地址
}mfd[10][20]={{{"a",'r',3,{0,1,2}},{"b",'w',2,{3,4}}},{{"x",'r',3,{5,6,7}},{"y",'w',2,{8,9}}}};
//用户已打开文件表
struct UOF
{
	char filename[20];//文件名
	char mode;//文件属性
	int length;//文件长度
	char status[10];//状态
	int read;//读指针
	int write;//写指针
}uof[10];
//注册
void regist(){
	int i;
	for(i=0;i<10;i++)
	{
		if(strlen(user[i].name)==0){
			scanf("%s",&user[i].name);
			scanf("%s",&user[i].password);
			scanf("%d",&user[i].id);
			return;
		}
	}
}
int login(){
	int i;
	char name[20];
	char password[20];
	printf("localhost login:\n");
	scanf("%s",&name);
	printf("password:\n");
	scanf("%s",&password);
	for(i=0;i<10;i++)
	{
		if(strcmp(user[i].name,name)==0)
		{
			if(strcmp(user[i].password,password)==0)
				return user[i].id;
		}
		else
		{
			printf("password error\n");
			return -1;
		}
	}
	printf("no user\n");
	return -1;
}
void create(int id){
    int i,j,k;
	char mode;
	char filename[10];
	printf("print user\n");
	scanf("%s",&filename);
	getchar();
	printf("print limit\n");
	scanf("%c",&mode);
	for(i=0;i<20;i++)
	{
		//UFD中有该文件
		if(strcmp(mfd[id][i].filename,filename)==0)
		{
			printf("The filename already exists\n");
			return;
		}
	}
	for(i=0;i<20;i++)
	{
		if(strlen(mfd[id][i].filename)==0)
		{
			for(j=0;j<100;j++)
			{
				if(cipan[j]==0)
					break;
			}
			//登记文件名，文件属性，长度，地址
			strcpy(mfd[id][i].filename,filename);
            mfd[id][i].mode=mode;
			mfd[id][i].length=1;
			mfd[id][i].address[0]=j;
			cipan[j]=1;
			for(i=0;i<10;i++)
			{
				//找一磁盘空闲块
				if(strlen(uof[i].filename)==0)
				{
					strcpy(uof[i].filename,filename);
					uof[i].length=1;
					uof[i].mode=mode;
					strcpy(uof[i].status,"create");
					uof[i].write=j;
					uof[i].read=j;
					printf("create success\n");
					return;
					
				}
			}
		}
	}
}
void write(int id)
{
	int i,j,ms,kuaihao;
	char filename[10];
	printf("print filename:\n");
	scanf("%s",&filename);
	getchar();
	//UFD中已有同名文件
	for(i=0;i<20;i++)
	{
       if(strcmp(mfd[id][i].filename,filename)==0)
		   break;
	}
	//UOF中有无该文件
	for(j=0;j<10;j++)
	{
       if(strcmp(uof[j].filename,filename)==0)
	   {
		   //文件是已建立状态
		   if(strcmp(uof[j].status,"create")==0)
		   {
			   printf("%d\n",uof[j].write);
			   printf("write success!\n");
			   return;
		   }
		   else
		   {
			   //文件属性只读
			   if(uof[j].mode=='r')
			   {
				   printf("file called read-only access can't write\n");
				   return;
			   }
			   else
			   {
				   printf("modify?Y/N\n");
				   scanf("%c",&ms);
				   //顺序修改
				   if(ms=='Y')
				   {
					   printf("%d\n",uof[j].write);
					   printf("write success\n");
					   return;
				   }
				   else
				   {
					   printf("print kuaihao\n");
					   scanf("%d",&kuaihao);
					   printf("%d\n",kuaihao);
					   printf("write success!\n");
					   return;
				   }
			   }
		   }
	   }
	}
	//UOF中没有该文件
	printf("file not create or open!\n");
    return;
}
void open(int id)
{
	int i,j;
	char filename[10];
    printf("print filename:\n");
	scanf("%s",&filename);
	for(i=0;i<20;i++)
	{
		if(strcmp(mfd[id][i].filename,filename)==0)
		{
			for(j=0;j<10;j++)
			{
				if(strcmp(uof[j].filename,filename)==0)
				{
					//该文件正在建立
					if(strcmp(uof[i].status,"create")==0)
					{
						printf("file is creating!\n");
                        return;					
					}
					strcpy(uof[j].status,"open");
					printf("file is opening!\n");
					return;
				}
			}
			for(j=0;j<10;j++)
			{
				if(strlen(uof[j].filename)==0)
				{
					//登记uof
					strcpy(uof[j].filename,filename);
					uof[j].length=mfd[id][i].length;
					uof[j].mode=mfd[id][i].mode;
					//文件属性为打开
					strcpy(uof[j].status,"open");
					uof[j].write=mfd[id][i].address[0];
					uof[j].read=mfd[id][i].address[0];
					printf("open success!\n");
					return;

				}
			}

		}
	}
	printf("files does not exit!\n");
	return;
}
void output(int id)
{
	int i,j;
	for(i=0;i<20;i++)
	{
		if(strlen(mfd[id][i].filename)==0);
		else
		{
			printf("%s\t",mfd[id][i].filename);
			printf("%c\t",mfd[id][i].mode);
			printf("%d\t",mfd[id][i].length);
			for(j=0;j<mfd[id][i].length;j++)
			{
				printf("%d\t",mfd[id][i].address[j]);
			}
			printf("\n");
		}
	}
	for(i=0;i<10;i++){
		if(strlen(uof[i].filename)==0);
		else{
			printf("%s\t",uof[i].filename);
			printf("%c\t",uof[i].mode);
			printf("%d\t",uof[i].length);
			printf("%s\t",uof[i].status);
			printf("%d\t",uof[i].read);
			printf("%d\t",uof[i].write);
			printf("\n");
		}
	}

} 
main(){
	int id,choice,n=1;
	printf("1.regist\t2.login\n");
	scanf("%d",&choice);
	if(choice==1)
		regist();
	while((id=login())==-1);
	while(1){
	printf("1.create\n"); 
	printf("2.open\n"); 
	printf("3.write\n"); 
	scanf("%d",&choice);
		switch(choice){
			case 1:create(id);output(id);break;
			case 2:open(id);output(id);break;
			case 3:write(id);output(id);break;
	}
	}				
}
