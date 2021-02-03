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


int n,m;
vector<vi> v;
vector<vi> adj;
vi color;
bool good;
vector<bool> seen;
vi indegree;

void dfs(int start){
	for(auto u:adj[start]){
		if(!good) return;
		if(color[u]==0){
			color[u]=1;
			dfs(u);
		}
		else if(color[u]==1){
			good=false;
			return;
		}
	}
	color[start]=2;
}

bool possible(int k){
	adj.clear();
	adj=vector<vi>(n);
	seen.clear();
	seen=vector<bool>(n,false);
	indegree.clear();
	indegree=vi(n,0);
	for(int j=0; j<k; j++){
		for(int i=0; i<v[j].size()-1; i++){
			adj[v[j][i]].pb(v[j][i+1]);
			seen[v[j][i]]=true;
			seen[v[j][i+1]]=true;
			indegree[v[j][i+1]]++;
		}
	}
	
	color.clear();
	color=vi(n,0);
	good=true;
	for(int i=0; i<n; i++){
		if(color[i]==0){
			color[i]=1;
			dfs(i);
			if(!good) return false;
		}
	}
	return true;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("milkorder.out");
	ifstream cin ("milkorder.in");
	
	cin>>n>>m;
	v=vector<vi>(m);
	for(int i=0; i<m; i++){
		int t;
		cin>>t;
		while(t--){
			int num;
			cin>>num;
			v[i].pb(--num);
		}
	}
	
	int k=1;
	for(int b=m/2; b>=1; b/=2){
		while(k+b<=m && possible(k+b)) k+=b;
	}
	
	bool b=possible(k);
	pqg q;
	vi ans;
	for(int i=0; i<n; i++) {
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int start=q.top(); q.pop();
		ans.pb(start);
		for(auto u:adj[start]){
			if(--indegree[u]==0) q.push(u);
		}
	}
	
	for(int i=0; i<n; i++){
		if(i!=0) cout<<" ";
		cout<<ans[i]+1;
	}
	cout<<"\n";
	return 0;
}
