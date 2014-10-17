class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > result;
		vector<int> output;
		if(S.size() ==0) return result;
		result.push_back(output);
		sort(S.begin(), S.end());
		generateSub(S, 0, result, output);
	}
	void generateSub(
		vector<int> &s,
		int step,
		vector<vector<int> > &result,
		vector<int>& output)
		{
			for(int i = step;i<s.size(); i++ )
			{
				output.push_back(s[i]);
				result.push_back(output);
				if(i< s.size()-1)
					generateSub(s, i+1, result, output);
				output.pop_back();
				while(i < s.size()-1 && s[i] == s[i+1])
					i++;
			}
		}
};

int main(int argc, char const *argv[])
{
	Solution s;

	return 0;
}