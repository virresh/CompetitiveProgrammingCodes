#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10000
int n;  // array size
int t[2 * sz];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r]
  int res = 0;
  for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  int l,r,s;
  cin>>s;
  while(s--)
  {
      cin>>l>>r;
      printf("%d\n", query(l,r));
  }
  return 0;
}
