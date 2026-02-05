class Solution {
public:

    // Counts how many partitions are needed for a given maxSum
    int countPartitions(vector<int>& nums, int maxSum) {
        int partitions = 1;      // at least one partition
        long long subarraySum = 0;

        for (int num : nums) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }


    int splitArray(vector<int>& nums, int k) {

          int low = *max_element(nums.begin(), nums.end());                 // largest element
        int high = accumulate(nums.begin(), nums.end(), 0);               // total sum

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int partitions = countPartitions(nums, mid);

            if (partitions > k) {
                low = mid + 1;      // too many partitions → increase maxSum
            } else {
                high = mid - 1;     // valid → try smaller maxSum
            }
        }
        return low;

        
    }
};