// DFS 구현. DFS는 스택을 이용하여 구현하고, 그래프는 인접 리스트를 이용하여 구현한다.
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void DFS_stack(vector<vector<int>> graph, bool *visit, int start) // 스택을 이용하여 DFS를 구현한 함수
{
    stack<int> stack;
    stack.push(start);
    visit[start] = true;
    cout << start << " ";
    while(!stack.empty())
    {
        int current_vertex = stack.top();
        stack.pop();
        for(int i = 0; i < graph[current_vertex].size(); i++)
        {
            int next = graph[current_vertex][i];
            if(!visit[next])
            {
                cout << next << " ";
                visit[next] = true;
                stack.push(next);
                break;
            }
        }
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
    DFS_stack(graph, visit, start);
    return 0;
}
