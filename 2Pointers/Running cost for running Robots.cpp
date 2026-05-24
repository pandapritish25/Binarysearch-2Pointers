#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    ll head = -1 , tail = 0 , sum = 0 , ans = 0;
    ll n = chargeTimes.size(); multiset<ll> x;
    while (tail < n) {
        while(head + 1 < n) {
            x.insert(chargeTimes[head + 1]);
            sum = sum + runningCosts[head + 1];
            ll rcost = (head - tail + 2) * sum; 
            ll f_cost = *x.rbegin() + rcost;
            if (f_cost <= budget) head ++;
            else {
                sum = sum - runningCosts[head + 1];
                auto it1 = x.find(chargeTimes[head + 1]);
                if (it1 != x.end()) x.erase(it1);
                break;
            }
        }
        ans = max(ans , head - tail + 1);
        if (tail <= head) {
            auto it1 = x.find(chargeTimes[tail]);
            if (it1 != x.end()) x.erase(it1);
            sum = sum - runningCosts[tail];
            tail ++;
        }
        else {
            tail ++; head = tail - 1;
            x.clear(); sum = 0;
        }
    }
    return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> x(n) , y(n); for (int i = 0; i < n; i++) cin >> x[i]; for (int i = 0; i < n; i++) cin >> y[i];
  int b; cin >> b;
  cout << maximumRobots(x , y , b) << endl;
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