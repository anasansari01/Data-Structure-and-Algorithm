class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
    int count = 0;

    while (pq.size() >= 2)
    {
      if (pq.top() >= k)
        break;

      long long x = pq.top();
      pq.pop();
      long long y = pq.top();
      pq.pop();

      long long newElement = 2 * min(x, y) + max(x, y);
      pq.push(newElement);
      count++;
    }

    return pq.top() >= k ? count : -1;
  }
};