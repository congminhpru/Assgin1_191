/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class DSAException {
    int     _error;
    string  _text;
public:

    DSAException() : _error(0), _text("Success") {}
    DSAException(int err) : _error(err), _text("Unknown Error") {}
    DSAException(int err, const char* text) : _error(err), _text(text) {}

    int getError() { return _error; }
    string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
    T data;
    L1Item<T> *pNext;
    L1Item() : pNext(NULL) {}
    L1Item(T &a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
    L1Item<T>   *_pHead;// The head pointer of linked list
    size_t      _size;// number of elements in this list
public:
    L1List() : _pHead(NULL), _size(0) {}
    ~L1List();

    void    clean();
    bool    isEmpty() {
        return _pHead == NULL;
    }
    size_t  getSize() {
        return _size;
    }

	T&      at(int i) // give the reference to the element i-th in the list
	{	
		L1Item<T> *temp = _pHead;
		for (int j = 1; j < i; j++) {
			temp = temp->pNext;
		}
		return temp->data;
	};
    T&      operator[](int i);// give the reference to the element i-th in the list

    bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.
    int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise
	int     remove(int i) {
		L1Item<T> *temp = _pHead;
		for (int j = 2; j < i; j++) {
			temp = temp->pNext;
		}
		L1Item<T> *tempnew = temp->pNext->pNext;
		delete temp->pNext;
		temp->pNext = tempnew;
		_size--;
		return 0;
	};// remove an element at position i in the list. Return 0 if success, -1 otherwise.

    int     push_back(T& a);// insert to the end of the list
    int     insertHead(T& a);// insert to the beginning of the list

    int     removeHead();// remove the beginning element of the list
    int     removeLast();// remove the last element of the list

    void    reverse();

    void    traverse(void (*op)(T&)) {
        // TODO: Your code goes here
    }
    void    traverse(void (*op)(T&, void*), void* pParam) {
        // TODO: Your code goes here
    }
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T &a) {
	
	if (_size == 0) { _size++; _pHead = new  L1Item<T>(a); return 0; };
	_size=_size+1;
	int i = 1;
	L1Item<T> *temp=_pHead;
	while (i < _size - 1)
	{
		temp = temp->pNext;
		i++;
	};
	temp->pNext = new  L1Item<T>(a);
    return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T &a) {
    // TODO: Your code goes here
	if (_size == 0) {
		L1Item<T> _pHead = new L1Item(a); _size++; return 0;};
	L1Item<T> *temp = new  L1Item(a);
	temp->pNext = _pHead;
	_pHead = temp;
	_size++;
    return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
    // TODO: Your code goes here
	if (_size == 0) return -1;
	L1Item<T> *tempnew = _pHead->pNext;
	delete _pHead;
	L1Item<T> _pHead=new L1Item<T>;
	_pHead = tempnew;
	_size--;
    return -1;
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
    // TODO: Your code goes here
	if (_size == 0) return -1;
	L1Item<T> *temp = _pHead;
	for (int i = 2; i < _size; i++)
	{
		temp = temp->pNext;
	};
	delete temp->pNext; // i wanna know that pNext in this = NULL?
	_size--;
    return -1;
}

#endif //DSA191_A1_DSALIB_H
