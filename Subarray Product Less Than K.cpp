#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int l = 0;
        int p = 1;
        int c = 0;

        for (int i = 0; i < nums.size(); i++) {
            p *= nums[i];

            while (p >= k) {
                p /= nums[l];
                l++;
            }

            c += i - l + 1;
        }

        return c;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;

    int result = obj.numSubarrayProductLessThanK(nums, k);

    cout << "Number of subarrays with product less than " << k << " = " << result << endl;

    return 0;
}