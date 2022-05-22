#include "Header.h"

int main() {
	int a[] = { 44, 18, 13, 15, 37, 23, 40, 56, 59, 88, 108, 71, 1, 4, 6, 19, 25, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << " 44, 18, 13, 15, 37, 23, 40, 56, 59, 88, 108, 71 " << endl;
	NODE *root;
	taoCayTuDaySo(root, a, n);

	cout << "\nNLR: ";
	NLR(root);

	//cout << "\nLNR: ";
	//LNR(root);
	//cout << "\nRNL: ";
	//RNL(root);

	cout << "\nLRN: ";
	LRN(root);

	// Cau 1
	cout << "\nTong cac nut = " << tinhTongCacNut(root);

	int soLuongCacNutLa = 0;
	tinhTongCacNutLa(root, soLuongCacNutLa);
	cout << "\nTong cac nut la = " << soLuongCacNutLa;

	cout << "\nSo luong cac nut cua cay = " << demSoLuongNutCuaCay(root);

	int chieuCao = tinhChieuCaoCuaCay(root);
	cout << "\nCay co chieu cao = " << chieuCao;

	// Cau 2
	cout << "\nSo luong cac nut chan = " << demSoLuongNutChan(root);
	cout << "\nSo luong cac nut le = " << demSoLuongNutLe(root);
	cout << "\nTong cac nut chan = " << tinhTongCacNutChan(root);
	cout << "\nTong cac nut le = " << tinhTongCacNutLe(root);
	cout << "\nLiet ke cac nut chan: ";
	lietKeCacNutChan(root);
	cout << "\nTich cac nut chan = " << tinhTichCacNutChan(root);

	// Cau 3
	cout << "\nSo luong so chinh phuong = " << demSoLuongSoChinhPhuong(root);
	cout << "\nSo luong so nguyen to = " << demSoLuongSoNguyenTo(root);
	cout << "\nSo luong so hoan hao = " << demSoLuongSoHoanHao(root);
	cout << "\nSo luong so chia het cho 3 = " << demSoLuongSoChiaHetCho3(root);

	system("pause");
	return 0;
}
