class Solution {
public:
 int mem[31] = {-1};
int dfs(int n)
{
	if (mem[n] != -1)
	{
		return mem[n];
	}
	if (n == 1 || n == 0)
	{
		mem[n] = n;
		return n;
	}
	mem[n] = dfs(n - 1) + dfs(n - 2);
	return dfs(n - 1) + dfs(n - 2);
}
int fib(int n) {
	memset(mem, -1, sizeof(mem));
	return dfs(n);
}
};
