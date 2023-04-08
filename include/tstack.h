// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
 private:
    T arr[size];
    int top;

 public:
    TStack():top(-1) {}
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == size;
    }
    void push(T value) {
        if (isFull()) {
            throw std::string("Stack is Full!");
        } else {
            arr[++top] = value;
        }
    }
    T pop() {
        if (isEmpty()) {
            throw std::string("Stack is Empty!");
        } else {
            return arr[top--];
        }
    }
    T get() const {
        if (isEmpty()) {
            throw std::string("Stack is Empty!");
        } else {
            return arr[top];
        }
    }
};

#endif  // INCLUDE_TSTACK_H_
