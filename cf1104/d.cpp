#include "bits/stdc++.h"
using namespace std;

int a[(int)1e6][(int)1e6];

bool valid(string s, int l){
  bool nothing = false;
  while (!nothing) {
    nothing = true;
    for (int i = 0; i < l; i++) {
      if(s[i] == s[i+1]){
        string rep = "0";
        if(s[i]== '0')  rep = "1";
        s.replace(i,2,rep);
        l--;
        nothing = false;
      }
    }
  }

  if(l==1) return true;
  return false;
}

int main (int argc, char *argv[]) {
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    string s; cin >> s;

    for(int i =0; i <n ; i++){
      a[i][i] = 1;
    }

    int sum = n;
    for (int i = 0; i < n; i++) {
      for(int j = i+1; j<n; j++){
        if(valid(s.substr(i,j),n)) {
          sum++;
        }
      } 
    }

    cout << sum << "\n";
  }
  return 0;
}
