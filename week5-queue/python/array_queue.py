# @File: array_queue.py
class ArrayQueue:
    def __init__(self, size):
        self.__size = size
        self.__data = [None] * size
        self.__front = 0
        self.__rear = 0

    def is_empty(self):
        return self.__front == self.__rear

    def is_full(self):
        return (self.__rear + 1) % self.__size == self.__front

    def add_element(self, element):
        if self.is_full():
            return False
        self.__data[self.__rear] = element
        self.__rear = (self.__rear + 1) % self.__size
        return True

    def delete_element(self):
        if self.is_empty():
            return None
        element = self.__data[self.__front]
        self.__front = (self.__front + 1) % self.__size
        return element

    def show_elements(self):
        i = self.__front
        while i != self.__rear:
            print(self.__data[i], end=' ')
            i = (i + 1) % self.__size
        print()