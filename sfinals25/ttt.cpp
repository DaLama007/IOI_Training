#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  map<char,char> blocks;
  blocks['A']='C';
  blocks['C']='A';
  blocks['B']='D';
  blocks['D']='B';

  int n;cin>>n;
  int result=0;
  char before='s';
  string full;cin>>full;
  for(auto var : full) {
    if(before=='s' || blocks[before]!=var){
      result+=2;
    }
    else{
      result+=1;
    }
    before=var;
  }
  cout<<result<<"\n";
  return 0;
}
