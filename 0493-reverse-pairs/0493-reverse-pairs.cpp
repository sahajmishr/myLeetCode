void merge(vector<int>& arr, int low, int mid, int high) {
       
        vector<int> temp;
        int left = low, right = mid + 1;

        // i will surely come back mate with extra gears and i will grave you ....
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        
        while (left <= mid)
            temp.push_back(arr[left++]);

      
        while (right <= high)
            temp.push_back(arr[right++]);

       
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    int countPairs( vector<int>& arr , int low , int mid , int high){
        int right = mid+1 ; 
        int count =0 ;
        for(int i = low ; i<=mid; i++){
            while(right<=high && (long long) arr[i]>2*(long long) arr[right]) right++;
                
                count +=(right-(mid+1));
                
            
        }
        return count ;
    }
    int mergeSort(vector<int>& arr, int low, int high) {
        int count = 0;
        if (low >= high)
            return count;

    
        int mid = (low + high) / 2;

      
       count += mergeSort(arr, low, mid);

      
        count += mergeSort(arr, mid + 1, high);
       count += countPairs(arr , low , mid , high);
        
         merge(arr, low, mid, high);
        return count ;
    }


class Solution {
public:
  
    int reversePairs(vector<int>& nums) {
        int n = nums.size() ;
        return mergeSort(nums , 0 , n-1);
    }
};