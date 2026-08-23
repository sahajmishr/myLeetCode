class Solution {
public:
  bool canSplit(const std::vector<int>& nums, int k, int maxSum) {
        int currentSum = 0;
        int subarraysCount = 1;
// should be ashamed of me ...mate
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                currentSum = num;
                subarraysCount++;
                if (subarraysCount > k) {
                    return false;
                }
            } else {
                currentSum += num;
            }
        }
        return true;
    }
    int splitArray(std::vector<int>& nums, int k) {
        int low = *std::max_element(nums.begin(), nums.end());
        int high = std::accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};