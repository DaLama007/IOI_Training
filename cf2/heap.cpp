#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;cin>>tc;
  while(tc--){
    int l;cin>>l;
    map<int,int> ival;
    vector<int> v(l);
    for (int  i = 0; i < l ; i++) {
      cin>>v[i];
    }
    int ind=0;
    for(auto var : v) {
      if(ind%2!=0 && ind>ceil(l/2) ){
        ival[ind] = var;
      }
      ind++;
    }

    sort(v.begin(),v.end());
    bool isS=true;
    for(auto var : ival) {
      if(v[var.first]!=var.second){
        isS=false;
        break;
      }
    }
    if (isS) {
      cout<<"Yes\n";
    }
    else{
      cout<<"No\n";
    }
  }
  return 0;
}
