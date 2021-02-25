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

	ofstream cout ("balance.out");
	ifstream cin ("balance.in");
	
	ll n;
	cin>>n;
	vl v(2*n);
	for(ll i=0; i<2*n; i++) cin>>v[i];
	
	ll a0=0;
	ll a1=0;
	ll b0=0;
	ll b1=0;
	ll a=0;
	ll b=0;
	for(ll i=0; i<n; i++){
		if(v[i]==0) a+=a1;
		else a1++;
	}
	for(ll i=n; i<2*n; i++){
		if(v[i]==0) {
			b+=b1;
			b0++;
		}
		else b1++;
	}
	
	//1-> <-0
	ll ans=abs(b-a);
	b1=0;
	ll l=n-1, r=n, c=0;
	while(a1!=0 && b0!=0){
		while(v[l]!=1){
			a0++;
			l--;
		}
		while(v[r]!=0){
			b1++;
			r++;
		}
		a-=a0;
		b-=b1;
		a1--;
		b0--;
		c+=r-l;
		r++;
		l--;
		a+=a1;
		b+=b0;
		a0++;
		b1++;
		ans=min(ans,abs(b-a)+c);
	}
	
	a0=0;
	a1=0;
	b0=0;
	b1=0;
	a=0;
	b=0;
	for(ll i=0; i<n; i++){
		if(v[i]==0) {
			a+=a1;
			a0++;
		}
		else a1++;
	}
	for(ll i=n; i<2*n; i++){
		if(v[i]==0) {
			b+=b1;
			b0++;
		}
		else b1++;
	}
	
	//0-> <-1
	l=n-1;
	r=n;
	c=0;
	while(a0!=0 && b1!=0){
		while(v[l]!=0){
			a1--;
			l--;
		}
		while(v[r]!=1){
			b0--;
			r++;
		}
		a-=a1;
		b-=b0;
		a0--;
		b1--;
		c+=r-l;
		r++;
		l--;
		ans=min(ans,abs(b-a)+c);
	}
	
	cout<<ans<<"\n";
	return 0;	
}
