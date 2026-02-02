class Solution {
public:
    int calSum(vector<int>& nums, int divisor) {
        int sum=0;
        
        // calculating sum(ceil ) when numbers are divided by a division
        for(int i:nums) {
            
            sum+=(i+divisor-1)/divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        // highest divisor would be the max size of the array 
        int divisor=*max_element(nums.begin(),nums.end());
        int low=1;
        int high=divisor;
        int ans=divisor;
    // search space of answers would be of divisiors from 1 to max ele of vector array
        while(low<=high) {
            int mid=low+(high-low)/2;
            int sum=calSum(nums,mid);
            if(sum<=threshold) { 
                // if sum less than limit found, check for even smaller divisor for larger sum 
                ans=mid;
                high=mid-1;
            } 
            // smaller divisor = larger sum
            else {
                 low=mid+1;
            }
        } 
        return ans;      
    }
};