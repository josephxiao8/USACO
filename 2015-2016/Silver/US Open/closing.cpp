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


set<int> closed;
vector<bool> visited;
vector<vi> adj;

void dfs(int start){
	if(closed.count(start) || visited[start]) return;
	visited[start]=true;
	for(auto u:adj[start]){
		dfs(u);
	}
	return;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("closing.out");
ifstream cin ("closing.in");

int n,m;
cin>>n>>m;

adj=vector<vi>(n);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

visited=vector<bool> (n,false);
for(int i=0; i<n; i++){
	if(!closed.count(i) && !visited[i]){
		dfs(i);
		break;	
	}
}

bool connection=true;
for(int i=0; i<n; i++){
	if(!closed.count(i) && !visited[i]){
		connection=false;
		break;
	}
}
if(connection) cout<<"YES"<<"\n";
else cout<<"NO"<<"\n";

for(int i=0; i<n; i++){
	int temp;
	cin>>temp;
	temp--;
	closed.insert(temp);
	
	visited.clear();
	visited=vector<bool> (n,false);
	for(int i=0; i<n; i++){
		if(!closed.count(i) && !visited[i]){
			dfs(i);
			break;	
		}
	}
	
	connection=true;
	for(int i=0; i<n; i++){
		if(!closed.count(i) && !visited[i]) {
			connection=false;
			break;
		}
	}
	
	if(i<n-1){
		if(connection) cout<<"YES"<<"\n";
		else cout<<"NO"<<"\n";
	}
}

return 0;
}
