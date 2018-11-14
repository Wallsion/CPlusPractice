class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tem;
        double value = 0;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while(1)
        {
            if(it1 != nums1.end() && it2 != nums2.end())
            {
                if(*it1 < *it2)
                {
                    tem.push_back(*it1);
                    it1++;
                }
                else
                {
                    tem.push_back(*it2);
                    it2++;
                }
            }
            else if(it1 == nums1.end() && it2 == nums2.end())
            {
                break;
            }
            else
            {
                if(it1 ==  nums1.end())
                {
                    for(auto it = it2; it != nums2.end();it++)
                    {
                        tem.push_back(*it);
                    }
                    break;
                }
                else
                {
                     for(auto it = it1; it != nums1.end();it++)
                    {
                        tem.push_back(*it);
                    }
                    break;
                }
            }
        }
        int temLength = tem.size();
        if(temLength % 2 == 0)
        {
            value = (tem[temLength / 2] + tem[temLength / 2 - 1]) / 2.0;
        }
        else
        {
            value = tem[temLength / 2];
        }
        return value;
    }
};
