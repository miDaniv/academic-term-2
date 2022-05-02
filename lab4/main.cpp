#include <iostream>

#include "stack.h"
#include "queue.h"
#include "list.h"

using namespace std;

int main() {
    Stack<int> stack;
    Queue<int> queue;
    List<int> list;

    while (true) {
        cout << "Input l - list, q - queue, s - stack, x - exit " << endl;
        string key;
        cin >> key;
        if (key == "x")
            break;
        else if (key == "l") {
            while (true) {
                cout << "Input ab - addBegin, am - addMid, ae - addEnd" << endl
                     << "db - deleteBegin, dm - deleteMid, de - deleteEnd" << endl
                     << "search - find element(print address), id - printIndex" << endl
                     << "s - show, c - clear, x - exit" << endl;
                cin >> key;
                if (key == "s")
                    list.show();
                else if (key == "c")
                    list.clear();
                else if (key == "x")
                    break;
                else if (key == "db")
                    list.deleteBegin();
                else if (key == "de")
                    list.deleteEnd();
                else {
                    int val;
                    cout << "input value " << endl;
                    cin >> val;
                    if (key == "ab")
                        list.addBegin(val);
                    else if (key == "am") {
                        int index_value;
                        cout << "Input key (to insert after this element)" << endl;
                        cin >> index_value;
                        list.addMid(index_value, val);
                    }
                    else if (key == "ae")
                        list.addEnd(val);
                    else if (key == "dm")
                        list.deleteMid(val);
                    else if (key == "search")
                        cout << "Element address - " << list.search(val) << endl;
                    else if (key == "id")
                        cout << "Index of - " << list.indexOf(val) << endl;
                }
            }
        } else if (key == "s") {
            while (true) {
                cout << "Input push - to add value; pop - remove value; s - show stack; clear - remove all;" << endl
                     << "top - print top element; x - exit" << endl;
                cin >> key;
                if (key == "push") {
                    int val;
                    cout << "input value " << endl;
                    cin >> val;
                    stack.push(val);
                } else if (key == "pop")
                    stack.pop();
                else if (key == "x")
                    break;
                else if (key == "s")
                    stack.show();
                else if (key == "top")
                    cout << "Top element - " << stack.top() << endl;
                else if (key == "clear")
                    stack.clear();
            }
        } else if (key == "q") {
            while (true) {
                cout << "Input e - to add value(enqueue); d - remove value(dequeue); s - show queue; c - remove all(clear);" << endl
                     << "f - print front element; b - print back elementl x - exit" << endl;
                cin >> key;
                if (key == "e") {
                    int val;
                    cout << "input value " << endl;
                    cin >> val;
                    queue.enqueue(val);
                } else if (key == "d")
                    queue.dequeue();
                else if (key == "x")
                    break;
                else if (key == "s")
                    queue.show();
                else if (key == "f")
                    cout << "Front element - " << queue.front() << endl;
                else if (key == "b")
                    cout << "Back element - " << queue.back() << endl;
                else if (key == "c")
                    queue.clear();
            }
        }
    }
}
