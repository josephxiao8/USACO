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
typedef priority_queue<int,vector<int>,greater<int>> pqg;
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

	ofstream cout ("sort.out");
	ifstream cin ("sort.in");

	int n;
	cin>>n;
	vpi v(n);
	vpi sorted(n);
	indexed_set sett;
	for(int i=0; i<n; i++){
		cin>>v[i].f;
		sorted[i].f=v[i].f;
		sorted[i].s=i;
	}
	
	sort(sorted.begin(), sorted.end());
	for(int i=0; i<n; i++) v[sorted[i].s].s=i;

	

	int ans=0;
	bool notzero=false;
	for(int i=0; i<n; i++){
		sett.insert(v[i].s);
		ans=max(ans,int(i+1-sett.order_of_key(i+1)));
		if(int(i+1-sett.order_of_key(i+1)!=0)) notzero=true;
	}
	
	if(!notzero) cout<<1<<"\n";
	else cout<<ans<<"\n";
	return 0;
}
