#pragma warning(disable: 4996)
#include <iostream>
#include <stdio.h>
using namespace std;

#define VOCUNG 30000
#define TRUE 1
#define FALSE 0
#define MAX 50
void init();
void docMaTran();
void ghiMaTran();
void xemMaTran();
void taoCung(int node1, int node2, int ts);
void xoaCung(int node1, int node2);
int bacDinhRa(int dinh);
void floyd();
void inLoTrinh(int x, int y);
void hienThiMaTranKeCuaDoThi();