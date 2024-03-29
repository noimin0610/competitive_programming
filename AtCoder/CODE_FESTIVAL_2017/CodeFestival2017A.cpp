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

    string s;
    cin >> s;

    string t = "KIHBR";
    int ti = 0, a = 0;

    rep((int)s.length()){
        if(s[i] == 'A'){
            if(a == 0 && ti != 2) a++;
            else{
                cout << "NO";
                return 0;
            }
            if(ti == 1){
                cout << "NO";
                return 0;
            }
        }else{
            a = 0;
            if(ti < 5 && s[i] == t[ti]) ti++;
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if(ti == 5) cout << "YES";
    else cout << "NO";
    return 0;


    return 0;
}