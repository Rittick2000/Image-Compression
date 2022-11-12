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
void get_lps(string &pat,vector<ll> &lps)
{
	int i=1,j=0;
	while(i<pat.length())
	{
		if(pat[i]==pat[j])
		{
			lps[i]=j+1;
			i++;
			j++;
		}
		else
		{
			if(j!=0)
				j=lps[j-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
bool kmp(string &s,string &pat,vector<ll> &lps)
{
	int i=0,j=0;
	while(i<s.length() and j<pat.length())
	{
		if(s[i]==pat[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
				i++;
		}
	}
	if(j==pat.length())
		return true;
	else
		return false;
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
		string s,pat;
		cin>>s;
		cin>>pat;
		s=s+s;
		ll s_len=s.length();
		ll pat_len=pat.length();
		vector<ll> lps(pat_len,0);
		get_lps(pat,lps);
		bool ans=kmp(s,pat,lps);
		if(ans)
			cout<<"Match"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
