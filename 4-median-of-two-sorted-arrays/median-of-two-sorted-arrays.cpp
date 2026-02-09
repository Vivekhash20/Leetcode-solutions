class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0; 
        int j=0;
         vector<int> merged;
         
        while(i<n && j<m) {
            if(nums1[i]<=nums2[j]) {
                merged.push_back(nums1[i++]);
                
            }
            else {
                merged.push_back(nums2[j++]);
            }

        }
        while(i<n) merged.push_back(nums1[i++]);
        while (j<m)  merged.push_back(nums2[j++]);

        int finalSize=n+m;

        if(finalSize%2==1) {
            return merged[finalSize/2];
        }
        else {
            return (merged[(finalSize/2)-1] + merged[finalSize/2])/2.0;
        }
        
        
    }
};