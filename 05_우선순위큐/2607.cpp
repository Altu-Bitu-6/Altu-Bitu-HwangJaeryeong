#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//기존 문자열의 길이 == 비교 문자열의 길이
// : 두 문자열 한 글자가 달라도 되고, 아예 구성이 같아도 됨
//기존 문자열 길이-1 == 비교 문자열의 길이
// : 비교문자열에 +1
//기존 문자열 길이+1 == 비교 문자열 길이
// : 비교문자열에서 -1

int same(int n){
    string str, com;
    cin >> str;

    int alpha[26] = {0,};
    int len_base = str.size();
    for(int i = 0; i < len_base; i++){
        alpha[str[i] - 'A'] += 1;
    }

    int count = 0;
    for(int i = 0; i < n - 1; i++){
        cin >> com;
        int len_com = com.size();
        int copy_c[26];
        copy(alpha, alpha+26, copy_c); //배열을 복사
        
        int same = 0;
        for(int i = 0; i < len_com; i++){
            if(copy_c[com[i] - 'A'] > 0){
                copy_c[com[i] - 'A']--;
                same++;
            }
        }

        if(len_base == len_com){
            if(same == len_base || same == len_base -1){
                count++;
            }
        }
        else if (len_base - 1 == len_com && same == len_base -1)
            count++;

        else if(len_base + 1 == len_com && same == len_base)
            count++;
        else
            continue;
    }

    cout << count << endl;	
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  same(n);

  return 0;
}