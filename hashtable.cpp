#include <iostream>
using namespace std;
#define M 100

struct Node {
  int key;
  Node* next;
};
typedef struct Node NODE;

NODE* bucket[M];
int hashFunction(int key);
void initBucket();
NODE* createNode();
bool empty(int b);
void push(int b, int x);
bool emptyBucket(int b);
int pop(int b);
void insertAfter(NODE* p, int k);
int deleteAfter(NODE* p);
void place(int b, int k);
void insert(int k);
void remove(int k);
void clearBucket(int b);
void clear();
void duyetBucket(int b);
void duyetHashTable();
int search(int k);

int main() {
  int b, key, i, n, chucnang;
  char c;
  initBucket();
  do {
    cout << "\n1. Them";
    cout << "\n2. Them ngau nhien";
    cout << "\n3. Xoa nut";
    cout << "\n4. Xoa toan bo";
    cout << "\n5. Duyet";
    cout << "\n6. Tim kiem";
    cout << "\nNhap lua chon cua ban: ";
    cin >> chucnang;
    switch (chucnang) {
    case 1:
      cout << "Khoa nut moi ";
      cin >> key;
      insert(key);
      break;
    case 2:
      cout << "Ban them bao nhieu ";
      cin >> n;
      for (i = 0; i < n; ++i) {
        key = rand() % 100;
        insert(key);
      }
      break;
    case 3:
      cout << "Khoa can xoa ";
      cin >> key;
      remove(key);
      break;
    case 4:
      cout << "Xoa toan bo ";
      c = getchar();
      if (c == 'C' || c == 'c')
        clear();
      break;
    case 5:
      cout << "Duyet bang bam ";
      duyetHashTable();
      break;
    case 6:
      cout << "Nhap khoa can tim ";
      cin >> key;
      b = search(key);
      if (b == -1)
        cout << "Khong thay";
      else
        cout << "Bucket " << b;
      break;
    }
  } while (chucnang != 0);
  clear();

  return 0;
}

int hashFunction(int key) {
  return key % M;
}

void initBucket() {
  int b;
  for (b = 0; b < M; ++b)
    bucket[b] = NULL;
}

NODE* createNode() {
  NODE* p;
  p = new NODE;
  return p;
}

bool empty(int b) {
  for (b = 0; b != M; ++b)
    if (bucket[b])
      return 0;
  return 1;
}

void push(int b, int x) {
  NODE* p;
  p = createNode();
  p->key = x;
  p->next = bucket[b];
  bucket[b] = p;
}

bool emptyBucket(int b) {
  return bucket[b] ? 0 : 1;
}

int pop(int b) {
  NODE* p;
  int k;
  if (emptyBucket(b)) {
    cout << "Khong xoa duoc";
    return 0;
  }
  p = bucket[b];
  k = p->key;
  bucket[b] = p->next;
  delete p;
  return k;
}

void insertAfter(NODE* p, int k) {
  NODE* q;
  if (p == NULL)
    cout << "Khong them nut moi duoc" << endl;
  else {
    q = createNode();
    q->key = k;
    q->next = p->next;
    p->next = q;
  }
}

int deleteAfter(NODE* p) {
  NODE* q;
  int k;
  if (!p || !p->next) {
    cout << "Khong xoa nut duoc\n";
    return 0;
  }
  q = p->next;
  k = q->key;
  p->next = q->next;
  delete q;
  return k;
}

void place(int b, int k) {
  NODE* p, * q;
  q = NULL;
  for (p = bucket[b]; p && k > p->key; p = p->next)
    q = p;
  if (!q)
    push(b, k);
  else
    insertAfter(q, k);
}

void insert(int k) {
  int b;
  b = hashFunction(k);
  place(b, k);
}

void remove(int k) {
  int b;
  NODE* p, * q;
  b = hashFunction(k);
  p = bucket[b];
  q = p;
  while (p && p->key != k) {
    q = p;
    p = p->next;
  }
  if (!p)
    cout << "Khong co nut co khoa " << k << endl;
  else if (p == bucket[b])
    pop(b);
  else deleteAfter(q);
}

void clearBucket(int b) {
  NODE* p, * q;
  q = NULL;
  p = bucket[b];
  while (p) {
    q = p;
    p = p->next;
    delete q;
  }
  bucket[b] = NULL;
}

void clear() {
  int b;
  for (b = 0; b != M; ++b)
    clearBucket(b);
}

void duyetBucket(int b) {
  NODE* p;
  p = bucket[b];
  while (p) {
    cout << "\t" << p->key;
    p = p->next;
  }
}

void duyetHashTable() {
  int b;
  for (b = 0; b < M; b++) {
    cout << "\n" << b;
    duyetBucket(b);
  }
}

int search(int k) {
  NODE* p;
  int b;
  b = hashFunction(k);
  p = bucket[b];
  while (p != NULL && k > p->key)
    p = p->next;
  if (p == NULL || k != p->key)
    return -1;
  else
    return b;
}
