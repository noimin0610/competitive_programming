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
#define EPS 1e-9
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll y,b, yellow, blue, green;

    cin >> y >> b;
    cin >> yellow >> green >> blue;
    ll y_need = yellow * 2 + green;
    ll b_need = blue * 3 + green;
    cout << max(0LL, y_need-y) + max(0LL, b_need-b) << endl;
}
