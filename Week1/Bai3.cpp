#include <iostream>
using namespace std;

const int MAX = 100;

struct ArrayList {
    int data[MAX];
    int size = 0;

    // 1. Thêm vào cuối
    bool insertLast(int x) {
        if (size >= MAX) return false;
        data[size++] = x;
        return true;
    }

    // 2. Thêm vào vị trí index
    bool insertAt(int index, int x) {
        if (size >= MAX || index < 0 || index > size) return false;
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = x;
        size++;
        return true;
    }

    // 3. Thêm vào đầu
    bool insertFirst(int x) {
        return insertAt(0, x);
    }

    // 4. Xóa tại vị trí index
    bool deleteAt(int index) {
        if (index < 0 || index >= size) return false;
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }

    // 5. Xóa đầu & Xóa cuối
    bool deleteFirst() { return deleteAt(0); }
    bool deleteLast()  { return deleteAt(size - 1); }

    // 6. Lấy giá trị tại index
    int get(int index) const {
        return (index >= 0 && index < size) ? data[index] : -1;
    }

    // 7. In xuôi
    void printForward() const {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << "\n";
    }

    // 8. In ngược
    void printReverse() const {
        for (int i = size - 1; i >= 0; i--) cout << data[i] << " ";
        cout << "\n";
    }
};

int main() {
    ArrayList list;

    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);

    cout << "Phan tu tai index 1: " << list.get(1) << "\n";
    cout << "Mang ban dau: ";
    list.printForward();

    cout << "Chen 5 vao dau: ";
    list.insertFirst(5);
    list.printForward();

    cout << "Chen 15 vao index 2: ";
    list.insertAt(2, 15);
    list.printForward();

    cout << "Xoa dau: ";
    list.deleteFirst();
    list.printForward();

    cout << "Xoa cuoi: ";
    list.deleteLast();
    list.printForward();

    cout << "Xoa index 1: ";
    list.deleteAt(1);
    list.printForward();

    cout << "In nguoc: ";
    list.printReverse();

    return 0;
}