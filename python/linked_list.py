class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    # Constructor
    def __init__(self, value):
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    # Destructor
    def __del__(self):
        while self.head:
            temp = self.head
            self.head = self.head.next
            del temp

    def append(self, value):
        new_node = Node(value)
        if self.tail:
            self.tail.next = new_node
            self.tail = new_node
        else:
            self.head = new_node
            self.tail = new_node
        self.length += 1

    def deleteLast(self):
        if self.length > 1:
            temp = self.head
            while(temp.next != self.tail):
                temp = temp.next
            del self.tail
            self.tail = temp
            self.tail.next = None
            self.length -= 1
        elif self.length == 1:
            del self.tail
            self.head = None
            self.tail = None
            self.length = 0
        else:
            return
    
    def prepend(self, value):
        new_node = Node(value)
        if (self.head):
            new_node.next = self.head
            self.head = new_node
            self.length += 1
        else:
            self.head = new_node
            self.tail = new_node
            self.length += 1

    def deleteFirst(self):
        temp = self.head
        if self.length > 1:
            self.head = self.head.next
            del temp
            self.length -= 1
        elif self.length == 1:
            self.head = None
            self.tail = None
            self.length = 0
        else:
            return

    def get(self, index):
        if (index == 0):
            return self.head
        elif index >= self.length:
            return None
        else:
            temp = self.head
            i = 0
            while i < index:
                temp = temp.next
                i += 1
            return temp

    def set(self, index, value):
        if index == 0:
            self.head.value = value
        elif (index >= self.length):
            return
        else:
            temp = self.head
            i = 0;
            while (i < index):
                temp = temp.next
                i += 1
            temp.value = value

    def insert(self, index, value):
        if self.length == 0 :
            new_node = Node(value)
            self.head = new_node
            self.tail = new_node
            self.length = 0
        elif index >= self.length:
            self.append(value)
        elif (index <= 0):
            self.prepend(value)
        else:
            i = 0
            pre = self.head
            post = self.head
            while (i < index):
                pre = post
                post = post.next
                i += 1
            pre.next = Node(value)
            pre.next.next = post
            self.length += 1

    def deleteNode(self, index):
        if self.length == 0:
            return
        elif index >= self.length - 1:
            self.deleteLast(self)
        elif index <= 0:
            self.deleteFirst(self)
        else:
            i = 0
            pre = self.head
            post = self.head
            while i < index:
                pre = post
                post = post.next
                i += 1
            pre.next = post.next
            del post
            self.length -= 1

    def reverse(self):
        if self.length <= 1:
            return
        else:
            first = self.head
            last = self.tail
            for i in range(0, self.length // 2):
                temp = first.value
                first.value = last.value
                last.value = temp
                first = first.next
                penultimate = first
                if (self.length > 3 and (i < (self.length // 2 - 1))):
                    while(penultimate.next != last):
                        penultimate = penultimate.next
                    last = penultimate

    def printList(self):
        temp = self.head
        while(temp):
            print(f"{temp.value}")
            temp = temp.next

    def getHead(self):
        print(f"Head: {self.head.value}")
        
    def getTail(self):
        print(f"Tail: {self.tail.value}")
        
    def getLength(self):
        print(f"Length: {self.length}")