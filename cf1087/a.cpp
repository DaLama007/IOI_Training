#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;cin>>tc;
  while (tc--) {
    long long n,c,k;cin>>n>>c>>k;
    vector<int> monsters(n);
    long long sum = c;
    for (long long i= 0; i < n; i++) {
      cin>> monsters[i];
    }
    sort(monsters.begin(),monsters.end());
    for (long long i = 0; i < n; i++) {
      long long mon = monsters[i];
      if (sum>mon) {
        if (k==0) {
          sum+=mon;
        }
        else if (c>=mon+k) {
          sum+= mon+k;
          k=0;
        }
        else if(k>=c-mon){
          k= k-(c-mon);
          sum+=c;
        }
        c= sum;
      }
    }
    cout<<sum<<"\n";
  }
  return 0;
}
