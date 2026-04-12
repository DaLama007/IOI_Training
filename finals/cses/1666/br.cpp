#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nodes;
vector<bool> searched;
vector<int> districts;
int bfs(int i){
  queue<int> q;
  q.push(i);
  searched[i] = true;
  districts.push_back(i);
  while(!q.empty()){
    int next = q.front();
    q.pop();

    for(auto var : nodes[next]) {
      if (!searched[var]) {
        searched[var]=true;
        q.push(var);
      }
    }
  }
  return 0;
}
int main (int argc, char *argv[]) {
  int n,m;cin>>n>>m;
  searched.resize(n+1,false);
  nodes.resize(n+1);
  for (int i = 0; i < m; i++) {
    int first; cin>>first;
    int second; cin>>second;

    nodes[first].push_back(second);
    nodes[second].push_back(first);
  }

  for (int i = 1; i <= n; i++) {
    if(!searched[i]){
      bfs(i);
    }
  }
  if (!districts.empty()) {
    cout<<districts.size()-1<<"\n";
    for (int i = 1; i < districts.size(); i++) {
      cout<<districts[i-1]<<" "<<districts[i]<<"\n";
    }
  }
  else {
    cout<<0<<"\n";
  }

  return 0;
}
