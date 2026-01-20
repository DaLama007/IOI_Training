#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  vector<int> v;
  int l;
  while(cin>>l){
    v.clear();
    for (size_t i = 0; i < l; i++) {

      int num;
      cin>>num;
      v.push_back(num);
    }
    sort(v.begin(),v.end());
    int sum;
    cin>>sum;
    int difference;
    int i = 0;
    int j=l-1;
    int minDiff = v[j]-v[i];
    int arr[2];
    while (i<j) {
      int currSum = v[i]+v[j];
      if (currSum==sum) {
        difference = v[j]-v[i];
        if (difference<=minDiff) {
          minDiff=difference;
          arr[0] = v[i];
          arr[1] = v[j];
        }
        j--;
        i++;
      }
      else if(currSum<sum){
        i++;
      }
      else{
        j--;
      }
    }
    cout<<"Peter should buy books whose prices are "<<arr[0]<<" and " << arr[1]<<"."<< "\n\n";
  }


  return 0;
}
