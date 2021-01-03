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
vector<bool> visited;
vector<bool> visited2;
vi dis;
vi dis2;
vi outdegree;
queue<int> q;
int ans=0;

void dfs(int start){
	for(auto u:adj[start]){
		if(!visited[u]){
			outdegree[start]++;
			dis[u]=dis[start]+1;
			visited[u]=true;
			dfs(u);
		}
	}
	if(outdegree[start]==0) {
		q.push(start);
		dis2[start]=0;
		visited2[start]=true;
	}
}

void dfs2(int start){
	for(auto u:adj[start]){
		if(!visited[u]){
			visited[u]=true;
			if(dis2[u]==1e9+7) dfs2(u);
			else ans++;
		}
	}
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("atlarge.out");
	ifstream cin ("atlarge.in");
	
	int n,k;
	cin>>n>>k;
	adj=vector<vi>(n);
	for(int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	k--;
	
	visited=vector<bool>(n, false);
	visited[k]=true;
	visited2=vector<bool>(n, false);
	dis=vi(n);
	dis[k]=0;
	dis2=vi(n,1e9+7); 
	outdegree=vi(n,0);
	dfs(k);
	
	while(!q.empty()){
		int start=q.front(); q.pop();
		if(dis[start]<dis2[start]) dis2[start]=1e9+7;
		for(auto u:adj[start]){
			if(!visited2[u]){
				dis2[u]=min(dis2[u],dis2[start]+1);
				if(--outdegree[u]==0){
					q.push(u);
					visited2[u]=true;
				}
			}
		}
	}
	
	visited=vector<bool>(n,false);
	visited[k]=true;
	dfs2(k);
	
	cout<<ans<<"\n";
	return 0;
}
