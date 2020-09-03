#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long ul;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
typedef priority_queue<pair<int,string>> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vector<vpi> adj;
vector<vi> relevance;
vector<bool> visited;

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("mootube.out");
ifstream cin ("mootube.in");

int n,q;
cin>>n>>q;

adj=vector<vpi>(n);
for(int i=0; i<n-1; i++){
	int a,b,c;
	cin>>a>>b>>c;
	a--;
	b--;
	adj[a].pb(mp(b,c));
	adj[b].pb(mp(a,c));
}

relevance=vector<vi>(n, vi(n,-1));
for(int i=0; i<n; i++){
	visited.clear();
	visited=vector<bool>(n,false);
	visited[i]=true;
	queue<pi> q;
	q.push(mp(i,INT_MAX));
	while(!q.empty()){
		int a,w;
		tie(a,w)=q.front(); q.pop();
		for(auto u:adj[a]){
			int b,c;
			tie(b,c)=u;
			if(!visited[b]){
				visited[b]=true;
				relevance[i][b]=min(w,c);
				q.push(mp(b,min(w,c)));
			}
		}
	}
}

for(int i=0; i<q; i++){
	int k,v;
	cin>>k>>v;
	v--;
	int ans=0;
	for(auto x:relevance[v]) {
		if(x>=k) ans++;
	}
	cout<<ans<<"\n";
}

return 0;
}
