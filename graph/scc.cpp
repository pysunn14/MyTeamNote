#include "../setting/template.h"

const int SIZE = 10000;

vector<int> graph[2 * SIZE + 1];
vector<int> rev_graph[2 * SIZE + 1];
vector<int> order;

bool vis[2 * SIZE + 1];
int SCC[2 * SIZE + 1];
int SCC_IDX;

void dfs(int n)
{
    vis[n] = true;  
    FORE(next, graph[n]) if(!vis[next]) dfs(next);
    order.push_back(n);
}

void rev_dfs(int n)
{
    vis[n] = true;
    FORE(next, rev_graph[n]) if(!vis[next]) rev_dfs(next);
    SCC[n] = SCC_IDX;
}

bool kosaraju(int N, int M)
{
    FOR(i,M+1,1) if(!vis[i]) dfs(i);
    FOR(i,SIZE + M + 1, SIZE + 1) if(!vis[i]) dfs(i);

    fill(vis, vis + 2*SIZE+1, 0);
    reverse(all(order));
    
    //reverse dfs
    FORE(i, order)
    {
        if(!vis[i])
        {
            // SCC그룹 설정
            rev_dfs(i);
            SCC_IDX++;
        }
    }
}