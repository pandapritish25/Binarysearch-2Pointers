//https://leetcode.com/problems/boats-to-save-people/description/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

using ll = long long;
int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin() , people.end());
    ll left = 0 , right = people.size() - 1 , count = 0;
    while(left <= right) {
        ll total_weight = people[left] + people[right];

        if (total_weight <= limit) {
            left ++ , right -- , count ++;
        }
        else if (total_weight > limit) {
            right --; count ++;
        }
    }
    return count;
}

void solve() {
    int n , limit; cin >> n >> limit;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
    cout << numRescueBoats(v , limit) << endl;
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