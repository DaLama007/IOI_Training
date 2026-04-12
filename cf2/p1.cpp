#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;
  cin>>tc;
  for (int i = 0; i < tc; i++) {
    int l;
    cin>>l;
    bool isdividable= false; 
    for (int i = 0; i < l; i++) {
      int n;
      cin>>n;
      if (n==67) {
        isdividable = true;
      }
    }

    if (isdividable) {
      cout<< "YES\n";
    }
    else{
      cout<< "NO\n";
    }

    
  }
  return 0;
}
