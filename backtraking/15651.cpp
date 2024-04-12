#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

int k, arr[15], mask[15];

// 주어진 k 개의 수 중에서 6개의 집합을 만드는 것.
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  while(1){
    cin >> k;
    if(k == 0) break;

    for (int i = 0; i < k; i++) cin >> arr[i];
    for(int i = 6; i < k; i++) mask[i] = 1; //뽑히지 않아야 할 원소 표시
    // 6개의 원소를 뽑는 것이므로 mask 배열에서 6번째부터 1로 표시한다.
    do {
        for(int i = 0; i < k; i++){
            if(!mask[i]) cout << arr[i] << ' ';
        } cout << '\n';
    } while(next_permutation(mask, mask + k));
    cout << '\n';
  }
}