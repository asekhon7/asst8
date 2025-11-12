#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int value) {
        size++;
        int i = size - 1;
        arr[i] = value;

        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    int extractMax() {
        if (size <= 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return root;
    }

    int getMax() {
        if (size <= 0) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        cout << "Current Priority Queue (Max-Heap): ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\n--- Priority Queue using Heap ---\n";
        cout << "1. Insert\n";
        cout << "2. Extract Max\n";
        cout << "3. Get Max\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
        }
        else if (choice == 2) {
            value = pq.extractMax();
            if (value != -1)
                cout << "Removed element with highest priority: " << value << endl;
        }
        else if (choice == 3) {
            value = pq.getMax();
            if (value != -1)
                cout << "Highest priority element: " << value << endl;
        }
        else if (choice == 4) {
            pq.display();
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
