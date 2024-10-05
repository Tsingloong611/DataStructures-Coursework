class LinkedList:
    def __init__(self):
        pass

    def append(self, data):
        pass

    def display(self):
        pass

    def _create_node(self, data):
        pass


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SLList(LinkedList):
    def __init__(self):
        self.head = self._create_node(None)

    def insert(self, data, index):
        current = self.head
        count = 1
        while current.next and count != index:
            current = current.next
            count += 1
        if (count != index):
            print("无效索引")
            return
        new_node = self._create_node(data)
        new_node.next = current.next
        current.next = new_node

    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        return elements

    def _create_node(self, data):
        return Node(data)


class DNode(Node):
    def __init__(self, data):
        super().__init__(data)
        self.prev = None


class DLList(LinkedList):
    def __init__(self):
        self.head = self._create_node(None)

    def _create_node(self, data):
        return DNode(data)

    def insert(self, data, index):
        count = 1
        current = self.head
        while current.next and count != index:
            current = current.next
            count += 1
        if (count != index):
            print("无效索引")
            return
        new_node = self._create_node(data)
        if (current.next):
            new_node.next = current.next
            new_node.prev = current
            current.next.prev = new_node
            current.next = new_node
            return
        new_node.prev = current
        current.next = new_node

    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        return elements


class CLList(LinkedList):
    def __init__(self):
        self.head = self._create_node(None)
        self.head.next = self.head
        self.head.prev = self.head


    def insert(self, data, index):
        count = 1
        current = self.head
        while current.next != self.head and count != index:
            current = current.next
            count += 1
        if (count != index):
            print("无效索引")
            return
        new_node = self._create_node(data)
        new_node.next = current.next
        new_node.prev = current
        current.next.prev = new_node
        current.next = new_node

    def display(self):
        if not self.head:
            return []
        elements = []
        current = self.head
        while True:
            elements.append(current.data)
            current = current.next
            if current == self.head:
                break
        return elements

    def _create_node(self, data):
        return DNode(data)