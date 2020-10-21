#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void findKthMin(vector<int> vector, int k)
{
    // priority queues use a heap to store internally.

    priority_queue<int, std::vector<int>,
        std::greater<> > pq(vector.begin(), vector.end());

    while (--k) {
        pq.pop();
    }

    cout << pq.top();
}

int main()
{
    vector<int> vector = { 1, 3, 5, 7, 2, 4, 6, 8 };
    int k = 3;

    findKthMin(vector, k);
    return 0;
}
