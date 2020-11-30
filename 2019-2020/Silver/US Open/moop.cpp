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
typedef priority_queue<pl,vector<pl>,greater<pl>> pqg;
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

ofstream cout ("moop.out");
ifstream cin ("moop.in");

int n;
cin>>n;

vpi v(n);
for(int i=0; i<n; i++) cin>>v[i].f>>v[i].s;
sort(v.begin(), v.end());
for(int i=0; i<n; i++) v[i]=mp(v[i].s,i);

vpi minn(n);
minn[0]=v[0];
for(int i=1; i<n; i++){
	if(v[i].f>=minn[i-1].f) minn[i]=minn[i-1];
	else minn[i]=v[i];
}

vpi maxx(n);
maxx[n-1]=v[n-1];
for(int i=n-2; i>=0; i--){
	if(v[i].f<=maxx[i+1].f) maxx[i]=maxx[i+1];
	else maxx[i]=v[i];
}

int ans=1;
for(int i=0; i<n-1; i++){
	if(minn[i]>maxx[i+1]) ans++;
}

cout<<ans<<"\n";
return 0;
}
