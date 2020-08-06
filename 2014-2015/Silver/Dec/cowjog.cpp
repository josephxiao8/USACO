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
 
typedef priority_queue<pair<int,string>> pq;
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

ofstream cout ("cowjog.out");
ifstream cin ("cowjog.in");

ll n,t;
cin>>n>>t;

vpl v(n);
for(ll i=0; i<n; i++){
	ll a,b;
	cin>>a>>b;
	v[i]=mp(a,b);
}

ll ans=n;
ll pos;
bool caughtup=false;
for(ll i=n-2; i>=0; i--){
	ll a,b,c,d;
	tie(a,b)=v[i];
	tie(c,d)=v[i+1];
	
	ll pos1,pos2;
	if(caughtup) pos2=pos;
	else pos2=c+d*t;
	pos1=a+b*t;
	
	if(pos1>=pos2){
		ans--;
		caughtup=true;
		pos=pos2;
	}
	else caughtup=false;	
}

cout<<ans<<"\n";
return 0;
}
