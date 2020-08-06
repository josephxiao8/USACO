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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("piggyback.out");
ifstream cin ("piggyback.in");

int b,e,p,n,m;
cin>>b>>e>>p>>n>>m;

vector<vi> adj(n);
for(int i=0; i<m; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

vi distance1(n);
vector<bool> visited1(n,false);
queue<int> q;
q.push(0);
visited1[0]=true;
distance1[0]=0;
while(!q.empty()){
	int start=q.front(); q.pop();
	for(auto u:adj[start]){
		if(visited1[u]) continue;
		visited1[u]=true;
		distance1[u]=distance1[start]+1;
		q.push(u);
	}
}

vi distance2(n);
vector<bool> visited2(n,false);
q.push(1);
visited2[1]=true;
distance2[1]=0;
while(!q.empty()){
	int start=q.front(); q.pop();
	for(auto u:adj[start]){
		if(visited2[u]) continue;
		visited2[u]=true;
		distance2[u]=distance2[start]+1;
		q.push(u);
	}
}

vi distance3(n);
vector<bool> visited3(n,false);
q.push(n-1);
visited3[n-1]=true;
distance3[n-1]=0;
while(!q.empty()){
	int start=q.front(); q.pop();
	for(auto u:adj[start]){
		if(visited3[u]) continue;
		visited3[u]=true;
		distance3[u]=distance3[start]+1;
		q.push(u);
	}
}

int ans=b*distance1[n-1]+e*distance2[n-1];
for(int i=0; i<n; i++) ans=min(ans,b*distance1[i]+e*distance2[i]+p*distance3[i]);

cout<<ans<<"\n";
return 0;	
}
