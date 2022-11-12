#include <bits/stdc++.h>
using namespace std;
int dp[201][201][2];
int helper(int i, int j,   int erased, string &s, string &t){
    if(i==s.size())
        return 0;
    if(j == t.size()){
        if(i == s.size()-1 && erased == 1)
            return 0;
        return 1e9;}
if(dp[i][j][erased] != -1)
        return dp[i][j][erased];   
    int w1=1e9,  w3=1e9, w4=1e9;
if(s[i] == t[j] || (s[i] == 'o' && t[j]=='a') || (s[i] == 'a' && t[j] == 'o') || (s[i] == 't' && t[j]=='l') || (s[i] == 'l' && t[j] == 't')){
        w1 = helper(i+1, j+1,  erased,   s, t);
    }
    w3 = 1 + helper(i, j+1, erased, s, t);
    if(erased>0)
        w4 = helper(i+1, j, 0, s, t);
    return dp[i][j][erased] = min({w1,  w3, w4});
}
int main() {
    int n; int toler; int ans=0;
    cin>>n;
    vector<string> arr;
    string ticket;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    cin>>ticket;
    cin>>toler;
    for(auto it: arr){     
        for(int i=0; i<ticket.size(); i++){
            memset(dp, -1, sizeof(dp));
            int x = helper(0, i, 1, it, ticket);
            // cout<<x<<" ";
            if( x <= toler){
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}