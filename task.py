class Node:
    # Node class
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    # linked list class

    def __init__(self):
        self.head = None  # list start

    # 1. adding element to the begin
    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head  # New node points to the current head
        self.head = new_node  # New node begin to new head

    # 2. adding elemnt to the end
    def append(self, data):
        new_node = Node(data)
        if self.head is None:  # if list is empthy
            self.head = new_node
            return
        last = self.head
        while last.next:  # going to the last node
            last = last.next
        last.next = new_node  # last node points to the new

    # 3. Deleting of the last element
    def remove_last(self):
        if self.head is None:  # If list is empthy
            return
        if self.head.next is None:  # if in the list on element
            self.head = None
            return
        second_last = self.head
        while second_last.next.next:  # finding the second last
            second_last = second_last.next
        second_last.next = None  # cutting of the last element

    # 4. Out put of the all elements
    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(str(current.data))
            current = current.next
        print(" -> ".join(elements) if elements else "List is empty")

    # 5. Finding of neccesary element
    def search(self, key):
        current = self.head
        while current:
            if current.data == key:
                return True
            current = current.next
        return False

    # 6. Putting the element to the neccessary index
    def insert_at(self, index, data):
        if index == 0:
            self.prepend(data)
            return
        new_node = Node(data)
        current = self.head
        # Going to the pre the necessary index
        for _ in range(index - 1):
            if current is None:
                raise IndexError("Index is out of range")
            current = current.next
        new_node.next = current.next  # New node points to the next
        current.next = new_node  # previous node points to the new

    # 7. Deleting element by the value
    def remove_by_value(self, key):
        current = self.head
        # if deleting elements is a head
        if current and current.data == key:
            self.head = current.next
            current = None
            return

        prev = None
        # Find the element, remember before element
        while current and current.data != key:
            prev = current
            current = current.next

        if current is None:  # elemnts is not found
            return

        prev.next = current.next  # continue deleting node
        current = None

    # 8. Merging of the two lists
    def merge(self, other_list):
        if self.head is None:
            self.head = other_list.head
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = other_list.head  #End of the first list points to the head of second list

    # 9. Reverse list
    def reverse(self):
        prev = None
        current = self.head
        while current:
            next_node = current.next  # Remember next node
            current.next = prev  # change the direction of the link
            prev = current  # Move prev on the current
            current = next_node  # Move current to the next
        self.head = prev  # New head is ex last element

    # 10. Sorting of the list
    def insertion_sort(self):
        if self.head is None or self.head.next is None:
            return  # Empthy list of only one element in the list

        sorted_head = None
        current = self.head

        while current:
            next_node = current.next

            # Putting current to the sort part
            if sorted_head is None or sorted_head.data >= current.data:
                current.next = sorted_head
                sorted_head = current
            else:
                search = sorted_head
                while search.next and search.next.data < current.data:
                    search = search.next
                current.next = search.next
                search.next = current

            current = next_node

        self.head = sorted_head