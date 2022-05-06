#include <iostream>
using namespace std;

#define VOCUNG 30000
#define TRUE 1
#define FALSE 0
#define MAX 50

int trongSo[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];
int soNut;

void init();
void taoCung(int node1, int node2, int ts);
void xoaCung(int node1, int node2);
void floyd();
void inLoTrinh(int x, int y);

int main() {
  int chon, x, y, i, j, ts;
  char c;
  int p, q, r;
  init();
  soNut = 0;
  do {
    cout << "\n1. Tao do thi moi";
    cout << "\n2. Them mot nut";
    cout << "\n3. Them mot cung";
    cout << "\n4. Xoa mot cung";
    cout << "\n5. Xoa toan bo do thi";
    cout << "\n6. Xac dinh so nut co tren do thi";
    cout << "\n7. Duyet cung";
    cout << "\n8. Tim cung";
    cout << "\n9. Tim duong di ngan nhat";
    cout << "\n0. Thoat";
    cout << "\nChon chuc nang ban can: ";
    cin >> chon;
    switch (chon) {
    case 1:
      init();
      cout << "\nDo thi moi co bao nhieu nut = ";
      cin >> soNut;
      x = y = 0;
      while (x < soNut && y < soNut) {
        cout << "Nhap x, y lon hon " << soNut << " de thoat" << endl;
        cout << "Nhap nut dau x = ";
        cin >> x;
        cout << "Nhap nut cuoi y = ";
        cin >> y;
        if (x < soNut && y < soNut) {
          cout << "Trong so cua cung (" << x << "," << y << ") = ";
          cin >> ts;
          taoCung(x, y, ts);
        }
      }
      break;
    case 2:
      if (soNut < MAX) {
        soNut++;
        cout << "\nSo nut hien tai = " << soNut;
      }
      else
        cout << "\nKhong the them nut moi";
      break;
    case 3:
      cout << "\nNhap cung can them x = ";
      cin >> x;
      cout << "\nNhap cung can them y = ";
      cin >> y;
      if (x < soNut && y > soNut)
        cout << "\nKhong hop le";
      else {
        cout << "Trong so cua cung = ";
        cin >> ts;
        trongSo[x][y] = ts;
      }
      break;
    case 4:
      cout << "\nNhap cung can xoa x = ";
      cin >> x;
      cout << "\nNhap cung can xoa y = ";
      cin >> y;
      xoaCung(x, y);
      break;
    case 5:
      cout << "\nBan co chac khong?";
      cin >> c;
      if (c == 'c' || c == 'C') {
        init();
        soNut = 0;
      }
      break;
    case 6:
      cout << "\nSo nut co tren do thi la = " << soNut;
      break;
    case 7:
      cout << "\nCac cung co tren do thi la: " << endl;
      for (i = 0; i < soNut; i++)
        for (j = 0; j < soNut; j++)
          if (trongSo[i][j] < VOCUNG && trongSo[i][j] > 0)
            cout << i << "->" << j << "(" << trongSo[i][j] << ")" << endl;
      break;
    case 8:
      cout << "\nNhap cung can tim x = ";
      cin >> x;
      cout << "\nNhap cung can tim y = ";
      cin >> y;
      if (x > soNut && y > soNut)
        cout << "\nKhong hop le";
      else {
        if (trongSo[x][y] < VOCUNG && trongSo[i][j] > 0)
          cout << "\nCo cung (" << x << "," << y << ")" << " voi trong so " << trongSo[x][y];
        else
          cout << "\nKhong co cung nay";
      }
      break;
    case 9:
      cout << "\nNhap nut di x = ";
      cin >> x;
      cout << "\nNhap nut den y = ";
      cin >> y;
      if (x >= soNut || y >= soNut)
        cout << "Khong hop le";
      else {
        floyd();
        cout << "\nChieu dai ngan nhat tu " << x << " den nut " << y << " la " << D[x][y];
        cout << "\nLo trinh duong di: ";
        inLoTrinh(x, y);
      }
      break;
    }
  } while (chon != 0);

  system("pause");
  return 0;
}

void init() {
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      if (i == j)
        trongSo[i][j] = 0;
      else
        trongSo[i][j] = VOCUNG;
}

void taoCung(int node1, int node2, int ts) {
  if (node1 != node2)
    trongSo[node1][node2] = ts;
}

void xoaCung(int node1, int node2) {
  trongSo[node1][node2] = VOCUNG;
}

void floyd() {
  int i, j, k;
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) {
      D[i][j] = trongSo[i][j];
      P[i][j] = -1;
    }
  for (k = 0; k < soNut; k++)
    for (i = 0; i < soNut; i++)
      if ((D[i][k] > 0) && (D[i][k] < VOCUNG))
        for (j = 0; j < soNut; j++)
          if ((D[k][j] > 0) && (D[k][j] < VOCUNG))
            if (D[i][j] && D[i][k] + D[k][j] < D[i][j]) {
              D[i][j] = D[i][k] + D[k][j];
              P[i][j] = k;
            }
}

void inLoTrinh(int x, int y) {
  int r;
  if ((P[x][y] == -1)) {
    cout << x << " -> " << y;
    return;
  }
  else {
    r = P[x][y];
    inLoTrinh(x, r);
    inLoTrinh(r, y);
  }
}
