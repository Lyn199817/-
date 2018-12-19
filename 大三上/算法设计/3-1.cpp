#include<iostream>
using namespace std;
#define MAX(a,b) a>b?a:b

void getSLIS(int* f, int* s, int n)
{
    for (int i = 0; i < n; i++)
    {
        s[i] = 1;//��ʼ��ÿ�������г���Ϊ1
        for (int j = 0; j < i; j++)
        {
            int k = 0;
            if (f[i]>f[j] && s[i] + 1>s[j])//��������
            {
                s[i] = s[j] + 1;//����
            }
        }
    }
}

int main()
{
    int father[10] = { 6, 7, 5, 6, 7, 8, 9, 10, 1,3 };//nԪ�ص�����
    int n = sizeof(father) / sizeof(father[0]);//�����С
    int sub[10] = { 0 };//0��{0,1,2,3,4,5������n}����Ĵ�С
    getSLIS(father,sub,n);//��ȡ�����г���
    int lensub = 0;
    cout << "������ÿ��������µõ������г���:" << endl;
    for (int i = 0; i < n; i++)//����sub���ҳ���������г���
    {
        cout << sub[i] << " ";//��ӡ����sub�е������г���
        lensub = MAX(lensub, sub[i]);//ѡ�����������
    }
    cout << endl;
    cout << "��������г���:" << endl;
    cout << lensub << endl;
    cout << endl;
}
