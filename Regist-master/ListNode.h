template <class T>
class ListNode
{
    public:
      ListNode();
      ListNode(T d);
      ~ListNode();

      T data;
      ListNode<T> *next;
      ListNode<T> *prev;
};

template <class T>
ListNode<T>::ListNode()
{
  next = nullptr;
  prev = nullptr;
}

template <class T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = nullptr; //nullptr
  prev = nullptr; //nullptr
}

template <class T>
ListNode<T>::~ListNode()
{
  delete next;
  delete prev;
}
