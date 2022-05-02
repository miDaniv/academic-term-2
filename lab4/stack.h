#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename Type>
struct StackElement {
    Type m_value;
    StackElement* m_next;
};

template <typename Type>
class Stack {
public:
    ~Stack() { clear(); }

    bool isEmpty() const { return m_head == nullptr; }

    Type const& top() const {
        return m_head->m_value;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(Type value) {
        StackElement<Type> *newEl = new StackElement<Type>;

        newEl->m_value = value;
        newEl->m_next = m_head;

        m_head = newEl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty";
            return;
        }
        StackElement<Type> *headCopy = m_head;
        m_head = headCopy->m_next;
        delete headCopy;
    }

    void show() {
        if (isEmpty())
            std::cout << "Stack is empty" << std::endl;
        StackElement<Type> * iter = m_head;

        while (iter) {
            std::cout << iter->m_value;
            iter = iter->m_next;
            if (iter)
                std::cout  << " --> ";
        }
        std::cout << std::endl;
    }

private:
    StackElement<Type> *m_head = nullptr;
};

#endif // STACK_H
