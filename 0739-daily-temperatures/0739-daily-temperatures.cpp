class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<int> st;

        for(int i=temperatures.size()-1;i>=0;i--){
            while(st.size()>0 && temperatures[st.top()]<=temperatures[i])
                st.pop();
            if(st.size()==0)
                ans.push_back(0);
            else
                ans.push_back(st.top()-i);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};