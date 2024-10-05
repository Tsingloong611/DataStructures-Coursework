# @File: array_stack.py
class ArrayStack:
    def __init__(self, size):
        self.__size = size
        self.__data = [None] * size
        self.__top = -1

    def is_empty(self):
        return self.__top == -1

    def is_full(self):
        return self.__top == self.__size - 1

    def push(self, element):
        if self.is_full():
            return False
        self.__top += 1
        self.__data[self.__top] = element
        return True

    def pop(self):
        if self.is_empty():
            return None
        element = self.__data[self.__top]
        self.__top -= 1
        return element

    def get_top(self):
        if self.is_empty():
            return None
        return self.__data[self.__top]

    def show_elements(self):
        for i in range(self.__top + 1):
            print(self.__data[i], end=' ')
        print()