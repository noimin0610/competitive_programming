#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
#define DEBUG 0
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    priority_queue<Pll, vector<Pll>, greater<Pll> > q;
    rep(n){
        cin >> a[i] >> b[i];
        q.push(Pll(a[i], i));
    }

    ll ans = 0;
    rep(k){
        Pll p = q.top(); q.pop();
        ans += p.first;
        q.push(Pll(p.first+b[p.second], p.second));
    }
    cout << ans << endl;
}