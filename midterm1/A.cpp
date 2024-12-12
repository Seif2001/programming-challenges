#include <bits/stdc++.h>

using namespace std;

map<int, int> factors;
map<int, int> factors_x;
void factorial_factorize(int n) {
    for(int x = 2; x*x <= n; x++){
        int temp = x;
        for (int i = 2; i*i <= x; ++i) {
            while (temp % i== 0) {
                factors[i]++;
                
                temp /= i;
                
            }
            
        }
            if (temp != 1)
                factors[temp]++;
    }
}

void factorize(int n) {
    for (int i = 2; i * i <= n; ++i) {
        int power = 0;
        while (n % i== 0) {
            ++power;
            n /= i;
        }
        if (power > 0)
            factors_x[i] = power;
    }
        if (n != 1)
            factors_x[n] = 1;
}

int main(){
    int n, x;

    cin >> n >> x;
    factorial_factorize(n);
    factorize(x);

    int mini = INT_MAX;
    for(int i = 0; i < factors_x.size(); i++){
        if(factors_x[i] == 0){
            continue;
        }
    mini = min(mini, factors[i]/factors_x[i]);
    }

    
    cout<<mini<<endl;
}