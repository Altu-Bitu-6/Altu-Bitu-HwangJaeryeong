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

const int MAX = 1000000;
vector<bool> is_prime(MAX+1, true); 

//소수 찾기
void isPrime(){
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= sqrt(MAX); ++i){
        if(is_prime[i]){
            for(int j = i * i; j <= MAX; j += i){
            is_prime[j] = false;
            }
        }
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  isPrime();

  // 1. 소수이고 && 홀수라면 -> isPrime 했을 때 존재하고 2씩 증가시키면서 홀수만 !
  // 2. 그 중 가장 앞에 있는 홀수 = a, n-a = b 해서 출력해주기

  while(1){
    int n;
    cin >> n;
    if(n == 0) break;

    bool pick = false;
    for(int i = 3; i <= n; i += 2){
        if(is_prime[i] && is_prime[n-i]){
            cout << n << " = " << i <<  " + "  << n - i << endl;
            pick = true;
            break;
        }
    }

    if(!pick){
        cout << "Goldbach's conjecture is wrong." << endl;
    }


    
  }

  return 0;
}