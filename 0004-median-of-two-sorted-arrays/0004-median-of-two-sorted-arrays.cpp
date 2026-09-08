class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=n1+n2;
        int in2=n/2;
        int in1=in2-1;
        int i=0,j=0,cnt=0;
        int el1=0,el2=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(cnt==in1)    el1=nums1[i];
                if(cnt==in2)    el2=nums1[i];
                i++,cnt++;
            }else{
                if(cnt==in1)    el1=nums2[j];
                if(cnt==in2)    el2=nums2[j];
                j++,cnt++;

            }
        }
        while(i<n1){
            if(cnt==in1)    el1=nums1[i];
            if(cnt==in2)    el2=nums1[i];
            i++,cnt++;

        }
        while(j<n2){
            if(cnt==in1)    el1=nums2[j];
            if(cnt==in2)    el2=nums2[j];
            j++,cnt++;

        }
        if(n%2==0)
            return double(el1+el2)/2;
        else
            return double(el2);
    }
};