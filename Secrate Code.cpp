#include<bits/stdc++.h>
#define f1 ios_base::sync_with_stdio(false);
#define f2 cin.tie(NULL);
#define f3 cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define inf INT_MAX
using namespace std;
ll power(ll n,ll key,ll m)
{
	if(key==1)
		return n%m;
	if(key%2)
	{
		ll ans=power(n,key/2,m);
		ans=((((ans%m)*(ans%m))%m)*(n%m))%m;
		return ans;
	}
	else
	{
		ll ans=power(n,key/2,m);
		ans=((ans%m)*(ans%m))%m;
		return ans;
	}
}
int main()
{
	f1;
	f2;
	f3;	
	ll T;
	cin>>T;
	rep(tk,0,T)
	{
		ll n,k1,k2;
		cin>>n>>k1>>k2;
		ll ans=power(n,k1,10);
		ans=power(ans,k2,mod);
		cout<<ans<<endl;
	}
	return 0;
}
