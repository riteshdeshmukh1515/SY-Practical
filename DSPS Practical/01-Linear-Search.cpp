#include <iostream>
using namespace std;
class lisearch {
public:
    void accept();
    void search();
private:
    int size;
    int arr[100];
    int target;
};

void lisearch::accept() {
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void lisearch::search() {
    cout << "Enter the target element to search: ";
    cin >> target;

    int firstIndex = -1, lastIndex = -1, count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            if (firstIndex == -1) {
                firstIndex = i;
            }
            lastIndex = i;
            count++;
        }
    }

    if (count > 0) {
        cout << "Element found " << count << " times" << endl;
        cout << "First occurrence at index: " << firstIndex << endl;
        cout << "Last occurrence at index: " << lastIndex << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}

int main() {
    lisearch l;
    int ch;

    while (1) {
        cout << "Enter your choice \n1. Accept the array\n2. Search the element\n3. Exit: ";
        cin >> ch;

        switch (ch) {
        case 1:
            l.accept();
            break;
        case 2:
            l.search();
            break;
        case 3:
            return 0;
        default:
            cout << "Wrong choice" << endl;
        }
    }

    return 0;
}
