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

int main()
{
	f1;
	f2;
	f3;	
	ll T;
	cin>>T;
	rep(tk,0,T)
	{
		ll n,mic;
		cin>>n>>mic;
		vll v(n);
		fr(0,n)
		cin>>v[i];
		ll low=1,high=inf;
		while(low<high)
		{
			ll mid=(low+high)/2;
			ll total=0;
			for(auto &i:v)
			{
				total+=ceil((double)i/(double)mid);
			}
			if(total<=mic)
			{
				high=mid;
			}
			else
			{
				low=mid+1;
			}
		}
		cout<<high<<endl;
	}
	return 0;
}
