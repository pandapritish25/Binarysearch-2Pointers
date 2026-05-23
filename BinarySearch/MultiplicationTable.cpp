#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// check function to exactly check the no of elements means that in each row we have col no of elements and that no of elements can be taken
// thus we can say that each row has col no of elements and only that many no of things can be taken 

// thus this is a problem and based on finding the kth element which means no of elements <= x should be greater than equal to k then you can have the search space
int check(const int &rows , const int &cols , int mid , int k) {
    int sum = 0;
    for (int i = 1; i <= rows; i++) {
        // we would be needing to take the min value apart from that we wont be able to take anything 
        // like min of col elements and no of elements taken
        int ans1 = min(cols , mid / i);
        sum += ans1;
    }
    return sum >= k;
}

void solve() {  
    int rows , cols , n; cin >> rows >> cols >> n;

    int lo = 1; int hi = rows * cols;
    int ans = -1;
    // then we would be doing basic binary search
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(rows , cols , mid , n)) {
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
    // cin >> t;
    while (t --) {
        solve();
    }
}
