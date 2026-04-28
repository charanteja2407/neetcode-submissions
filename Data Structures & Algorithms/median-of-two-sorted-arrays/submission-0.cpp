class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        bool odd = (n + m) %2;

        int mid = (n + m)/2;

        // int l = 0, h = n -1;
        int m1 = 0, m2 = 0;
        int i = 0, j = 0;
        for(int count = 0; count < mid + 1; count++){
            m2 = m1;

            if(i < n && j < m){
                if(nums1[i] < nums2[j]){
                    m1 = nums1[i];
                    i++;
                }else {
                    m1 = nums2[j++];
                }
            } else if( i < n){
                m1 = nums1[i++];
            } else {
                m1 = nums2[j++];
            }
            cout << m1 << ' ';
        }

        if(odd) return(double) m1;
        else return (m1 + m2)/ 2.0;
        

    }
};
