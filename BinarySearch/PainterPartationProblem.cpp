#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

int check(const vector<int> &v , int mid , int k) {
    // lets assume that the number_of_painter is 1 and then we would be having time left with each painter as t
    int number_of_painter = 1;
    // time left is basically the mid value for the element
    int time_left_painter = mid;
    int ok = 1;

    for (int i = 0; i < v.size(); i++) {
        // now if the painter has time he would be painting the wall
        if (time_left_painter - v[i] >= 0) time_left_painter -= v[i];
        else {
            // else we would be needing another painter
            number_of_painter ++;
            time_left_painter = mid;
            // if after that this painter can paint then good
            if (time_left_painter - v[i] >= 0) {
                time_left_painter -= v[i];
            }
            // else if the time is only much more then we would be needing to break;
            else {
                // computing the ok not to take the values
                ok = 0;
                break;
            }
        }
    }
    // in case ok is 1 then only return the values
    if (ok == 1 && number_of_painter <= k) return true;
    return false;
}
void solve() {  
    int n , k; cin >> n >> k;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    int ans = -1;
    // like suppose you have n painters then the value would be max element
    int lo = *max_element(v.begin() , v.end());
    // just taking the max value
    // hi can be basically the sum for all elements 
    int hi = 0;
    for (auto x : v) hi += x;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        // then we have made the check function
        if (check(v , mid , k)) {
            ans = mid; hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ans << endl;
}  


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t;
    while (t --) {
        solve();
    }
}
