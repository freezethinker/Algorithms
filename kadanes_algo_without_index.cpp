#include <iostream>

using namespace std;

int maxsum (int a[], int n) {
    int sum_here = 0, max_sum = 0;
    int start = 0, end = 0;
    for(int i = 0; i<n; i++) {
        sum_here += a[i];
        sum_here = (sum_here < 0) ? 0 : sum_here;
        max_sum = (sum_here > max_sum) ? sum_here : max_sum;
    }
    cout<<max_sum;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    maxsum(a,n);
    return 0;
}

