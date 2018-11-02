class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> num(nums.begin(), nums.end());
	std::sort(num.begin(), num.end());
	auto it1 = num.begin();
	auto it2 = num.end() - 1;
	vector<int> tem;
	while (it2 - it1 > 0)
	{
		if (*it1 + *it2 > target)
			it2--;
		else if (*it1 + *it2 < target)
			it1++;
		else
		{
            if(*it1 != *it2)
            {
			    tem.push_back(find(nums.begin(), nums.end(), *it1)-nums.begin());
			    tem.push_back(find(nums.begin(), nums.end(), *it2)-nums.begin());
            }
            else
            {
                tem.push_back(find(nums.begin(), nums.end(), *it1)-nums.begin());
                tem.push_back(find(find(nums.begin(), nums.end(), *it1)+1, nums.end(), *it2)-nums.begin());
            }
			return tem;
		}
	}
}
};
