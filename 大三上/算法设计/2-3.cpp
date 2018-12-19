#include<iostream>
using  namespace std;
int BinarySearch(int a[], int x, int n) {
	//找到x时返回其在数组中的位置，否则返回-1
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
    return -1;  //未找到x
}

int main() {
    int n;
    int y;
	cout<<"数组个数"<<" "<<"查找的数字"<<endl;
    cin >> n>> y;
    cout<<"数组内所有数字"<<endl;
    int *a = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    BinarySearch(a, y, n);

}
