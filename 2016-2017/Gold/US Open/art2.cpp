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
	
	ofstream cout ("art2.out");
	ifstream cin ("art2.in");
	
	int n;
	cin>>n;
	vpi pos(n+1, {-1,-1});
	vi v(n);
	
	for(int i=0; i<n; i++){
		int num;		
		cin>>num;
		v[i]=num;
		if(pos[num].f==-1) pos[num].f=i;
		pos[num].s=i;
	}
	
	stack<int> stac;
	for(int i=0; i<n; i++){
		if(v[i]==0){
			if(!stac.empty()){
				cout<<-1<<"\n";
				return 0;
			}
			continue;
		}
		if(!stac.empty() && stac.top()==v[i]) stac.pop();
		if(pos[v[i]].s!=i) stac.push(v[i]);
	}
	if(!stac.empty()){
		cout<<-1<<"\n";
		return 0;
	}
	
	vpi canvas(n,{0,0}); //paintcan method-pick/drop
	for(int i=1; i<=n; i++){
		if(pos[i].f==-1) continue;
		canvas[pos[i].f].f++;
		canvas[pos[i].s].s++;
	}
	
	int ans=0;
	int layers=0;
	for(int i=0; i<n; i++){
		layers+=canvas[i].f;
		ans=max(ans, layers);
		layers-=canvas[i].s;
	}
	
	cout<<ans<<"\n";
	return 0;
}
