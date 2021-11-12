#include <iostream>
#include <queue>
#include <stack>

using namespace std;
void BFS(int G[][7], int start, int n)
{
    int u = start;
    queue<int> q;
    int visited[7] = {0};
    cout << "First vertex is " << u << endl;
    visited[u] = 1;
    q.push(u);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
            {
                cout << "Vertex visited is " << v << endl;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}
void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    int u = start;
    if (visited[u] == 0)
    {
        cout << "Visited vertex is " << u << endl;
        visited[u] = 1;
        for (int v = 1; v < n; v++)
        {
            if (G[u][v] == 1 && visited[v] == 0)
                DFS(G, v, n);
        }
    }
}

int main(void)
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 0, 0, 0}, {0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 0, 0}, {0, 0, 1, 1, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0}};
    // BFS(G, 4, 7);
    DFS(G, 4, 7);
}
