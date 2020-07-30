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

ofstream cout ("tracing.out");
ifstream cin ("tracing.in");

int n,t; 
string s;
cin>>n>>t>>s;

vector<tuple<int,int,int> > v(t);
for(int i=0; i<t; i++){
	int a,b,c;
	cin>>a>>b>>c;
	b--;
	c--;
	v[i]= make_tuple(a,b,c);
}
sort(v.begin(), v.end());

int x=0,y=INT_MAX,z=INT_MIN;
for(int j=0; j<n; j++){
	
	if(s[j]=='0') continue;
	bool goodcase=false;
	
	for(int k=0; k<=t; k++){
		string comp(n,'0');
		comp[j]='1';
		vi handshake(n,0);
		
		for(auto x:v){
			int a,b,c;
			tie(a,b,c)=x;
			if(comp[b]=='1' && comp[c]=='0'){
				if(handshake[b]<k) {
					handshake[b]++;
					comp[c]='1';
				}
			}
			else if(comp[c]=='1' && comp[b]=='0'){
				if(handshake[c]<k) {
					handshake[c]++;
					comp[b]='1';
				}
			}
			else if(comp[c]=='1' && comp[b]=='1'){
				if(handshake[c]<k) handshake[c]++;
				if(handshake[b]<k) handshake[b]++;
			}
		}
		
		if(comp==s) {
			goodcase=true;
			y=min(y,k);
			z=max(z,k);
		}
	}
	if(goodcase) x++;
}

cout<<x<<" "<<y<<" ";
if(z==t) cout<<"Infinity"<<endl;
else cout<<z<<endl;
return 0;
}
