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
 
typedef priority_queue<int> pq;
typedef priority_queue<tl,vector<tl>,greater<tl>> pqg;
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

	ofstream cout ("shortcut.out");
	ifstream cin ("shortcut.in");
	
	ll n,m,t;
	cin>>n>>m>>t;
	
	vl cows(n);
	for(ll i=0; i<n; i++) cin>>cows[i];
	
	vector<vpl> adj(n);
	for(ll i=0; i<m; i++){
		ll a,b,c;
		cin>>a>>b>>c;
		a--; b--;
		adj[a].pb(mp(b,c));
		adj[b].pb(mp(a,c));
	}
	
	vl dis(n);
	vector<bool> visited(n,false);
	pqg q;
	q.push(mt(0,0,-1));
	vl parent(n);
	while(!q.empty()){
		ll a,b,c;
		tie(b,a,c)=q.top(); q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		dis[a]=b;
		parent[a]=c;
		for(auto u:adj[a]){
			if(!visited[u.f]){
				q.push(mt(u.s+b,u.f,a));
			}
		}
	}
	
	vl ans(n,0);
	for(ll i=0; i<n; i++){
		ans[i]+=max(0LL,cows[i]*(dis[i]-t));
		ll par=parent[i];
		while(par!=-1){
			ans[par]+=max(0LL,cows[i]*(dis[par]-t));
			par=parent[par];
		}
	}
	
	ll ret=LONG_LONG_MIN;
	for(ll i=0; i<n; i++){
		ret=max(ret,ans[i]);
	}
	cout<<ret<<"\n";
	return 0;
}
