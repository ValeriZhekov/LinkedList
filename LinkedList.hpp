template <typename T>
class LinkedList
{
private:
    template <class G>
    struct Node
    {
        G key;
        Node<G> *next;
        Node(G key) : key(key), next(nullptr){};
    };
    Node<T> *front;
    std::size_t size;

public:
    LinkedList() : front(nullptr), size(0){};
    ~LinkedList()
    {
        while (front)
        {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }
    LinkedList(const LinkedList<T> &other){};
    bool operator==(const LinkedList<T> &other) const
    {
        return *this;
    }
    LinkedList<T> &operator=(const LinkedList<T> &other)
    {
    }
    std::size_t getSize()
    {
        return this->size;
    }
    void print() const
    {
        int i = this->size;
        Node<T> *current = front;
        while (i--)
        {
            std::cout << current->key << std::endl;
            current = current->next;
        }
    }
    const T &getElementAtPos(unsigned pos)
    { 
        Node<T> *current = front;
        while (pos--)
        {
            current = current->next;
        }
        return current->key;
    }
    void insertAtPos(T a, std::size_t pos = 0)
    {
        if (pos > size)
        {
            std::cout << "pos > size" << std::endl;
            return;
        }
        else if (pos == 0)
        {
            Node<T> *newNode = new Node<T>(a);
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node<T> *traverse = front;
            while (--pos)
            {
                traverse = traverse->next;
            }
            Node<T> *newNode = new Node<T>(a);
            newNode->next = traverse->next;
            traverse->next = newNode;
        }
        size++;
    }
    void removeAtPos(std::size_t pos)
    {
        if (pos > size)
        {
            std::cout << "pos > size" << std::endl;
            return;
        }
        if (pos == 0)
        {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
        }
        else
        {
            Node<T> *newNode = front;
            while (--pos)
            {
                newNode = newNode->next;
            }
            Node<T>* temp = newNode->next;
            newNode->next = temp->next;
            delete temp;
        }
        size--;
    }

};