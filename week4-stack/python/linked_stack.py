# @File: linked_stack.py
class LinkedStack:

    def __init__(self):
        self.__top = None

    def is_empty(self):
        return self.__top is None

    def push(self, element):
        node = self._create_node(element)
        node.next = self.__top
        self.__top = node

    def pop(self):
        if self.is_empty():
            return None
        element = self.__top.element
        self.__top = self.__top.next
        return element

    def get_top(self):
        if self.is_empty():
            return None
        return self.__top.element

    def show_elements(self):
        current = self.__top
        while current is not None:
            print(current.element, end=' ')
            current = current.next
        print()

    def _create_node(self, element):
        return Node(element)


class Node:
    def __init__(self, element, next=None):
        self.element = element
        self.next = next
