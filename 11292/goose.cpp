#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int n,m;
  while (1) {
    cin>>n>>m;
    if(n==0){
      break;
    }
    vector<int> heads;
    for (int i = 0; i < n; i++) {
      int h;
      cin>>h;

      heads.push_back(h);
    }
    
    vector<int> knights;
    for (int i = 0; i < m; i++) {
      int h;
      cin>>h;

      knights.push_back(h);
    }
    sort(knights.begin(),knights.end());
    sort(heads.begin(),heads.end());
    int sum=0;
    int currKn=0;
    int currDr=0;
    while(currKn<knights.size() && currDr<heads.size()){
      if(knights[currKn]<heads[currDr]){
        currKn++;
      }
      else{
        sum+=knights[currKn];
        currKn++;
        currDr++;
      }
    }
    if(currDr==heads.size()){
    cout<<sum<<"\n";
    }
    else{
      cout<<"Loowater is doomed!"<<"\n";
    }
  }
  return 0;
}
