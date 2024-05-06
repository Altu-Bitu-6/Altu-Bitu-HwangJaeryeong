#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'
int n, m;
int arr[10];
int num[10];
vector<bool> check(10005);

void backt(int k){ // 현재 k개까지 수를 택했음
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' '; // arr에 기록해둔 수를 출력
    cout << '\n';
    return;
  }
  for(int i = 0; i < n; i++){
      arr[k] = i; // k번째 수를 i로 정함
      backt(k+1); // 다음 수를 정하러 한 단계 더 들어감
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;

  int index = 0;

  while(n--){
    cin >> num[index];
    if(check[num[index]]) continue;
    check[num[index]] = true;
    index++;
  }

  n = index; // 현재 num에는 중복되지 않은 수들만 들어가 있음
  sort(num, num+n);
  
  backt(0);
}