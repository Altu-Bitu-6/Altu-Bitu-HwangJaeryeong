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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x;
  cin >> n;
  int arr[21] = {0};

  while(n--){
    string active = "";
    cin >> active;
    if(active == "add"){
        cin >> x;
        if(arr[x] == 0){
            arr[x] = 1;
        }
    }

    else if (active == "check"){
        cin >> x;
        if(arr[x] == 0){
            cout << "0" << endl;
        }  else {
            cout << "1" << endl;
        }
    }

    else if(active == "toggle"){
        cin >> x;
        if(arr[x] == 1){
            arr[x] = 0;
        } else {
            arr[x] = 1;
        }
    }

    else if(active == "remove"){
        cin >> x;
        if (arr[x] == 1){
            arr[x] = 0;
        }
    }

    else if(active == "all"){
        fill (arr+1, arr+21, 1);
    }

    else if(active == "empty"){
        fill (arr+1, arr+21, 0);
    }
  }

  return 0;
}