class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
      if(source==destination){
        return true;
      }
      vector<bool> visited(n,false);
      queue<int> q;
      vector<vector<int>> v(n);
      for (int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
      }
      q.push(source);
      while(!q.empty()){
        int node = q.front();
        q.pop();
        vector<int> nb = v[node];
        for (int i = 0; i < nb.size(); i++) {
          if (!visited[nb[i]]) {
            if (nb[i]==destination) {
              return true;
            }
            q.push(nb[i]);
            visited[nb[i]] = true;
          }

        }
      }
        return false;
    }
};
