#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left, *right;
};
typedef struct Node NODE;

void init(NODE*& root);
NODE* getNode(int x);
void themNodeVaoCay(NODE*& root, int x);
void NLR(NODE *root);
void LNR(NODE *root);
void RNL(NODE *root);
void LRN(NODE *root);
void taoCayTuDaySo(NODE *&root, int a[], int n);
int tinhTongCacNut(NODE *root);
void tinhTongCacNutLa(NODE *root, int &dem);
int demSoLuongNutCuaCay(NODE *root);
int tinhChieuCaoCuaCay(NODE *root);
int demSoLuongNutChan(NODE *root);
int demSoLuongNutLe(NODE *root);
int tinhTongCacNutChan(NODE *root);
int tinhTongCacNutLe(NODE *root);
void lietKeCacNutChan(NODE *root);
long long tinhTichCacNutChan(NODE *root);
int demSoLuongSoChinhPhuong(NODE *root);
int kiemtraSNT(int n);
int demSoLuongSoNguyenTo(NODE *root);
int kiemTraHoanThien(int x);
int demSoLuongSoHoanHao(NODE *root);
int demSoLuongSoChiaHetCho3(NODE *root);
