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

ofstream cout ("blist.out");
ifstream cin ("blist.in");

int n;
cin>>n;
vector<tuple<int,int,int> > v;
int maxx=0;
for(int i=0; i<n; i++){
	int a,b,c;
	cin>>a>>b>>c;
	a--;
	b--;
	v.pb(make_tuple(a,b,c));
	maxx=max(maxx,b+1);
}

vi buckets(maxx,0);
for(auto x:v){
	int a,b,c;
	tie(a,b,c)=x;	
	for(int i=a; i<=b; i++) buckets[i]+=c;
}

int ans=0;
for(auto x:buckets) ans=max(ans,x);
cout<<ans<<endl;
return 0;
}
