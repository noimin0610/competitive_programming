#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

map<ll, ll> d;
priority_queue< Pll, vector<Pll>, greater<Pll> > que;
map<ll, vector<Pll> > edges;

void dijkstra(ll start){
    d[start] = 0;
    que.push(Pll(0, start));

    while(!que.empty()){
        Pll v = que.top(); que.pop();
        if(d.find(v.second) != d.end() && d[v.second] < v.first) continue;
        for(Pll e: edges[v.second]){
            if(d.find(e.first) == d.end() || d[e.first] > d[v.second] + e.second){
                d[e.first] = d[v.second] + e.second;
                que.push(Pll(d[e.first], e.first));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n;
    ll u, k, c, v;
    cin >> n;
    rep(n){
        cin >> u >> k;
        repp(j, k){
            cin >> v >> c;
            edges[u].emplace_back(v, c);
        }
    }

    dijkstra(0);
    repp(u, n) cout << u << " " << d[u] << endl;

}
