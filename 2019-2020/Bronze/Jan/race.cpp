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


ll k;

ll time(ll speed,ll x){
	ll time=0;
	ll dis=0;
	time+=speed;
	dis+=((speed)*(speed+1))/2;
	
	if(dis>k) {
		time=1e9;
		return time;
	}
	
	if(speed<=x){
		time+=(k-dis)/speed;
		dis+=((k-dis)/speed)*speed;
		
		if(dis<k) time++;
	}
	
	else{
		time+=(speed-x);
		dis+=((speed-x)*(speed-1+x))/2;
		
		if(dis>k) {
			time=1e9;
			return time;
		}
		
		time+=(k-dis)/speed;
		dis+=((k-dis)/speed)*speed;
		
		if(dis<k) time++;
	}
	
	return time;
}

ll binary(ll x){ //binary gives the maximum speed that can possible be achevied anywhere in the interval given the constraints
	ll speed=1;
	int n=1e5;
	for(ll b=n/2; b>=1; b/=2){
		while(speed+b<=n && time(speed+b,x)!=1e9) speed+=b;
	}
	return speed;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("race.out");
ifstream cin ("race.in");

ll n;
cin>>k>>n;
for(ll i=0; i<n; i++){
	ll x;
	cin>>x;
	cout<<time(binary(x),x)<<endl;
}

return 0;
}
