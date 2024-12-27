#include "../setting/template.h"

int cost[101][101] = {0};
const int INF = 9999999;

void floyd(int n, int m)
{
    FOR(i,n+1,0)
    {
        FOR(j,n+1,0)
        {
            cost[i][j] = INF;
            //자신에서 자신으로 가는 거리는 0으로 초기화
            if(i == j) cost[i][j] = 0;
        }
    }

    FOR(i,m,0)
    {
        int a,b,c; cin>>a>>b>>c;
        if(cost[a][b] > c) cost[a][b] = c;
    }
    
    //floyd -> 모든 정점에 대해서 생각
    FOR(k,n+1,1) FOR(i,n+1,1) FOR(j,n+1,1) cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    FOR(i,n+1,1)
    {
        FOR(j,n+1,1)
        {
            // 가는 경로가 존재하지 않음 (갈 수 없음)
            if(cost[i][j] >= INF) cout << 0 << " ";
            // 가는 경로가 존재함
            else cout << cost[i][j] << " ";
        }
        cout<<'\n';
    }
}

