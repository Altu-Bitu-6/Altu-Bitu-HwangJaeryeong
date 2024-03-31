#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int>> minHeap;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, size;
        cin >> a;
        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(a);
        }
        else {
            minHeap.push(a);
        }
        if (!maxHeap.empty()&&!minHeap.empty()&&maxHeap.top()>minHeap.top()) {
            int max_val, min_val;
            max_val = maxHeap.top();
            min_val = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(min_val);
            minHeap.push(max_val);


        }
        cout << maxHeap.top() << '\n';
    }



    return 0;
}