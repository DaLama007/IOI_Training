#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;
  cin>>tc;
  for (int i = 0; i < tc; i++) {
    int n,s,x;
    cin>>n>>s>>x;

    int sum=0;
    for (int i = 0; i < n; i++) {
      int num;
      cin>>num;
      sum+=num;
    }
    if(sum<=s &&(s-sum)%x==0){
      cout<<"YES\n";
    }
    else {
      cout<<"NO\n";
    }
  }
  return 0;
}
