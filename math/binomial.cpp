#include "../setting/template.h"

const ll mod = 1e9 + 7;
const int sz = 400000;

ll fact[sz];
ll inv_fact[sz];

// fast mul
ll fp(ll a, ll b)
{
    if(b == 1) return a % mod;
    if(b % 2 == 0) 
    {
        ll res = fp(a, b/2) % mod; 
        return ( res % mod * res % mod ) % mod;
    }
    if(b % 2 == 1) return ((a % mod) * (fp(a, b - 1) % mod)) % mod;
}

//nCr
ll binomial(int n, int r)
{
    return (((fact[n] % mod ) * (inv_fact[r] % mod))) % mod * (inv_fact[n-r] % mod) % mod;
}

void fastFactorial(int n)
{
    fact[0] = fact[1] = 1;
    for(ll i = 2 ; i <= n ; i++) 
    {
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }

    inv_fact[0] = 1;
    inv_fact[n] = fp(fact[n], mod-2) % mod;

    for(ll i = n ; i >= 1 ; i--) 
    {
        inv_fact[i-1] = (inv_fact[i] * i) % mod;
        inv_fact[i-1] %= mod;
    }
}