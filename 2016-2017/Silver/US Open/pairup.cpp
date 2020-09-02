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

ofstream cout ("pairup.out");
ifstream cin ("pairup.in");

int n;
cin>>n;
vpi v;
for(int i=0; i<n; i++){
	int a,b;
	cin>>a>>b;
	v.pb(mp(b,a));
}
sort(v.begin(), v.end());

int l=0, r=n-1;
int ans=0;
while(l<=r){
	ans=max(ans,v[l].f+v[r].f);
	int sub=min(v[l].s,v[r].s);
	if(l==r) sub/=2;
	v[l].s-=sub;
	v[r].s-=sub;
	if(v[l].s==0) l++;
	if(v[r].s==0) r--;
}

cout<<ans<<"\n";
return 0;	
}

