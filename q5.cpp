#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool isMaxHeap) {
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, isMaxHeap);
    }
}

void heapSort(int arr[], int n, bool increasing) {
    bool isMaxHeap = increasing;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }

    if (!increasing) {
        for (int i = 0; i < n / 2; i++)
            swap(arr[i], arr[n - i - 1]);
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "\nSort Order:\n1. Increasing\n2. Decreasing\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        heapSort(arr, n, true);
    else if (choice == 2)
        heapSort(arr, n, false);
    else {
        cout << "Invalid choice!";
        return 0;
    }

    cout << "\nSorted array: ";
    display(arr, n);

    return 0;
}
