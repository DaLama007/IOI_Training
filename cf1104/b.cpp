#include "bits/stdc++.h"
using namespace std;

int arrA[2005];
int arrB[2005];

int main (int argc, char *argv[]) {
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
      cin >> arrA[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> arrB[i];
    }

    int swaps = 0;
    bool swap;
    for (int i = 0; i < n; i++) {
      swap = false;
      for (int j = i; j < n; j++) {
        if(arrB[i] >= arrA[j]){
          if(i == j){
            arrA[i] = arrB[i];
          }
          else{
            swaps += j-i;

            //shift so we move every value at i to a position i+1;
            for (size_t k = j; k > i; k--) {
              arrA[k] = arrA[k-1];
            }
            arrA[i] = arrB[i];
          }
          swap = true;
          break;
        }
      }
      if (swap != true) {
        break;
      }
    }

    if (swap != true) cout << -1 << "\n";
    else cout << swaps << "\n";
  }
  return 0;
}
