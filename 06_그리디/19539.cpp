#include <iostream>
#include <algorithm>


using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, sum = 0, count = 0;
    int tree[100000] = {};

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
        sum += tree[i];
        count += tree[i]/2;
    }

    if(sum%3 != 0) {
        cout << "NO" << endl;
    } else{
        if(count >= sum / 3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}
