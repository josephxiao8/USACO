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

ofstream cout ("moobuzz.out");
ifstream cin ("moobuzz.in");

int n;
cin>>n;
int ans=n;
int counter=n/3 + n/5 - n/15;
while(counter!=0){
	int ans2=ans+counter;
	int counter2=ans2/3+ans2/5-ans2/15-ans/3-ans/5+ans/15;
	ans=ans2;
	counter=counter2;
}

cout<<ans<<"\n";
return 0;	
}

