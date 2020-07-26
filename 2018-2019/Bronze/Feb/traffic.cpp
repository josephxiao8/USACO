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

ofstream cout ("traffic.out");
ifstream cin ("traffic.in");

int n;
cin>>n;

vector<pair<string,pi> > v;
for(int i=0; i<n; i++){
	string s;
	int a,b;
	cin>>s>>a>>b;
	v.pb(mp(s,mp(a,b)));
	
}

bool good=false;
int l=INT_MIN;
int r=INT_MAX;
for(int i=n-1; i>=0; i--){
	string s;
	int a,b;
	s=v[i].f;
	tie(a,b)=v[i].s;
	
	if(s=="on") {
		if(good){
			l-=b;
			r-=a;
		}
	}
	
	else if(s=="off") {
		if(good){
			l+=a;
			r+=b;
		}
	}
	
	else{
		l=max(l,a);
		r=min(r,b);
		good=true;
	}
}
if(l<0) l=0;
if(r<0) r=0;
cout<<l<<" "<<r<<endl;

good=false;
l=INT_MIN;
r=INT_MAX;
for(int i=0; i<n; i++){
	string s;
	int a,b;
	s=v[i].f;
	tie(a,b)=v[i].s;
	
	if(s=="on") {
		if(good){
			l+=a;
			r+=b;
		}
	}
	
	else if(s=="off") {
		if(good){
			l-=b;
			r-=a;
		}
	}
	
	else{
		l=max(l,a);
		r=min(r,b);
		good=true;
	}
}
if(l<0) l=0;
if(r<0) r=0;
cout<<l<<" "<<r<<endl;

return 0;
}
