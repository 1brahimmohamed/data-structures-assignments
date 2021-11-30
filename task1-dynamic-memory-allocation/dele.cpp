#include "MyArray.h"
#include <iostream>


template<class T>
MyArray <T>::MyArray()
{
    size = 0;
    capacity = INITIAL_CAPACITY;
    data = new T[capacity];
}


template<class T>
MyArray <T>::MyArray(T arr[], int size) {
    if(size >= INITIAL_CAPACITY) {
        expand();
    }

    data=new T[capacity];
    for (int i=0; i<size; i++)
        data[i]= arr[i];
    this->size = size;
}


template <class T>
T MyArray <T> ::get(int index) {
    return data[index];
}


template <class T>
void MyArray <T> ::push(T element) {
    if (size == capacity) expand();
    data[size++] = element;
}


template <class T>
T MyArray <T> ::pop() {
    if (size==0)
        return -1;

    else {

        T x = data[size - 1];
        size--;
        if (size == capacity / 4) {
            shrink();
        }
        return x;
    }
}


template <class T>
void MyArray <T> ::insert(int index, T element) {
    if (size == capacity) expand();
    if ((index >= 0 && index < size)) {
        for (int i = size ; i > index; i--) {
            data[i] = data[i-1];
        }
        data[index] =  element;
        size++;
    }

}


template <class T>
T MyArray <T> ::remove(int index) {
    if (index >= size){
        return -1;
    }
    else{
        T returnedElement = data[index];

        for (int i = index; i < size; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size == capacity / 4){
            shrink();
        }
        return returnedElement;
    }
}


template <class T>
void MyArray <T> ::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << ' ' ;
    }
}


template <class T>
int MyArray <T> ::get_size() {
    return size;
}


template <class T>
int MyArray <T> ::get_capacity() {
    return capacity;
}


template <class T>
void MyArray <T> ::expand() {
    capacity*=2;
    T* arr1 = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr1[i] = data[i];
    }
    delete[] data;
    data = arr1;
}


template <class T>
void MyArray <T> :: shrink() {
    capacity /= 2;
    int newCapacity = (capacity);
    T* arr1 = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        arr1[i] = data[i];
    }
    delete[] data;
    data = arr1;
}