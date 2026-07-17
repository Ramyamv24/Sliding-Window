#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int target) {
        if (target < 0) return 0;

        int left = 0, oddCount = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1)
                oddCount++;

            while (oddCount > target) {
                if (nums[left] % 2 == 1)
                    oddCount--;
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;

    int result = obj.numberOfSubarrays(nums, k);

    cout << "Number of nice subarrays = " << result << endl;

    return 0;
}