#include <bits/stdc++.h>
using namespace std;

bool canSort(int minW, int M, int N, vector<int>& pos, vector<tuple<int,int,int>>& wh){
  vector<pair<int,int>> goodW;
  for (int i = 0; i < M; i++) {
    if (get<2>(wh[i]) >= minW) {
      goodW.push_back({get<0>(wh[i]),get<1>(wh[i])});
    }
  }
  
  vector<vector<int>> n(N);
  for (int i = 0; i < goodW.size(); i++) {
    n[goodW[i].first] = goodW[i].second;
    n[goodW[i].second] = goodW[i].first;
  }
  vector<vector<int>> comps;
  vector<bool> visited(N,false);
  queue<int> q;
  
  for (int i = 0; i < n.size(); i++) {
    if (!visited[i]) {
      vector<int> comp;
      q.push(i);

      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        comp.push_back(curr);
        visited[curr] = true;

        for (size_t i = 0; i < n[curr].size(); i++) {
          int nb = n[curr][i];
          if (!visited[nb]) {
            q.push(nb);
          }
        }
      }
      comps.push_back(comp);
    }
  }
  
  //check positions
  for(auto comp : comps) {
    set<int> need;
    set<int> have;
    for (int i = 0; i < comp.size(); i++) {
      need.insert(comp[i]);
      have.insert(pos[comp[i]]);
    }
    if (need != have) {
      return false;
    }
  }
  return true;
}

int main (int argc, char *argv[]) {
  int N, M;
  cin >> N >> M;
  //get all positions
  vector<int> pos(N);
  for (int i = 0; i < N; i++) {
    cin >> pos[i];
  }

  //get all wormholes
  vector<tuple<int,int,int> wh(M);
  for (int i = 0; i < M; i++) {
    int c1,c2,w;
    cin>>c1>>c2>>w;
    //0-index the input
    c1--;c2--;

    wh[i] = {c1,c2,w};
  }

  int low = 0;
  int high = N;
  int cmin = -1;
  while (low<high) {
    int mid = (high -low)/2;

    // check if sortable with that amount
    if (canSort(mid, M, N, pos, wh)) {
      cmin = max(mid,cmin);
      low = mid+1;
    }
    // if not increase amount of wormholes 
    // by adjusting the allowed wormhole width
    else{
      high = mid-1;
    }
  }

  cout<<cmin<<"\n";
  return 0;
}
