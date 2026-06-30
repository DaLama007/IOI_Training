#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int t; cin >> t;
  while (t--) {
    int l; cin >> l;
    string num; cin >> num;

    int bsum = 0;
    int curr = 1;
    for (int i = l-1; i >= 0; i--) {
      if(num[i] == '1'){ bsum += curr;
      cout << "ADD "<< curr << " for idx: " << i << "\n";}
      curr = 2 * curr;
    }
    cout << "BSUM: " << bsum << "\n";
    int otherSum = 0;
    int currMult = -1;
    while(bsum != 0){
      int mod = bsum%10;
      otherSum += mod*currMult;
      currMult = -currMult;
      bsum = bsum/10;
    }
    if(otherSum == 0) cout << "1" << "\n";
    else cout << "2" << "\n";


  }
  return 0;
}
