#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int p;
  while (cin>>p) {
    int q,r,s,t,u;
    cin>>q>>r>>s>>t>>u;
    double f0= p * pow(exp(1),-0) + q* sin(0) + r*cos(0) + s* tan(0) + t* pow(0,2) + u;
    double f1= p * pow(exp(1),-1) + q* sin(1) + r*cos(1) + s* tan(1) + t* pow(1,2) + u;
    if (f0 * f1 > 0) {
      cout << "No solution\n";
      continue;
    }
    double start=0;
    double end=1;
    for (int i = 0; i < 100; i++) { // started with a while loop but my answer never got accepted so opted for a for loop so I dont just break if i have a too unprecise answer
      double mid = (start+end)/2;
      double res= p * pow(exp(1),-mid) + q* sin(mid) + r*cos(mid) + s* tan(mid) + t* pow(mid,2) + u;
      if (res<0) {
        end = mid;
      }
      else{
        start = mid;
      }
    }
    double mid = (start+end)/2;
    mid=round(mid * 10000) / 10000;
    cout<<fixed << setprecision(4) << mid<<"\n";
  }
  return 0;
}

