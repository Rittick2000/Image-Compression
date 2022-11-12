#include <bits/stdc++.h>
using namespace std;

void solve() {
  int p,qi;
  cin >> p >> qi;
  
  set<int> visited;
  int res = INT_MAX;

  queue<pair<int,int>> q;
  q.push({qi,0});
  
  while(q.size()) {
      pair<int,int> f = q.front();

      if(f.first == p)
        break;
        
      q.pop();
      int num = f.first;
      if(num%2==0 && visited.count(num/2)==0) {
          q.push({num/2,f.second+1});
          visited.insert(num/2);
      }
      res = (num==0 ? min(res,1+f.second) : res);

      int x = sqrt(num);
      if(x*x==num && visited.count(x)==0) {
          q.push({x, f.second+1});
          visited.insert(x);
      }

      if(num==1)
        res = min(res, 1+f.second);
  }

  if(!q.empty())
    res = min(res, q.front().second);

  cout<<(res==INT_MAX?-1:res);
  cout<<endl;
}

int main() {

  int T;
  cin >> T;
  while(T--) {
      solve();
  }

  return 0;

}