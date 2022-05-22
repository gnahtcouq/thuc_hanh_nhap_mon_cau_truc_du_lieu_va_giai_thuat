#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define MAX 50
#define MAXNODES 50
#define VOCUNG 3000

int trongSo[MAX][MAX]; // biến toàn cục -> thêm vào file source, thêm extern vào file main
int soNut;
void init();
void themCung(int node1, int node2, int ts);
void xoaCung(int node1, int node2);
void dijkstra(int nutDi, int nutDen, int* ngan, int duongDi[]);

int main() {
  int chon, x, y, i, j;
  char c;
  int wt, ngan;
  int duongDi[MAXNODES];
  int nutDi, nutDen;
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
        cout << "\nNhap cung x = ";
        cin >> x;
        cout << "\nNhap cung y = ";
        cin >> y;
        if (x < soNut && y < soNut) {
          cout << "\nTrong so cua cung = ";
          cin >> wt;
          trongSo[x][y] = wt;
        }
      }
      break;
    case 2:
      if (soNut < MAXNODES) {
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
      if (x > soNut && y > soNut)
        cout << "\nKhong hop le";
      else {
        cout << "\nTrong so cua cung = ";
        cin >> wt;
        themCung(x, y, wt);
      }
      break;
    case 4:
      cout << "\nNhap cung x can xoa = ";
      cin >> x;
      cout << "\nNhap cung y can xoa = ";
      cin >> y;
      break;
    case 5:
      cout << "\nBan co chac khong? ";
      c = getchar();
      if (c == 'c' || c == 'C') {
        init();
        soNut = 0;
      }
      break;
    case 6:
      cout << "\nSo nut co tren do thi la = " << soNut;
      break;
    case 7:
      cout << "\nCac cung co tren do thi la: ";
      for (i = 0; i < soNut; i++)
        for (j = 0; j < soNut; j++)
          if (trongSo[i][j] < VOCUNG)
            cout << i << "->" << j << "(" << trongSo[i][j] << ") - ";
      break;
    case 8:
      cout << "\nNhap cung can tim x = ";
      cin >> x;
      cout << "\nNhap cung can tim y = ";
      cin >> y;
      if (x > soNut && y > soNut)
        cout << "\nKhong hop le";
      else {
        if (trongSo[x][y] < VOCUNG)
          cout << "\nCo cung (" << x << y << ") voi trong so " << trongSo[x][y];
        else
          cout << "\nKhong co cung nay";
      }
      break;
    case 9:
      cout << "\nNhap nut di = ";
      cin >> nutDi;
      cout << "\nNhap nut den = ";
      cin >> nutDen;
      dijkstra(nutDi, nutDen, &ngan, duongDi);
      cout << "\nDuong di ngan nhat tu " << nutDi << " den nut " << nutDen << " la " << ngan;
      cout << "\nLo trinh ";
      i = nutDen;
      while (i != nutDi) {
        cout << i << " <- ";
        i = duongDi[i];
      }
      cout << nutDi;
      break;
    }
  } while (chon != 0);

  return 0;
}

void init() {
  for (int i = 0; i < MAX; i++)
    for (int j = 0; j < MAX; j++)
      trongSo[i][j] = VOCUNG;
}

void themCung(int node1, int node2, int ts) {
  trongSo[node1][node2] = ts;
}

void xoaCung(int node1, int node2) {
  trongSo[node1][node2] = VOCUNG;
}

void dijkstra(int nutDi, int nutDen, int* ngan, int duongDi[]) {
  int i, k, kc, nutHienTai, min, kcMoi;
  int tapNut[MAXNODES];
  int kcNgan[MAXNODES];

  for (i = 0; i < soNut; ++i) {
    tapNut[i] = FALSE;
    kcNgan[i] = VOCUNG;
  }
  tapNut[nutDi] = TRUE;
  kcNgan[nutDi] = 0;
  nutHienTai = nutDi;
  while (nutHienTai != nutDen) {
    min = VOCUNG;
    kc = kcNgan[nutHienTai];
    for (i = 0; i < soNut; i++) {
      if (tapNut[i] == FALSE) {
        kcMoi = kc + trongSo[nutHienTai][i];
        if (kcMoi < kcNgan[i]) {
          kcNgan[i] = kcMoi;
          duongDi[i] = nutHienTai;
        }
        if (kcNgan[i] < min) {
          min = kcNgan[i];
          k = i;
        }
      }
    }
    nutHienTai = k;
    tapNut[nutHienTai] = TRUE;
  }
  *ngan = kcNgan[nutDen];
}
