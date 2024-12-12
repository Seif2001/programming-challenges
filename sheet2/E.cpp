#include<bits/stdc++.h>

using namespace std;

long long r;

int st[3];
int p[3];
int n[3];

bool ok(long long x){
    long long k = 0ll;
    for(int i = 0; i<3; i++){
        long long m = st[i] * x - n[i];
        if(m > 0){
            k += m * p[i];
        }
        if(k>r){
            return false;
        }
    }
    return k<=r;
}

int main(){
    string str;
    cin>>str;

    for(int i = 0; i<3; i++){
        cin>>n[i];
    }

    for(int i = 0; i<3; i++){
        cin>>p[i];
    }

    cin >> r;

    int j = 0;

    while (j<str.size()) {
        if(str[j] == 'B'){
            st[0]++;
        }

        if(str[j] == 'S'){
            st[1]++;
        }

        if(str[j] == 'C'){
            st[2]++;
        }
        j++;
    }


    long long s = 0;
    long long e = 1e13;

    while(e - s > 1){
        long long mid = s + (e - s)/2;
        //cout<<s<<" "<<e<< " " << mid << endl;

        if(ok(mid)) s = mid;

        else e = mid;

    }

    cout<<s<<endl;

    
}