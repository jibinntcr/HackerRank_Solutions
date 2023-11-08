#include <bits/stdc++.h>

using namespace std;

#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(ll ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(ll ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'

#define pii pair < ll ,ll > 

typedef long long ll;

#define hash asdasd

const int inf = 1e9;
const ll mod = 1e9+7;
const ll mod2 =  1e9+7;
const int N = 2e5+5;
const int logN = 18;

ll F[N], i, j, k, n, m, sorted[N], 
suff[N], lcp[N], ans, hash[N], hash2[N], p, P[N];

string str, str2;

vector< pii > v[N], q[N], v2[N], q2[N];

pair< pii , ll > C[N];

void update(ll x,ll y){
x--;
for(; x > 0 ; x -= x&-x) F[x]--;
for(; y > 0 ; y -= y&-y) F[y]++;
}

ll query(ll x){
ll sum = 0;
for(; x < N ; x += x&-x) sum += F[x];
return sum;
}

ll take(ll x,ll y)
{ return (hash[y] - (
    (ll)P[y-x+1] * hash[x-1] % mod)+mod)%mod; }

ll take2(ll x,ll y){    return (hash2[x] - (
    (ll)P[y-x+1] * hash2[y+1] % mod)+mod)%mod; }

void solve(ll x,ll y){

int bas = 0, son = x;

while(bas < son){

int orta = bas + son >> 1;

if(bas == orta) orta++;

if(take(x-orta+1,x) == take2(y,y+orta-1)) bas = orta;

else son = orta - 1;

}

if(x == y) v[y].pb(mp(x-bas+1,x));

else v2[y].pb(mp(x-bas+1,x));

}

int main(){

cin >> str;

n = str.size(); str = '0' + str;

FOR(i,1,n) suff[i] = str[i];

FOR(j,1,logN){

FOR(i,1,n) C[i] = mp(mp(suff[i],
suff[min(n+1,i+(1ll<<j-1))]),i);

sort(C+1,C+n+1);

FOR(i,1,n) suff[C[i].nd] = 
suff[C[i-1].nd] + (C[i].st != C[i-1].st);

}

FOR(i,1,n) sorted[suff[i]] = i;

int j = 0;

FOR(i,1,n){

if(suff[i] == 1) continue ;

while(i + j <= n && sorted[suff[i]-1] + j <=
 n && str[sorted[suff[i]-1]+j] == str[i+j]) j++;

if(j%2) q[i+j/2].pb(mp(i,suff[i]-1));

else q2[i+j/2].pb(mp(i,suff[i]-1));

if(j) j--;

}   


P[0] = 1;

p = 8;

FOR(i,1,n) P[i] = (P[i-1] * p) % mod;

FOR(i,1,n) hash[i] = (((ll)hash[i-1] * p + 
(str[i] - 'a'))) % mod;

ROF(i,n,1) hash2[i] = (((ll)hash2[i+1] * p +
 (str[i] - 'a'))) % mod;

FOR(i,1,n){

if(i != n && str[i] == str[i+1]) solve(i,i+1);

solve(i,i);

}

FOR(i,1,n){

foreach(it,v2[i]) update(it->st,it->nd);

foreach(it,q2[i]) lcp[it->nd] = query(it->st);

foreach(it,v[i]) update(it->st,it->nd);

foreach(it,q[i]) lcp[it->nd] = query(it->st);

}

stack< pii > S;

FOR(i,1,n+1){

//      cout << i << ' ' << lcp[i] << endl;

ll index = i;

while(!S.empty() && S.top().st >= lcp[i]){

pii temp = S.top(); S.pop();

index = temp.nd;

ll mx = lcp[i];

if(!S.empty()) mx = max(mx, S.top().st);

ans = (ans + ((temp.st - mx) * (i-temp.nd) * 
(i-temp.nd+1) / 2)) % mod2;

}

S.push(mp(lcp[i],index));

}

cout << ans << endl;

return 0;
}
