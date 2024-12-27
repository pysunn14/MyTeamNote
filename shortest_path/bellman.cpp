#include "../setting/template.h"

ll INF = 1e9;

bool bellman(int START, int N, const vector<pair<pii,ll>>& v, ll dist[])
{
    for (int i = 1; i <= N-1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int from = v[j].first.first;
            int to = v[j].first.second;
            int cost = v[j].second;

            if (dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }
    
    // more change : minus edge detecting!
    for (int j = 0; j < v.size(); j++)
    {
        int from = v[j].first.first;
        int to = v[j].first.second;
        int cost = v[j].second;

        if (dist[to] > dist[from] + cost) return true;
    }
    return false;
}