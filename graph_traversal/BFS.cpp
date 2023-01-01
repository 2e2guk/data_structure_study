// BFS 구현하기 - 그래프는 인접 행렬을 이용하여 구현한다. 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // std::fill 의 헤더

using namespace std;
void BFS(vector<vector<int>> graph, bool *visit, int start)
{
    queue<int> queue;
    visit[start] = true;
    queue.push(start);
    while(!queue.empty())
    {
        int current_vertex = queue.front();
        queue.pop(); 
        cout << current_vertex << " "; // BFS 그래프 순회 순서 출력.

        for(int i = 0; i < graph[current_vertex].size(); i++) // 현재 정점과 인접한 정점들에 대하여, 
        {
            int next = graph[current_vertex][i];
            if(!visit[next]) // 만약 인접한 정점을 방문하지 않았다면, 방문 처리를 하고, 큐에 해당 정점을 push한다. 
            {
                visit[next] = true;
                queue.push(next);
            }
        }
    }

}

int main()
{
    int v, e, start; //  그래프의 정점의 개수 v, 간선의 개수 e, 시작 정점 start
    cin >> v >> e >> start;
    vector<vector<int>> graph(v + 1); // 그래프 vector(인접 행렬)
    bool visit[v + 1] = {false}; // 정점을 방문했는지를 체크하는 bool 타입 배열
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
    BFS(graph, visit, start);
    return 0;
}