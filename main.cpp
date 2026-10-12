#include <iostream>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    int n, m;
    std::cin >> n >> m;
    
    // Create a circular linked list with n nodes
    Node* head = new Node(1);
    Node* current = head;
    
    // Create the rest of the nodes
    for (int i = 2; i <= n; i++) {
        Node* newNode = new Node(i);
        current->next = newNode;
        current = newNode;
    }
    
    // Make it circular by connecting the last node to the head
    current->next = head;
    
    // Start from the node before the first node (the last node)
    Node* prev = current;
    current = head;
    
    // Process n-1 eliminations
    for (int i = 0; i < n - 1; i++) {
        // Move m-1 steps forward (since we're already on the first node to count)
        for (int j = 0; j < m - 1; j++) {
            prev = current;
            current = current->next;
        }
        
        // Print and delete the current node
        std::cout << current->data << std::endl;
        
        // Remove the current node from the list
        prev->next = current->next;
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    // Print the last remaining node
    std::cout << current->data << std::endl;
    
    // Clean up the last node
    delete current;
    
    return 0;
}
