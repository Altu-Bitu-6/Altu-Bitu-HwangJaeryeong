#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define endl '\n'

int n, x, y, m;
int count = 0;
int arr[102][102];
int visited[102];

// 시작 값을 bfs 함수에 넣고 방문할 때마다 값을 하나씩 올려준다.
// 마지막에 목표값에 대해 출력하기

void bfs(int x){ // 너비 우선 탐색 : 자신의 자식들부터 순차적으로 탐색
    queue<int> q;
    q.push(x);
    visited[x] = 0;

    while(!q.empty()){
        x = q.front(); // 현재 탐색할 정점을 가져오기 위해 필요
        q.pop();

        for(auto i = 1; i <= n; i++){
            if(arr[x][i] && visited[i] == -1) { // 연결되어있고 방문하지 않은 정점이라면
                visited[i] = visited[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y >> m;

    memset(arr, 0, sizeof(arr)); // 배열 초기화
    memset(visited, -1, sizeof(visited)); // visited 배열 -1로 초기화

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    bfs(x);
    cout << visited[y];

    return 0;
}