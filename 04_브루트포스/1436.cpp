#include <iostream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <algorithm>
#include <queue>

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
  int endNum = 666; //종말번호
  int n;
  cin >> n;
  int count = 0; //종말번호 업데이트 시켜줄 값
  while(1){
    string numberStr = to_string(endNum);
    //std::string::npos를 사용하면 666을 찾은 경우에 true가 되고 그렇지 않으면 false가 된다.
    if(numberStr.find("666") != std::string::npos){
        count += 1;
        if(count == n) break;
    }
    endNum +=1;
  }
  cout << endNum << endl;

  return 0;
}