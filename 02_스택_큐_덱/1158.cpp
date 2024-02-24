#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
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

  int n, k;
  cin >> n >> k;

  queue<int> q;
  for(int i = 1; i <= n; i++){
    q.push(i); //1, 2, 3, 4, 5, 6, 7
  }
  cout << "<";
  while(q.size() > 1){
    for(int i = 0; i < k-1; i++){
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << q.front() << ">\n";
}