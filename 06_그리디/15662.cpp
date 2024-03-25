#include <iostream>
#include <string>

using namespace std;

#define endl '\n'
#define MAX 1001
int T, k;
int gear[MAX][8];
int ch[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for(int i = 1; i <= T; i++){
        for(int j = 0; j < 8; j++) cin >> gear[i][j];
    }

    cin >> k;

    for(int i = 0; i < k; i++){
        memset(ch, 0, sizeof(ch));
        int a, b;
        cin >> a >> b;
        ch[a] = b;
        for(int j = a; j < T; j++){
            if(gear[j][2] != gear[j+1][6]) ch[j+1] = -ch[j];
            else break;
        }
        for(int j = a; j > 1; j--){
            if(gear[j][6] != gear[j-1][2]) ch[j-1] = -ch[j];
            else break;
        }
        for(int j = 1; j <= T; j++){
            if(ch[j] == 0) continue;
            else if (ch[j] == 1){
                int mp = gear[j][7];
                gear[j][7] = gear[j][6];
                gear[j][6] = gear[j][5];
                gear[j][5] = gear[j][4];
                gear[j][4] = gear[j][3];
                gear[j][3] = gear[j][2];
                gear[j][2] = gear[j][1];
                gear[j][1] = gear[j][0];
                gear[j][0] = mp;
            } else if(ch[j] == -1){
                int mp = gear[j][0];
                gear[j][0] = gear[j][1];
                gear[j][1] = gear[j][2];
                gear[j][2] = gear[j][3];
                gear[j][3] = gear[j][4];
                gear[j][4] = gear[j][5];
                gear[j][5] = gear[j][6];
                gear[j][6] = gear[j][7];
                gear[j][7] = mp;
            }
        }
    }

    int result = 0;
    for(int i = 0; i <= T; i++){
        if(gear[i][0] == 1)
            result += 1;
    }
    cout << result << endl;

 
    return 0;
}
