#include <iostream>

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Function to create a circular linked list with n nodes
Node* createCircularList(int n) {
    if (n == 0) return nullptr;
    
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
    
    return head;
}

// Function to solve the Josephus problem
void solveJosephus(int n, int m) {
    // Create a circular linked list with n nodes
    Node* head = createCircularList(n);
    
    if (head == nullptr) return;
    
    Node* current = head;
    Node* prev = nullptr;
    
    // Find the last node
    while (current->next != head) {
        current = current->next;
    }
    prev = current;  // prev points to the last node
    current = head;  // current points to the first node
    
    // Process n-1 eliminations
    for (int i = 0; i < n - 1; i++) {
        // Move m-1 steps forward
        for (int j = 0; j < m - 1; j++) {
            prev = current;
            current = current->next;
        }
        
        // Delete the current node
        Node* nextNode = current->next;
        prev->next = nextNode;
        std::cout << current->data << std::endl;
        delete current;
        
        // Update current for next iteration
        current = nextNode;
    }
    
    // Print the last remaining node
    std::cout << current->data << std::endl;
    
    // Clean up the last node
    delete current;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    solveJosephus(n, m);
    
    return 0;
}
