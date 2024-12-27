#include "../setting/template.h"

const int sz = 101010;
ll A[sz];
ll tree[4 * sz];

ll init(int lo, int hi, int node)
{
    if (lo == hi) return tree[node] = A[lo];                                              
    return tree[node] = init(lo, mid, node * 2) + init(mid + 1, hi, node * 2 + 1); 
}

ll query(int lo, int hi, int node, int left, int right)
{
    if (left > hi || right < lo) return 0;
    if (left <= lo && hi <= right) return tree[node];
    return query(lo, mid, node * 2, left, right) + query(mid + 1, hi, node * 2 + 1, left, right);
}

void update(int lo, int hi, int node, int idx, ll value)
{
    if (idx < lo || idx > hi) return;
    if (lo == hi) tree[node] = value;
    else
    {
        update(lo, mid, node * 2, idx, value);
        update(mid + 1, hi, node * 2 + 1, idx, value); 
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

ll count_inversion(int n)
{
    FOR(i, n + 1, 1) cin >> A[i];
    vector<pii> v;
    FOR(i, n + 1, 1)
    v.push_back({A[i], i});

    sort(all(v));
    FOR(i, n + 1, 1)
    v[i].first = i;

    reverse(all(v));

    ll cnt = 0;
    FORE(e, v)
    {
        int value = e.second;
        cnt += query(1, n, 1, 1, value - 1);
        update(1, n, 1, value, 1);
    }
    
    return cnt;
}