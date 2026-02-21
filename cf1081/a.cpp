#include <bits/stdc++.h>
using namespace std;
int count(string s, int l){
  char prev = s[0];
  int result = 1;
  for (int i = 1; i < l; i++) {
    if(prev == s[i]){
      continue;
    }
    else{
      result++;
      prev = s[i];
    }
  }
  return result;
}
int main (int argc, char *argv[]) {
  int tc;cin>>tc;
  while (tc--) {
    int l;cin>>l;
    string s; cin>>s;
    int best=1;
    if(l==1){
      cout<<"1\n";
    }
    else{
      for (int i = 0; i < l; i++) {

        int res = count(s,l);
        s = s.back() + s.substr(0,l-1);
        if (best<res) {
          best=res;
        }
      }
      cout<<best<<"\n";
    }
  }
  return 0;
}
