#include "../setting/template.h"
#define MAX_SIZE 33333

int inDegree[MAX_SIZE];
vector<int> E[MAX_SIZE];
int N, M;

vector<int> result;
void topologySort()
{
    queue<int> q;
    FOR(i,N+1,1) if(!inDegree[i]) q.push(i);
    FOR(i,N+1,1)
    {
        if (q.empty()) return;
        int now = q.front(); q.pop();
        result.push_back(now);
        FORE(next, E[now]) if (--inDegree[next] == 0) q.push(next);            
    }
}