#include "header.h"

int maTran[MAX][MAX];
int D[MAX][MAX];
int P[MAX][MAX];
int soNut;

void init() {
	int i, j;
	FILE* f;
	fopen_s(&f, "Floyd.txt", "wt");
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
	fopen_s(&f, "Floyd.txt", "rt");
	if (f == NULL) return;
	fscanf(f, "%d", &soNut);
	for (int i = 0; i < soNut; i++)
		for (int j = 0; j < soNut; j++)
			fscanf_s(f, "%d", &maTran[i][j]);
	fclose(f);
}

void ghiMaTran() {
	FILE* f;
	fopen_s(&f, "Floyd.txt", "wt");
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

void taoCung(int node1, int node2, int ts) {
	if (node1 != node2)
		maTran[node1][node2] = ts;
}

void xoaCung(int node1, int node2) {
	maTran[node1][node2] = VOCUNG;
}

int bacDinhRa(int dinh) {
	int dem = 0;
	for (int i = 0; i < soNut; i++)
		if (maTran[dinh][i] > 0)
			dem++;
	return dem;
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

void hienThiMaTranKeCuaDoThi() {
	cout << "\nMa tran ke cua do thi: " << endl;
	for (int i = 0; i < soNut; i++) {
		for (int j = 0; j < soNut; j++)
			cout << maTran[i][j] << "\t";
		cout << "\n";
	}
}