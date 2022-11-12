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
		ll n,k;
		cin>>n>>k;
		map<ll,ll> mp;
		vector<pair<ll,ll>> v;
		int count=0;
		for(int i=0;i<n;i++)
		{
			ll a,b;
			cin>>a>>b;
			if(mp.find(a)==mp.end())
			{
				mp[a]=count;
				count++;
			}
			if(mp.find(b)==mp.end())
			{
				mp[b]=count;
				count++;
			}
			v.pb({a,b});
		}
		vector<ll> adj[count];
		for(auto &i:v)
		{
			adj[mp[i.first]].pb(mp[i.second]);
			adj[mp[i.second]].pb(mp[i.first]);
		}
		ll ans=0;
		set<pair<ll,ll>> st;
		for(int i=0;i<count;i++)
		{
			vector<int> visited(count,0);
			queue<ll> q;
			q.push(i);
			visited[i]=1;
			ll dist=k;
			while(!q.empty() and dist)
			{
				ll nn=q.size();
				while(nn--)
				{
					ll node=q.front();
					q.pop();
					for(auto &child:adj[node])
					{
						if(!visited[child])
						{
							q.push(child);
							visited[child]=1;
						}
					}
				}
				dist--;
			}
			while(!q.empty())
			{
				pair<ll,ll> p={i,q.front()};
				q.pop();
				if(p.first>p.second)
					swap(p.first,p.second);
				st.insert(p);
			}
		}
		for(auto &i:st)
			cout<<i.first<<" "<<i.second<<endl;
		cout<<st.size()<<endl;
	}
	return 0;
}

