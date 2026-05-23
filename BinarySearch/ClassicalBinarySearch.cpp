#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long


// classical binary search , just search an element inside an array 

int classical_binary_search(vector<int> v , int n) {
    // redefining the lo and hi and also the ans
    int lo = 0; int hi = v.size() - 1; int ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] > n) {
            ans = mid; 
            hi = mid - 1;
        }
        else if (v[mid] > n) {
             hi = mid - 1;
        }
        else if (v[mid] < n) {
             lo = mid + 1;
        }
    }

    if (ans > 0) {
        cout << v[ans] << " The ans is found at index \n" << endl;
        return ans;    
    }
    else {
        cout << "The ans is not found \n";
        return ans;
    }

    return ans;
}
void solve() {
    int n; cin >> n; int x; cin >> x;
    vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];

    cout << classical_binary_search(v , x) << endl;
}


signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t --) {
        solve();
    }
}
