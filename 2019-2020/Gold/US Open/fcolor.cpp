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


int n;
vi parent;
vi size;
vector<vi> adj;
queue<int> q;

void init(){
	parent=vi(n);
	size=vi(n);
	adj=vector<vi>(n);
	for(int i=0; i<n; i++){
		parent[i]=i;
		size[i]=1;
	}
}

int find(int node){
	if(parent[node]!=node){
		parent[node]=find(parent[node]);
	}
	return parent[node];
}

void unite(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	
	if(size[a]<size[b]) swap(a,b);
	parent[b]=a;
	size[a]+=size[b];
	
	for(auto u:adj[b]) adj[a].pb(u);
	adj[b].clear();
	if(adj[a].size()>1) q.push(a);
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("fcolor.out");
	ifstream cin ("fcolor.in");
	
	int m;
	cin>>n>>m;
	
	init();
	
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		a--; b--;
		adj[a].pb(b); 
	}
	
	for(int i=0; i<n; i++) {
		if(adj[i].size()>1) q.push(i);
	}
	
	while(!q.empty()){
		int start=find(q.front()); q.pop();
		if(adj[start].size()>1){
			int node=adj[start][0];
			for(int i=0; i<int(adj[start].size())-1; i++){
				unite(adj[start][i], adj[start][i+1]);
			}
			adj[start].clear();
			adj[start].pb(find(node));
		}
	}
	
	vi mapp(n,0);
	int cnt=1;
	for(int i=0; i<n; i++){
		if(mapp[find(i)]==0){
			mapp[find(i)]=cnt;
			cnt++;
		}
		cout<<mapp[find(i)]<<"\n";
	}
	
	return 0;	
}
