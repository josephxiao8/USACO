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

ofstream cout ("clocktree.out");
ifstream cin ("clocktree.in");

int n;
cin>>n;
vi v(n);
for(int i=0; i<n; i++) cin>>v[i];

vector<vi> adj(n);
for(int i=0; i<n-1; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

int ans=0;
for(int i=0; i<n; i++){
	vector<bool> visited(n,false);
	visited[i]=true;
	vi parent(n,-1);
	deque<int> dq;
	dq.push_front(i);
	
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int start=q.front(); q.pop();
		for(auto u:adj[start]){
			if(!visited[u]){
				visited[u]=true;
				dq.push_front(u);
				q.push(u);
				parent[u]=start;
			}
		}
	}
	
	vi temp=v;
	while(!dq.empty()){
		int start=dq.front(); dq.pop_front();
		int add=12-temp[start];
		if(parent[start]!=-1){
			temp[parent[start]]=(temp[parent[start]]+add)%12;
			if(temp[parent[start]]==0) temp[parent[start]]=12;
		}
	}
	if(temp[i]==12 || temp[i]==1) ans++;
}

cout<<ans<<"\n";
return 0;
}
