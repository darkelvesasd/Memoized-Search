class Solution {
public:
int m, n;
int vv[101][101];
int mem[101][101];
int dfs(int x, int y)
{
	if (x == 0 || y == 0)
	{
		mem[x][y] = 0;
		return mem[x][y];
	}
	if (mem[x][y] != 0)
	{
		return mem[x][y];
	}
	mem[x][y] = dfs(x, y - 1) + dfs(x - 1, y);
	return mem[x][y];
}
int uniquePaths(int a, int b) {
	m = a;
	n = b;
	mem[1][1] = 1;
	return dfs(a, b);
}
};
