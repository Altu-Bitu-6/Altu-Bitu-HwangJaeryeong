#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAX 20

int N = 19;
int map[MAX][MAX];
bool visit[MAX][MAX][4];
int dy[] = { 0, 1, 1, 1 };
int dx[] = { 1, 1, 0, -1 };
vector<pair<int, int>> pp;
 
// vector에 넣은 좌표를 정렬
bool sorting(pair<int, int> a, pair<int, int> b) {
    if (a.second >= b.second)
        if (a.second == b.second)
            if (a.first > b.first)
                return false;
            else
                return true;
        else
            return false;
    else
        return true;
}

// 현재 좌표에 대해 박스 밖으로 나가는지?
bool isRight(int y, int x) {
    if (y<1 || x<1 || y>N || x>N) return false;
    return true;
}
 

int checking(int now_y, int now_x, int dir, int val, int cnt) {
    visit[now_y][now_x][dir] = true;
    pp.push_back(make_pair(now_y, now_x));
    
    int next_y = now_y + dy[dir];
    int next_x = now_x + dx[dir];
    // 시작점에 대해 방향성에 대해 탐색 했기 때문에 
    // 해당 함수에서 연속되는 탐색에 대해서는 visit을 확인할 필요 없음, 어차피 false
    if (!isRight(next_y, next_x) || map[next_y][next_x] != val) return cnt;
 
    return checking(next_y, next_x, dir, val, cnt + 1);
}
 
int main() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0)continue;
            // 시작점에 대해 4방향 확인
            // 같은 값에 대해 연속성을 가지면 dfs 탐색
            for (int d = 0; d < 4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];
 
                if (!isRight(ny, nx))continue;
                if (map[ny][nx] == map[i][j] && !visit[i][j][d]) {
                    pp.clear();
                    visit[i][j][d] = true;
                    pp.push_back(make_pair(i, j));
                    if (checking(ny, nx, d, map[i][j], 2) == 5) {
                        sort(pp.begin(), pp.end(), sorting);
                        cout << map[i][j] << endl;
                        cout << pp[0].first << ' ' << pp[0].second;
                        return 0;
                    }
                }
            }
        }
    }
    // 위의 for문에서 return 되지 않는 다면 이긴 돌이 없다는 의미
    cout << 0;
    return 0;
}