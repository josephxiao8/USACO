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
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vector<vi> adj;
vector<string> file_names;
vl down;
vl child;
vl up;

void dfs(int start){
	for(auto u:adj[start]){
		dfs(u);
		down[start]+=down[u]+(1+file_names[u].size())*child[u]; // "/folder/folder/folder"
		child[start]+=child[u];
	}
	if(adj[start].size()==0) {
		down[start]=0;
		child[start]=1;
	}
}

void dfs2(int start){
	for(auto u:adj[start]){
		up[u]=up[start]+down[start]-(down[u]+(1+file_names[u].size())*child[u])+(child[0]-child[u])*(3);
		dfs2(u);
	}
}
 

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("dirtraverse.out");
	ifstream cin ("dirtraverse.in");
	
	int n;
	cin>>n;
	adj=vector<vi>(n);
	file_names=vector<string>(n);
	for(int i=0; i<n; i++){
		cin>>file_names[i];
		int m;
		cin>>m;
		for(int j=0; j<m; j++){
			int node;
			cin>>node;
			adj[i].pb(--node);
		}
	}
	
	down=vl(n,0);
	child=vl(n,0); //number of leaves in subtree
	dfs(0);
	
	up=vl(n,0);
	up[0]=0;
	dfs2(0);
	
	ll ans=LONG_LONG_MAX;
	for(int i=0; i<n; i++){
		int temp=child[0];
		if(adj[i].size()==0) temp--;
		ans=min(ans,down[i]+up[i]-temp);
	}
	
	cout<<ans<<"\n";
	return 0;
}
