#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int countOne = 0, countTwo = 0, countThree = 0;
    for (int i = 0; i<s.size(); i++){
        if (s[i] == '1'){
            countOne++;
        }
        else if (s[i] == '2'){
            countTwo++;
        }
        else if (s[i] == '3'){
            countThree++;
        }
    }
    string result = "";
    for (int i = 0; i<countOne; i++){
        result += "1+";
    }
    for (int i = 0; i<countTwo; i++){
        result += "2+";
    }
    for (int i = 0; i<countThree; i++){
        result += "3+";
    }
    result.pop_back();
    cout << result;
}