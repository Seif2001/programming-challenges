#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5; // Correct array size
int values[N];

long long prefix[N];
long long prefixSorted[N];
int l[N], r[N], m[N];

int main(){
    int n;
    cin >> n;
    
    // Input values
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int q;
    cin >> q;


    // Input queries
    for(int i = 0; i < q; i++) {
        cin >> m[i] >> l[i] >> r[i];
    }

    // Calculate prefix sums for the original array
    prefix[0] = values[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + values[i];
    }

    // Sort the array and calculate prefix sums for the sorted array
    sort(values, values + n);

    prefixSorted[0] = values[0];
    for(int i = 1; i < n; i++) {
        prefixSorted[i] = prefixSorted[i - 1] + values[i];
    }

    // Answer queries
    for(int i = 0; i < q; i++) {
        int lo = l[i] - 1;  // Convert to 0-based index
        int ri = r[i] - 1;  // Convert to 0-based index
        int t = m[i];

        if(t == 1) {  // Query on the original array
            long long result = prefix[ri] - (lo > 0 ? prefix[lo - 1] : 0);
            cout << result << endl;
        }
        else {  // Query on the sorted array
            long long result = prefixSorted[ri] - (lo > 0 ? prefixSorted[lo - 1] : 0);
            cout << result << endl;
        }
    }

    return 0;
}
