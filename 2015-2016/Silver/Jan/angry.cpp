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


int divide(int x,vi v){
	int l=0;
	int r=1;
	int counter=0;
	
	while(l!=v.size()){
		while(r<v.size() && v[r]-v[l]+1<=2*x+1){
			r++;
		}
		counter++;
		l=r;
		r=l+1;
	}
	return counter;
}

int main() {
ios::sync_with_stdio(0);
cin.tie(0);

ofstream cout ("angry.out");
ifstream cin ("angry.in");

int n,k;
cin>>n>>k;

if(n==1){
	cout<<0<<"\n";
	return 0;
}

vi v(n);
for(int i=0; i<n; i++) cin>>v[i];
sort(v.begin(), v.end());

int ans=0;
for(int b=(v[v.size()-1]-v[0])/2; b>=1; b/=2){
	while(divide(ans+b,v)>k) ans+=b;
}

cout<<ans+1<<"\n";
return 0;	
}
