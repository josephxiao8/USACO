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

ofstream cout ("cowcode.out");
ifstream cin ("cowcode.in");

string s;
ll n;
cin>>s>>n;

ll pos=n-1;
for(ll i=ceil(log(ceil(n/double(s.size())))/log(2)); i>0; i--){
	ll temp=s.size()*ll(pow(2,i-1));
	if(pos>=temp) pos=(pos%temp-1+temp)%temp;
}

cout<<s[pos]<<"\n";
return 0;
}
