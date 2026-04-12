#include <bits/stc++.h>
using namespace std;


int main (int argc, char *argv[]) {
  int l;cin>>l;
  string first;cin>>first;
  string second;cin>>second;
  
  int dp[first.length()][second.length()];
  //Now we gotta fill this table by calculating each
  //subproblem to be able to calculate bigger problems 
  
  for (int i = 0; i < first.length(); i++) {
    for (int j = 0; j < second.length(); j++) {
      if(first[i] == second[j]){
        1+ first
      }
      else{
        dp[i][j] = 0;
      }
    }
  }
  return 0;
}
