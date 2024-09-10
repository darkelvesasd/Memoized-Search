class Solution {
public:
 int dfs(int a,int b, vector<vector<int>>&mem)
{
	int ret = INT_MAX;
	if (a >= b)
	{
		return 0;
	}
	if (mem[a][b])
	{
		return mem[a][b];
	}
	for (int i = a; i <= b; i++)
	{
		int x=dfs(a, i-1, mem);
		int y=dfs(i + 1, b, mem);
		ret = min(ret, i+max(x, y));
	}
	mem[a][b] = ret;
	return ret;
}
int getMoneyAmount(int n) {
	vector<vector<int>>mem(1+n,vector<int>(1+n));
	return dfs(1,n,mem);
}
};
