#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define MAX_V 100000
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int to; ll cap; int rev;};

vector<edge> G[MAX_V];
vector<int> level(MAX_V);
vector<int> iter(MAX_V, 0);
int H, W, s, t;

void add_edge(int from, int to, ll cap){
    /*
        ある点vに対する辺の集合はvectorで管理されているので，
        そのvectorの中の何番目の辺に対応しているかを記憶する→rev
    */
    G[from].push_back({to, cap, (int)G[to].size()});
    G[to].push_back({from, 0, (int)G[from].size()-1});
}

void bfs(int s){
    level = vector<int>(MAX_V, -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(edge e : G[v]){
            if(e.cap > 0 && level[e.to] == -1){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

ll dfs(int v, int t, ll f){
    if(v == t) return f;
    rep((int)G[v].size()){
        edge &e = G[v][i]; //eの中身を書き換えたいのでポインタを使用
        if(level[v] < level[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll dinic(int s, int t){
    ll max_flow = 0;
    while(true){
        bfs(s);
        if(level[t] < 0) return max_flow;
        ll f;
        while((f = dfs(s, t, INF)) > 0){
            max_flow += f;
        }
    }

    return max_flow;
}

signed main(){
    cin >> H >> W;
    rep(H){
        string tmp;
        cin >> tmp;
        repp(j, W){
            if(tmp[j] == 'S'){
                s = W*i + j;
                add_edge(W+H, i, INF);
                add_edge(W+H, H+j, INF);
            }else if(tmp[j] == 'T'){
                t = W*i + j;
                add_edge(i, W+H+1, INF);
                add_edge(H+j, W+H+1, INF);
            }else if(tmp[j] == 'o'){
                add_edge(i, H+j, 1);
                add_edge(H+j, i, 1);
            }
        }
    }
    
    if(s / W == t / W || s % W == t % W){
        cout << -1;
    }else{
        cout << dicnic(W+H, W+H+1);
    }
}
