class Solution {
public:
int mem[2500];
int m;
int dfs(int n, vector<int>& nums)
{
	if (mem[n] != 0)
	{
		return mem[n];
	}
	int mx = 1;
	for (int i = n; i < m; i++)
	{
		if (nums[n] < nums[i])
		{
			mx = max(mx, 1 + dfs(i, nums));
		}
	}
	mem[n] = mx ;
	return mem[n];
}
int lengthOfLIS(vector<int>& nums) {
	m = nums.size();
	int mx = 0;
	for (int i = 0; i < m; i++)
	{
		mx = max(dfs(i, nums), mx);
	}
	return mx;
}
};
