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


vector<bool> visited;
vector<vi> adj;
int counter;

void dfs(int start){
	for(auto u:adj[start]){
		if(!visited[u]){
			counter++;
			visited[u]=true;
			dfs(u);
		}
	}
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("moocast.out");
ifstream cin ("moocast.in");

int n;
cin>>n;
vector<tuple<int,int,int> > v(n);
for(int i=0; i<n; i++){
	int x,y,p;
	cin>>x>>y>>p;
	v[i]=make_tuple(x,y,p);
}

adj=vector<vi>(n);
for(int j=0; j<n-1; j++){
	for(int i=j+1; i<n; i++){
		if(i==j) continue;
		int a,b,c,d,e,f;
		tie(a,b,c)=v[j];
		tie(d,e,f)=v[i];
		
		int temp=((a-d)*(a-d))+((b-e)*(b-e));
		if(temp<=c*c) adj[j].pb(i);
		if(temp<=f*f) adj[i].pb(j);
	}
}

int ans=0;
for(int i=0; i<n; i++){
	visited.clear();
	visited=vector<bool>(n,false);
	counter=1;
	visited[i]=true;
	dfs(i);
	ans=max(ans,counter);
}

cout<<ans<<"\n";
return 0;
}
