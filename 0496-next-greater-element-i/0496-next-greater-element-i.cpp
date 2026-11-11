class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int,int> mpp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.size()>0 && st.top()<=nums2[i])
                st.pop();
            if(st.size()==0)
                mpp[nums2[i]]=-1;
            else
                mpp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};