#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int t; cin >> t;
  while (t--) {
    int x, y; cin >> x >> y;
    double z = ((double)x)/y;
    int zint = (int)z;
    if(z == zint) cout << "YES" << "\n"; 
    else cout << "NO" << "\n"; 
  }
  return 0;
}
