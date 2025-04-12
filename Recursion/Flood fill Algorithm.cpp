class Solution
{
public:
  vector<vector<int>> floodFill(vector<vector<int>> &img, int sr, int sc, int nC)
  {
    int oC = img[sr][sc];
    if (oC != nC)
      dfs(img, sr, sc, oC, nC);
    return img;
  }

private:
  void dfs(vector<vector<int>> &img, int r, int c, int oC, int nC)
  {
    int n = img.size(), m = img[0].size();
    if (r < 0 || r >= n || c < 0 || c >= m || img[r][c] != oC)
      return;
    img[r][c] = nC;
    dfs(img, r + 1, c, oC, nC);
    dfs(img, r - 1, c, oC, nC);
    dfs(img, r, c + 1, oC, nC);
    dfs(img, r, c - 1, oC, nC);
  }
};
