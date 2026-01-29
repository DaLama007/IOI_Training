#include "bits/stdc++.h"
using namespace std;

int main (int argc, char *argv[]) {
  int n;
  while(cin>>n){
    int coins[5] = {1,5,10,25,50};
    vector<long long > v(30001,0);//0==1 , 1==5 , 2==10 , 3==25 , 4==50
    v[0] =1;

    for(auto coin: coins) {
      for (int i = coin; i < 30001; i++) {
        v[i] += v[i-coin];
      }
    }
    if(v[n]==1){

      cout<<"There is only 1 way to produce "<<n<<" cents change.\n";
    }else{
      cout<<"There are "<<v[n] <<" ways to produce "<<n<<" cents change.\n";}
  }
  return 0;
}
