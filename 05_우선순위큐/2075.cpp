#include <iostream>
#include <queue>


using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solution(int n){
    priority_queue<int, vector<int>, greater<int>> min;
    int t;
    for(int i = 0; i < n*n ; i++){
        cin >> t;
        min.push(t);
        if(min.size() > n) min.pop();
    }
    cout << min.top();
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  solution(n);

  return 0;
}