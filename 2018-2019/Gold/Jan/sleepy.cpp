#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std; 
 
typedef long long ll;
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<ti> vti;
typedef vector<tl> vtl;
 
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int>> pqg;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound


int main() {
ios::sync_with_stdio(0);
cin.tie(0);
    
    ofstream cout ("sleepy.out");
    ifstream cin ("sleepy.in");
    
    int n;
    cin>>n;
    vi v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    indexed_set sett;
    for(int i=n-1; i>=0 && sett.order_of_key(v[i])==0; i--) sett.insert(v[i]);
    
    cout<<n-sett.size()<<"\n";
    int cnt=n-sett.size();
    int cnt2=cnt;
    vi ans;
    for(int i=0; i<cnt2; i++){
		cnt--;
		ans.pb(cnt+sett.order_of_key(v[i]));
		sett.insert(v[i]);
    }
	
    for(int i=0; i<ans.size(); i++){
		if(i!=0) cout<<" ";
		cout<<ans[i];
    }
    return 0;
}
