#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int longest(const vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int max_length = 0;
    for(int i = 0; i < n; i++) max_length = max(max_length, dp[i]);

    return max_length;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << longest(arr) << endl;

    return 0;
}