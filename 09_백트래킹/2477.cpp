#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int dd[6];
    int arr[6];
    vector<bool> mFlag(6);
    for(int i = 0; i < 6; i++){
        cin >> dd[i] >> arr[i];
    }
    int max_w = 0, max_h = 0; // 너비, 높이
    int d1, d2;
    for(int i = 0; i < 6; i++){
        if(i % 2 == 0){
            if(max_w < arr[i]){
                max_w = arr[i];
                d1 = i;
            }
        }
        else{
            if(max_h < arr[i]){
                max_h = arr[i];
                d2 = i;
            }
        }
    }

    mFlag[d1] = 1;
    mFlag[d2] = 1;

    int mini = 1;
    for(int i = 0; i < 6; i++){
        if(mFlag[i] == 1) continue;
        if(i == 0){
            if (mFlag[i + 1] == 0 && mFlag[5] == 0) mini *= arr[i];
        } else if (i == 5) {
            if(mFlag[0] == 0 && mFlag[i-1] == 0) mini *= arr[i];
        } else{
            if(mFlag[i-1] == 0 && mFlag[i+1] == 0) mini *= arr[i];
        }
    }

    cout << (max_w * max_h - mini) * k << endl;

    return 0;
}
