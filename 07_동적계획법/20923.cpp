#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> doo(n);
    deque<int> su(n);

    for(int i = 0; i < n; i++){
        cin >> doo[i] >> su[i];
    }

    deque<int> doodoo;
    deque<int> susu;

    bool doo_turn = true;
    int count = 0;
    string win = "";

    while(1){
        count++;
        if(doo_turn){
            doodoo.push_back(doo.back()); //도도 카드 내려놓기
            doo.pop_back();
        } else {
            susu.push_back(su.back());
            su.pop_back();
        }

        //0개인지 아닌지
        if(doo.size() == 0){
            win = "su";
            break;
        } else if(su.size() == 0){
            win = "do";
            break;
        }

        // 수연 : 종치기
        if(doodoo.size() != 0 && susu.size() != 0 && doodoo.back() + susu.back() == 5){
            while(doodoo.size() > 0){
                su.push_front(doodoo.front());
                doodoo.pop_front();
            }
            while(susu.size() > 0){
                su.push_front(susu.front());
                susu.pop_front();
            }
        }
        // 도도 : 종치기
        else if(doodoo.size() != 0 && doodoo.back() == 5 || susu.size() != 0 && susu.back() == 5){
            while(susu.size() > 0){
                doo.push_front(susu.front());
                susu.pop_front();
            }while(doo.size() > 0){
                doo.push_front(doodoo.front());
                doo.pop_front();
            }
        }

        if(count == m){
            int answer = doo.size() - su.size();
            if(answer < 0){
                win = "su";
            } else if (answer > 0){
                win = "do";
            } else {
                win = "dosu";
            } break;
        }

        doo_turn = !doo_turn; // 차례 변경
    }

    cout << win;

    return 0;
}