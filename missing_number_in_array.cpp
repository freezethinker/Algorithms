#include <iostream>

using namespace std;

int cal_miss (int a[], int n) {
    int to_be_sum = (n+1)*(n+2)/2;
    for(int i = 0; i < n; i++)
        to_be_sum -= a[i];
    return to_be_sum;
}

int main()
{
    int a[] = {1, 2, 3, 4, 6};
    int n = sizeof(a)/sizeof(a[0]);
    int missing_no = cal_miss(a,n);
    cout<<"Missing number: "<<missing_no;
}
