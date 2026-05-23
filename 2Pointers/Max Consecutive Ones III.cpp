#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int count1 = 0 , count0 = 0;
    int head = -1 , tail = 0 , sum = 0 , ans = 0;

    while(tail < n) {
        while(head + 1 < n && (count0 < k || nums[head + 1] == 1)) {
            head ++;
            if (nums[head] == 0) count0 ++;
        }
        ans = max(ans , head - tail + 1);
        if (tail <= head) {
            if (nums[tail] == 0) count0 --;
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
        }
    }
    return ans;
}
void solve() {
    int n , x; cin >> n >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << longestOnes(v , x) << endl;
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