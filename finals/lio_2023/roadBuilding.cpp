#include <bits/stdc++.h>
#include <limits>

int dfs(vector<bool>& inStack, int num, stack<int>& st, vector<vector<int>>& nodes,vector<int>& low, vector<int>& disc,int& timer){
  int ns = nodes[num].size();
  
  // not needed cus 
  //  if cross-edge, skip by returning veri big number
  //    if(disc[num]!= -1 && inStack[num]) return INT_MAX;

  // if disc is not yet set, we set it to time we got from param
  if(disc[num] == -1){
    disc[num] = timer;
    timer++;
  }
  // check if low has already been set, to not overwrite
  if(low[num] == -1) low[num] = disc[num];

  st.push(num);
  inStack[num] = true;
  
  //dfs for neighbors -> recursive
  for (int i = 0; i < ns; i++) {
    low[num] = min( dfs(inStack, nodes[num][i],st,nodes,low,disc,timer), low[num]);
  }

  // and then, ladies and gentlemen, we pop
  if (low[num] == disc[num]) {
    st.pop();
  }
  return low[num];
}
int main (int argc, char *argv[]) {
  int N, M; cin>>N>>M;
  vector<vector<int>> nodes;
  vector<bool> inStack(N,false);
  vector<int> low(N,-1);
  vector<int> disc(N,-1);
  stack<int> st;

  for (int i = 0; i < N; i++) {
    int n, c; cin>>n c;
    nodes[n-1].push_back(c-1);
  }
  int timer = 0;
  //go through undiscovered nodes
  for (int i = 0; i < N; i++) {
    if(disc[i]==-1)  {
      dfs(inStack, i, st,  nodes, low,  disc, timer); 
    }
  }
  
  int count = 0;
  for (int i = 0; i < N; i++) {
    int currLow =low[i]
    if (currLow!=0 && currLow = disc[i]) {
     count++;
    }
  }
  return count;
}
