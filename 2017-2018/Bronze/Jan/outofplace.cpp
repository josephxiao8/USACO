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

ofstream cout ("outofplace.out");
ifstream cin ("outofplace.in");

int n;
cin>>n;

vi v(n);
vi sorted(n);
for(int i=0; i<n; i++) {
	cin>>v[i];
	sorted[i]=v[i];
}
sort(sorted.begin(), sorted.end());

int posl=-1, posr=-1;
for(int i=0; i<n; i++){
	if(v[i]!=sorted[i]){
		posl=i;
		break;
	}
}

for(int i=n-1; i>=0; i--){
	if(v[i]!=sorted[i]){
		posr=i;
		break;
	}
}

if(posl==-1 && posr==-1){
	cout<<0<<endl;
	return 0;
}

int doubles=0;
for(int i=posl; i<posr-1; i++){
	if(v[i]==v[i+1]) doubles++;
}

cout<<abs(posl-posr)-doubles<<endl;
return 0;
}
