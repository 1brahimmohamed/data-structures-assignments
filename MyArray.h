#ifndef MyArray_H
#define MyArray_H
#define INITIAL_CAPACITY 8


    template <class T>
    class MyArray{
    private:
        int size{};
        int capacity;
        T* data;
        void capacityExpansion();
        void capacityShrink();

    public:
        MyArray();
        MyArray(T[], int size);
        T get(int index);
        void push(T element);
        T pop();
        void insert(int index, T element);
        void remove(int index);
        void print();
        int get_size();
        int get_capacity();
    };

    #include "MyArray.cpp"
    #endif