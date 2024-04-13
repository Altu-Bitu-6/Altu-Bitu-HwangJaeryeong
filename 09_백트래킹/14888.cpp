#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'
int n;
int num[11];
int op[4]; // +, -, ×, ÷
int mini = 1000000001;
int maxi = -1000000001;

void bt(int result, int index){
  if(index == n){
    if(result > maxi) maxi = result;
    if(result < mini) mini = result;
    return;
  }

  for(int i = 0; i < 4; i++){
    if(op[i] > 0){
      op[i]--; // 사용한 연산자 줄여주기
      if(i == 0) bt(result + num[index], index + 1);
      else if(i == 1) bt(result - num[index], index + 1);
      else if(i == 2) bt(result * num[index], index + 1);
      else bt(result / num[index], index + 1);
      op[i]++; // 원상복귀
    }
  }
  return;
}

// 출력 : 만들 수 있는 식의 결과의 최댓값 출력 \n 둘째줄에는 최솟값 출력
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> num[i];
  for(int i = 0; i < 4; i++) cin >> op[i];
  bt(num[0], 1);
  cout << maxi << '\n';
  cout << mini << endl;
}