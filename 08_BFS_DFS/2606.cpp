#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

vector<vector<int>> adj; // 인접 리스트; 그래프를 표현한 것
// -> adj[node]는 현재 노드와 연결된 다른 노드들의 리스트를 나타낸다.
vector<bool> visited; //방문한 노드를 표시하기 위한 배열

// 깊이 우선 탐색 : 재귀적인 방식이나 스택을 이용하여 그래프를 탐색
void dfs (int node){
    visited[node] = true; //visit 배열에 현재 노드의 인덱스를 true로 설정
    // 현재 노드와 연결된 모든 노드들을 탐색
    for(int i = 0; i < adj[node].size(); i++){
        int nextNode = adj[node][i];
        if(!visited[nextNode]) dfs(nextNode);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int com, net;
    cin >> com >> net;

    adj.resize(com + 1);
    visited.resize(com + 1, false);

    for(int i = 0; i < net; i++){
        int from, to;
        cin >> from >> to;
        // 양방향 연결이므로 양쪽에 추가
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    dfs(1); // 1번 컴퓨터를 시작으로 dfs 실행

    int countVirus = count(visited.begin(), visited.end(), true) - 1; // 1번 컴퓨터는 제외
    
    cout << countVirus << endl;

    return 0;
}