#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;


int shortestSubarray(vector<int>& nums, int k) {
    ll n = nums.size() , sum = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    ll ansx = 1e9; 
    // one of the most important questions to be remembered because what happens is
    // you always need to push the 0 , -1 because that would be the bare minimum comparision needed for you to check
    // in case you can go ahead for this or not because this is one of the genuine conditions needed tp check

    // remember one more thing dont subtract as you are directly having the prefix_sum
    pq.push({0,-1}); 

    for (int i = 0; i < n; i++) {
        sum = sum + nums[i];

        while (!pq.empty() && sum - pq.top().first >= k) {
            pair<ll,ll> ans1 = pq.top();
            ll size = i - ans1.second;
            ansx = min(ansx , size); 
            pq.pop();
        }
        pq.push({sum , i});
        
    }
    if (ansx == 1e9) return -1;
    return ansx;
}
void solve() {    
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int x; cin >> x;
    cout << shortestSubarray(v , x) << endl;
}                        
signed main() {                                                                    
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}