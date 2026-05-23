// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
long long countSubarrays(vector<int>& nums, long long k) {
    ll n = nums.size() , head = -1 , tail = 0 , ans = 0 , sum = 0;
    while (tail < n) {
        while (head + 1 < n) {
            ll needed_sum = sum + nums[head + 1];ll size = head - tail + 2; 
            ll prod = needed_sum * size;
            if (prod < k) {
                sum = sum + nums[head + 1];
                head ++;
            }
            else break;
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            ll deleted_sum = nums[tail];
            sum = sum - deleted_sum;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            sum = 0;
        }
    }
    return ans;
}

void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << countSubarrays(v , k) << endl;
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