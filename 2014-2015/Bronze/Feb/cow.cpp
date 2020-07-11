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

ofstream cout ("cow.out");
ifstream cin ("cow.in");

ll letters;
cin>>letters;
string s;
cin>>s;
string comp="COW";
int counter=0;
vector<pair<ll,char>> ans;

for(auto x:s){
	
	if(x==comp[counter] && counter<3){  // first time appearing in order C,O,W
			counter++;
			ans.pb(mp(1,x));
	}
	
	else { 
		for(int i=0; i<counter; i++){
				if(x==comp[i]){ 
					if(ans.back().s==x) ans.back().f++;
					else ans.pb(mp(1,x));	
				}	
		}
	}
}


ll times=0;
ll c=0;
ll o=0;
ll co=0;
ll w=0;
for(auto x:ans){
	if(x.s=='C') {
		c+=x.f;
	}
	else if(x.s=='O') {
		o=0;
		o+=x.f;
		co+=c*o;
	}
	else{
		w=0;
		w+=x.f;
		times+=co*w;
	}		
}
cout<<times<<endl;


return 0;
}
