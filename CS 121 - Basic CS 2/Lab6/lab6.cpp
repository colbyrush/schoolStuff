#include <iostream>

template <typename T>
class Node {
public:
  Node<T> *next;
  T data;
};

/**
 * Represents a basic linked list.
 * @invariant The head pointer must be initialized to NULL.
 */

template <typename T>
class List {
public:

  /**
   * Constructs a new list, ensuring head is initialized to NULL.
   */

  List()
    : head_ (NULL)
  { }

  /**
   * Frees the list, preventing memory leaks.
   */

  ~List()
  {
    delete head_;
  }

  /**
   * Adds a new node to the end of the list. 
   * @param[in] data The data to hold within the node.
   * @returns True if insertion was successful, false otherwise.
   */

  bool add_node(T data)
  {
    Node<T> *itr = head_;
    Node<T> *node = new Node<T>;
    
    node->next = NULL;
    node->data = data;

    if (itr == NULL)
      head_ = node;
    else
      while (itr->next != NULL)
        {
          itr = itr->next;
          itr->next = node;
        }
    free (head_);
    return true;
  }


  /**
   * Removes the first node in the list that has data matching the parameter.
   * @param[in] data The data to search for.
   * @returns True if deletion was successful, false otherwise.
   */

  bool delete_node_by_info(T data)
  {
    Node<T> *itr = head_;
    Node<T> *lag = head_;

    while (itr->data != data)
      itr = itr->next;
    
    lag->next = itr->next;

    return true;
  }

  /**
   * Returns a reference to the head of the list.
   * @return A reference to the list's head pointer.
   * @note This is dangerous, as client code can alter the list pointer.
   */

  Node<T> *& head() 
  { return head_; }

  
private:
  Node<T> *head_;
};



int main(int argc, char **argv)
{
  // Construct a list that holds integers.
  List<int> oh_no;
  oh_no.add_node(100);
  oh_no.add_node(200);
  oh_no.add_node(300);

  // Examine the data of the list's head
  std::cout << oh_no.head()->data << std::endl;

  // Construct a list that holds strings.
  List<std::string> goodness;
  goodness.add_node("Hello!");
  goodness.add_node("Oops!");
  goodness.add_node("Am I leaking memory here? :(");

  // Examine the data of the list's head
  std::cout << goodness.head()->data << std::endl;

  // Construct a list of floats.
  List<float> badnews;
  
  // Example the data of the list's head
  std::cout << badnews.head()->data << std::endl;

  return 0;
}
