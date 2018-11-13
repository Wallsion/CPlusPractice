class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::array<int,128> temArray;
        for(auto it = temArray.begin(); it != temArray.end(); ++it)
        {
            *it = 0;
        }
        int pre = 0;
        int next = 0;
        int max = 0;
        while(next != s.length())
            {
                if(temArray[s[next]] < 1)
                    temArray[s[next]] = temArray[s[next]] + 1;
                else
                {
                    temArray[s[next]] = temArray[s[next]] + 1;
                    if(max < next - pre)
                            max = next - pre;
                    for(int i = pre; i < next; ++i)
                    {
                        if(s[i] != s[next])
                            temArray[s[i]] = temArray[s[i]] - 1;
                        else
                        {
                            temArray[s[i]] = temArray[s[i]] - 1;
                            pre = i + 1;
                            break;
                        }
                    }
                }
               ++next;
            }
        return max > next - pre ? max : next - pre;
    }
};
