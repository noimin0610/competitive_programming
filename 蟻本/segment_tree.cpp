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
#define MOD 1000000007
#define MAX 10000
#define INF 1410065408
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{int from, to; ll cost;};

int n, seg[2*MAX-1];

void init(int n_){
  n = 1;
  while(n < n_) n *= 2;
  //n: number of leaf
  rep(2*n-1) seg[i] = INF;
}

void update(int k, int a){
  k += n-1;
  seg[k] = a;
  while(k > 0){
	k = (k-1) / 2;
	seg[k] = min(seg[2*k+1], seg[2*k+2]);
  }
}

int query(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return INF;
  if(a <= l && r <= b) return seg[k];
  int vl = query(a, b, k*2+1, l, (l+r) / 2);
  int vr = query(a, b, k*2+2, (l+r)/2, r);
  return min(vl, vr);
}

signed main(){
  vector<int> u{1, 2, 3, 4, 5};
  init(5);
  update(2, 6);
  printf("%d\n", query(0, 1, 0, 0, n));
  printf("%d\n", query(0, n, 0, 0, n));
}
