//https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

int minLength(vector<int>& nums, int k) {
    ll ans = 1e9 , head = -1 , tail = 0 , sum = 0 , n = nums.size();
    ll freq[100100]; 
    memset(freq, 0, sizeof(freq));

    while(tail < n) {
        while(head + 1 < n && sum < k) {
            head ++; 
            if (freq[nums[head]] == 0) sum += nums[head];
            freq[nums[head]] ++;
        }
        if (sum >= k) {
            ll c_size = head - tail + 1;
            ans = min(ans , c_size);
        }
        if (tail <= head) {
            freq[nums[tail]] --;
            if (freq[nums[tail]] == 0) sum -= nums[tail];
            tail ++;
        }
        else {
            tail ++; head = tail - 1; memset(freq , 0 , sizeof(freq));
        }
    }
    if (ans == 1e9) return -1;
    return ans;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    int k; cin >> k;
    cout << minLength(v , k) << endl;
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