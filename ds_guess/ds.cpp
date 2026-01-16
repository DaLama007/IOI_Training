#include <bits/stdc++.h>
using namespace std;
int main (int argc, char *argv[]) {
  size_t nOP;

  while(cin>>nOP){
    int cOP;
    int num;
    bool isS=true;
    bool isQ=true;
    bool isPQ=true;
    stack<int> s;
    priority_queue<int> pQ;
    queue<int> q;
    size_t i;
    for (i = 0; i < nOP; i++) {
      cin >> cOP;
      cin>> num;
      if(cOP==1){
        if(isS){
          s.push(num);
        }
        if(isQ){
          q.push(num);
        }
        if(isPQ){
          pQ.push(num);
        }
      }
      else {
        if(isS){
          if(s.empty() ||s.top()!=num){
            isS=false;
          }
          s.pop();
        }
        if(isQ){
          if(q.empty() ||q.front()!=num){
            isQ=false;
          }
          q.pop();
        }
        if(isPQ){
          if(pQ.empty() || pQ.top()!=num){
            isPQ=false;
          }
          pQ.pop();
        }
      }
    }
    int score=0;
    if(isS) score++;
    if(isQ) score++;
    if(isPQ) score++;
    if(score>1){
      cout<<"not sure\n";
    }
    else if(score==1){
      if(isS) cout<<"stack\n";
      else if(isQ) cout<<"queue\n";
      else cout<<"priority queue\n";
    }
    else{
      cout<< "impossible\n";
    }
  }
  return 0;
}
