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
	
	ofstream cout ("bphoto.out");
	ifstream cin ("bphoto.in");
	
	int n;
	cin>>n;
	
	vi prefix(n);
	vi suffix(n);
	vi v(n);
	
	indexed_set sett;
	for(int i=0; i<n; i++){
		cin>>v[i];
		prefix[i]=sett.size()-sett.order_of_key(v[i]);
		sett.insert(v[i]);
	}
	
	indexed_set sett2;
	for(int i=n-1; i>=0; i--){
		suffix[i]=sett2.size()-sett2.order_of_key(v[i]);
		sett2.insert(v[i]);
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		if(prefix[i]>2*suffix[i] || 2*prefix[i]<suffix[i]) ans++;
	}
	
	cout<<ans<<"\n";
	return 0;
}
