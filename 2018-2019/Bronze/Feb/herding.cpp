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

ofstream cout ("herding.out");
ifstream cin ("herding.in");

int a,b,c;
cin>>a>>b>>c;

if(b-a==1 && c-b==1) cout<<0<<endl<<0<<endl;
else {
	int temp1=b-a,temp2=c-b;
	if(temp1==1) temp1=INT_MAX;
	if(temp2==1) temp2=INT_MAX;
	cout<<min(2,min(temp1,temp2)-1)<<endl<<max(b-a,c-b)-1<<endl;
}

return 0;	
}
