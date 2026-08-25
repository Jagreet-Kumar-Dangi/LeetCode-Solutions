class Solution {
public:
     void mergeSort(vector<pair<int, int>>& arr,
                   vector<int>& ans,
                   int low,
                   int high) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, ans, low, mid);
        mergeSort(arr, ans, mid + 1, high);

        vector<pair<int, int>> temp;

        int i = low;
        int j = mid + 1;

        int rightSmaller = 0;

        while (i <= mid && j <= high) {

            if (arr[j].first < arr[i].first) {
             
                temp.push_back(arr[j]);
                rightSmaller++;
                j++;
            }
            else {
           
                ans[arr[i].second] += rightSmaller;

                temp.push_back(arr[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[arr[i].second] += rightSmaller;
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
         int n = nums.size();

        vector<pair<int, int>> arr;


        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        vector<int> ans(n, 0);

        mergeSort(arr, ans, 0, n - 1);

        return ans;
    }
};