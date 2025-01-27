"""
This module is used to test the linked_list module.
"""

from python.data_structures.linked_list import Node

def test_construct_node():
    """
    This tests the node's constructor.
    """
    node = Node(20)
    assert node.value == 20
    assert node.next is None
