#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {

            // Remove indices outside the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Store the maximum of the current window
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter window size (k): ";
    cin >> k;

    vector<int> result = obj.maxSlidingWindow(nums, k);

    cout << "Maximum of each sliding window: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}