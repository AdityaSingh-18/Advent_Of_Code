#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ifstream file("Day10.txt");
    string s;
    int totalPress = 0;
    while (getline(file, s)) {
        int leftBrac  = s.find('['), rightBrac = s.find(']');
        string lights = s.substr(leftBrac + 1, rightBrac - leftBrac - 1);
        vector<vector<int>> buttons;
        for (int i = rightBrac + 1; i < s.size(); i++) {
            if (s[i] == '(') {
                int j = i + 1;
                while (j < s.size() && s[j] != ')')     j++;
                string button = s.substr(i + 1, j - i - 1);
                vector<int> nums;
                for (int k = 0; k < button.size(); k++){
                    string buttonNumber = "";
                    while(k < button.size() && button[k] != ','){
                        buttonNumber += button[k];
                        k++;
                    }
                    nums.push_back(stoi(buttonNumber));
                }
                buttons.push_back(nums);
                i = j;
            }
            if (s[i] == '{') break;
        }
        int n = buttons.size();
        int minPress = 1e9;
        for (int k = 1; k <= n; k++) {
            vector<int> comb(k);
            for (int i = 0; i < k; i++)     comb[i] = i;
            while (true) {
                string target(lights.size(), '.');
                for (int idx : comb) {
                    for (int x : buttons[idx]){
                        target[x] = (target[x] == '.' ? '#' : '.');
                    }
                }
                if(lights == target){
                    minPress = min (minPress, k);
                }
                int i;
                for (i = k - 1; i >= 0; i--) {
                    if (comb[i] != i + n - k) {
                        comb[i]++;
                        for (int j = i + 1; j < k; j++)     comb[j] = comb[j - 1] + 1;
                        break;
                    }
                }
                if (i < 0)     break;
            }
        }
        totalPress += minPress;
    }
    cout << totalPress << "\n";
}
