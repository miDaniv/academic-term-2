#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename Type>
struct ListElement {
    Type m_value;
    ListElement* m_next;
    ListElement* m_prev;
};

template <typename Type>
class List {
public:
    ~List() { clear(); }
    void addBegin(Type value) {
        ListElement<Type> *temp = new ListElement<Type>;
        temp->m_prev = nullptr;
        temp->m_value = value;

        temp->m_next = m_head;

        if (m_head)
            m_head->m_prev = temp;
        else
            m_tail = temp;
        m_head = temp;
    }

    void addEnd(Type value) {
        ListElement<Type> *temp = new ListElement<Type>;
        temp->m_next = nullptr;
        temp->m_value = value;

        temp->m_prev = m_tail;
        if (m_tail)
            m_tail->m_next = temp;
        else
            m_head = temp;
        m_tail = temp;
    }

    void deleteBegin() {
        if (m_head == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        ListElement<Type> *temp = m_head;
        m_head = temp->m_next;
        if (m_head)
            m_head->m_prev = nullptr;
        else
            m_tail = nullptr;
        delete temp;
    }

    void deleteEnd() {
        if (m_tail == nullptr) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        ListElement<Type> *temp = m_tail;
        m_tail = temp->m_prev;
        if (m_tail)
            m_tail->m_next = nullptr;
        else
            m_head = nullptr;
        delete temp;
    }

    ListElement<Type> *search(Type value) {
        ListElement<Type> *iter = m_head;
        while (iter) {
            if (iter->m_value == value)
                return iter;
            else
                iter = iter->m_next;
        }

        std::cout << "Item not found" << std::endl;
        return nullptr;
    }

    int indexOf(Type value) {
        ListElement<Type> *iter = m_head;
        int cnt{0};
        while (iter) {
            if (iter->m_value == value)
                return cnt;
            else
                iter = iter->m_next;
            cnt++;
        }

        std::cout << "Item not found" << std::endl;
        return -1;
    }

    void addMid(Type key, Type value) {
        ListElement<Type> * el = search(key);
        if (el == nullptr) {
            return;
        }
        if (el == m_tail)
            addEnd(value);
        else {
            ListElement<Type> *temp = new ListElement<Type>;
            temp->m_value = value;
            temp->m_next = el->m_next;
            temp->m_prev = el;
            el->m_next = temp;
            (temp->m_next)->m_prev = temp;
        }
    }

    void deleteMid(Type key) {
        ListElement<Type> * el = search(key);
        if (el == nullptr) {
            return;
        }
        if (el == m_head)
            deleteBegin();
        else if (el == m_tail)
            deleteEnd();
        else {
            (el->m_prev)->m_next = el->m_next;
            (el->m_next)->m_prev = el->m_prev;
            delete el;
        }
    }

    void show() const {
        ListElement<Type> *iter = m_head;
        if (iter == nullptr)
            std::cout << "List is empty" << std::endl;
        else {
            while (iter) {
                std::cout << iter->m_value;
                iter = iter->m_next;
                if (iter)
                    std::cout << " <---> ";
            }
            std::cout << std::endl;
        }
    }

    void clear() {
        while (m_head) {
            deleteBegin();
        }
    }

private:
    ListElement<Type> *m_head = nullptr;
    ListElement<Type> *m_tail = nullptr;
};

#endif // LIST_H
