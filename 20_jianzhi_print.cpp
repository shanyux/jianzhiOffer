class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> res;
		int start = 0;
		int rows = matrix.size();
		int cols = matrix[0].size();
		if(rows ==0 || cols ==0)
			return res;
		while(start * 2 < rows && start * 2 < cols) {
			int endx = rows - start - 1;
			int endy = cols - start - 1;
			for(int i = start; i <= endy; i++)
				res.push_back(matrix[start][i]);
			if(start < endx)//这里说一下 判断有个条件。。。或许过去的很多不能ac的都是因为判断条件
				for(int i = start+1; i <= endx; i++)
					res.push_back(matrix[i][endy]);
			if(start < endx && start < endy)
				for(int i = endy - 1; i >= start; i--)
					res.push_back(matrix[endx][i]);
			if(start < endx-1 && start < endy)
				for(int i = endx -1; i > start; i--)
					res.push_back(matrix[i][start]);
			start++;
		}
		return res;

	}
};