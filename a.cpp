#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> ans(numRows);
  int col = 1;
  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (j == 0)
        ans[i].push_back(1);
      else if (j == col - 1)
        ans[i].push_back(1);
      else
      {
        ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
      }
    }
    if (col < numRows)
    {
      col++;
    }
  }
  return ans;
}

int main()
{
  int num = 5;
  vector<vector<int>> ans(num);
  ans = generate(num);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}