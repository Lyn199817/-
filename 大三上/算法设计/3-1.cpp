#include<iostream>
using namespace std;
#define MAX(a,b) a>b?a:b

void getSLIS(int* f, int* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i] = 1;//初始化每个子序列长度为1
        for (int j = 0; j < i; j++)
        {
            int k = 0;
            if (f[i]>f[j] && s[i] + 1>s[j])//更新条件
            {
                s[i] = s[j] + 1;//更新
            }
        }
    }
}

int main()
{
    int father[10] = { 6, 7, 5, 6, 7, 8, 9, 10, 1,3 };//n元素的数组
    int n = sizeof(father) / sizeof(father[0]);//数组大小
    int sub[10] = { 0 };//0到{0,1,2,3,4,5，，，n}区间的大小
    getSLIS(father,sub,n);//获取子序列长度
    int lensub = 0;
    cout << "以下是每个区间更新得到子序列长度:" << endl;
    for (int i = 0; i < n; i++)//遍历sub，找出最大子序列长度
    {
        cout << sub[i] << " ";//打印更于sub中的子序列长度
        lensub = MAX(lensub, sub[i]);//选出最长的子序列
    }
    cout << endl;
    cout << "输出子序列长度:" << endl;
    cout << lensub << endl;
    cout << endl;
}
