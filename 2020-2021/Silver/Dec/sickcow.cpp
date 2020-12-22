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
vector<bool> visited;
int ans=0;

void dfs(int start){
	int cnt=0;
	for(auto u:adj[start]){
		if(!visited[u]){
			visited[u]=true;
			cnt++;
			dfs(u);
		}
	}
	if(cnt!=0) ans+=cnt+int(ceil((log(cnt+1)/log(2.0))));
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	int n;
	cin>>n;
	adj=vector<vi>(n);
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	visited=vector<bool>(n,false);
	visited[0]=true;
	dfs(0);
	
	cout<<ans<<"\n";
	return 0;
}

