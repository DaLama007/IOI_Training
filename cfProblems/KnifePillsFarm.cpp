#include "bits/stdc++.h"
using namespace std;

int main (int argc, char *argv[]) {
  int t; cin >> t;
  while(t--){
    long long n,m; cin >> n >> m;
    vector<int> ratings(n);
    priority_queue<long long> minRat;
    for(int i=0;i<n;i++){
      cin >> ratings[i];
    }
    
    long long currSum = 0;
    long long maxSum = 0;
    for (int i = 0; i < m-1; i++) {
      long long currRat= ratings[i];
      minRat.push(currRat);
      currSum -= currRat;
    }
    maxSum = currSum + ratings[m-1]*m;

    for (int i = m-1; i < n-1; i++) {
      if(m>1){
      long long topEl = minRat.top();
      if(topEl >= ratings[i]){
        currSum = currSum + topEl - ratings[i];
        minRat.pop();
        minRat.push(ratings[i]);
      }
      }
      long long newRating = currSum + ratings[i+1]*m;
      if(newRating>maxSum) maxSum = newRating;
    }

    cout << maxSum << "\n";
  }
  return 0;
}
