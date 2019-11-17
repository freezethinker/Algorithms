/**
Solution for Code Forces: Balanced Rating Changes
https://codeforces.com/contest/1237/problem/A
**/

#include <iostream>

using namespace std;

int main()
{
    int n, sum = 0, a;
    bool toggle = true;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a;
        if(a % 2 == 0) cout<<(a/2)<<endl;
        else {
            if (toggle) cout<<(a+1)/2<<endl;
            else cout<<(a-1)/2<<endl;
            toggle ^= true;
        }
    }
}