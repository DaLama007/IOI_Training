#include "bits/stdc++.h"
using namespace std;

const int maxQ = 2*1e5;
int boss[maxQ];

int main (int argc, char *argv[]) {
  int n, q; cin >> n >> q;

  for (int i = 2; i <= n; i++) {
    cin >> boss[i];
  }

  set<int> visited;

  for (int i = 0; i < q; i++) {
    int a, b; cin>>a >> b;
    int B = a;

      while (B!= 1) {
        B = boss[B];
        visited.insert(B);
      }

    B = b;
    while (B!=1) {
      B = boss[B];
      if (visited.find(B) != visited.end()) {
        cout<<B<<"\n";
        break;
      }
    }
    visited.clear();
  }

  return 0;
}
