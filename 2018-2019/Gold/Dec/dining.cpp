#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;
 
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
typedef priority_queue<pi,vector<pi>,greater<pi>> pqg;
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

	ofstream cout ("dining.out");
	ifstream cin ("dining.in");
	int n,m,k;
	cin>>n>>m>>k;
	vector<vpi> adj(n);
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a-1].pb(mp(b-1,c));
		adj[b-1].pb(mp(a-1,c));
	}
	
	//shorted path from node 'n' to all other nodes
	vi dis(n,1e9+7);
	dis[n-1]=0;
	vector<bool> visited(n, false);
	pqg q;
	q.push(mp(0,n-1));
	
	while(!q.empty()){
		int a,c;
		tie(c,a)=q.top(); q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		dis[a]=c;
		for(auto u:adj[a]){
			if(!visited[u.f]){
				q.push(mp(c+u.s,u.f));
			}
		}
	}
	
	while(k--){
		int a,b;
		cin>>a>>b;
		a--;
		q.push(mp(dis[a]-b,a));
	}
	
	visited=vector<bool> (n, false);
	vi ans(n,0);
	while(!q.empty()){
		int a,c;
		tie(c,a)=q.top(); q.pop();
		if(visited[a]) continue;
		visited[a]=true;
		if(c<=dis[a]) ans[a]=1;
		for(auto u:adj[a]){
			if(!visited[u.f]){
				q.push(mp(c+u.s,u.f));
			}
		}
	}
	
	for(int i=0; i<n-1; i++) cout<<ans[i]<<"\n";
	return 0;
}
