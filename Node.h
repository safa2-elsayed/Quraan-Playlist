#pragma once
#pragma once
template<class T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T val) :data(val), prev(nullptr), next(nullptr) {}
};
