class Solution {
public:
    long long calTotalhours( vector<int>& piles, int speed) {
        long long totalHours=0;
        for(int bananas:piles) {
             totalHours+=((bananas+speed-1)/speed);

        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxSize= *max_element(piles.begin(),piles.end());
        long long low=1;
        long long high= maxSize;
        long long ans =maxSize;
        
        
        
       
        while(low<=high) {
        long long mid=low+(high-low)/2;
         long long totalHours= calTotalhours(piles,mid);
        if(totalHours<=h) {
            ans=mid;
            high=mid-1;
        }
        else {
            low=mid+1;
        }
       
        }
         return ans;

        
    }
};