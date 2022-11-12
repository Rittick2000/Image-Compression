#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void solve(){
   int n;
   cin>>n;

   vector<int> chefs(n);

   for(int i=0;i<n;i++)
      cin>>chefs[i];

   sort(chefs.begin(),chefs.end());

   int pos=0,neg=0,i=0;

   for(i=0;i<chefs.size()-1;i++) {
      if(chefs[i]==chefs[i+1])
         i++;
      else{
         if(chefs[i] < 0)
            neg += chefs[i];
         else
            pos += chefs[i];
      }
   }

   if(i==chefs.size()-1) {
      if(chefs[i] < 0)
         neg += chefs[i];
      else
         pos += chefs[i];
   }

   cout<<pos-neg;
}

int main()
{  
   std::ios::sync_with_stdio(false);
   int T=1; 
   // cin >> T;
   while(T--){
      solve();
   }
   return 0;
}