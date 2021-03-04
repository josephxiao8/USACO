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
typedef priority_queue<pi,vector<pi>,greater<pi>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main(){
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("pump.out");
	ifstream cin ("pump.in");
	
	int n,m;
	cin>>n>>m;
	vector<vti> adj(n);
	for(int i=0; i<m; i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--; b--;
		adj[a].pb(mt(b,c,d));
		adj[b].pb(mt(a,c,d));
	}
	
	int ans=0;
	for(int i=1; i<=1000; i++){
		pqg q;
		q.push(mp(0,0));
		vector<bool> vis(n,false);
		vi dis(n,1e9+7);
		dis[0]=0;
		
		while(!q.empty()){
			int a,b;
			tie(a,b)=q.top(); q.pop();
			if(vis[b]) continue;
			vis[b]=true;
			if(b==n-1) break;
			
			for(auto x:adj[b]){
				if(get<2>(x)<i) continue;
				if(!vis[get<0>(x)] && a+get<1>(x)<dis[get<0>(x)]){
					q.push(mp(a+get<1>(x),get<0>(x)));
					dis[get<0>(x)]=a+get<1>(x);
				}
			}
		}
		
		if(vis[n-1]) ans=max(ans, (i*int(1e6)/dis[n-1]));
		else break;
	}
	
	
	cout<<ans<<"\n";
	return 0;
}
