#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        int missing = t.size();
        int left = 0, bestLeft = 0, bestRight = 0;

        for (int right = 0; right < s.size(); right++) {

            if (need[s[right]] > 0)
                missing--;

            need[s[right]]--;

            if (missing == 0) {

                while (need[s[left]] < 0) {
                    need[s[left]]++;
                    left++;
                }

                if (bestRight == 0 || right - left < bestRight - bestLeft) {
                    bestLeft = left;
                    bestRight = right + 1;
                }

                need[s[left]]++;
                missing++;
                left++;
            }
        }

        return s.substr(bestLeft, bestRight - bestLeft);
    }
};

int main() {
    Solution obj;

    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    string ans = obj.minWindow(s, t);

    cout << "Minimum Window Substring: " << ans << endl;

    return 0;
}