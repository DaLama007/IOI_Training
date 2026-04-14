#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define fi(n) for(size_t i = 0; i < n; i++)
int main (int argc, char *argv[]) {
  int n, l;
  cin>> n >> l;
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(3, vector<ll>(l+1,0)));
  
  dp[0][0][0] = 1;
  fi(n-1){
    for (int k = 0; k <= l; k++) {
      for (int j = 0; j < 3; j++) {
        ll curr = dp[i][j][k];

        if(j==0){
          dp[i+1][j][k] += curr;

          if(k+1<=l){
            dp[i+1][1][k+1]+=curr;
            dp[i+1][2][k+1]+=curr;
          }
        }

        else if (j==1) {
          dp[i+1][0][k]+=curr;
          if (k+1<=l) {
            dp[i+1][2][k+1]+=curr;
          }
        }

        else{
          dp[i+1][k][j]+=curr;
          if (k+1<=l) {
            dp[i+1][1][k+1]+=curr;
          }
        }

      }
    }
  }
  int sum =0 ;
  for (int i = 0; i <= l; i++) {
    sum += dp[n-1][0][i]%MOD; 
  }
  cout<<sum<<"\n";
  return 0;
}
