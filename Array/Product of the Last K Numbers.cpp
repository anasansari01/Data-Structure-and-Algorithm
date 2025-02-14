class ProductOfNumbers
{
public:
  // stack<int> s1, s2;
  vector<int> v;
  ProductOfNumbers() {}

  void add(int num)
  {
    // s1.push(num);
    v.push_back(num);
  }

  int getProduct(int k)
  {
    int multi = 1;
    // while(k--){
    //   int val = s1.top();
    //   s1.pop();
    //   multi *= val;

    //   s2.push(val);

    // }

    // while(!s2.empty()){
    //   int val = s2.top();
    //   s2.pop();
    //   s1.push(val);
    // }

    int j = v.size() - k;

    for (int i = j; i < v.size(); i++)
    {
      multi *= v[i];
    }

    return multi;
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */