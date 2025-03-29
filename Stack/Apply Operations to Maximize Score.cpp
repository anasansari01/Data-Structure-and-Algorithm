class Solution
{
public:
  int maximumScore(vector<int> &nums, int k)
  {
    const int mod = 1e9 + 7;
    int n = nums.size();

    vector<int> factors(n);
    for (int i = 0; i < n; ++i)
    {
      factors[i] = countPrimeFactors(nums[i]);
    }

    vector<int> left(n, -1), right(n, n);
    stack<int> stk;

    for (int i = 0; i < n; ++i)
    {
      while (!stk.empty() && factors[stk.top()] < factors[i])
      {
        stk.pop();
      }
      if (!stk.empty())
      {
        left[i] = stk.top();
      }
      stk.push(i);
    }

    while (!stk.empty())
      stk.pop();

    for (int i = n - 1; i >= 0; --i)
    {
      while (!stk.empty() && factors[stk.top()] <= factors[i])
      {
        stk.pop();
      }
      if (!stk.empty())
      {
        right[i] = stk.top();
      }
      stk.push(i);
    }

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i)
    {
      arr.push_back({nums[i], i});
    }
    sort(arr.rbegin(), arr.rend());

    long long ans = 1;

    for (auto [value, i] : arr)
    {
      int l = left[i], r = right[i];
      long long count = 1LL * (i - l) * (r - i);

      if (count <= k)
      {
        ans = ans * power(value, count, mod) % mod;
        k -= count;
      }
      else
      {
        ans = ans * power(value, k, mod) % mod;
        break;
      }
    }

    return ans;
  }

  int countPrimeFactors(int n)
  {
    int count = 0;
    for (int i = 2; i * i <= n; ++i)
    {
      if (n % i == 0)
      {
        ++count;
        while (n % i == 0)
        {
          n /= i;
        }
      }
    }
    if (n > 1)
    {
      ++count;
    }
    return count;
  }

  long long power(long long base, long long exp, int mod)
  {
    long long result = 1;
    while (exp > 0)
    {
      if (exp % 2 == 1)
      {
        result = result * base % mod;
      }
      base = base * base % mod;
      exp /= 2;
    }
    return result;
  }
};
