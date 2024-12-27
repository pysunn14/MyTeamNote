#include "../setting/template.h"

#define x first
#define y second
#define pll pair<ll,ll>

ll ccw(pll a, pll b, pll c)
{
    return (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
}

double dist(pll a, pll b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool ccw_cmp(pll a, pll b, pll o)
{
    ll c = ccw(o, a, b);
    if (c != 0) return c > 0;
    return dist(o, a) < dist(o, b);
}