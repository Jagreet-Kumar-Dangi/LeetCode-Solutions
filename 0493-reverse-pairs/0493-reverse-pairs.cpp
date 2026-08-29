class Solution {
public:
    void conquer(vector<int> &arr,int low,int mid,int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }
        while(left<=mid)
            temp.push_back(arr[left++]);
        while(right<=high)
            temp.push_back(arr[right++]);
        for(int i=low;i<=high;i++)
            arr[i]=temp[i-low];
    }
    int count(vector<int> &arr,int low,int mid,int high){
        int right=mid+1;
        int cnt=0;
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)arr[i]>arr[right]*2ll)
                right++;
            cnt =cnt+(right-(mid+1));
        }
        return cnt;
    }
    int divide(vector<int> &arr,int low,int high){
        int cnt=0;
        if(low>=high)
            return cnt;
        int mid=low+(high-low)/2;
        cnt +=divide(arr,low,mid);
        cnt +=divide(arr,mid+1,high);
        cnt +=count(arr,low,mid,high);
        conquer(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return divide(nums,0,nums.size()-1);
    }
};