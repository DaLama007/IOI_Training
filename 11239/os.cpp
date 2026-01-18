#include <bits/stdc++.h>
using namespace std;

int main (int argc, char *argv[]) {
  while (1) {
    
    map<string, set<string>> pOfC ;
    string line;
    map<string,int> m;
    set<string>* cS = nullptr;
    while (getline(cin, line)) {
       if(line=="0") return 0;
       if(line == "1" ) break;
       if(isupper(line[0])){
          cS= &pOfC[line];
       }
       else {
         if(cS->find(line)== cS->end()){
          cS->insert(line);
          m[line]++;

         }
       }
    }
    vector<pair<string,int>> v;
    size_t i;
    for (const auto& p : pOfC) {
      string key = p.first;
      int count=0;
      size_t j;

      for(string var : p.second) {
        if(m[var]==1) count++;

      }
      pair<string,int> pr = {key,count};
      v.push_back(pr);
    }

    sort(v.begin(),v.end(),[](pair<string, int> &a,pair<string, int> &b){
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

    for(auto &var : v) {
      cout<<var.first<< " "<<var.second << "\n";
    }
  }

  return 0;
}
