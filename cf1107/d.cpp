#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<n ; i ++ ) cin >> a[i];
    for(int i = 0; i<n ; i ++ ) cin >> b[i];

    int l = -1;
    int r = -1;
    bool isFound = false;
    for (int i = 0; i < n; i++) {
      if(isFound && a[i] == b[i]){r = i-1;
        break;
      }
      if(!isFound && a[i] != b[i]){
        l = i;
        isFound = true;
      }

    }
    if(l ==-1 && r == -1){
      cout << "YES" << "\n";
    }
    else if(r ==-1){
      r=n-1;
    }
    else{
      bool isBad = false;
      for (int i = r+2; i < n; i++) {
        if(a[i] != b[i]){
          isBad = true;
          break;
        }
      }
      if(isBad) cout << "NO" << "\n";
      else{
        isBad = false;
        int pointer = l;
        while (!isBad && pointer<=r) {
        int pointer = l;
        bool ops = false;
          if(a[pointer]-l < b[pointer]){
            if((a[pointer]-l)%2 == 0) cout <<
          }
        }
      }
    }
  }
  return 0;
}
