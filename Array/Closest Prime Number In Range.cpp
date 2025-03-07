class Solution
{
public:
  vector<int> closestPrimes(int left, int right)
  {
    int limit = right;
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
      if (isPrime[i])
      {
        for (int j = i * i; j <= limit; j += i)
        {
          isPrime[j] = false;
        }
      }
    }

    vector<int> primes;
    for (int i = left; i <= right; i++)
    {
      if (isPrime[i])
      {
        primes.push_back(i);
      }
    }

    vector<int> res(2, -1);
    int minDiff = INT_MAX;

    for (int i = 1; i < primes.size(); i++)
    {
      int diff = primes[i] - primes[i - 1];
      if (diff < minDiff)
      {
        minDiff = diff;
        res[0] = primes[i - 1];
        res[1] = primes[i];
      }
    }

    return res;
  }
};
