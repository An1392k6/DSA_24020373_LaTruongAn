#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getSize(Node* head) {
    int cnt = 0;
    for (Node* cur = head; cur; cur = cur->next) cnt++;
    return cnt;
}

// 1. Thêm vào đầu
void insertFirst(Node* &head, int x) {
    Node* p = new Node(x);
    p->next = head;
    head = p;
}

// 2. Thêm vào cuối
void insertLast(Node* &head, int x) {
    if (!head) { insertFirst(head, x); return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = new Node(x);
}

// 3. Thêm vào vị trí k 
void insertMiddle(Node* &head, int x, int k) {
    int n = getSize(head);
    if (k < 1 || k > n + 1) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    if (k == 1) { insertFirst(head, x); return; }
    if (k == n + 1) { insertLast(head, x); return; }

    Node* cur = head;
    for (int i = 1; i < k - 1; i++) cur = cur->next;

    Node* p = new Node(x);
    p->next = cur->next;
    cur->next = p;
}

// 4. Xóa phần tử ở đầu
void deleteFirst(Node* &head) {
    if (!head) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

// 5. Xóa phần tử ở cuối
void deleteLast(Node* &head) {
    if (!head || !head->next) { deleteFirst(head); return; }

    Node* cur = head;
    while (cur->next->next) cur = cur->next;

    delete cur->next;
    cur->next = nullptr;
}

// 6. Xóa tại vị trí k 
void deleteMiddle(Node* &head, int k) {
    int n = getSize(head);
    if (k < 1 || k > n) {
        cout << "Vi tri khong hop le!\n";
        return;
    }
    if (k == 1) { deleteFirst(head); return; }

    Node* cur = head;
    for (int i = 1; i < k - 1; i++) cur = cur->next;

    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

// 7. Duyệt in xuôi
void inXuoi(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " ";
    cout << "\n";
}

// 8. Duyệt in ngược (đệ quy)
void inNguoc(Node* head) {
    if (!head) return;
    inNguoc(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = nullptr;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Chen dau\n2. Chen cuoi\n3. Chen vi tri k\n";
        cout << "4. Xoa dau\n5. Xoa cuoi\n6. Xoa vi tri k\n";
        cout << "7. In xuoi\n8. In nguoc\n0. Thoat\n";
        cout << "Lua chon: ";

        int lc; 
        if (!(cin >> lc) || lc == 0) break;

        int x, pos;
        if (lc == 1) {
            cout << "Gia tri: "; cin >> x;
            insertFirst(head, x);
        } else if (lc == 2) {
            cout << "Gia tri: "; cin >> x;
            insertLast(head, x);
        } else if (lc == 3) {
            cout << "Gia tri va vi tri: "; cin >> x >> pos;
            insertMiddle(head, x, pos);
        } else if (lc == 4) {
            deleteFirst(head);
        } else if (lc == 5) {
            deleteLast(head);
        } else if (lc == 6) {
            cout << "Vi tri can xoa: "; cin >> pos;
            deleteMiddle(head, pos);
        } else if (lc == 7) {
            cout << "Danh sach: ";
            inXuoi(head);
        } else if (lc == 8) {
            cout << "Danh sach nguoc: ";
            inNguoc(head);
            cout << "\n";
        }
    }
    while (head) deleteFirst(head);
    return 0;
}