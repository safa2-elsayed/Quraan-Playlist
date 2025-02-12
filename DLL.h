#pragma once
#pragma once
#include "Node.h"
#include <iostream>
using namespace std;
template<class T>
class DLL
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    DLL() :head(nullptr), tail(nullptr), size(0) {}
    DLL(DLL& dll)
    {
        Clear();
        Node<T>* current = dll.getHead();
        while (current)
        {
            insertAtEnd(current->data);
            current = current->next;
        }
    }
    DLL& operator=(DLL& dll)
    {
        if (this != &dll)
        {
            Clear();
            Node<T>* current = dll.getHead();
            while (current)
            {
                insertAtEnd(current->data);
                current = current->next;
            }
        }
        return *this;
    }
    void insertAtBeg(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
        size++;
    }
    void insertAtEnd(T val)
    {
        Node<T>* newNode = new Node<T>(val);
        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertAt(T val, int index)
    {
        if (index < 1 || index > size + 1)
            cout << "Index Out Of Bounds :(";
        else if (index == 1)
            insertAtBeg(val);
        else
        {
            Node<T>* newNode = new Node<T>(val);
            Node<T>* current = head;
            for (int i = 1; i < index - 1; i++)
                current = current->next;
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
    }
    void deleteFromBegining()
    {
        if (size == 0)
        {
            cout << "The List Is Empty :(" << endl;
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node<T>* current = head;
            head = head->next;
            head->prev = nullptr;
            delete current;
        }
        size--;

    }
    void deleteFromEnd()
    {
        if (size == 0)
        {
            cout << "The List Is Empty :(" << endl;
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node<T>* current = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
        }
        size--;
    }
    void deleteElement(T element)
    {
        if (size == 0)
        {
            cout << "The List Is Empty :(" << endl;
            return;
        }
        else if (head->data == element)
            deleteFromBegining();
        else
        {
            Node<T>* current = head->next;
            while (current)
            {
                if (current->data == element)
                    break;
                current = current->next;
            }
            if (current == nullptr)
            {
                cout << "Element Not Found" << endl;
                return;
            }
            else if (current->next == nullptr)
                deleteFromEnd();
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
        }

    }
    void Display() const
    {
        Node<T>* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void rDisplay() const
    {
        Node<T>* current = tail;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    T& search(T val)
    {
        Node<T>* current = head;
        while (current)
        {
            if (current->data == val)
                return current->data;
            current = current->next;
        }
        throw std::runtime_error("Element not found.");
    }
    int getSize()
    {
        return size;
    }
    Node<T>* getHead()
    {
        return head;
    }
    void Clear()
    {
        Node<T>* current = head;
        while (current)
        {
            Node<T>* temp = current->next;
            delete current;
            current = temp;
        }
        size = 0;
        head = tail = nullptr;
    }
    ~DLL()
    {
        Clear();
    }

};
