class Solution
{
public:
  int minJumps(vector<int> &arr)
  {
    int far = 0;
    int curr = 0;
    int jump = 0;

    for (int i = 0; i < arr.size() - 1; i++)
    {
      far = max(far, arr[i] + i);
      if (i == curr)
      {
        curr = far;
        jump++;
      }
    }
    if (curr >= arr.size() - 1)
    {
      return jump;
    }

    return -1;
  }
};