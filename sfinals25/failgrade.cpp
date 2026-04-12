#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  map<int,int> m;

  int n;
  cin>>n;
  int max;
  cin>>max;

  for (int i = 0; i < n; i++) {
    int key,val;
    cin>>key>>val;
    m[key] = val;
  }
  int sum = 0;
  for(auto p: m) {
    sum+=p.second;
  }
  sum=sum/2;

  int cs=0;
  int prevGrade =0;

  for(auto p: m) {
    cs+=p.second;
    if(cs>sum){
      cout<<p.first<<"\n";
      break;
    }
  }


  return 0;
}
