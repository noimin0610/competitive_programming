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
#define ll long long
#define Pll pair<ll, ll>
#define Pii pair<int, int>
 
using namespace std;
struct edge{int from, to; ll cost;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> a(1501, 0);
    rep(3){
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    if(a[1] >= 1 || a[2] >= 2 || a[3] >= 3 || (a[2] == 1 && a[4] == 2)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}