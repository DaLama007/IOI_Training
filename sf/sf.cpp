#include <bits/stdc++.h>
using namespace std;

typedef long long  l;
int main (int argc, char *argv[]) {
  size_t tC;
  cin>>tC;
  size_t i;
  for ( i = 0; i < tC; i++) {
    size_t sfN;
    cin>>sfN;
    unordered_map<int,int> m;
    size_t j;
    int left=0;
    int right=-1;
    int maxSize=0;
    vector<int> sar;

    for (j = 0; j< sfN; j++) {
      int num;
      cin>>num;
      sar.push_back(num);
      right++;
      m[num]++;
      if(m[num] > 1){
        while(m[num] > 1){
          int otherNum = sar[left];
          m[otherNum]--;
          if (m[otherNum]==0) {
            m.erase(otherNum);
          }
          if(otherNum!=num){
            left++;
          }
          else{
            left++;
            break;
          }

        }  
      }


      if(maxSize<right-left+1){
        maxSize=right-left+1;
      }

    }
    cout<<maxSize;
    cout << "\n";
  }
  return 0;
}
