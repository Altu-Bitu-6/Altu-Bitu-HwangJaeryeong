#include <iostream>
#include <vector>
#include <algorithm>

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
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a, b;
    vector <pair<int,int>> vc(n);
    for (int i = 0; i < n; i++) {
      cin >> vc[i].first >> vc[i].second;
    }
    // 정렬 시 첫번 째 원소 기준으로 정렬이 되고, 같으면 두번째 원소 적용
    sort(vc.begin(), vc.end());
    int top = vc[0].se, ans=1;
    for(int i=1; i<n; i++){
        if(top>vc[i].se){
            top = vc[i].se;
            ans++;
        }
    }
    cout << ans << endl;
  }

  return 0;
}