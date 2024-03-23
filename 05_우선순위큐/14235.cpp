#include <iostream>
#include <queue>

using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  priority_queue<int> maxHeap;

  int n;
  cin >> n;

  while(n--){
    int a;
    cin >> a;
    if(a == 0) {
        if(maxHeap.empty()){cout << -1 << endl;}
        else{
            int large = maxHeap.top();
            maxHeap.pop();
            cout << large << endl;
        }
    }
    else{
        while(a--){
            int num;
            cin >> num;
            maxHeap.push(num);
        }
    }
  }
  

  return 0;
}