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
    void copy(const LinkedList<T> &other)
    {
        if (other.size > 0)
        {
            this->front = new Node<T>(other.front->key);
            int i = other.size;
            Node<T> *Current = this->front;
            Node<T> *Other = other.front->next;
            while (--i)
            {
                Current->next = new Node<T>(Other->key);
                Current = Current->next;
                Other = Other->next;
            }
            this->size = other.size;
        }
    }
    void erase()
    {
        while (front)
        {
            Node<T> *temp = front;
            std::cout << "del: " << front->key << std::endl;
            front = front->next;
            delete temp;
            size--;
        }
    }

public:
    LinkedList() : front(nullptr), size(0){};
    ~LinkedList()
    {
        this->erase();
    }
    LinkedList(const LinkedList<T> &other)
    {
        this->copy(other);
    };
    bool operator==(const LinkedList<T> &other) const
    {   
        if (this->size == other.size)
        {   Node<T>* This=this->front;
            Node<T>* Other=other.front;
            for (int i = 0; i < this->size; i++)
            {
                if (This->key!=Other->key)
                {
                    return 0;
                }
                This=This->next;
                Other=Other->next;
            }
            return 1;
        }
        return 0;
    }
    LinkedList<T> &operator=(const LinkedList<T> &other)
    {
        if (this != &other)
        {
            this->erase();
            this->copy(other);
        }
        return *this;
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
            Node<T> *temp = newNode->next;
            newNode->next = temp->next;
            delete temp;
        }
        size--;
    }
};