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

ofstream cout ("milkvisits.out");
ifstream cin ("milkvisits.in");

int n,m;
string s;
cin>>n>>m>>s;
vector<vi> adj(n);
for(int i=0; i<n-1; i++){
	int a,b;
	cin>>a>>b;
	a--;
	b--;
	adj[a].pb(b);
	adj[b].pb(a);
}

int counter=0;
vi cc(n);
vector<bool> visited(n,false);
for(int i=0; i<n; i++){
	if(!visited[i]){
		visited[i]=true;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int start=q.front(); q.pop();
			cc[start]=counter;
			for(auto u:adj[start]){
				if(!visited[u] && s[u]==s[start]){
					visited[u]=true;
					q.push(u);
				}
			}
		}
		counter++;
	}
}

for(int i=0; i<m; i++){
	int a,b;
	char c;
	cin>>a>>b>>c;
	a--;
	b--;
	
	if(s[a]!=s[b]) cout<<1;
	else if(cc[a]!=cc[b]) cout<<1;
	else if(s[a]==c) cout<<1;
	else cout<<0;
}

cout<<"\n";
return 0;
}
