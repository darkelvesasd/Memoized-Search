class Solution {
public:
int m, n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool vb[200][200];
int mem[200][200];
int dfs(int a,int b, vector<vector<int>>& matrix)
{
	vb[a][b] = true;
	int mx = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = dx[i] + a;
		int y = dy[i] + b;
		if (x >= 0 && x < m && y >= 0 && y<n && matrix[x][y]>matrix[a][b] && vb[x][y] == false)
		{
			if (mem[x][y])
			{
				mx = max(mx, mem[x][y]);
			}
			else 
			{
				mem[x][y] = dfs(x, y, matrix);
				mx = max(mx, mem[x][y]);
			}
		}
	}
	vb[a][b] = false;
	return mx+1;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
	m = matrix.size();
	n = matrix[0].size();
	int ret = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret=max(ret,dfs(i, j,matrix));
		}
	}
	return ret;
}
};
