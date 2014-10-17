#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int word_cnt = words.size();
        vector<string> ret;
        if (word_cnt == 0){
            ret.push_back(string(L, ' '));
            return ret;
        }

        int current_length = 0;
        string tstr("");
        vector<int> tline;
        for (int i = 0 ; i <= word_cnt ; ++i){
            if (i == word_cnt || current_length + words[i].length() > L){
                int word_per_line = tline.size();
                int spaces = L - current_length + word_per_line;
                int remain = (word_per_line > 1)?(spaces % (word_per_line-1)):0;
                spaces = (word_per_line > 1)?(spaces/(word_per_line-1)):spaces;
                // cout << "spaces:\t" << spaces <<endl;
                for (int j = 0; j < word_per_line - 1; j++){
                    tstr += words[tline[j]] + string(spaces , ' ');
                    if (remain > 0){
                        tstr += string(" ");
                        remain--;
                    }
                }
                tstr += words[tline[word_per_line - 1]];
                ret.push_back(tstr);
                tstr = "";
                current_length = 0;
                tline.clear();
            }
            if (i == word_cnt) break;
            tline.push_back(i);
            current_length += words[i].length() + 1;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> words;
    // words.push_back("this");
    // words.push_back("is");
    // words.push_back("an");
    // words.push_back("example");
    // words.push_back("of");
    // words.push_back("text");
    // words.push_back("justification.");
    vector<string> ans;
    // words.push_back("a");
    // words.push_back("b");
    // words.push_back("c");
    // words.push_back("d");

    ans = s.fullJustify(words, 2);
    // ans = s.fullJustify(words, 16);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i].length() << endl;
        cout << ans[i] << endl;
    }
    return 0;
}