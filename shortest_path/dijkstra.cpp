#include "../setting/template.h"

vector<pii> v[20202]; // {cost, next} edge[x] : x를 시작점으로 하는 {거리,도착점} 의 집합 모음
int INF = 999999;
int dis[20202];

int V,E;
void dijkstra(int start)
{
    priority_queue<pii> pq; //cost, next
    pq.push({0, start}); // 자기 자신으로 가는 비용은 0
    dis[start] = 0; 

    //pq가 빌때까지 반복
    while (!pq.empty())
    {
        // now : 거리가 가장 짧은 정점
        int dist = -pq.top().first; //now로 가는 비용
        int now = pq.top().second; //정점
        pq.pop();

        //이미 최단거리 존재 시 skip
        if (dist > dis[now]) continue;

        // now를 시작점으로 하는 연결된 다른 모든 간선들에 대해서 확인
        for (int i = 0; i < v[now].size() ; i++)
        {
            int nextcost = v[now][i].first;
            int next = v[now][i].second;

            // 출발점 -> next 로 바로 가는 것 보다, 출발점 -> now -> next로 거쳐 가는 거리가 더 짧을 경우 갱신
            if (dis[next] > dis[now] + nextcost)
            {
                dis[next]  = dis[now] + nextcost;
                //우선순위 큐 삽입
                pq.push({-dis[next], next}); 
            }
        }
    }

    FOR(i,V+1,1)
    {
        if (dis[i] == INF) cout <<"INF\n";
        else cout << dis[i]<<'\n';
    }
}