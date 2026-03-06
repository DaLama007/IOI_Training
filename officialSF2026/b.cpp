#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int N;cin>>N;
  int T;cin>>T;
  vector<pair<int,int>> a;
  vector<int> market;
  map<int,vector<int>> vft;
  int result=0;
  for (int i = 0; i < N; i++) {
    int f;cin>>f;
    int s;cin>>s;
    pair<int,int> p = {f,s};
    a.push_back(p);
  }
  for (int i = 0; i < N; i++) {
    vft[a[i].second].push_back(a[i].first);
  }
  for (int i = T ; i !=0; i--) {
    int m=0;
    bool inM = false;
    int index=-1;
    for (int j = 0; j < vft[i].size(); j++) {
      int var = vft[i][j];
      if (var>m) {
        m=var;
        index=j;
      }
    }
    for (int j = 0; j < market.size(); j++) {
      int var = market[j];
      if(var>m){
        m = var;
        inM=true;
        index = j;
      }
    }
    if(index!=-1){

    result+=m;
    if(inM){
      market[index]=-1;
    }
    else{
      vft[i][index]= -1;
    }
    }

    for (int j = 0; j < vft[i].size(); j++) {
      if (vft[i][j]!=-1) {
        market.push_back(vft[i][j]);
      }
    }
  }
  cout<<result;
  return 0;
}
