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

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<=n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define MOD 1000000007
#define MAX 1000000001
#define INF 1410065408
#define EPS 1e-18
#define DEBUG 0

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

signed main(){
    int n;
    cin >> n;

    string command;
    int box, t, next = 1, ans = 0;
    stack<int> st;
    rep(2*n){
        cin >> command;
        if(command == "add"){
            cin >> box;
            st.push(box);
        }else{
            if(!st.empty()){
                t = st.top(); st.pop();
                if(t != next){
                    ans++;
                    while(!st.empty()) st.pop();
                }
            }
            next++;
        }
    }

    cout << ans << endl;

    return 0;

}