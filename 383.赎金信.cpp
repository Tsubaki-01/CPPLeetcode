/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = { 0 };
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j] - 'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

