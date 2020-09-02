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

ofstream cout ("homework.out");
ifstream cin ("homework.in");

int n;
cin>>n;
vi prefix(n+1);
prefix[0]=0;

int sum=0;
for(int i=1; i<=n; i++){
	int temp;
	cin>>temp;
	sum+=temp;
	prefix[i]=sum;
}

double avg=0;
vi ans;
for(int i=1; i<=n-2; i++){
	double temp=double(sum-prefix[i])/(n-i);
	if(temp>avg){
		avg=temp;
		ans.clear();
		ans.pb(i);
	}
	else if(temp==avg){
		ans.pb(i);
	}
}

for(auto x:ans) cout<<x<<"\n";
return 0;	
}

