#include "bits/stdc++.h"
using namespace std;

int t[105];
int main (int argc, char *argv[]) {
  int tc; cin >> tc;

  while (tc--) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }

    int minT = t[0];

    for (int i = 1; i < n; i++) {
      if(minT>=t[i]) minT = t[i];
      else t[i] = t[i] -(t[i]-minT);
    }

    int sum= 0;
    for (int i = 0; i < n; i++) {
      sum+= t[i];
    }

    cout<< sum << "\n";
  }
  return 0;
}
