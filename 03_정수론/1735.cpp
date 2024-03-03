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

//최대공약수
int gcd(int a, int b){
  while(b){
    a%= b;
    swap(a, b);
  }
  return a;
}

// 두 분수를 더하는 함수
pair<int, int> sumFraction(int n1, int d1, int n2, int d2){
  int lcm = (d1 * d2) / gcd(d1, d2);
  int ans_n = (n1 * (lcm / d1)) + (n2 * (lcm / d2));
  int ans_d = lcm;

  int c_factor = gcd(ans_n, ans_d);
  ans_n = ans_n / c_factor;
  ans_d = ans_d / c_factor;
  
  return make_pair(ans_n, ans_d);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // n1, n2 : 분자 / d1, d2 : 분모
  int n1, d1, n2, d2;
  int ans = 0;
  cin >> n1 >> d1 >> n2 >> d2;

  pair<int, int> answer = sumFraction(n1, d1, n2, d2);
  cout << answer.first << ' ' <<answer.second << endl;

  return 0;
}