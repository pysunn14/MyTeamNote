// optimize
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// main
#include <bits/stdc++.h>
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define mid (lo + hi) / 2
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

using namespace std;

// util
#define test(a) int _; cin >> _; FOR(a, _, 0)
#define FOR(a, b, c) for (int a = c; a < b; a++)
#define FORE(a, b) for (const auto &a : b)

// 임의 정밀도
__float128 float_number;