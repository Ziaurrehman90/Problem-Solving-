// knigh can move in 8 directions
int dx[] = {1, 2, 2, 1, -1, -2, -1, -2};
int dy[] = {2, 1, -1, -2, 2, 1, -2, -1};
int visited[501][501];
int dist[501][501];
bool isValid(int row, int col, int n, int m)
{
    if (row < 0 || row > n || col < 0 || col > m || visited[row][col] == 1)
    {
        return false;
    }
    return true;
}
void BFS(int A, int B, int C, int D)
{
    queue<pair<int, int>> q;
    q.push({C, D});
    visited[C][D] = 1;
    dist[C][D] = 0;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int currX = node.first;
        int currY = node.second;
        for (int i = 0; i < 8; i++)
        {
            if (isValid(currX + dx[i], currY + dy[i], A, B))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                q.push({newX, newY});
                visited[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }
}
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    for (int i = 1; i <= A; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            visited[i][j] = 0;
            dist[i][j] = 0;
        }
    }
    BFS(A, B, C, D);
    if (dist[E][F] == 0 && E == C && F == D)
    {
        return 0;
    }
    if (dist[E][F] != 0)
    {
        return dist[E][F];
    }
    return -1;
}
