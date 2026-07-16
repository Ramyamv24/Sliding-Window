#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0, result = 0;

        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;

            while (count.size() > 2) {
                count[fruits[left]]--;

                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }

                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> fruits = {1, 2, 1, 2, 3, 2, 2};

    int ans = obj.totalFruit(fruits);

    cout << "Maximum number of fruits collected: " << ans << endl;

    return 0;
}