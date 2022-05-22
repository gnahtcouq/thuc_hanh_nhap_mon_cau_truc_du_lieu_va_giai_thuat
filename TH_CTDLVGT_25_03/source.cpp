#include "Header.h"

void init(NODE*& root) {
	root = NULL;
}

NODE* getNode(int x) {
	NODE* p = new NODE;
	if (p == NULL)
		return NULL;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}

void themNodeVaoCay(NODE*& root, int x) {
	if (root != NULL) {
		if (x > root->data)
			themNodeVaoCay(root->right, x);
		else if (x < root->data)
			themNodeVaoCay(root->left, x);
	}
	else
		root = getNode(x);
}

void NLR(NODE *root) {
	if (root != NULL) {
		cout << root->data << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(NODE *root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->data << " ";
		LNR(root->right);
	}
}

void RNL(NODE *root) {
	if (root != NULL) {
		RNL(root->right);
		cout << root->data << " ";
		RNL(root->left);
	}
}

void LRN(NODE *root) {
	if (root != NULL) {
		LRN(root->left);
		LRN(root->right);
		cout << root->data << " ";
	}
}

void taoCayTuDaySo(NODE *&root, int a[], int n) {
	init(root);
	for (int i = 0; i < n; ++i)
		themNodeVaoCay(root, a[i]);
}

// Cau 1
int tinhTongCacNut(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int sum = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		sum += p->data;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return sum;
}

void tinhTongCacNutLa(NODE *root, int &dem) {
	if (root != NULL) {
		if (root->left == NULL && root->right == NULL) {
			dem += root->data;
			//cout << root->data << " ";
		}
		tinhTongCacNutLa(root->left, dem);
		tinhTongCacNutLa(root->right, dem);
	}
}

int demSoLuongNutCuaCay(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();

		dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}

int tinhChieuCaoCuaCay(NODE *root) {
	if (root == NULL)
		return 0;
	int left = tinhChieuCaoCuaCay(root->left);
	int right = tinhChieuCaoCuaCay(root->right);

	return left > right ? left + 1 : right + 1;
}

// Cau 2
int demSoLuongNutChan(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 2 == 0)
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}

int demSoLuongNutLe(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 2 != 0)
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}

int tinhTongCacNutChan(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int sum = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 2 == 0)
			sum += p->data;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return sum;
}

int tinhTongCacNutLe(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int sum = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 2 != 0)
			sum += p->data;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return sum;
}

void lietKeCacNutChan(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int sum = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 2 == 0)
			cout << p->data << " ";
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
}

long long tinhTichCacNutChan(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	long long tich = 1;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 2 == 0)
			tich *= p->data;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return tich;
}

int kiemtraSNT(int n) {
	if (n < 2)
		return 0;
	else if (n > 2) {
		if (n % 2 == 0)
			return 0;
		for (int i = 3; i <= (int)sqrt((double)n); i += 2) {
			if (n % i == 0)
				return 0; // Khong thoa
		}
	}
	return 1; // Thoa
}

int demSoLuongSoNguyenTo(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (kiemtraSNT(p->data) == 1)
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}


int kiemTraHoanThien(int x) {
	int tong = 0;
	for (int i = 1; i <= x / 2; i++) {
		if (x % i == 0)
			tong += i;
	}
	return tong == x;
}

int demSoLuongSoHoanHao(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (kiemTraHoanThien(p->data) == 1)
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}

int demSoLuongSoChiaHetCho3(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (p->data % 3 == 0)
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}

int demSoLuongSoChinhPhuong(NODE *root) {
	queue<NODE *> q;
	if (root != NULL)
		q.push(root);

	int dem = 0;
	while (!q.empty()) {
		NODE *p = q.front();
		if (sqrt(p->data) == (int)sqrt(p->data))
			dem++;
		q.pop();
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
	return dem;
}
