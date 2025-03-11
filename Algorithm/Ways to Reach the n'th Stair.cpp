class Solution
{
public:
  int countWays(int n)
  {
    // your code here
    // int count = 0;
    // fun(n, count, 0);

    if (n == 1)
      return 1;

    int p1 = 1, p2 = 1, curr;

    for (int i = 2; i <= n; i++)
    {
      curr = p1 + p2;
      p2 = p1;
      p1 = curr;
    }

    return curr;
  }

  // private:
  // Not efficient because of exponential time complexity...
  // void fun(int n, int& count, int trk){
  //     if(trk == n){
  //         count++;
  //         return;
  //     }
  //     if(trk > n) return;

  //     fun(n, count, trk+1);
  //     fun(n, count, trk+2);

  // }
};