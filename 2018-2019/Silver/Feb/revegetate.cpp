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
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


vector<vi> adj_s;
vector<vi> adj_d;
vi color;
vector<bool> visited;
bool possible=true;

void dfs(int start){
	for(auto u:adj_s[start]){
		if(!possible) return;
		
		if(color[u]==0){
			color[u]=color[start];
			dfs(u);
		}
		else if(color[u]==3-color[start]){
			possible=false;
			return;
		}
	}
	
	for(auto u:adj_d[start]){
		if(!possible) return;
		
		if(color[u]==0){
			color[u]=3-color[start];
			dfs(u);
		}
		else if(color[u]==color[start]){
			possible=false;
			return;
		}
	}
	
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("revegetate.out");
ifstream cin ("revegetate.in");

int n,m;
cin>>n>>m;
adj_s=vector<vi>(n);
adj_d=vector<vi>(n);
for(int i=0; i<m; i++){
	char c;
	int a,b;
	cin>>c>>a>>b;
	a--;
	b--;
	if(c=='S'){
		adj_s[a].pb(b);
		adj_s[b].pb(a);
	}
	else{
		adj_d[a].pb(b);
		adj_d[b].pb(a);
	}
}

color=vi(n,0);
int cc=0;
for(int i=0; i<n; i++){
	if(color[i]==0){
		cc++;
		color[i]=1;
		dfs(i);
		if(!possible){
			cout<<0<<"\n";
			return 0;
		}
	}
}

cout<<1;
for(int i=0; i<cc; i++) cout<<0;
cout<<"\n";
return 0;
}
