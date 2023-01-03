// DFS 구현하기. DFS는 재귀적으로 구현, 그래프는 인접 리스트를 이용하여 구현
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS_recursive(vector<vector<int>> graph, bool *visit, int current_vertex) // DFS를 재귀적으로 구현한 함수
{
    visit[current_vertex] = true;
    cout << current_vertex << " ";
    for(int i = 0; i < graph[current_vertex].size(); i++)
    {
        int next = graph[current_vertex][i];
        if(!visit[next])
            DFS_recursive(graph, visit, next);
    }
}

int main()
{
    int v, e, start;
    cin >> v >> e >> start;
    vector<vector<int>> graph(v + 1);
    bool visit[v + 1] = {false};
    for(int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        graph[src].emplace_back(dst);
        graph[dst].emplace_back(src);
    }
    for(int i = 1; i <= v; i++)
    {
        sort(graph[i].begin(), graph[i].end()); // 인접한 정점이 여러 개인 경우, 작은 정점을 먼저 방문하도록 처리한다. 
    }
    DFS_recursive(graph, visit, start);
    return 0;
}