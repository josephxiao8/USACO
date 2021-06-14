#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<pi> pq;
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("time.out");
	ifstream cin ("time.in");
	
	int n, m, c;
	cin>>n>>m>>c;
	vi v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	vector<vi> adj(n);
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		a--; b--;
		adj[b].pb(a);
	}
	
	int ans=0;
	vector<vi> dp(n, vi(1001,-1));
	dp[0][0]=0;
	for(int t=1; t<=1000; t++){
		for(int i=0; i<n; i++){
			for(auto u:adj[i]){
				if(dp[u][t-1]!=-1) dp[i][t]=max(dp[u][t-1]+v[i],dp[i][t]);
			}
			if(i==0 && dp[i][t]!=-1) ans=max(ans, dp[i][t]-c*t*t);
		}
	}
	
	cout<<ans<<"\n";
	return 0;	
}
