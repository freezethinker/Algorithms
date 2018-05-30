#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find_duplicates(int a[], int n) {
    unordered_set<int> distinct_set;
    unordered_set<int> duplicate_set;
    
    for(int i = 0; i < n; i++) {
        if(distinct_set.find(a[i]) == distinct_set.end())
            distinct_set.insert(a[i]);
        else
            duplicate_set.insert(a[i]);
    }
    
    unordered_set<int> :: iterator iter;
    for(iter = duplicate_set.begin(); iter != duplicate_set.end(); iter++)
        cout<<*iter;
}

int main()
{
    int a[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5, 3};
    int n = sizeof(a)/sizeof(a[0]);
    find_duplicates(a, n);
    return 0;
}

