#include <bits/stdc++.h>
#include "node.h"
using namespace std;

class LinkedList {

    node* head = nullptr;
    int counter = 0;

    bool empty() {
        return (head == nullptr);
    }

    bool found(int item) {
        bool find_item = false;
        if (!empty()) {
            node* curr_ptr = head;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    find_item = true;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
        }
        return find_item;
    }

public:

    LinkedList() {
        // This is constructor
    }

    void insert(int item) {
        node* new_node = new node(item);
        if (!empty()) {
            new_node->set_next(head);
        }
        head = new_node;
        counter++;
    }

    void append(int item) {
        node* new_node = new node(item);
        if (empty()) {
            insert(item);
        } else {
            node* curr_ptr = head;
            while (curr_ptr->get_next() != nullptr) {
                curr_ptr = curr_ptr->get_next();
            }
            curr_ptr->set_next(new_node);
            counter++;
        }
    }

    void insert(int item_before, int new_item) {
        if (empty()) {
            insert(new_item);
        }else {
            node* new_node = new node(new_item);
            bool check = false;
            node* curr_ptr = head;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item_before) {
                    check = true;
                    new_node->set_next(curr_ptr->get_next());
                    curr_ptr->set_next(new_node);
                    counter++;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
            if (!check) {
                cout << "Can't insert, Item isn't found." << endl;
            }
        }
    }

    void create(int num) {
        for (int i = 0; i < num; ++i) {
            int item = 0;
            cout << "Enter node " << i + 1 << " : ";
            cin >> item;
            append(item);
        }
    }

    void pop_front(){
        if (!empty()){
            node* curr_ptr = head;
            head = head->get_next();
            delete curr_ptr;
            counter--;
        }else{
            cout << "Can't delete this item, LinkedList is empty." << endl;
        }
    }

    void pop_back(){
        if(!empty()){
            if (counter == 1) {
                delete head;
                head = nullptr;
            }else {
                node *curr_ptr = head;
                while (curr_ptr->get_next()->get_next() != nullptr) {
                    curr_ptr = curr_ptr->get_next();
                }
                delete curr_ptr->get_next();
                curr_ptr->set_next(nullptr);
                counter--;
            }
        }else{
            cout << "Can't delete this item, LinkedList is empty." << endl;
        }
    }

    void pop_this(int item) {
        if (empty()) {
            cout << "Can't delete this item, LinkedList is empty." << endl;
        } else if (item == head->get_data()) {
            pop_front();
        } else {
            node* curr_ptr = head;
            node* pre_ptr = nullptr;
            bool check = false;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    pre_ptr->set_next(curr_ptr->get_next());
                    check = true;
                    counter--;
                    delete curr_ptr;
                    break;
                }
                pre_ptr = curr_ptr;
                curr_ptr = curr_ptr->get_next();
            }
            if (!check) {
                cout << "Can't delete this item, It isn't found" << endl;
            }
        }
    }

    void get_head(){
        if(!empty()){
            cout << "The Head is : " << head->get_data() << endl;
        }else{
            cout << "No Head, LinkedList is empty" << endl;
        }
    }

    void search(int item) {
        if (found(item)) {
            cout << "Yes " << item << " is found" << endl;
        } else {
            cout << "No " << item << " isn't found " << "LinkedList is empty or item don't in it" << endl;
        }
    }

    void replace(int curr_item, int new_item) {
        if (empty()) {
            cout << "Can't replace, LinkedList is empty." << endl;
        } else {
            bool check = false;
            node* curr_ptr = head;
                while (curr_ptr != nullptr) {
                    if (curr_ptr->get_data() == curr_item){
                        curr_ptr->set_data(new_item);
                        check = true;
                        break;
                    }
                    curr_ptr = curr_ptr->get_next();
                }
            if (!check){
                cout << "Can't replace, Item isn't found." << endl;
            }
        }
    }

    void get_size(){
        cout << "The size of the LinkedList is ==> " << counter << endl;
    }

    void is_empty(){
        string check = empty() ? "Yes, LinkedList is empty" : "No, LinkedList isn't empty";
        cout << check << endl;
    }

    void join(LinkedList l){
        node* curr_ptr = l.head;
        while (curr_ptr != nullptr) {
            append(curr_ptr->get_data());
            curr_ptr = curr_ptr->get_next();
        }
    }

    void reverse(){
        node* pre_ptr = nullptr;
        node* curr_ptr = head;
        node* next_ptr;
        while (curr_ptr != nullptr){
            next_ptr = curr_ptr->get_next();
            curr_ptr->set_next(pre_ptr);
            pre_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        head = pre_ptr;
    }

    void display(){
        if(!empty()){
            node* curr_ptr = head;
            cout << "The LinkedList is ===> ";
            while (curr_ptr->get_next() != nullptr){
                cout << curr_ptr->get_data() << " ---> ";
                curr_ptr = curr_ptr->get_next();
            }
            cout << curr_ptr->get_data() << endl;
        }else{
            cout << "Can't display, LinkedList is empty" << endl;
        }
    }

    void clear(){
        if(!empty()){
            while (! empty()){
                pop_front();
            }
        } else{
            cout << "Can't clear, LinkedList is empty" << endl;
        }
    }
};