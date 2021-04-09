#include<iostream>
#ifndef _STRUCT_H
#define _STRUCT_H
#define MAXMH 100
#define MAXLOP 500
#define STACKSIZE 1000

using namespace std;
struct monHoc
{
	string maMH;
	string tenMH;	
};
struct DSMH
{
	int somon = 0;
	monHoc *m[MAXMH] = {NULL};	
};
struct CTdethi
{
	int sct;
	int tg;
	int *bode;
	int *dapan;
};
struct diemThi
{
	string maMH;
	float diem;
	CTdethi ctdt;
};
struct nodediemThi
{
	diemThi info;
	nodediemThi *pNext = NULL;
};
struct dsdiemThi
{
	nodediemThi *First = NULL;
};

struct sinhVien
{
	string maSV;
	string ho;
	string ten;
	string gioiTinh;
	string password;
	dsdiemThi diem;
};
struct nodeSV
{
	sinhVien info;
	nodeSV *pNext = NULL;
};
struct dssv
{
	nodeSV *First = NULL;
};
struct lop
{
	string maLop;
	string tenLop;
	string nienKhoa;
	dssv danhsach;
};
struct dslop
{
	int solop;
	lop *l [MAXLOP] = {NULL};
};
struct cauHoi
{
	string maMH;
	string noiDung;
	string A;
	string B;
	string C;
	string D;
	string dapAn;
};
struct nodecauHoi
{
	int id;
	cauHoi info;
	nodecauHoi *pLeft = NULL;
	nodecauHoi *pRight = NULL;
};
typedef struct nodecauHoi *NODECH;
struct dscauhoi
{
	nodecauHoi *Root = NULL;
};
struct TG 
{
	int gio;
	int phut;
	int giay;
};
#endif
