#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

int n;
int s[10], w[10];
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수


void func(int k){ //k번째 계란으로 다른 걸 깰 차례
    if(k == n){
        mx = max(mx, cnt);
        return;
    }

    if(s[k] <= 0 || cnt == n-1){ //자기가 깨졌거나 자기 빼고 다 깨졌을 때
        func(k+1);
        return;
    }

    for(int t = 0; t < n; t++){ // t번째 계란을 내리치고 싶다.
        if(t == k || s[t] <= 0) continue;
        s[k] = s[k] - w[t];
        s[t] = s[t] - w[k];
        if(s[k] <= 0) cnt++;
        if(s[t] <= 0) cnt++;
        func(k+1);
        if(s[k] <= 0) cnt--;
        if(s[t] <= 0) cnt--;
        s[k] += w[t];
        s[t] += w[k];
    }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i] >> w[i];
  func(0);
  cout << mx;

  return 0;
}