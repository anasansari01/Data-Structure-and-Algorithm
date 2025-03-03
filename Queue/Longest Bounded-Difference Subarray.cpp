class Solution
{
public:
  vector<int> longestSubarray(vector<int> &arr, int x)
  {
    int n = arr.size();
    deque<int> minDeque, maxDeque;
    int left = 0, max_length = 0, start_index = 0;

    for (int right = 0; right < n; right++)
    {
      while (!minDeque.empty() && arr[minDeque.back()] > arr[right])
        minDeque.pop_back();
      minDeque.push_back(right);

      while (!maxDeque.empty() && arr[maxDeque.back()] < arr[right])
        maxDeque.pop_back();

      maxDeque.push_back(right);

      while (!minDeque.empty() && !maxDeque.empty() &&
             arr[maxDeque.front()] - arr[minDeque.front()] > x)
      {
        if (minDeque.front() == left)
          minDeque.pop_front();
        if (maxDeque.front() == left)
          maxDeque.pop_front();
        left++;
      }

      if (right - left + 1 > max_length)
      {
        max_length = right - left + 1;
        start_index = left;
      }
    }

    return vector<int>(arr.begin() + start_index, arr.begin() + start_index + max_length);
  }
};