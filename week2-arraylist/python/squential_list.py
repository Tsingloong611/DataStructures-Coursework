# @File: squential_list.py
class SequentialList:
    def __init__(self, size):
        self.__size = size
        self.__data = [None] * size
        self.__length = 0

    def is_empty(self):
        return self.__length == 0

    def is_full(self):
        return self.__length == self.__size

    def add_element(self, element):
        if self.is_full():
            return False
        self.__data[self.__length] = element
        self.__length += 1
        return True

    def get_element(self, index):
        if index < 1 or index > self.__length:
            return None
        return self.__data[index - 1]

    def insert_element(self, index, element):
        if self.is_full() or index < 1 or index > self.__length + 1:
            return False
        for i in range(self.__length, index - 1, -1):
            self.__data[i] = self.__data[i - 1]
        self.__data[index - 1] = element
        self.__length += 1
        return True

    def delete_element(self, index):
        if index < 1 or index > self.__length:
            return False
        for i in range(index - 1, self.__length - 1):
            self.__data[i] = self.__data[i + 1]
        self.__length -= 1
        return True

    def show_elements(self):
        for i in range(self.__length):
            print(self.__data[i], end=' ')
        print()


if __name__ == "__main__":
    while (True):
        option = input(
            "1.初始化线性表\n2.判断空\n3.判断满\n4.表尾增加元素\n5.根据索引查询元素\n6.根据索引插入元素\n7.根据索引删除元素\n8.展示线性表\n")
        if (option == "1"):
            size = input("请输入大小")
            L = SequentialList(int(size))
        elif (option == "2"):
            print(L.is_empty())
        elif (option == "3"):
            print(L.is_full())
        elif (option == "4"):
            e = input("输入元素值")
            L.add_element(e)
        elif (option == "5"):
            index = input("输入索引值")
            L.get_element(int(index))
        elif (option == "6"):
            e = input("输入元素值")
            index = input("输入索引值")
            L.insert_element(int(index), e)
        elif (option == "7"):
            index = input("输入索引值")
            L.delete_element(int(index))
        elif (option == "8"):
            L.show_elements()
        else:
            print("无效输入")
