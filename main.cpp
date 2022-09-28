#include <bits/stdc++.h>
#include "linked_list.h"
using namespace std;

int main() {

    cout << "welcome to LinkedList" << endl;

    cout << "To add ==> insert , append" <<endl;
    cout << "To create ==> create" <<endl;
    cout << "To delete ==> pop_this , pop_front , pop_back" <<endl;
    cout << "To get head ==> get_head" <<endl;
    cout << "To search  ==> search" << endl;
    cout << "To replace ==> replace" << endl;
    cout << "To know size ==> get_size" << endl;
    cout << "To check if empty ==> is_empty" << endl;
    cout << "To add LinkedList to another  ==> join" << endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To display ==> display" <<endl;
    cout << "To clear ==> clear" << endl;

    cout << "==========================================" << endl;

//  check empty LinkedList

    LinkedList l1;

    l1.insert(1,99);
    l1.get_head();
    l1.get_size();
    l1.search(5);
    l1.replace(5,7);
    l1.pop_back();
    l1.is_empty();
    l1.pop_back();
    l1.pop_front();
    l1.pop_this(80);
    l1.clear();
    l1.display();
    l1.create(5);   // 1 2 3 4 5
    l1.display();

//  check not empty LinkedList

    LinkedList l2;

    l2.create(5);   // 1 2 4 5 6
    l2.insert(0);
    l2.append(7);
    l2.insert(2,3);
    l2.display();
    l2.get_size();
    l2.search(0);
    l2.search(3);
    l2.search(7);
    l2.search(99);
    l2.is_empty();
    l2.get_head();
    l2.pop_front();
    l2.pop_back();
    l2.pop_this(3);
    l2.display();
    l2.replace(1,99);
    l2.replace(6,100);
    l2.replace(2,50);
    l2.replace(80,1000);
    l2.display();
    l2.join(l1);
    l2.display();
    l2.get_size();
    l2.reverse();
    l1.reverse();
    l2.display();
    l1.display();
    l1.clear();
    l2.clear();

    return 0;
}
