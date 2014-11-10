class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangles;
        if (numRows == 0) return triangles;
        triangles.push_back(vector<int>(1,1));
        for (int i = 1; i < numRows; ++i){
            vector<int> tmp;
            tmp.push_back(triangles[i-1][0]);
            for (int j = 1; j < triangles[i-1].size(); ++j)
                tmp.push_back(triangles[i-1][j-1]+triangles[i-1][j]);
            tmp.push_back(triangles[i-1][triangles[i-1].size()-1]);
            triangles.push_back(tmp);
        }
        return triangles;
    }
};