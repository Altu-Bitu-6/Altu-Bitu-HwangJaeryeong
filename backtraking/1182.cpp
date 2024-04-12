#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

// 부분 수열의 합
int n, s; // n개의 수가 주어지고, 부분수열의 합이 s인 경우를 출력
int arr[30];
int cnt = 0;
void func(int cur, int tot){
  if(cur == n){
    if(tot == s) cnt++;
    return;
  }
  func(cur+1, tot);
  func(cur+1, tot+arr[cur]); //현재 인덱스의 숫자를 선택하여 부분 수열의 합에 더하는 경우
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  func(0, 0);
  if(s == 0) cnt--; //공집합 제외
  cout << cnt;
}