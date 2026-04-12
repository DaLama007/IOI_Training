#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  int tc;
  cin>>tc;
  for (int i = 0; i < tc; i++) {
    bool isroll=true;
    int l;
    cin>>l;
    int currNum;
    cin>>currNum;
    int result=0;
    for (int i = 0; i < l-1; i++) {
      int num;
      cin>>num;
      if (currNum == num || num== 7- currNum) {
        isroll = false;
        result++;
      }
    }

    if(isroll){
      cout<<"0\n";
    }
    else {
      cout<<result<<"\n";
    }
  }
  return 0;
}
