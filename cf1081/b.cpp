#include <bits/stdc++.h>
using namespace std;

int flip(int index,string s,int l){
  int c;
  for (int i = 0; i < l; i++) {
    if(i!=index){
      if(s[i]== '0'){
        s[i] == '1';
      }
      else{

        s[i] == '0';
      }
      if(s[i]==1){
        c++;
      }
    }
  }
  return c;
}
int main (int argc, char *argv[]) {
  int tc;cin>>tc;
  while (tc--) {
    int l;cin>>l;
    string l;cin>>l;
    int nop=0;
    string op="";
    int count=0;
    for (int i = 0; i < l; i++) {
      if(s[i]==1){
        count++;
      }
    }
    if(count==0){
      cout<<"0\n";
    }
    else{
    for (int i = 0; i < 2; i++) {
      if(count==0){
        cout<<nop<<"\n"<<"op";
      }
      else if(count%2!=0){
        for (int i = 0; i < l; i++) {
          if(s[i]==1){
            flip(i,s,l);
            break;
          }
        }
        nop++;
      }
      else{
        for (int i = 0; i < l; i++) {
          if(s[i]==1){
            flip(i,s,l);
            break;
          }
        }
        nop++;
      }
    }
    if (count!=0) {
      cout<<"-1\n";
    }
    else{
        cout<<nop<<"\n"<<"op";
    }
    }

  }
  return 0;
}
