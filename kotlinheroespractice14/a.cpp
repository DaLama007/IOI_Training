#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;cin>>tc;
  while (tc--) {
    map<int,int> count;
    int l;cin>>l;
    for (size_t i = 0; i < l; i++) {
      int num;cin>>num;
      if(count[num]!=0){
        count[num]=1+count[num];
      }
      else {
        count[num]=1;
      }
    }

    int score=0;
    for(auto var : count) {
      score += floor(var.second/2);
    }
    cout<<score<<"\n";
  }
  return 0;
}
