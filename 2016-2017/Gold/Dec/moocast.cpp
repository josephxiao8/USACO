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
typedef priority_queue<ti,vector<ti>,greater<ti>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int n;
vi parent;
vi size;

//DSU
void init() {
    for (int i = 0; i <n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}
 
int find(int node) {
    if (parent[node] != node) {
		parent[node] = find(parent[node]);
	}
    return parent[node];
}
 
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (size[a] < size[b]) swap(a,b);
    
	parent[b]=a;
	size[a]+=size[b];
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("moocast.out");
	ifstream cin ("moocast.in");
	
	cin>>n;
	vpi v(n);
	for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s;
	
	pqg q;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int a,b,c,d;
			tie(a,b)=v[i];
			tie(c,d)=v[j];
			q.push(mt((a-c)*(a-c)+(b-d)*(b-d),i,j));
		}
	}
	
	parent=vi(n);
	size=vi(n);
	init();
	
	int cnt=n;
	int ans=0;
	while(cnt!=1){
		int a,b,c;
		tie(a,b,c)=q.top(); q.pop();
		if(find(b)!=find(c)){
			cnt--;
			unite(b,c);
			ans=a;
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}
