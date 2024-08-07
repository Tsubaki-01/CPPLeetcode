// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem127.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <numeric>
using namespace std;
/*
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

*/


// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
        {
            return 0;
        }

        queue<string> que;
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        que.emplace(beginWord);
        visited.emplace(beginWord);
        int cnt = 1;

        if (wordset.find(endWord) != wordset.end())
            while (!que.empty())
            {
                int size = que.size();
                for (int i = 0;i < size;i++)
                {
                    string curWord = que.front();
                    que.pop();
                    if (curWord == endWord)
                    {
                        return cnt;
                    }
                    for (int i = 0;i < curWord.size();i++)
                    {
                        string tmpWord = curWord;
                        for (int j = 0;j < 26;j++)
                        {
                            tmpWord[i] = 'a' + j;
                            if (wordset.find(tmpWord) != wordset.end()
                                && visited.find(tmpWord) == visited.end())
                            {
                                que.emplace(tmpWord);
                                visited.emplace(tmpWord);
                            }
                        }
                    }

                }
                cnt++;
            }
        return 0;

    };
};
// @lc code=end

/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty())
            return 0;

        queue<string> que;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        visited.emplace(beginWord);
        que.push(beginWord);

        int cnt = 0;
        while (!que.empty())
        {
            cnt++;
            int queSize = que.size();
            for (int t = 0;t < queSize;t++)
            {
                string curWord = que.front();
                que.pop();

                int wordSize = curWord.size();
                for (int index = 0;index < wordSize;index++)
                {
                    string tmpWord = curWord;
                    for (int i = 0;i < 26;i++)
                    {
                        tmpWord[index] = 'a' + i;
                        if (tmpWord == endWord && wordSet.find(tmpWord) != wordSet.end())
                            return ++cnt;

                        if (visited.find(tmpWord) == visited.end() && wordSet.find(tmpWord) != wordSet.end())
                        {
                            que.push(tmpWord);
                            visited.emplace(tmpWord);
                        }
                    }
                }

            }
        }
        return 0;

    }
};
 */

