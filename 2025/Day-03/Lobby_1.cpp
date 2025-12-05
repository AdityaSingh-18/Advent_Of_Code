#include <bits/stdc++.h> 
using namespace std;  

int main(){ 
    ifstream file("Day03.txt"); 
    int totalSum = 0; 
    string s;
    while(file >> s){ 
        int n = s.size(), maxJolt = 0; 
        for(int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                int jolt = (s[i] - '0') * 10 + (s[j] - '0');
                if(jolt > maxJolt)  maxJolt = jolt;
            } 
        }
        totalSum += maxJolt;
    } 
    cout << totalSum << "\n";
}