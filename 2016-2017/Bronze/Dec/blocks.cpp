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

ofstream cout ("blocks.out");
ifstream cin ("blocks.in");

int n;
cin>>n;
vi alpha(26,0);
for(int i=0; i<n; i++){
	string s1,s2;
	cin>>s1>>s2;
	
	vi temp1(26,0);
	for(auto c:s1){
		temp1[c-'a']++;
	}
	
	vi temp2(26,0);
	for(auto c:s2){
		temp2[c-'a']++;
	}
	
	for(int j=0; j<26; j++){
		alpha[j]+=max(temp1[j],temp2[j]);
	}
}

for(auto x:alpha) cout<<x<<endl;

return 0;
}
