//
// Created by hmkam on 06/11/2024.
//

#ifndef CIRCULARBUFFER_HPP
#define CIRCULARBUFFER_HPP

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

template<typename T>
class CircularBuffer {
private:
    std::vector<T> buffer;
    uint16_t head;
    uint16_t tail;
    uint16_t capacity;

public:
    // Constructor to intialize circular buffer's data members
    explicit CircularBuffer(uint16_t capacity_) {
        capacity = capacity_;
        head = 0;
        tail = 0;
        buffer.resize(capacity);
    }

    ~CircularBuffer() {
        while (!empty()) {
            pop_f();
        }
    }

    // Function to add an element to the buffer
    void push_back(T element) {
        if (capacity == 0) {
            throw std::out_of_range("Cannot push an empty buffer");
        }
        buffer[head] = element;
        head = (head + 1) % capacity;
        if (head == tail) {
            pop_f();
        }
    }

    // Function to remove an element from the buffer
    void pop_front() {
        if (empty()) {
            throw std::out_of_range("Buffer is empty");
        }

        pop_f();
    }

    // Function to check if the buffer is empty
    [[nodiscard]] bool empty() const { return head == tail; }

    // Function to check if the buffer is full
    [[nodiscard]] bool full() const {
        return (head + 1) % capacity == tail;
    }

    // Function to get the size of the buffer
    [[nodiscard]] uint16_t size() const {
        if (head >= tail) {
            return head - tail;
        }
        return capacity - (tail - head);
    }

    // Overload the [] operator to access elements by index
    const T &operator[](uint16_t index) const {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return buffer[(index + tail) % capacity];
    }

    const T &index_front(uint16_t index) const {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return buffer[abs(head - 1 - index) % capacity];
    }


    // Iterator class
    class iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        iterator(T *ptr) : ptr_(ptr) {}

        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        iterator &operator++() {
            ++ptr_;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++ptr_;
            return tmp;
        }

        iterator &operator--() {
            --ptr_;
            return *this;
        }

        iterator operator--(int) {
            iterator tmp = *this;
            --ptr_;
            return tmp;
        }

        bool operator==(const iterator &other) const {
            return ptr_ == other.ptr_;
        }

        bool operator!=(const iterator &other) const {
            return ptr_ != other.ptr_;
        }

    private:
        T *ptr_;
    };

    iterator begin() { return iterator(&buffer[tail]); }
    iterator end() { return iterator(&buffer[(tail + size()) % capacity]); }

private:
    void pop_f() {
        if constexpr (std::is_pointer_v<T>) {
            delete buffer[tail];
        }

        tail = (tail + 1) % capacity;
    }
};

#endif //CIRCULARBUFFER_HPP
