class Solution
{
public:
  int countSymmetricIntegers(int low, int high)
  {
    int count = 0;

    for (int i = low; i <= high; i++)
    {

      string num = to_string(i);

      int n = num.length();

      int half = n / 2;

      int fSum = 0, sSum = 0;
      for (int j = 0; j < half; j++)
      {

        fSum += num[j] + '0';
      }
      for (int j = half; j < n; j++)
      {

        sSum += num[j] + '0';
      }

      if (fSum == sSum)
        count++;
    }

    return count;
  }
};