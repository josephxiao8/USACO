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
typedef priority_queue<pi,vector<pi>,greater<pi> > pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


ll n,k,m; 
bool possible(ll ans){
	ll tempn=n;
	ll days=0;
	while(tempn>0){
		ll y=tempn/ans;
		if(y>m){
			ll g=tempn-(ans*y)+1;
			ll consecutive_days=ll((g+y-1)/y);
			tempn-=y*consecutive_days;
			days+=consecutive_days;
		}
		else{
			days+=ll((tempn+m-1)/m);
			break;
		}
	}
	
	if(days<=k) return true;
	else return false;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("loan.out");
ifstream cin ("loan.in");

cin>>n>>k>>m;

ll ans=0;
for(ll b=n/2; b>=1; b/=2){
	while(ans+b<=n && possible(ans+b)) ans+=b;
}

cout<<ans<<"\n";
return 0;	
}

