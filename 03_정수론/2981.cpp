#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}


// 어떤 수 A, B가 있을 때 M로 나눈 나머지가 항상 R이라면?
// (A-R), (B-R)을 M로 나눈 나머지는 0이라는 말과 같음.
// M가 될 수 있는 수는 ..? (A-R), (B-R)의 공약수 !!!! -> 최대공약수의 약수
// 주어진 수의 연속된 차이의 최대공약수 구하기
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> arr;
  queue<int> result;
  int n;
  cin >> n;
  arr.resize(n);
  for(int i = 0; i < n; i++) 
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  
  int gcd_first = arr[1] - arr[0];
  for(int i = 2; i < n; i++)
    gcd_first = gcd(gcd_first, arr[i] - arr[i-1]);

  vector<int> v_gcd;
  for (int i=1; i<=gcd_first; i++){
        if (gcd_first%i==0){
            if (i>gcd_first/i) break; 
            v_gcd.push_back(i);
            if (i==gcd_first/i) break;
            v_gcd.push_back(gcd_first/i);
        }
    }

  sort(v_gcd.begin(), v_gcd.end(), greater<int>());

  while(!v_gcd.empty()){
    if(v_gcd.back()!=1) cout << v_gcd.back() << " ";
    v_gcd.pop_back();
  }

  return 0;
}