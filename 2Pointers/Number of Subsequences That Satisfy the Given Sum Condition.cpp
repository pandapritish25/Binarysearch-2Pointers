#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
ll MOD = 1e9 + 7;

ll modular(ll n) {
    ll ans = ((n % MOD) + MOD) % MOD;
    return ans;
}
ll expo_dp(ll a, ll b) {
    a = modular(a) , b = modular(b);
    ll ans = 1;
    ans = modular(ans);
    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a;
            ans = modular(ans);
        }
        a = a * a;
        a = modular(a);
        b = b / 2;
    }
    ans = modular(ans);
    return ans;
}
int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin() , nums.end());
    ll ans = 0;

    int left = 0 , right = nums.size() - 1;

    while(left <= right) {
        ll target_sum = nums[left] + nums[right];
        if (target_sum <= target) {
            ll size = right - left;
            ll no_of_subsequence = expo_dp(2 , size);
            no_of_subsequence = modular(no_of_subsequence);
            ans = ans + no_of_subsequence;
            ans = modular(ans);
            left ++;
        }
        else right --;
    }
    ans = modular(ans);
    return ans;
 }
void solve() {
    int n , target; cin >> n >> target;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << numSubseq(v , target) << endl;
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