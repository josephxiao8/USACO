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


vi bit; 
int n;

int sum(int k){ 
	int s=0;
	while(k>=1){
		s+=bit[k];
		k-=k&-k;
	}
	return s;
}

void add(int k,int x){
	while(k<=n){
		bit[k]+=x;
		k+=k&-k;
	}
}

bool comp(pi a, pi b){
	if(a.f==b.f) return a.s>b.s;
	else return a.f>b.f;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

	ofstream cout ("haircut.out");
	ifstream cin ("haircut.in");
	
	cin>>n;
	vpi v(n);
	for(int i=0; i<n; i++){
		cin>>v[i].f;
		v[i].s=i;
	}
	sort(v.begin(), v.end(), comp);
	
	bit=vi(n+1,0);
	vl ans(n+1,0);
	
	int idx=0;
	for(int i=n; i>=0; i--){
		if(i!=n) ans[i]=ans[i+1];
		while(idx<n && v[idx].f==i){
			ans[i]+=sum(v[idx].s+1);
			add(v[idx].s+1,1);
			idx++;
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<ans[0]-ans[i]<<"\n";
	}
	
	return 0;	
}
