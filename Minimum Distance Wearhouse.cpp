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
ll dijkstra(vector<pair<ll,ll>> adj[],ll s,vll &house_no,ll n)
{

	vector<ll> dist(n,mod);
	dist[s]=0;
	priority_queue<pair<ll,ll> ,vector<pair<ll,ll>> , greater<pair<ll,ll>>> pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		auto it=pq.top();
		pq.pop();
		ll node=it.second;
		ll distance=it.first;
		distance=dist[node];
		for(auto &child:adj[node])
		{
			if(dist[child.first]>distance+child.second)
			{
				pq.push({child.second+distance,child.first});
				dist[child.first]=distance+child.second;
			}
		}
	}
	ll ans=INT_MAX;
	for(auto &i:house_no)
	{
		if(i==s)
			continue;
		else
			ans=min(ans,dist[i]);
	}
	return ans;
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
		ll nodes,houses;
		cin>>nodes>>houses;
		vll house_no(houses);
		fr(0,houses)
		cin>>house_no[i];
		vector<pair<ll,ll>> adj[nodes];
		ll edges;
		cin>>edges;
		fr(0,edges)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			adj[a].pb({b,c});
			adj[b].pb({a,c});
		}
		ll ans=INT_MAX;

		for(auto &i:house_no)
		{
			ans=min(ans,dijkstra(adj,i,house_no,nodes));
		}
		cout<<ans<<endl;
	}
	return 0;
}
