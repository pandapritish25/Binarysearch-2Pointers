#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

using ll = long long;
ll ceil_div(ll n){
    if (n % 2 == 0) {
        ll ans1 = n / 2; ll ans2 = n + 1; ll ans = ans1 * ans2 * 1LL; return ans;
    }
    else {
        ll ans1 = (n + 1) / 2; ll ans2 = n; ll ans = ans1 * ans2 * 1LL; return ans;
    }
    return 0;
}

int medianOfUniquenessArray(vector<int>& nums) {
    int n = nums.size();
    ll size = ceil_div(n) , median = (size + 1) / 2;
    auto check = [&](ll mid) {
        ll freq[100010]; memset(freq , 0 , sizeof(freq));
        ll distinct = 0;
        ll head = -1 , tail = 0 , ans = 0;
        while (tail < n) {
            while ((head + 1 < n) && (distinct < mid || freq[nums[head + 1]] > 0)) {
                head ++; if (freq[nums[head]] == 0) distinct ++;
                freq[nums[head]] ++;
            }
            ans = ans + (head - tail + 1);
            if (tail <= head) {
                freq[nums[tail]] --; if (freq[nums[tail]] == 0) distinct --;
                tail ++;
            }
            else {
                tail ++; head = tail - 1;
                memset(freq , 0 , sizeof(freq));
            }
        }
        return ans;
    };

    ll lo = 0 , hi = nums.size() , ans = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid) >= median) ans = mid , hi = mid - 1;
        else lo = mid + 1;
    }
    return ans;
}


void solve() {
  int n; cin >> n; vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];

  cout << medianOfUniquenessArray(v) << endl;
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