#include <bits/stdc++.h>

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(ll j=0;j<n;j++)
#define reppp(i, m, n) for(ll i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const double EPS = 1e-9;

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    ll h, w, tmp, d, l, r;
    cin >> h >> w >> d;
    Pll mp[h*w+1];
    ll p[h*w+1];
    rep(h){
        repp(j, w){
            cin >> tmp;
            mp[tmp] = Pll((ll)i, (ll)j);
        }
    }

    rep(d) p[i] = 0;
    reppp(i, d, 2*d){
        for(ll j=(ll)i;j<=w*h;j+=d){
            p[j] = abs(mp[j].first - mp[j-d].first) + abs(mp[j].second - mp[j-d].second) + p[j-d];
        }
    }

    int q;
    cin >> q;
    rep(q){
        cin >> l >> r;
        if(l == r) cout << 0 << endl;
        else cout << p[r] - p[l] << endl;
    }
}
