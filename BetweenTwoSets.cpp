#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

// Macros for convenient coding
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

// Typedefs for clarity in code
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

// Template function to update a variable with the minimum value
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }

// Template function to update a variable with the maximum value
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

// Main function
int main() {
    // Input/Output optimizations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    // Optional file input for local testing
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    // Input: Number of elements in arrays 'a' and 'b'
    int n, m;
    cin >> n >> m;

    // Input: Elements of array 'a'
    vi a(n);
    forn(i, n) cin >> a[i];

    // Input: Elements of array 'b'
    vi b(m);
    forn(i, m) cin >> b[i];

    // Initialize answer variable
    int ans = 0;

    // Iterate over possible values of 'k' from 1 to 100
    for1(k, 100) {
        bool ok = true;

        // Check if 'k' is a common multiple for all elements of 'a'
        for (int x: a) ok &= k % x == 0;

        // Check if 'k' is a common divisor for all elements of 'b'
        for (int x: b) ok &= x % k == 0;

        // If 'k' satisfies both conditions, increment the answer
        if (ok) ++ans;
    }

    // Output the final answer
    cout << ans << '\n';

    // Optional time tracking for local testing
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
