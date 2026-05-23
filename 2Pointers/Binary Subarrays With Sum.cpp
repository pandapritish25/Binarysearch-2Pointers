#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

ll func(vector<int> &nums , int k) {
    ll head = -1 , tail = 0 , n = nums.size() , sum = 0 , ans = 0;
    while (tail < n) {
        while (head + 1 < n && sum + nums[head + 1] <= k) {
            head ++; 
            sum = sum + nums[head];
        }
        ans = ans + (head - tail + 1);
        if (tail <= head) {
            sum = sum - nums[tail];
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }
    return ans;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return func(nums , goal) - func(nums , goal - 1);
}
void solve() {
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << numSubarraysWithSum(v , k) << endl;
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