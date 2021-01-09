#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std; 
using namespace __gnu_pbds;
 
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


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
	
	ofstream cout ("snowboots.out");
	ifstream cin ("snowboots.in");
	
	int n,b;
	cin>>n>>b;
	
	pqg q;
	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		if(i==0 || i==n-1) continue;
		q.push(mp(a,i));
	}
	
	vti queries(b);
	for(int i=0; i<b; i++) {
		int depth,step;
		cin>>depth>>step;
		queries[i]=mt(depth,step,i);
	}
	sort(queries.begin(), queries.end());
	
	vi ans(b,0);
	set<int> tiles;
	tiles.insert(0);
	tiles.insert(n-1);
	multiset<int> dis;
	dis.insert(n-1);
	for(int i=0; i<b; i++){
		int depth, step, pos;
		tie(depth, step, pos)=queries[i];
		while(!q.empty() && q.top().f<=depth){
			int pos2=q.top().s; q.pop();
			
			auto ut=tiles.ub(pos2);
			auto lt=--tiles.ub(pos2);
			tiles.insert(pos2);
			
			dis.erase(dis.find(*ut-*lt));
			dis.insert(pos2-*lt);
			dis.insert(*ut-pos2);
		}
		if(*dis.rbegin()<=step) ans[pos]=1;
	}
	
	for(auto x:ans) cout<<x<<"\n";
	return 0;
}
