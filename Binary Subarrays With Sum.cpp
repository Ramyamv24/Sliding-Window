#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int atmost(vector<int>& nums, int t) {
        if (t < 0) return 0;

        int l = 0;
        int wc = 0;
        int c = 0;

        for (int r = 0; r < nums.size(); r++) {
            wc += nums[r];

            while (wc > t) {
                wc -= nums[l];
                l++;
            }

            c += r - l + 1;
        }

        return c;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;

    int result = obj.numSubarraysWithSum(nums, goal);

    cout << "Number of subarrays with sum " << goal << " = " << result << endl;

    return 0;
}