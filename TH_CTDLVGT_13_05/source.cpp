#include <iostream>
#include <stdio.h>
using namespace std;

#define VOCUNG 30000
#define TRUE 1
#define FALSE 0
#define MAX 50

int maTran[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];
int soNut;

void init();
void taoCung(int node1, int node2, int ts);
void xoaCung(int node1, int node2);
void floyd();
void inLoTrinh(int x, int y);
int bacDinhVao(int dinh);
int bacDinhRa(int dinh);
int bacDinh(int dinh);
void docMaTran();
void ghiMaTran();
void xemMaTran();
void dijkstra(int nutDi, int nutDen, int* ngan, int duongDi[]);

int main() {
  int chon, x, y, i, j, ts;
  char c;
  int p, q, r, dinh;
  int ngan, duongDi[MAX];
  soNut = 0;
  do {
    cout << "\n1. Tao do thi moi";
    cout << "\n2. Them mot nut";
    cout << "\n3. Xoa mot nut";
    cout << "\n4. Them mot cung";
    cout << "\n5. Xoa mot cung";
    cout << "\n6. Xoa toan bo do thi";
    cout << "\n7. Xac dinh so nut co tren do thi";
    cout << "\n8. Xem cac canh co trong do thi";
    cout << "\n9. Tim cung";
    cout << "\n10. Tim duong di ngan nhat";
    cout << "\n11. Xem ma tran";
    cout << "\n12. Bac cua mot dinh";
    cout << "\n13. Bac cua mot dinh vao";
    cout << "\n14. Bac cua mot dinh ra";
    cout << "\n0. Thoat";
    cout << "\nChon chuc nang ban can: ";
    cin >> chon;
    switch (chon) {
    case 1:
      cout << "\nDo thi moi co bao nhieu nut = ";
      cin >> soNut;
      init();
      docMaTran();
      while (true) {
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
        else
          break;
      }
      ghiMaTran();
      break;
    case 2:
      cout << "\nThem mot nut moi";
      if (soNut < MAX) {
        docMaTran();
        soNut++;
        cout << "\nSo nut hien tai = " << soNut;
        for (int i = 0; i < soNut - 1; i++)
          maTran[i][soNut - 1] = -1;
        for (int i = 0; i < soNut - 1; i++)
          maTran[soNut - 1][i] = -1;
        ghiMaTran();
      }
      else
        cout << "\nKhong the them nut moi";
      break;
    case 3:
      cout << "\nXoa mot nut da co trong do thi";
      if (soNut < MAX) {
        docMaTran();
        soNut--;
        cout << "\nSo nut hien tai = " << soNut;
        ghiMaTran();
      }
      else
        cout << "\nKhong the them nut moi";
      break;
    case 4:
      docMaTran();
      cout << "\nNhap cung can them x = ";
      cin >> x;
      cout << "\nNhap cung can them y = ";
      cin >> y;
      if (x > soNut && y > soNut)
        cout << "\nKhong hop le";
      else {
        cout << "Trong so cua cung (" << x << "," << y << ") = ";
        cin >> ts;
        maTran[x][y] = ts;
      }
      ghiMaTran();
      break;
    case 5:
      cout << "\nNhap cung can xoa x = ";
      cin >> x;
      cout << "\nNhap cung can xoa y = ";
      cin >> y;
      docMaTran();
      xoaCung(x, y);
      ghiMaTran();
      break;
    case 6:
      cout << "\nBan co chac khong?";
      cin >> c;
      if (c == 'c' || c == 'C') {
        init();
        soNut = 0;
      }
      break;
    case 7:
      cout << "\nSo nut co tren do thi la = " << soNut;
      break;
    case 8:
      docMaTran();
      cout << "\nCac cung co tren do thi la: " << endl;
      for (i = 0; i < soNut; i++)
        for (j = 0; j < soNut; j++)
          if (maTran[i][j] < VOCUNG && maTran[i][j] > 0)
            cout << i << "->" << j << "(" << maTran[i][j] << ")" << endl;
      break;
    case 9:
      docMaTran();
      cout << "\nNhap cung can tim x = ";
      cin >> x;
      cout << "\nNhap cung can tim y = ";
      cin >> y;
      if (x > soNut && y > soNut)
        cout << "\nKhong hop le";
      else {
        if (maTran[x][y] > 0)
          cout << "\nCo cung (" << x << "," << y << ")" << " voi trong so " << maTran[x][y];
        else
          cout << "\nKhong co cung nay";
      }
      break;
      // case 10:
      //   docMaTran();
      //   cout << "\nNhap nut di x = ";
      //   cin >> x;
      //   cout << "\nNhap nut den y = ";
      //   cin >> y;
      //   if (x >= soNut || y >= soNut)
      //     cout << "Khong hop le";
      //   else {
      //     floyd();
      //     cout << "\nChieu dai ngan nhat tu " << x << " den nut " << y << " la " << D[x][y];
      //     cout << "\nLo trinh duong di: ";
      //     inLoTrinh(x, y);
      //   }
      //   break;
    case 10:
      docMaTran();
      cout << "\nNhap nut di x = ";
      cin >> x;
      cout << "\nNhap nut den y = ";
      cin >> y;
      dijkstra(x, y, &ngan, duongDi);
      cout << "\nDuong di ngan nhat tu " << x << " den nut " << y << " la " << ngan;
      cout << "\nLo trinh ";
      i = y;
      while (i != x) {
        cout << i << " <- ";
        i = duongDi[i];
      }
      cout << x;
      break;
    case 11:
      cout << "\nXem ma tran";
      docMaTran();
      xemMaTran();
      break;
    case 12:
      docMaTran();
      cout << "\nBac cua mot dinh";
      cout << "\nNhap dinh can biet = ";
      cin >> dinh;
      cout << "\nBac cua dinh " << dinh << " = " << bacDinh(dinh);
      break;
    case 13:
      docMaTran();
      cout << "\nBac cua mot dinh co cung vao";
      cout << "\nNhap dinh can biet = ";
      cin >> dinh;
      cout << "\nBac cua dinh " << dinh << " = " << bacDinhVao(dinh);
      break;
    case 14:
      docMaTran();
      cout << "\nBac cua mot dinh co cung ra";
      cout << "\nNhap dinh can biet = ";
      cin >> dinh;
      cout << "\nBac cua dinh " << dinh << " = " << bacDinhRa(dinh);
      break;
    }
  } while (chon != 0);

  system("pause");
  return 0;
}

void taoCung(int node1, int node2, int ts) {
  if (node1 != node2)
    maTran[node1][node2] = ts;
}

void xoaCung(int node1, int node2) {
  maTran[node1][node2] = VOCUNG;
}

void floyd() {
  int i, j, k;
  for (i = 0; i < MAX; i++)
    for (j = 0; j < MAX; j++) {
      D[i][j] = maTran[i][j];
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

void init() {
  int i, j;
  FILE* f;
  fopen_s(&f, "dothi3.txt", "wt");
  if (f != NULL) {
    fprintf(f, "%d\n", soNut);
    for (i = 0; i < soNut; i++) {
      for (j = 0; j < soNut; j++)
        if (i == j)
          fprintf(f, "%d\t", 0);
        else
          fprintf(f, "%d\t", -1);
      fprintf(f, "\n");
    }
    fclose(f);
  }
}

void docMaTran() {
  FILE* f;
  fopen_s(&f, "dothi3.txt", "rt");
  if (f == NULL) return;
  fscanf(f, "%d", &soNut);
  for (int i = 0; i < soNut; i++)
    for (int j = 0; j < soNut; j++)
      fscanf_s(f, "%d", &maTran[i][j]);
  fclose(f);
}

void ghiMaTran() {
  FILE* f;
  fopen_s(&f, "dothi3.txt", "wt");
  if (f == NULL) return;
  fprintf(f, "%d", soNut);
  for (int i = 0; i < soNut; i++) {
    fprintf(f, "\n");
    for (int j = 0; j < soNut; j++)
      fprintf(f, "%d\t", maTran[i][j]);
  }
  fclose(f);
}

void xemMaTran() {
  cout << "\nGia tri trong file la: ";
  cout << "\n" << soNut << "\n";
  for (int i = 0; i < soNut; i++) {
    for (int j = 0; j < soNut; j++)
      cout << maTran[i][j] << "\t";
    cout << "\n";
  }
}

int bacDinhVao(int dinh) {
  int dem = 0;
  for (int i = 0; i < soNut; i++)
    if (maTran[i][dinh] > 0)
      dem++;
  return dem;
}

int bacDinhRa(int dinh) {
  int dem = 0;
  for (int i = 0; i < soNut; i++)
    if (maTran[dinh][i] > 0)
      dem++;
  return dem;
}

int bacDinh(int dinh) {
  return bacDinhRa(dinh) + bacDinhVao(dinh);
}

void dijkstra(int nutDi, int nutDen, int* ngan, int duongDi[]) {
  int i, k, kc, nutHienTai, min, kcMoi;
  int tapNut[MAX];
  int kcNgan[MAX];

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
        kcMoi = kc + maTran[nutHienTai][i];
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