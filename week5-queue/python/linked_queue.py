# @File: linked_queue.py
class LinkedQueue:

    def __init__(self):
        self.__front = None
        self.__rear = None

    def is_empty(self):
        return self.__front is None

    def add_element(self, element):
        node = self._create_node(element)
        if self.is_empty():
            self.__front = node
        else:
            self.__rear.next = node
        self.__rear = node

    def delete_element(self):
        if self.is_empty():
            return None
        element = self.__front.element
        self.__front = self.__front.next
        return element

    def show_elements(self):
        current = self.__front
        while current is not None:
            print(current.element, end=' ')
            current = current.next
        print()

    def _create_node(self, element):
        return Node(element)


class Node:
    def __init__(self, element):
        self.data = element
        self.next = None
