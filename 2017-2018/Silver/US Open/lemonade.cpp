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
typedef priority_queue<pi,vector<pi>,greater<pi>> pqg;
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

ofstream cout ("lemonade.out");
ifstream cin ("lemonade.in");

int n;
cin>>n;
multiset<int> sett;;
for(int i=0; i<n; i++){
	int temp;
	cin>>temp;
	sett.insert(temp);
}


int ans=0;
while(!sett.empty()){
	if(*(sett.begin())<ans){
		sett.erase(sett.begin());
	}
	else{
		sett.erase(--sett.end());
		ans++;
	}
}

cout<<ans<<"\n";
return 0;	
}

