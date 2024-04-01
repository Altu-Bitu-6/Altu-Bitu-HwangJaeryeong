#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> stairs(n);
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++) cin >> stairs[i];

    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i], dp[i-2] + stairs[i]);
    }

    cout << dp[n-1] << endl;

    return 0;
}