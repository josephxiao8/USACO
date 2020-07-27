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


vector<vi> adj;
void dfs(int start, vector<bool>& visited){
	if(visited[start]) return;
	visited[start]=true;
	for(auto u:adj[start]) dfs(u,visited);
}


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("factory.out");
ifstream cin ("factory.in");

int n;
cin>>n;

adj=vector<vi>(n);
for(int i=0; i<n-1; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
}

set<int> sett;
for(int i=0; i<n; i++) sett.insert(i);

for(int i=0; i<n; i++){
	vector<bool> visited(n,false);
	dfs(i,visited);
	
	for(int j=0; j<n; j++) if(!visited[j]) sett.erase(j);
}

if(sett.empty()) cout<<-1<<endl;
else cout<<*sett.begin()+1<<endl;
return 0;
}
