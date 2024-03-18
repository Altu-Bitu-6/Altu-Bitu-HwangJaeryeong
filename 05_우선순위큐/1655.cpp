#include <iostream>
#include <queue>


using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int findMin(int n){
    while(n--){
        int num, answer;
        cin >> num;

        if(maxHeap.empty() || num < maxHeap.top()){
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // 힙의 크기 조정하여 중간값 계산
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (maxHeap.size() > minHeap.size()){
            cout << maxHeap.top() << endl;
        } else if (maxHeap.size() < minHeap.size()){
            cout << minHeap.top() << endl;
        } else if(maxHeap.size() == minHeap.size()){
            cout << min(maxHeap.top(), minHeap.top()) << endl;
        }
    }
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  findMin(n);

  return 0;
}