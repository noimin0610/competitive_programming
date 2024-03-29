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
#include<numeric>

#define rep(n) for(ll i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};


signed main(){
    ll k;
    cin >> k;
    ll n;
    vector<ll> a;
    if(k == 0){
        n = 2;
        rep(2) a.pb(1);
    }else if(k == 1){
        n = 2;
        a.pb(2);
        a.pb(0);
    }else if(k <= 50){
        n = k;
        rep(k) a.pb(k);
    }else{
        n = 50;
        rep(n) a.pb(50 + (k-1)/50);
        
        if(k % 50 != 0){
            rep(50 - k%50){
                auto max_iter = max_element(all(a));
                *max_iter -= n;
                for(auto iter=a.begin();iter != a.end();++iter){
                    if(iter != max_iter){
                        (*iter)++;
                    }
                }
            }
        }
        
    }
    cout << n << endl;
    rep(n-1){
        cout << a[i] << " ";
    }
    cout << a[n-1];
}