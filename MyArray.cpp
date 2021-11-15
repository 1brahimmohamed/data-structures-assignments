    #include "MyArray.h"
    #include <iostream>


    /*
     * Default constructor
     * */
    template<class T>
    MyArray<T>::MyArray() {
        size = 0;
        capacity = INITIAL_CAPACITY;
        data = new T[capacity];
    }


    /*
     * Constructors that is given an array and size as parameters
     * */

    template<class T>
    MyArray<T>::MyArray(T *arr, int size) {
        this -> size = size;
        capacity = size;
        data = new T [capacity];

        for (int i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    template<class T>
    void MyArray<T>::capacityExpansion() {
        capacity *= 2;                          // doubling the capacity
        T *temp = new T[capacity];
        for (int i = 0; i < size ; ++i) {
            temp[i] = data[i];                  // transfer the data to another bigger array
        }
        delete []data;                          // delete the first array
        data = temp;                            // make the pointer of data points to the new array
    }

    template<class T>
    void MyArray<T>::capacityShrink() {
        capacity /= 2;                          // halving the capacity
        T *temp = new T[capacity];
        for (int i = 0; i < size ; ++i) {
            temp[i] = data[i];                  // transfer the data to another smaller array
        }
        delete []data;                          // delete the first array
        data = temp;                            // make the pointer of data points to the new array
    }


    /*
     * the following function adds new element to the array from the last index
     * */

    template<class T>
    void MyArray<T>::push(T element) {

        // check if the array is full
        if (size == capacity){                      // check if size = capacity
            capacityExpansion();
        }
        data[size] = element;                       // adding the element to the array
        size++;                                     // increment the size by one

    }

    template<class T>
    T MyArray<T>::pop() {
        T deletedElement = data[size-1];

        size--;
        if (size == capacity/4)                    // check if size = 1/4 capacity
            capacityShrink();                      // halve the capacity

        return deletedElement;
    }

    template<class T>
    void MyArray<T>::insert(int index, T element) {
        if (size == capacity)                       // check if size = capacity
            capacityExpansion();                        // expand the capacity

        for (int i = ++size; i >= index; i--)
            data[i] = data[i - 1];

        // insert element at index
        data[index] = element;
    }

    template<class T>
    void MyArray<T>::remove(int index) {
        size--;
        if (size == capacity/4)                    // check if size = 1/4 capacity
            capacityShrink();                      // halve the capacity

        for (int i = index; i <= size; i++)
            data[i] = data[i + 1];
    }

    /*
     * the following method prints all the array elements
     * */
    template<class T>
    void MyArray<T>::print() {
        for (int i = 0; i < size; ++i)
            std::cout << data[i] << " ";        // prints every element
            std::cout << std::endl;
    }

    /*
   * the following method returns the array size
   * */
    template<class T>
    int MyArray<T>::get_size() {
        return size;
    }


    /*
    * the following method returns the array capacity
    * */
    template<class T>
    int MyArray<T>::get_capacity() {
        return capacity;
    }

    template<class T>
    T MyArray<T>::get(int index) {
        return data[index];
    }


