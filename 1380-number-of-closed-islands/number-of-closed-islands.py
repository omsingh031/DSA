class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        def dfs(r, c):
            if (r<0 or r>=m or c<0 or c>=n):
                return False
            if grid[r][c]==1:
                return True
            grid[r][c]=1

            left=dfs(r-1,c)
            right=dfs(r+1,c)
            up=dfs(r,c-1)
            down=dfs(r,c+1)

            if up and right and left and down:
                return True
        count=0
        for i in range (m):
            for j in range (n):
                if(grid[i][j]==0):
                    if(dfs(i,j)):
                        count+=1
        return count                
                



        