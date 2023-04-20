///////////////////////////////////////////////////////////////////
//                     |                                          |                 
//                     |      Generic Data Structure Library      |                
//                     |                                          |               
///////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//
//  Data structure - Singly Linear Linked List
//
//////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

template<class T>
struct SLnode
{
    T data;
    struct SLnode<T> *next;
};

template<class T>
class SinglyLL
{
    private:
        struct SLnode<T> *Head;
        int Count;
    
    public:
        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int Countnode();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct SLnode<T> *newn = NULL;
    newn = new SLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct SLnode<T> *newn = NULL;
    newn = new SLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct SLnode<T> *temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct SLnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Singly Linear Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<class T>
int SinglyLL<T>::Countnode()
{
    return Count;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
    }
    else
    {
        struct SLnode<T> *temp = Head;

        Head = Head->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
    }
    else
    {
        struct SLnode<T> *temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct SLnode<T> *newn = NULL;
        newn = new SLnode<T>;

        newn->data = no;
        newn->next = NULL;

        struct SLnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void SinglyLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct SLnode<T> *temp = Head;
        struct SLnode<T> *tempdelete = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Count--;
    }
}


//////////////////////////////////////////////////////////
//
//  Data structure - Doubly Linear Linked List
//
//////////////////////////////////////////////////////////
template<class T>
struct DLnode
{
    T data;
    struct DLnode<T> *next;
    struct DLnode<T> *prev;
};

template<class T>
class DoublyLL
{
    private:
        struct DLnode<T> *Head;
        int Count;
    
    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int Countnode();
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct DLnode<T> *newn = NULL;
    newn = new DLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct DLnode<T> *newn = NULL;
    newn = new DLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct DLnode<T> *temp = NULL;
        temp = Head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

template<class T>
void DoublyLL<T>::Display()
{
    struct DLnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Linear Linked List are : "<<endl;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<class T>
int DoublyLL<T>::Countnode()
{
    return Count;
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct DLnode<T> *temp = NULL;
        temp = Head;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template<class T>
void DoublyLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct DLnode<T> *newn = NULL;
        newn = new DLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        struct DLnode<T> *temp = NULL;
        temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void DoublyLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct DLnode<T> *temp = NULL;
        temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}


//////////////////////////////////////////////////////////
//
//  Data structure - Singly Circular Linked List
//
//////////////////////////////////////////////////////////

template<class T>
struct SCnode
{
    T data;
    struct SCnode<T> *next;
};

template<class T>
class SinglyCLL
{
    private:
        struct SCnode<T> *Head;
        struct SCnode<T> *Tail;
        int Count;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int Countnode();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SCnode<T> *newn = NULL;
    newn = new SCnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SCnode<T> *newn = NULL;
    newn = new SCnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;

    Count++;
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct SCnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Singly Circular Linked List are : "<<endl;

    do 
    {
        cout<<"|"<<temp->data<<"| ->";
        temp = temp->next;
    }while(temp != Tail->next);
    cout<<"NULL"<<endl;
}

template<class T>
int SinglyCLL<T>::Countnode()
{
    return Count;
}

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
    }
    Tail->next = Head;

    Count--;
}

template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        struct SCnode<T> *temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }
        delete temp->next;
        Tail = temp;
    }
    Tail->next = Head;

    Count--;
}

template<class T>
void SinglyCLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct SCnode<T> *newn = NULL;
        newn = new SCnode<T>;
        newn->data = no;
        newn->next = NULL;

        struct SCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void SinglyCLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct SCnode<T> *temp = Head;
        struct SCnode<T> *tempdelete = NULL;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete tempdelete;

        Count--;
    }
}


//////////////////////////////////////////////////////////
//
//  Data structure - Doubly Circular Linked List
//
//////////////////////////////////////////////////////////


template<class T>
struct DCnode
{
    T data;
    struct DCnode<T> *next;
    struct DCnode<T> *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct DCnode<T> *Head;
        struct DCnode<T> *Tail;
        int Count;
    
    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int Countnode();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DCnode<T> *newn = NULL;
    newn = new DCnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;

    Count++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DCnode<T> *newn = NULL;
    newn = new DCnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

template<class T>
void DoublyCLL<T>::Display()
{
    struct DCnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Circular Linked List are : "<<endl;

    do 
    {
        cout<<"|"<<temp->data<<"| <->";
        temp = temp->next;
    }while(temp != Tail->next);
    cout<<"NULL"<<endl;
}

template<class T>
int DoublyCLL<T>::Countnode()
{
    return Count;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

template<class T>
void DoublyCLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
    else
    {
        struct DCnode<T> *newn = NULL;
        newn = new DCnode<T>;
        newn->data = no;
        newn->next = NULL;

        struct DCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void DoublyCLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct DCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
//    Data structure - Queue
//
///////////////////////////////////////////////////////////////////////////////////////


template<class T>
struct QueueNode
{
    T data;
    struct QueueNode<T> *next;
};

template<class T>
class Queue
{
    private:
        struct QueueNode<T> *Head;
        int Count;

    public:
        Queue();
        void Enqueue(int);
        void Dequeue();
        void Display();
        int CountElements();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Queue<T>::Enqueue(int no)
{
    struct QueueNode<T> *newn = NULL;
    newn = new QueueNode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct QueueNode<T> *temp = Head;

        while(temp->next != NULL)
        {
            temp =temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void Queue<T>::Dequeue()
{
    int no = 0;
    struct QueueNode<T> *temp = NULL;
    temp = Head;

    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        no = Head->data;
        delete Head;
        Head = NULL;        // VIMP
    }
    else
    {
        no = Head->data;
        Head = temp->next;
        delete temp;
    }
    cout<<"Removed elements is : "<<no<<endl;
    Count--;
}

template<class T>
void Queue<T>::Display()
{
    struct QueueNode<T> *temp = Head;

    if(Head == NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }
    else
    {
        cout<<"Elements of Queue are : "<<endl;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"| ->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

template<class T>
int Queue<T>::CountElements()
{
    return Count;
}


///////////////////////////////////////////////////////////////////////////////////////
//
//    Data structure - Stack
//
///////////////////////////////////////////////////////////////////////////////////////


template<class T>
struct StackNode
{
    T data;
    struct StackNode<T> *next;
};

template<class T>
class Stack
{
    private:
        struct StackNode<T> *Head;
        int Count;

    public:
        Stack();
        void Push(T);
        void Pop();
        void Display();
        int CountElements();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct StackNode<T> *newn = NULL;
    newn = new StackNode<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void Stack<T>::Pop()
{
    T no;
    struct StackNode<T> *temp = NULL;
    temp = Head;

    if(Head == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        no = Head->data;
        delete Head;
        Head = NULL;        // VIMP
    }
    else
    {
        no = Head->data;
        Head = temp->next;
        delete temp;
    }
    cout<<"Removed elements is : "<<no<<endl;
    Count--;
}

template<class T>
void Stack<T>::Display()
{
    struct StackNode<T> *temp = Head;

    if(Head == NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }
    else
    {
        cout<<"Elements of Stack are : "<<endl;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"| ->";
            temp = temp->next;
        }
        cout<<endl;
    }
}

template<class T>
int Stack<T>::CountElements()
{
    return Count;
}


///////////////////////////////////////////////////////////////////////////////////////
//
//  Searching Techniques - Linear Search , Bidirectional Search and Binary Search               
//
///////////////////////////////////////////////////////////////////////////////////////


template<class T>
class Searching
{
    private:
        T *Arr;
        int iSize;

    public:
        Searching(int);
        void Accept();
        void Display();
        T LinearSearch(T);
        T BidirectionalSearch(T);  
        T BinarySearchI(T); // sorted array in increasing order
        T BinarySearchD(T);  // sorted array in decreasing order
};

template<class T>
Searching<T>::Searching(int a)
{
    iSize = a;
    Arr = new T[iSize];
}

template<class T>
void Searching<T>::Accept()
{
    cout<<"Enter elements of array : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void Searching<T>::Display()
{
    cout<<"Elements of array are : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"  ";
    }
    cout<<endl;
}

template<class T>
T Searching<T>::LinearSearch(T No)
{
    int i = 0;

    for(i = 0; i < this->iSize; i++)
    {
        if(this->Arr[i] == No)
        {
            break;
        }
    }
    if(i == iSize)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

template<class T>
T Searching<T>::BidirectionalSearch(T No)
{
    int iStart = 0;
    int iEnd = iSize-1;
    int iPos = -1;

    while(iStart <= iEnd)
    {
        if(Arr[iStart] == No)
        {
            iPos = iStart;
            break;
        }
        else if(Arr[iEnd] == No)
        {
            iPos = iEnd;
            break;
        }
        iStart++;
        iEnd--;
    }
    return iPos;
}

template<class T>
T Searching<T>::BinarySearchI(T No)
{
    int iStart = 0, iMiddle = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMiddle = (iStart + iEnd) / 2;

        if(Arr[iMiddle] == No)
        {
            break;
        }

        if(No > Arr[iMiddle])
        {
            iStart = iMiddle + 1;
        }
        if(No < Arr[iMiddle])
        {
            iEnd = iMiddle - 1;
        }
    }
    if(Arr[iMiddle] == No)
    {
        return iMiddle;
    }
    else
    {
        return -1;
    }
}

template<class T>
T Searching<T>::BinarySearchD(T No)
{
    int iStart = 0, iMiddle = 0;
    int iEnd = iSize - 1;

    while(iStart <= iEnd)
    {
        iMiddle = (iStart + iEnd) / 2;

        if(Arr[iMiddle] == No)
        {
            break;
        }

        if(No > Arr[iMiddle])
        {
            iEnd = iMiddle - 1;
        }
        if(No < Arr[iMiddle])
        {
            iStart = iMiddle + 1;
        }
    }
    if(Arr[iMiddle] == No)
    {
        return iMiddle;
    }
    else
    {
        return -1;
    }
}


///////////////////////////////////////////////////////////////////////////////
//
//  Sorting Techniques - Bubble Sort, Selection Sort and Insertion Sort               
//
/////////////////////////////////////////////////////////////////////////////


template<class T>
class Sorting
{
    private:
        T *Arr;
        int iSize;

    public:
        Sorting(int);
        void Accept();
        void Display();
        void BubbleSortI();         // increasingly sorted data
        void BubbleSortD();         // decreasingly sorted data
        void SelectionSortI();      // increasingly sorted data
        void SelectionSortD();      // decreasingly sorted data
        void InsertionSort();
};

template<class T>
Sorting<T>::Sorting(int a)
{
    iSize = a;
    Arr = new T[iSize];
}

template<class T>
void Sorting<T>::Accept()
{
    cout<<"Enter elements of array : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cin>>Arr[i];
    }
}

template<class T>
void Sorting<T>::Display()
{
    cout<<"Elements of array are : "<<endl;

    for(int i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"  ";
    }
    cout<<endl;
}

template<class T>
void Sorting<T>::BubbleSortI()
{
    int i = 0, j = 0, temp = 0;
    bool Swap = false;

    for(i = 0; i < iSize; i++)
    {
        Swap = false;
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                Swap = true;
            }
        }
        if(Swap == false)
        {
            break;
        }
        cout<<"Pass no : "<<(i+1)<<endl; 
    }
}

template<class T>
void Sorting<T>::BubbleSortD()
{
    int i = 0, j = 0, temp = 0;
    bool Swap = false;

    for(i = 0; i < iSize; i++)
    {
        Swap = false;
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                Swap = true;
            }
        }
        if(Swap == false)
        {
            break;
        }
        cout<<"Pass no : "<<(i+1)<<endl; 
    }
}

template<class T>
void Sorting<T>::SelectionSortI()
{
    int i = 0, j = 0, min_index = 0, temp = 0;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[min_index] > Arr[j])
            {
                min_index = j;
            }
        }
        if(i != min_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[min_index];
            Arr[min_index] = temp;
        }
    }
}

template<class T>
void Sorting<T>::SelectionSortD()
{
    int i = 0, j = 0, max_index = 0, temp = 0;

    for(i = 0; i < iSize-1; i++)
    {
        max_index = i;
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[max_index] < Arr[j])
            {
                max_index = j;
            }
        }
        if(i != max_index)
        {
            temp = Arr[i];
            Arr[i] = Arr[max_index];
            Arr[max_index] = temp;
        }
    }
}

template<class T>
void Sorting<T>::InsertionSort()
{
    int i = 0, j = 0, selected = 0;

    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = selected;
    }
}
