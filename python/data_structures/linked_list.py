"""
This module implements a singly linked list data structure in Python.
Classes:
    Node: Represents a node in the linked list.
    LinkedList: Represents the linked list with various methods to manipulate it.
Methods of LinkedList:
    __init__(value): Initializes the linked list with a single node.
    __del__(): Destructor to clean up the linked list.
    append(value): Appends a node with the given value to the end of the list.
    deleteLast(): Deletes the last node of the list.
    prepend(value): Prepends a node with the given value to the start of the list.
    deleteFirst(): Deletes the first node of the list.
    get(index): Returns the node at the specified index.
    set(index, value): Sets the value of the node at the specified index.
    insert(index, value): Inserts a node with the given value at the specified index.
    deleteNode(index): Deletes the node at the specified index.
    reverse(): Reverses the linked list.
    printList(): Prints all the values in the linked list.
    getHead(): Prints the value of the head node.
    getTail(): Prints the value of the tail node.
    getLength(): Prints the length of the linked list.
"""

class Node:
    """
    A class used to represent a Node in a linked list.

    Attributes
    ----------
    value : any
        The value stored in the node.
    next : Node or None
        The reference to the next node in the linked list, or None if there is no next node.

    Methods
    -------
        __init__(self, value):
            Initializes the node with a value and sets the next reference to None.
    """

    def __init__(self, value):
        self.value = value
        self.next = None

    def get_value(self):
        """
        This method will get the value of the node.

        Returns
        -------
        int
            This is the value of the node.
        """
        return self.value

    def get_next(self):
        """
        This method will return the next node pointed to by this node.

        Returns
        -------
        Node
            This is the next node that is pointed to by this node.
        """
        return self.next

class LinkedList:
    """
    A class used to represent a linked list.

    Attributes
    ----------
    head : Node or None
        The first node in the linked list, or None if the list is empty.
    tail : Node or None
        The last node in the linked list, or None if the list is empty.
    length : int
        The number of nodes in the linked list.

    Methods
    -------
    __init__(self, value):
        Initializes the linked list with a single node.
    __del__(self):
        Destructor to clean up the linked list.
    append(self, value):
        Appends a node with the given value to the end of the list.
    deleteLast(self):
        Deletes the last node of the list.
    prepend(self, value):
        Prepends a node with the given value to the start of the list.
    deleteFirst(self):
        Deletes the first node of the list.
    get(self, index):
        Returns the node at the specified index.
    set(self, index, value):
        Sets the value of the node at the specified index.
    insert(self, index, value):
        Inserts a node with the given value at the specified index.
    deleteNode(self, index):
        Deletes the node at the specified index.
    reverse(self):
        Reverses the linked list.
    printList(self):
        Prints all the values in the linked list.
    getHead(self):
        Prints the value of the head node.
    getTail(self):
        Prints the value of the tail node.
    getLength(self):
        Prints the length of the linked list.
    """
    def __init__(self, value):
        new_node = Node(value)
        self.head = new_node
        self.tail = new_node
        self.length = 1

    def __del__(self):
        while self.head:
            temp = self.head
            self.head = self.head.next
            del temp

    def append(self, value):
        """
        A method to append a value to the end of the linked list.

        Parameters
        ----------
        value : int
            This is the integer value to be appended to the linked list.
        """
        new_node = Node(value)
        if self.tail:
            self.tail.next = new_node
            self.tail = new_node
        else:
            self.head = new_node
            self.tail = new_node
        self.length += 1

    def delete_last(self):
        """
        A method to delete the last node at the end of the linked list.
        """
        if self.length > 1:
            temp = self.head
            while temp.next != self.tail:
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

    def prepend(self, value):
        """
        This method will prepend an integer value to the beginning of a linked list.

        Parameters
        ----------
        value : int
            This is the integer value to be prepended to the linked list.
        """
        new_node = Node(value)
        if self.head:
            new_node.next = self.head
            self.head = new_node
            self.length += 1
        else:
            self.head = new_node
            self.tail = new_node
            self.length += 1

    def delete_first(self):
        """
        This method will delete the first node of the linked list.
        """
        temp = self.head
        if self.length > 1:
            self.head = self.head.next
            del temp
            self.length -= 1
        elif self.length == 1:
            self.head = None
            self.tail = None
            self.length = 0

    def get(self, index):
        """
        This method will get the node at the specified index in the linked list.

        Parameters
        ----------
        index : int
            This is the position of the node in the linked list.

        Returns
        -------
        Node
            This is the node at the specified index position of the linked list.
        """
        if index == 0:
            return self.head
        if index >= self.length:
            return None
        temp = self.head
        i = 0
        while i < index:
            temp = temp.next
            i += 1
        return temp

    def set(self, index, value):
        """
        This method will set a node's value to the value parameter at the specified index.

        Parameters
        ----------
        index : int
            This is the index position of the node at which the value will be changed.
        value : int
            This is the new value of the node.
        """
        if index == 0:
            self.head.value = value
        elif index >= self.length:
            return
        else:
            temp = self.head
            i = 0
            while i < index:
                temp = temp.next
                i += 1
            temp.value = value

    def insert(self, index, value):
        """
        This method will insert a node with a value at the specified index of the linked list.

        Parameters
        ----------
        index : int
            This is the index at which to insert the node.
        value : int
            This is the value of the node that is inserted.
        """
        if self.length == 0 :
            new_node = Node(value)
            self.head = new_node
            self.tail = new_node
            self.length = 0
        elif index >= self.length:
            self.append(value)
        elif index <= 0:
            self.prepend(value)
        else:
            i = 0
            pre = self.head
            post = self.head
            while i < index:
                pre = post
                post = post.next
                i += 1
            pre.next = Node(value)
            pre.next.next = post
            self.length += 1

    def delete_node(self, index):
        """
        This method will delete a node at the specified index of the linked list.

        Parameters
        ----------
        index : int
            This is the index at which to delete the node from the linked list.
        """
        if self.length == 0:
            return
        if index >= self.length - 1:
            self.delete_last()
        elif index <= 0:
            self.delete_first()
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
        """
        This method will reverse the linked list.
        """
        if self.length > 1:
            first = self.head
            last = self.tail
            for i in range(0, self.length // 2):
                temp = first.value
                first.value = last.value
                last.value = temp
                first = first.next
                penultimate = first
                if (self.length > 3 and (i < (self.length // 2 - 1))):
                    while penultimate.next != last:
                        penultimate = penultimate.next
                    last = penultimate

    def print_list(self):
        """
        This method will print the items in the linked list.
        """
        temp = self.head
        while temp:
            print(f"{temp.value}")
            temp = temp.next

    def get_head(self):
        """
        This method will print the item at the head of the linked list.
        """
        print(f"Head: {self.head.value}")

    def get_tail(self):
        """
        This method will print the value of the item at the tail of the linked list.
        """
        print(f"Tail: {self.tail.value}")

    def get_length(self):
        """
        This method will print the lenght of the linked list.
        """
        print(f"Length: {self.length}")
