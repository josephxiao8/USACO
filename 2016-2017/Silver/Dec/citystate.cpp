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

ofstream cout ("citystate.out");
ifstream cin ("citystate.in");

ll n, ans=0;
cin>>n;
multiset<pair<string,string> > sett;
for(ll i=0; i<n; i++){
	string s1,s2;
	cin>>s1>>s2;
	if(s2==s1.substr(0,2)) continue;
	ans+=ll(sett.count(mp(s2,s1.substr(0,2))));
	sett.insert(mp(s1.substr(0,2),s2));
}

cout<<ans<<"\n";
return 0;	
}
