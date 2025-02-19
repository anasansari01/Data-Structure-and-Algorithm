struct Compare
{
  bool operator()(Node *a, Node *b)
  {
    return a->data > b->data;
  }
};

class Solution
{
public:
  Node *mergeKLists(vector<Node *> &arr)
  {
    priority_queue<Node *, vector<Node *>, Compare> minHeap;
    for (auto list : arr)
    {
      if (list)
        minHeap.push(list);
    }

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (!minHeap.empty())
    {
      Node *smallest = minHeap.top();
      minHeap.pop();

      tail->next = smallest;
      tail = tail->next;

      if (smallest->next)
        minHeap.push(smallest->next);
    }

    return dummy->next;
  }
};