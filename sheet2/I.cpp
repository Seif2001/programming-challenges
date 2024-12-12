#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;



int meas[N];

int main(){
    ios_base::sync_with_stdio(false);
   cin.tie(NULL); 
   freopen("input.txt", "r", stdin);  
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
    int n;

    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>meas[i];
    }

    sort(meas, meas+n);

    int l = 0, maxSize = 0;
    for (int r = 0; r < n; r++) {
        // Ensure the condition meas[r] <= 2 * meas[l] is met
        while (meas[r] > 2 * meas[l]) {
            l++;
        }
        // Update the maximum size of the valid subset
        maxSize = max(maxSize, r - l + 1);
    }

    // Calculate the minimum number of measurements to remove
    cout << n - maxSize << endl;
}