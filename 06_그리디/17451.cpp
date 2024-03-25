#include <iostream>

using namespace std;

#define endl '\n'
int n;
int arr[300000] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 뒤에서부터 순회하며 값 찾기
    // 현재 값의 배수이면서 && 이전값보다 큰 최솟값
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long result = arr[n-1];
    for(int i = n-2; i > -1; i--){
        if(arr[i] > result) result = arr[i];
        else if(result % arr[i] != 0){
            result = arr[i] * (result / arr[i] + 1);
        }
    }

    cout << result;
 
    return 0;
}
