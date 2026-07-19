#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int target) {
        if (target <= 0) return 0;

        unordered_map<int, int> count;
        int left = 0, result = 0;

        for (int right = 0; right < nums.size(); right++) {
            count[nums[right]]++;

            while (count.size() > target) {
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]);
                }
                left++;
            }

            result += right - left + 1;
        }

        return result;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> k;

    Solution obj;
    cout << obj.subarraysWithKDistinct(nums, k) << endl;

    return 0;
}