#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename Type>
struct QueueElement {
    Type m_value;
    QueueElement* m_next;
};

template <typename Type>
class Queue {
public:
    ~Queue() { clear(); }

    bool isEmpty() const { return m_back == nullptr; }

    Type const& front() const {
        return m_front->m_value;
    }

    Type const& back() const {
        return m_back->m_value;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(Type value) {
        QueueElement<Type> *newEl = new QueueElement<Type>;
        newEl->m_value = value;
        newEl->m_next = nullptr;

        if (m_back != nullptr)
            m_back->m_next = newEl;
        else
            m_front = newEl;
        m_back = newEl;
    }

    void dequeue() {
        if (m_front != nullptr) {
            QueueElement<Type> *old = m_front;
            m_front = old->m_next;
            if (m_front == nullptr)
                m_back = nullptr;
            delete old;
        }
    }

    void show() {
        if (isEmpty())
            std::cout << "Queue is empty" << std::endl;
        QueueElement<Type> * iter = m_front;

        while (iter) {
            std::cout << iter->m_value;
            iter = iter->m_next;
            if (iter)
                std::cout  << " --> ";
        }
        std::cout << std::endl;
    }

private:
    QueueElement<Type> *m_front = nullptr;
    QueueElement<Type> *m_back = nullptr;
};

#endif // QUEUE_H
