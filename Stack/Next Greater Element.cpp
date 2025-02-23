class Solution
{
public:
  // Function to find the next greater element for each element of the array.
  vector<int> nextLargerElement(vector<int> &arr)
  {
    vector<int> v(arr.size(), -1);

    stack<int> s;
    s.push(0);

    for (int i = 0; i < arr.size(); i++)
    {
      while (!s.empty() && arr[i] > arr[s.top()])
      {
        v[s.top()] = arr[i];
        s.pop();
      }
      s.push(i);
    }

    return v;
  }
};