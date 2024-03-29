#include <iostream>
#include <map>

using namespace std;

int main(){
    int n, m;
    string str;
    int res = 0;
    cin >> n >> m;
    map<string, bool> M;

    for (int i = 0; i < n; i++){
        cin >> str;
        M.insert(pair<string, bool>(str, true));
    }

    for (int i = 0; i < m; i++){
        cin >> str;
        if(M[str]==true)
            res++;
    }
    cout << res;
}