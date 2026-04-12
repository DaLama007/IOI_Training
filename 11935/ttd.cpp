#include <bits/stdc++.h>
using namespace std;

struct Event {
  pair<string,int> info;
  int distance;
};
int tryNum(double num, vector<Event> v){
  int index=1;
  int leak = 0;
  int maxf = num;
  int cons = v[0].info.second;  
  for (int i = 0; i < v[v.size()-1].distance; i++) {
    if(i==v[i].distance){
      string c = v[i].info.first;
      if(c=="Fuel"){
        cons = v[i].info.second;
      }
      else if(c=="Leak"){
        leak++;
      }
      else if(c=="Mechanic"){
        leak =0;
      }
      else if(c=="Gas"){
        num=maxf;
      }
      else if(c == "Goal"){
        break;
      }
    }
    num-(0.01)*cons-leak;
  }
  return num;
}
int main (int argc, char *argv[]) {
  while(1){

    vector<Event> v;
    while(1){
      Event e;
      int distance;
      string eventname;
      cin>>distance>>eventname;
      
      if(eventname=="Fuel"){
        string filler ;
        int consum;
        cin>>filler>>consum;
        pair<string,int> p;
        p.first = eventname;
        p.second = consum;
        e.info = p;
        e.distance = distance;
      }
      
      else{
        pair<string,int> p;
        p.first = eventname;
        p.second = 0;
        e.info = p;
        e.distance = distance;
      }
      if (eventname=="Gas") {
        string filler;
        cin>>filler;
      }
      v.push_back(e);
      if(e.info.first=="Goal") break;
    }

    int low = 0;
    int high = 100000;

    while(low<high){
      int mid = (low+high)/2;
      int result = tryNum(mid,v);
      if(round(fabs(result)*1000)/1000==0){
        cout<<round(mid*1000)/1000;
        break;
      }
      else if(result<0){
        mid=low+0.001;
      }
      else{
        high = mid-0.001;
      }
    }
  }
  return 0;
}
