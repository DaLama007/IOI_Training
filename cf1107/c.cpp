#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int t; cin >> t;
  while (t--) {
    int l; cin >> l;
    string num; cin >> num;

    int count =0;
    for(int i =0 ; i < l-1; i++ ) if(num[i] != num[i+1]) count++;
    cout<< (count==1 ? 2 : 1) << "\n";
  }
  return 0;
}
