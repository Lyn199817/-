#include<iostream>
using  namespace std;
int BinarySearch(int a[], int x, int n) {
	//�ҵ�xʱ�������������е�λ�ã����򷵻�-1
    int left = 0;
    int right = n - 1;

    int i = 0;
    int j = 0;
    while (left <= right) {
        int middle = (left + right) / 2;

        if (x == a[middle])
        {
            i = j = middle;
             cout <<"i="<< i<<" "<<"j="<< j<<endl;

            //cout << t; 
            return middle;
        }
        if (x > a[middle])left = middle + 1;
        else { right = middle - 1; }

    }
     i = right;
     j = left;
    cout <<"i="<< i<<" "<<"j="<< j<<endl;
    return -1;  //δ�ҵ�x
}

int main() {
    int n;
    int y;
	cout<<"�������"<<" "<<"���ҵ�����"<<endl;
    cin >> n>> y;
    cout<<"��������������"<<endl;
    int *a = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    BinarySearch(a, y, n);

}
