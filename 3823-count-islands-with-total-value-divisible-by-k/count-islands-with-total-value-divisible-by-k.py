class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        def dfs(r,c):
            sum=grid[r][c]
            grid[r][c]=0

            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

            for di, dj in directions:
                ni = r + di
                nj = c + dj

                if (0 <= ni <m and
                    0 <= nj <n and
                    grid[ni][nj] > 0):
                    sum+=dfs(ni,nj)

            return sum

        m=len(grid)
        n=len(grid[0])
        count =0
        for i in range (m):
            for j in range (n):
                if grid[i][j]>0:
                    sum=dfs(i,j)
                    if sum%k==0:
                        count+=1
        return count                

                    


        