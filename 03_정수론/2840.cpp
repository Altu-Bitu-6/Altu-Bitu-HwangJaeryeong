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

int n, k;
void setting(vector<char> &lucky) {
	for (int i = 0; i < n; i++) {
		lucky[i] = '?';
	}
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  vector<char> lucky(n);
  setting(lucky);
  int index;
  for(int i = 0; i < k; i++){
    int s; char alpha;
    cin >> s >> alpha;
    if(i == 0) {lucky[0] = alpha; index = 0; continue;}
    index = (s + index) % n;
    if(lucky[index] != '?' && lucky[index] != alpha){
        cout << "!";
        return 0;
    }
    else
        lucky[index] = alpha;
  }

  //중복인지 아닌지 확인
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        if(lucky[i] != '?' && lucky[i] == lucky[j]){
            cout << "!";
            return 0;
        }
    }
  }
  for(int i = 0; i < n; i++){
    cout << lucky[index];
    index--;
    if (index == -1) index = n - 1;
  }

  return 0;
}