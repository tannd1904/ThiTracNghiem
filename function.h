#ifndef _FUNCTION_H
#define _FUNCTION_H
#include<iostream>
#include<string.h>
#include<fstream>
#include<time.h>
#include <thread>
#include <sstream>
using namespace std;
// ==================== MAIN PROCESS ==========================
int DangNhap(dslop &dsl ,string &masv);
int mainMenu();
void mainProcess(dslop &dsl, dssv &ds, DSMH &dsm, NODECH &dsch, int arr1[], int arr2[]);

// ==================== Function Lop  ==========================
void FunctionLop(dslop &dsl);

void ThemLop(dslop &dsl, int page);
void NhapLop(dslop &dsl, int page);

void XoaLop (dslop &dsl, int &page);
void NhapLopXoa(dslop &dsl,int &page);

void ChinhLop(dslop &dsl, int &page);
void NhapLopChinh(dslop &dsl , int &page);
void SuaLop(lop *&l);

// ==================== Function SV  ==========================
void FunctionSV(dslop &dsl);

void selectFunctionSV(lop *&l ,int page);

void NhapSinhVien(lop *&l );
void Them1SinhVien(lop *l, sinhVien sv);

void XoaSinhVien(lop *&l ,int page);
void DeleteInfo_SV(dssv &ds , string maSV);

// ==================== Function MH ==========================
void FunctionMon(DSMH &dsm, dslop dsl, NODECH &dsch);

void ThemMonHoc(DSMH &dsm, int page);
void NhapMonHoc(DSMH &dsm, int page);

void XoaMonHoc (DSMH &dsm, dslop dsl, NODECH &dsch);
void NhapMonXoa(DSMH &dsm,int &page, dslop dsl,NODECH &dsch);

void ChinhMon(DSMH &dsm, int &page, NODECH dsch,dslop dsl );
void NhapMonChinh(DSMH &dsm , int &page, NODECH &dsch, dslop dsl);
void SuaMon(monHoc *&m);

// ==================== Function CH  ==========================
void FunctionCH(NODECH &dsch, DSMH dsm,dslop dsl,int &idlonnhat, int arr1[], int arr2[]);

void ThemCH(NODECH &dsch, DSMH dsm, int *arr[], int arr1[], int arr2[]);
void NhapCHThem(NODECH &dsch,monHoc *mh, int *arr[], int arr1[], int arr2[]);
void Them1CauHoi(NODECH &tree, cauHoi ch, int maxid , int arr1[], int arr2[]);

void XoaCauHoi (NODECH &dsch, int *arr[], int &idlonnhat,dslop dsl);
void NhapCHXoa(NODECH &dsch,int &page, int *arr[], int&idlonnhat,dslop dsl);
void remove (int x , NODECH &p );

void XemCauHoi (NODECH &dsch, int *arr[], int &idlonnhat);
void XemCH(NODECH &dsch,int &page, int *arr[], int&idlonnhat);

void XemCHtheoMon (DSMH dsm, NODECH dsch);
// ==================== Function DIEM  ==========================
void FunctionDiem(dslop dsl, dssv ds,DSMH dsm, NODECH dsch);

void NhapLopXemDiem(dslop dsl , DSMH dsm, NODECH dsch);
void NhapMonXemDiem(lop *l, DSMH dsm, NODECH dsch);
void XemDiem1Lop(lop *l, monHoc *m, NODECH dsch);
void InChiTiet1LanThi(nodediemThi *p, NODECH dsch);

// ==================== Function THI  ==========================
void FunctionThi(NODECH dsch,int tg, int sct, string monthi,string &diem, CTdethi &ctdt);
int *LayDeThi(NODECH dsch, int sct, string mamon);



int maxid = 10000;
bool stop = 1;

// ==================== THOAT  ==========================
bool Exit (char &s, bool &sCheck)
{
	AnConTro();
	gotoxy(130,26);
	vekhungTB(10,36);
	string tb = "Ban co chac chan muon thoat ? (Y/N)";
	InTB(tb,132,30);
	batPhim(s,sCheck);
	while(s != ESC)
	{
		AnConTro();
		if((s == 'y' || s == 'Y')&& sCheck == true)
		{
			XoaTB(130,26);
			return true;
		}
		else if((s == 'n' || s == 'N') && sCheck == true)
		{
			XoaTB(130,26);
			return false;
		}
		batPhim(s,sCheck);
	}
}
// ==================== CHIA STRING  ==========================
int doiso( char n)
{
    return n - '0';
}
char doichar (int n)
{
	return (char)(n+48);
}
string IntToString(int s)
{
	int x;
	string p;
	while(s>=10)
	{
		x = s%10;
		p.insert(0,1,doichar(x));
		s = s/10;
	}
	p.insert(0,1,doichar(s));
	return p;
}
void xoakhongdau (string &s1)
{
	while (s1[0]==48)
	{
		s1.erase(0,1);
	}
}
void xoakhongcuoi (string &s1)
{
	int n = s1.length()-1;
	while (s1[n]==48 && n >= 1)
	{
		s1.erase(n,1);
		n--;
	}
}
void lambangso (string &s1, string &s2)
{
	if (s1.length()>s2.length())
	{
		int x = s1.length () - s2.length();
		s2.insert  (0,x,'0');
	}
	if (s2.length()>s1.length())
	{
		int y = s2.length () - s1.length();
		s1.insert  (0,y,'0');
	}
}
int sosanh1(string &s1,string &s2)
{
	lambangso(s1,s2);
	for (int i = 0; i < s1.length();i++)
	{
		int x = doiso(s1[i]);
		int y = doiso(s2[i]);
		if (x>y)
		{
			xoakhongdau(s1);
			xoakhongdau(s2);
			return 1;
		}
		if (x==y)
		{
			continue;
		}
		if (x<y)
		{
			xoakhongdau(s1);
			xoakhongdau(s2);
			return 2;
		}
	}
	xoakhongdau(s1);
	xoakhongdau(s2);
	return 0;
}
string cong (string s1, string s2)
{
	string s3;
	lambangso(s1,s2);
	int x = 0;
	int temp = 0;
	for (int i =s1.length()-1; i >= 0 ; i--)
	{
		if ((doiso(s1[i]) + doiso(s2[i])) + temp >= 10)
		{
			temp = doiso(s1[i]) + doiso(s2[i]) + temp;
			s3.insert(0,1,doichar(temp%10));
			temp /=10;
		}
		else
		{
			x = doiso(s1[i]) + doiso(s2[i])+temp;
			s3.insert(0,1,doichar(x));
			temp = 0;
		}		
	}
	s3.insert(0,1,doichar(temp));
	return s3;
}
string tru (string s1, string s2)
{
	string s3;
	lambangso(s1,s2);
	int x = 0;
	int temp = 0;
	for (int i =s1.length()-1; i >= 0 ; i--)
	{
		x = doiso(s1[i]) - doiso(s2[i]) - temp;
		if (x>0)
		{
			s3.insert(0,1,doichar(x));
			temp = 0;
		}
		else if (x < 0)
		{
			x = 10 + x;
			s3.insert(0,1,doichar(x));
			temp = 1;
		}
		else if (x == 0)
		{
			s3.insert(0,1,'0');
			temp = 0;
		}
	}
	return s3;
}
string nhan1so (string b, char n)
{
	string s;
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)      
    {
        temp = doiso(n) * doiso(b[i]) + temp;
        s.insert(0,1,doichar(temp%10));
        temp = temp/10;
    }
	s.insert(0,1,doichar(temp));
    return s;
}
string nhan (string s1, string s2)
{
	lambangso(s1,s2);
	string s3;
	string s = "";
	for (int i = s2.length()-1; i >=0; i--)
	{
		s3 = nhan1so(s1,s2[i]);
		s3.insert(s3.length(), s3.length()-i-1, '0'); 
		s = cong(s,s3);
	}
	s.insert(s.length()-1,1,'.');
	return s;
}
void xoadutich(string &tich)
{
	int k = tich.length()-1;
	for (int i = 0; i < 2; i++)
	{
		tich.erase(k,1);
		k--;
	}
}
string chia (string s1, string s2)
{
	string s = "";
	string c = "";
	string kq = "";
	string du = "";
	for (int i = 0; i < s1.length(); i++)
	{
		s.push_back(s1[i]);
		if (sosanh1(s,s2)==1||sosanh1(s,s2)==0 )
		{
			for (int j = 1; j <=9; j++)
			{
				c = nhan1so(s2,doichar(j));
				if (sosanh1(c,s)==1  )
				{
					j--;
					kq.push_back(doichar(j));
					c = nhan1so(s2,doichar(j));
					xoakhongdau(c);
					xoakhongdau(kq);
					string hieu = tru (s,c);
					s = hieu;
					j=1;
					break;
				}
				if (j==9 && sosanh1 (c,s)==2)
				{
					kq.push_back(doichar(j));
					c = nhan1so(s2,doichar(j));
					xoakhongdau(c);
					xoakhongdau(kq);
					string hieu = tru (s,c);
					s = hieu;
					j=1;
					break;
				}
				
			}
		}
		else if(sosanh1(s,s2)==2)
				{
					kq.push_back('0');
				}
	}
	xoakhongdau(kq);
	string tich = nhan(s2,kq);
	xoakhongdau(tich);
	xoadutich(tich);
	du = tru(s1,tich);
	if (sosanh1(s1,s2)==2)
	{
		kq = "0";
		du = s1;
	}
	string kq2 = "";
	int t = kq2.length()-1;
	string p = "";
		for(int u = 0; u < 5; u++)
		{
			du.push_back('0');
			
			if (sosanh1(du,s2)==1 || sosanh1(du,s2)==0)
			{
				for(int k = 1; k <=9;k++)
				{
					p = nhan1so(s2,doichar(k));
					if (sosanh1(p,du)==1)
					{
						k--;
						kq2.push_back(doichar(k));
						p = nhan1so(s2,doichar(k));
						xoakhongdau(p);
						string hieu2 = tru (du,p);
						du = hieu2;
						k=1;
						break;
					}
					else if (k==9 && sosanh1 (p,du)==2)
					{
						kq2.push_back(doichar(k));
						p = nhan1so(s2,doichar(k));
						xoakhongdau(p);
						string hieu2 = tru (du,p);
						du = hieu2;
						k=1;
						break;
					}
				}
			}
			else if(sosanh1(du,s2)==2)
					{
						kq2.push_back('0');
					}	
		}
	xoakhongcuoi(kq2);
	int y = kq.length();
	while(kq2.length() > 3)
	{
		kq2.erase(kq2.length()-2,kq2.length()-1);		
	}
	int r = kq2.length();
	if (doiso(kq2[r-1])>5 && r >2)
	{
		int e = doiso(kq2[r-2]);
		e++;
		kq2.erase(r-2,2);
		kq2.push_back(doichar(e));
	}
	else if(doiso(kq2[r-1])<=5 && r > 2)
	{
		kq2.erase(r-1,1);
	}
	kq.insert(y,1,'.');
	y++;
	kq.insert(y,kq2);
	return kq;
}
void Initialize(NODECH &root)
{
	root = NULL;
}
NODECH New_Node(void)
{
	NODECH p;
	p = new nodecauHoi;
	return p;
}
// ==================== DEM SO SV  ==========================
int DemSV(dssv ds)
{
	int dem = 0;
	
	for (nodeSV *k = ds.First; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
// ==================== XOA CAU HOI TRUONG HOP 3 ==========================
void remove_case_3 ( NODECH &r , NODECH &rp )
{
	if (r->pLeft != NULL)
	{
		remove_case_3 (r->pLeft,rp);	
	}
	//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
	{
		rp->id = r->id; //Chep noi dung cua r sang rp ";
		rp->info = r->info; // de lat nua free(rp)
		rp = r;
		r = rp->pRight;
	}
}
// ==================== XOA 1 CAU HOI ==========================
void remove (int x , NODECH &p )
{
	NODECH rp;
	if (p == NULL)
	{
		cout <<  "Khong tim thay";
	} 
	else
	{
		if (x < p->id)
		{
			remove (x, p->pLeft);
		} 
		else
		{
			if (x > p->id)
			{
				remove (x, p->pRight);
			}
			else // p->key = x
			{
				rp = p;
				if (rp->pRight == NULL) 
				{
					p = rp->pLeft;	
				}
				// p là nút lá hoac la nut chi co cay con ben trai
				else 
				{
					if (rp->pLeft == NULL)
					{
						p = rp->pRight; // p là nut co cay con ben phai
					}
					else
					{
						remove_case_3 (rp->pRight,rp);
					}
				}
				delete rp;
			}	
		}
	}
	
}
// ==================== TIM KIEM SINH VIEN ==========================
nodeSV* search_SV(dssv &ds, string maSV)
{
	nodeSV *p;
	p = ds.First;
	while(p != NULL && p->info.maSV.compare(maSV) != 0 )
	{
		p = p->pNext;
	}
	return p;
}
// ==================== TIM KIEM LOP ==========================
lop* Search_Lop(dslop dsl, string maLop)
{
	for(int i = 0; i < dsl.solop ; i++)
	{
		if(dsl.l[i]->maLop.compare(maLop) == 0)
		{
			return dsl.l[i];
		}
	}
}
// ==================== TIM KIEM MON HOC ==========================
monHoc* Search_Mon(DSMH dsm, string maMH)
{
	for(int i = 0; i < dsm.somon ; i++)
	{
		if(dsm.m[i]->maMH.compare(maMH) == 0)
		{
			return dsm.m[i];
		}
	}
}
// ==================== TIM KIEM CAU HOI ==========================
NODECH Search_CH(NODECH p, int id)
{
	while (p != NULL && p->id != id)
	if(id < p->id)
	p = p->pLeft;
	else
	p = p->pRight;
	return p;
}

// ==================== TACH MA SINH VIEN ==========================
int TachMSSV (string maSV) 
{
	maSV.erase(0,maSV.length()-3);
	return StringToInt(maSV);
}
// ==================== TACH HO SINH VIEN ==========================
string TachHoSV(string hoten)
{
	string ho;
	for(int i = 0; i < hoten.length(); i ++)
	{
		if(hoten[i] == 32)
		{
			return ho;
		}
		ho += hoten[i];
	}
}
// ==================== TACH TEN SINH VIEN ==========================
string TachTenSV(string hoten)
{
	string ten ;
	for(int i = 0; i < hoten.length(); i ++)
	{
		if (hoten[i] == ' ')
		{
			for(int j = i + 1;j < hoten.length();j++)
			{
				ten += hoten[j];
			}
			return ten;
		}
	}
}
// ==================== SO SANH MA SINH VIEN ==========================
int SoSanhMaSo (sinhVien sv1, sinhVien sv2)
{
	if(TachMSSV(sv1.maSV) < TachMSSV(sv2.maSV) ) 
	{
		return -1;
	}
	if (TachMSSV(sv1.maSV) > TachMSSV(sv2.maSV)) 
	{
		return 1;
	}
	if (TachMSSV(sv1.maSV) == TachMSSV(sv2.maSV)) 
	{
		return 0;
	}
}
// ==================== THEM DIEM VAO SAU ==========================
void Insert_After_Diem(nodeSV *sv, nodediemThi *diem)
{	
	if(sv->info.diem.First == NULL)
	{
		nodediemThi *p;
		p = new nodediemThi;
		p->info = diem->info;
		p->pNext = sv->info.diem.First;
		sv->info.diem.First = p;
	}
	else
	{
		nodediemThi *k;
		for(k = sv->info.diem.First; k->pNext != NULL; k = k->pNext);
		k->pNext = diem;
		diem->pNext = NULL;
	}
}
// ==================== THEM SINH VIEN VAO DAU DS ==========================
void Insert_SV_First(nodeSV *&First, sinhVien sv)
{
	nodeSV *p;
	p = new nodeSV;
	p->info = sv;
	p->pNext = First;
	First = p;

}
// ==================== THEM SINH VIEN VAO SAU ==========================
void Insert_after_SV(nodeSV *p, sinhVien sv)
{
	nodeSV *q;
	if(p == NULL)
	{
		string tb = "Khong them sinh vien vao danh sach duoc";
		InTB(tb,132,30);
		AnConTro();
		Sleep(650);
		XoaTB(130,26);
	}
	else
	{ 
		nodeSV *q = new nodeSV;
		q->info = sv;
		q->pNext = p->pNext;
		p->pNext = q;
	}
}
// ==================== SO SANH MA MH ==========================
int SoSanhMaMH(string mA, string mB)
{
	int x = mA.length();
	int y = mB.length();
	int z;
	if(x < y)
	{
		z = x;
	}
	else z = y;
	for(int i = 0; i < z; i++)
	{
		if(mA[i] < mB[i])
		{
			return 1;
		}
		else if(mA[i] >  mB[i])
		{
			return -1;
		}
		//else continue;
	}
	return 0;
}
// ==================== THEM MON THEO THU TU ==========================
void InsertMon(DSMH &dsm, monHoc mh)
{
	if(dsm.m[0] == NULL)
	{
		dsm.m[dsm.somon] = new monHoc;
		*dsm.m[dsm.somon] = mh;
		dsm.somon++;
	}
	else
	{
		int j;
		for(j = dsm.somon-1; j >=0 ; j--)
		{
			if(SoSanhMaMH(mh.maMH,dsm.m[j]->maMH) == -1)
			{
				break;
			}
		}
		dsm.m[dsm.somon] = new monHoc;
		dsm.somon ++;
		if(j == dsm.somon - 2)
		{
			*dsm.m[j+1] = mh;
		}
		else
		{
			
			for(int i = dsm.somon-1; i > j+1; i--)
			{
				*dsm.m[i] = *dsm.m[i-1];
			}
			*dsm.m[j+1] = mh;
		}
	}
}
// ==================== THEM SINH VIEN ==========================
void Them1SinhVien(lop *l, sinhVien sv)
{ 
	nodeSV *t,*s;
	if(l->danhsach.First == NULL)
	{
		Insert_SV_First(l->danhsach.First,sv);
	}
//	else if (l->danhsach.First->pNext == NULL)
//	{
//		if(SoSanhMaSo(l->danhsach.First->info,sv) < 0 )
//		{
//			
//			Insert_after_SV(l->danhsach.First,sv);
//		}
//		else if (SoSanhMaSo(l->danhsach.First->info,sv) > 0)
//		{
//			Insert_SV_First(l->danhsach.First,sv);
//		}
////		else 
////		{
////			return;
////		}
//	}
	else 
	{
		if(SoSanhMaSo(l->danhsach.First->info,sv) > 0)
		{
			Insert_SV_First(l->danhsach.First,sv);
		}
		else
		{
			for(s = l->danhsach.First; s != NULL && SoSanhMaSo(s->info,sv) < 0 ; t=s, s = s->pNext) ;
			Insert_after_SV(t,sv);	
		}
	}
	
}
// ==================== XOA SINH VIEN DAU ==========================
void DeleteFirst_SV(dssv &ds)
{
	nodeSV *s;
	if(ds.First== NULL)
	{
		return;
	}
	s = ds.First;
	ds.First = s->pNext;
	delete s;
		
	
}
// ==================== XOA SINH VIEN SAU ==========================
void DeleteAfter_SV(nodeSV *s)
{
	nodeSV *svS;
	if (s == NULL || s->pNext == NULL)
	{
		return;
	}
	svS = s->pNext;
	s->pNext = svS->pNext;
	delete svS;
	
}
// ==================== XOA SINH THEO INFO ==========================
void DeleteInfo_SV(dssv &ds , string maSV)
{
	nodeSV *s;
	nodeSV *svS;
	s = search_SV(ds,maSV);
	if ( s == NULL)
	{
		return;
	}
	if (s == ds.First)
	{
		DeleteFirst_SV(ds);
	}
	else 
	{
		svS = ds.First;
		while(svS->pNext != s)
		{
			svS = svS->pNext;
		}
		DeleteAfter_SV(svS);
	}
}
// ==================== THEM DIEM THI VAO DAU DS ==========================
void Insert_Diem_First(nodediemThi *&First, diemThi diem)
{
	nodediemThi *p;
	p = new nodediemThi;
	p->info = diem;
	p->pNext = First;
	First = p;

}
// ==================== THEM DIEM THI VAO SAU ==========================
void Insert_Diem_after(nodediemThi *p , diemThi diem)
{
	nodeSV *q;
	if(p == NULL)
	cout <<"khong them sinh vien vao danh sach duoc";
	else
	{ 
		nodediemThi *q = new nodediemThi;
		q->info = diem;
		q->pNext = p->pNext;
		p->pNext = q; 
	}
}

// ==================== KIEM TRA DIEM THI ==========================
void checkdiemThi(dsdiemThi &dsm, string x)
{
	int s = x.find(':');
	string p = x.substr(s,1);
	string maMh = x.substr(0,s);
	diemThi d;
	d.maMH = maMh;
	d.diem = StringToInt(p);
	Insert_Diem_after(dsm.First,d);
}
// ==================== KIEM TRA SL THI ==========================
bool CheckSLThi (dsdiemThi dsd, string mamon)
{
	for(nodediemThi *k = dsd.First; k != NULL; k = k->pNext)
	{
		if(k->info.maMH.compare(mamon) == 0)
		{
			return true;
		}
	}
	return false;
}
// ==================== DOC FILE DIEM 1 LOP ==========================
void DocFileDiem1Lop ( lop *l)
{
	ifstream fileIn;
	fileIn.open("DIEM_"+l->maLop+".txt", ios_base :: in);
	if(fileIn.fail())
	{
		cout << "Nopezz";
		return;	
	} 
	string masv;
	string x;
	int slt;
	nodediemThi *diem = new nodediemThi;
	while(!fileIn.eof())
	{
		getline(fileIn,masv,'\n');
		getline(fileIn,x,'\n');
		slt = StringToInt(x);
		if(slt == 0)
		{
			fileIn.ignore();
		}
		else
		{
			string temp;
			for(int i = 0; i < slt; i++)
			{
				getline(fileIn,temp,':');
				diem->info.maMH = temp;
				getline(fileIn,temp,':');
				diem->info.diem = StringToFloat(temp);
				getline(fileIn,temp,':');
				diem->info.ctdt.sct = StringToInt(temp);
				diem->info.ctdt.bode = new int [diem->info.ctdt.sct];
				diem->info.ctdt.dapan = new int [diem->info.ctdt.sct];
				for(int i = 0 ; i < diem->info.ctdt.sct; i++)
				{
					getline(fileIn,temp,'@');
					diem->info.ctdt.bode[i] = StringToInt(temp);
				}
				for(int i = 0 ; i < diem->info.ctdt.sct; i++)
				{
					getline(fileIn,temp,'#');
					diem->info.ctdt.dapan[i] = StringToInt(temp);
					if(i == diem->info.ctdt.sct -1)
					{
						fileIn.ignore();
					}
				}
				//fileIn.ignore();
				diemThi diemsv;
				diemsv = diem->info;
				if (search_SV(l->danhsach,masv)->info.diem.First == NULL) 
				{
					Insert_Diem_First(search_SV(l->danhsach,masv)->info.diem.First,diemsv);
				}
				else 
				{
					nodediemThi *p = search_SV(l->danhsach,masv)->info.diem.First;
					while (p->pNext != NULL)
					{
						p = p->pNext;
					}
					Insert_Diem_after(p,diemsv);
				}
				//Insert_After_Diem(search_SV(l->danhsach,masv),diem);
				
//				delete diem->info.ctdt.bode;
//				delete diem->info.ctdt.dapan;
			}	
		}
	}
//	while(!fileIn.eof())
//	{
//		dsdiemThi dsd;
//		string x;
//		int y=0;
//		string z;
//		getline(fileIn,x,'\n');
//		fileIn >> y;
//		string *p = new string [y];
//		if (y == 0)
//		{
//			continue;
//		}
//		
//		else
//		{
//			for(int i = 0 ; i < y; i++)
//			{
//				if (i = y-1)
//				{
//					getline(fileIn,p[i],'\n');
//					checkdiemThi(dsd,p[i]);
//					break;
//				}
//				getline(fileIn,p[i],',');
//				checkdiemThi(dsd,p[i]);
//			}	
//		}
//		for(int j = 0; j < dsl.solop ; j++)
//		{
//			nodeSV *k;
//			k = search_SV(dsl.l[j]->danhsach,x);
//			k->info.diem = dsd;
//		}
//	}
}
//bool is_empty(std::ifstream& pFile)
//{
//    return pFile.peek() == std::ifstream::traits_type::eof();
//}
// ==================== DOC FILE 1 LOP ==========================
void DocFileLop (lop *&l, string filename )
{
	ifstream fileIn;
	fileIn.open(filename.c_str(),ios_base :: in );
	if(fileIn.fail()) cout << "Nope2";
	sinhVien sv ;
	while(!fileIn.eof())
	{	
		if(fileIn.peek() == std::ifstream::traits_type::eof()) break;
		getline(fileIn,sv.maSV,'\n');
		getline(fileIn,sv.ho,' ');
		getline(fileIn,sv.ten,'\n');
		getline(fileIn,sv.gioiTinh,'\n');
		getline(fileIn,sv.password,'\n');
		InHoaChuoi(sv.maSV);
		InHoaChuoi(sv.ho);
		InHoaChuoi(sv.ten);
		if(StringToInt(sv.gioiTinh) == 1)
		{
			sv.gioiTinh = "NAM";
		}
		else if(StringToInt(sv.gioiTinh) == 0)
		{
			sv.gioiTinh = "NU";
		}
		Them1SinhVien(l,sv);
	}
	fileIn.close();
}
// ==================== DOC DANH SACH LOP TU FILE ==========================
void DocFileDSLop (dslop &dsl)
{
	ifstream fileIn;
	fileIn.open("DSLOP.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Nope";
	fileIn >> dsl.solop;
	fileIn.ignore();
	for(int i = 0; i < dsl.solop; i++)
	{
		dsl.l[i] = new lop;
		getline(fileIn,dsl.l[i]->tenLop,'\n');
		getline(fileIn,dsl.l[i]->maLop,'\n');
		dsl.l[i]->nienKhoa = dsl.l[i]->maLop.substr(1,2);
		DocFileLop(dsl.l[i],dsl.l[i]->maLop+".txt");
		DocFileDiem1Lop(dsl.l[i]);
	}
	fileIn.close();
}
// ==================== DOC DANH SACH MON HOC TU FILE ==========================
void DocFileDSMH (DSMH &dsm)
{
	ifstream fileIn;
	fileIn.open("DSMONHOC.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Nope";
	monHoc mh;
	while(!fileIn.eof())
	{
		getline(fileIn,mh.maMH,'\n');
		getline(fileIn,mh.tenMH,'\n');
		InsertMon(dsm,mh);
	}
	fileIn.close();
}
// ==================== IN DS MON HOC ==========================
void InDSMon (DSMH dsm, int &page)
{
	if (dsm.somon == 0)
	{
		return;
	}
	int k = 2;
	int maxpage;
	if (dsm.somon % 10 == 0)
	{
		maxpage = dsm.somon/10;
	}
	else maxpage = dsm.somon/10 +1;
	for(int i = page*10; i < (page+1)*10; i++)
	{
		if(dsm.m[i] == NULL)
		{
			break;
		}
		gotoxy(30,4+k);
		cout << dsm.m[i]->maMH;
		gotoxy(65+((60 - dsm.m[i]->tenMH.length()) / 2),4+k);
		cout << dsm.m[i]->tenMH;
		k += 3;
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage;
	
}
// ==================== IN DS LOP ==========================
void InDSLop (dslop dsl, int &page)
{
	if (dsl.solop == 0)
	{
		return;
	}
	int k = 2;
	int maxpage;
	if (dsl.solop % 10 == 0)
	{
		maxpage = dsl.solop/10;
	}
	else maxpage = dsl.solop/10 +1;
	for(int i = page*10; i < (page+1)*10; i++)
	{
		if(dsl.l[i] == NULL)
		{
			break;
		}
		gotoxy(5+6,4+k);
		cout << dsl.l[i]->tenLop;
		gotoxy(5+6+50,4+k);
		cout << dsl.l[i]->maLop;
		gotoxy(5+6+50+40,4+k);
		int x = StringToInt(dsl.l[i]->nienKhoa);
		cout <<  2000 + x << "-" << 2000 + x + 5;
		k += 3;
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage;
	
}

// ==================== KIEM TRA MA LOP & TEN LOP TRONG DS ==========================
bool CheckLopNhap (dslop dsl, string malop, string tenlop)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(malop.compare(dsl.l[i]->maLop) == 0 || tenlop.compare(dsl.l[i]->tenLop) == 0)
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA MON & TEN MON TRONG DS ==========================
bool CheckMonNhap (DSMH dsm, string mamon, string tenmon)
{
	for(int i = 0; i < dsm.somon; i++)
	{
		if(mamon.compare(dsm.m[i]->maMH) == 0 || tenmon.compare(dsm.m[i]->tenMH) == 0)
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA TEN LOP TRONG DS  ==========================
bool CheckTenLop (dslop dsl, string tenlop)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(tenlop.compare(dsl.l[i]->tenLop) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA LOP TRONG DS  ==========================
bool CheckMaLop (dslop dsl, string malop)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(malop.compare(dsl.l[i]->maLop) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA LOP TRONG DS  ==========================
bool CheckMaSV (lop *l, string masv)
{
	for(nodeSV *k = l->danhsach.First; k != NULL; k = k->pNext)
	{
		if(masv.compare(k->info.maSV) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA NIEN KHOA  ==========================
bool CheckNK (dslop dsl, string nk)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		if(nk.compare(dsl.l[i]->nienKhoa) == 0 )
		{
			return false;
		}
	}
	return true;
}
// ==================== KIEM TRA MA LOP  ==========================
bool CheckFormMaLop (string malop)
{
	if (malop.length() != 9 || malop[0] != 'D')
	{
		return false;
	}
	if (malop[1] < '0' || malop[1] > '9' || malop[2] < '0' || malop[2] > '9')				//1,2,7,8,9
	{
		return false;
	}
	for(int i = 7; i < 9; i++)
	{
		if(malop[i] < '0' || malop[i] > '9')
		{
			return false;
		}
	}
	for(int i = 3; i < 7; i++)
	{
		if(malop[i] < 'A' || malop[i] > 'Z')
		{
			return false;
		}
	}	
	return true;
}
// ==================== CHUAN HOA TEN  ==========================
void ChuanHoaTen (string &text)
{
	if(text[0] == 32)
	{
		text.erase(0,1);
		ChuanHoaTen(text);
	}
	if(text[text.length()-1] == 32)
	{
		text.erase(text.length()-1,1);
		ChuanHoaTen(text);
	}
} 
// ==================== KTRA NHAP MA SV ==========================
bool CheckFormMaSv (string masv)
{
	if (masv.length() != 10 || masv[0] != 'N')
	{
		return false;
	}
	if (masv[1] < '0' || masv[1] > '9' || masv[2] < '0' || masv[2] > '9')				//1,2,7,8,9
	{
		return false;
	}
	for(int i = 7; i < 10; i++)
	{
		if(masv[i] < '0' || masv[i] > '9')
		{
			return false;
		}
	}
	for(int i = 3; i < 7; i++)
	{
		if(masv[i] < 'A' || masv[i] > 'Z')
		{
			return false;
		}
	}	
	
	return true;
}

// ==================== KIEM TRA NHAP DU HO TEN  ==========================
bool CheckFormTen (string text)
{
	for(int i = 0; i < text.length();i++)
	{
		if(text[i] == ' ')
		{
			return true;
		}
	}
	return false;
}
// ==================== DEM SO LAN THI  ==========================
int DemLanThi(dsdiemThi diem)
{
	int dem = 0;
	for (nodediemThi *k = diem.First; k != NULL; k = k->pNext)
	{
		dem++;
	}
	return dem;
}
// ==================== NHAP LOP THEM ==========================
void NhapLop(dslop &dsl, int page)
{	
	gotoxy(5,40);
	veKhung(5,120);
	gotoxy(7,42);
	cout << "Ma lop :";
	gotoxy(15,41);
	veKhung(3,30);
	gotoxy(80,42);
	cout << "Ten lop :";
	gotoxy(88,41);
	veKhung(3,35);
	int maxpage;
	string tenlop;
	string malop;
	char s;
	bool state = true;
	bool sCheck;
	string tb;
	int hd;
	int td;
	gotoxy(17,42);
	HienConTro();
	batPhim(s,sCheck);
	while (1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				if(state == true)
				{
					gotoxy(17+malop.length(),42);
				}
				else
				{
					gotoxy(90+tenlop.length(),42);	
				}
				HienConTro();
				batPhim(s,sCheck);
				
			}
		}
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+malop.length(),42);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenlop.length(),42);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')  ) && sCheck == true)
		{
			HienConTro();
			if (state == false )
			{
				if (tenlop.length() < 30)
				{
					cout << InHoa(s);
					tenlop += InHoa(s);
				}
			}
			else 
			{
				if (malop.length() < 20)
				{
					cout << InHoa(s);
					malop += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenlop.length() == 0)
					{
						gotoxy(90+tenlop.length(),42);
					}
					else if(tenlop[tenlop.length()-1]!= ' ')
					{
						cout << InHoa(s);
						tenlop += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenlop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					tenlop.erase(tenlop.length()-1);
				}
			}
			else
			{
				if (malop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					malop.erase(malop.length()-1);
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
				page ++;
				InDSLop(dsl,page);
				
			}
			if(state == true)
			{
				gotoxy(17+malop.length(),42);
			}
			else
			{
				gotoxy(90+tenlop.length(),42);	
			}
			HienConTro();
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 29;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				page--;
				InDSLop(dsl,page);
			}
			if(state == true)
			{
				gotoxy(17+malop.length(),42);
			}
			else
			{
				gotoxy(90+tenlop.length(),42);	
			}
			HienConTro();
		}
		if (s == ENTER)
		{
			AnConTro();
			ChuanHoaTen(tenlop);
			if(tenlop.length() == 0 || malop.length() == 0)
			{
				tb = "Ban chua nhap ten lop hoac ma lop, vui long dien day du thong tin";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(17+malop.length(),42);
			}
			else
			{
				if(CheckFormMaLop(malop) == false)
				{
					XoaTB(130,26);
					tb = "Ban nhap sai dinh dang ma lop, vui long nhap lai";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(17+malop.length(),42);
				}
				else
				{
					if(CheckLopNhap(dsl,malop,tenlop) == false)
					{
						XoaTB(130,26);
						tb = "Ma lop hoac ten lop da bi trung, vui long nhap lai";
						InTB(tb,132,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						gotoxy(17+malop.length(),42);
					}
					else
					{
						int n = dsl.solop;
						dsl.l[n] = new lop;
						dsl.l[n]->maLop = malop;
						dsl.l[n]->tenLop = tenlop;
						dsl.l[n]->nienKhoa = dsl.l[n]->maLop.substr(1,2);
						dsl.solop++; 
						AnConTro();
						XoaTB(130,26);
						gotoxy(132,30);
						tb = "Them lop vao danh sach thanh cong";
						InTB(tb,132,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						HienConTro();
					}
				}
			}
			for(int i = 0; i < 29;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(46,6+i);
				cout << "                                      ";
				gotoxy(86,6+i);
				cout << "                                      ";
			}
			InDSLop(dsl,page);
			malop = "";
			tenlop = "";
			gotoxy(17,42);
			cout << "                           ";
			gotoxy(90,42);
			cout << "                           ";
			gotoxy(17+malop.length(),42);
			HienConTro();
			state = true;
		}
		batPhim(s,sCheck);
	}
	AnConTro();
	for(int i = 0; i < 5; i++)
	{
		gotoxy(5,40+i);
		cout << "                                                                                                                        ";
	}
}
// ==================== THEM LOP ==========================
void ThemLop(dslop &dsl, int page)
{
	ChangeColor(15);
	int n = dsl.solop;
	if(n  == MAXLOP)
	{
		gotoxy(130,26);
		string tb = "Khong the them lop, danh sach lop da day";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLop(dsl,page);
	}
}
// ==================== IN DS LOP THEO NIEN KHOA ==========================
void InDSLopNK (dslop dsl, int page, string nk)
{
	if (dsl.solop == 0)
	{
		return;
	}
	int k = 2;
	for(int i = page*10; i < (page+1)*10; i++)
	{
		if(dsl.l[i] == NULL)
		{
			break;
		}
		else if (dsl.l[i]->nienKhoa.compare(nk) == 0)
		{
			gotoxy(5+6,4+k);
			cout << dsl.l[i]->tenLop;
			gotoxy(5+6+50,4+k);
			cout << dsl.l[i]->maLop;
			gotoxy(5+6+50+40,4+k);
			int x = StringToInt(dsl.l[i]->nienKhoa);
			cout << 2000+x << "-" << 2000+x+5;
			k += 2;		
		}
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1;
}
// ==================== NHAP NIEN KHOA ==========================
void NhapNK(dslop &dsl)
{
	system("cls");
	gotoxy(130,26);
	vekhungTB(10,36);
	gotoxy(5,2);
	ChangeColor(15);
	vekhungDS(34,120,3);
	gotoxy(22,3);
	cout << "TEN LOP";
	gotoxy(63,3);
	cout << "MA LOP";
	gotoxy(101,3);
	cout << "NIEN KHOA";
	gotoxy(45+1,33+6);
	veKhung(5,33);
	gotoxy(45+3,33+8);
	cout << "Nhap nien khoa:";
	gotoxy(45+18,33+7);
	veKhung(3,5);
	gotoxy(45+18+6,33+8);
	cout << "-";
	gotoxy(45+18+6+2,33+7);
	veKhung(3,5);
	string nk;
	int page = 0;
	char s;
	bool sCheck;
	gotoxy(45+19,33+8);
	HienConTro();
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if ( (s >= '0' && s <= '9') && sCheck == true)
		{
			HienConTro();
			if (nk.length() < 2)
			{
				cout << s;
				nk += s;
			}
			AnConTro();
			int x = StringToInt(nk) + 5;
			gotoxy(45+18+6+3,33+8);
			cout << x;
			gotoxy(45+19+nk.length(),33+8);
			HienConTro();		
		}
		if (s == BACKSPACE)
		{
			if (nk.length() > 0)
			{
				AnConTro();
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(wherex()-1,wherey());
				HienConTro();
				nk.erase(nk.length()-1);
			}
		}
		if (s == ENTER)
		{
			dslop tam;
			tam.solop=0;
			for(int i = 0; i < dsl.solop; i ++)
			{
				if(dsl.l[i]->nienKhoa.compare(nk) == 0)
				{
					tam.l[tam.solop] = new lop;
					tam.l[tam.solop] = dsl.l[i];
					tam.solop++;
				}
			}
			gotoxy(45+19,33+8);
			cout << "  ";
			gotoxy(45+18+6+3,33+8);
			cout << "  ";
			for(int i = 0; i < 29;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(46,6+i);
				cout << "                                      ";
				gotoxy(86,6+i);
				cout << "                                      ";
			}
			if(nk.length() == 0 )
			{
				gotoxy(132,30);
				string tb1 = "Ban chua nhap nien khoa!";
				InTB(tb1,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(55+18,33+3);
			}
			else
			{
				if(CheckNK(dsl,nk) == false)
				{
					AnConTro();
					InDSLop(tam,page);
					int state = 0;
					gotoxy(7,6);
					cout << muiten;
					batPhim(s,sCheck);
					while(s != ESC)
					{
						int maxpage = 0;
						for(int i = 0; i < tam.solop; i++)
						{
							if(tam.l[i]->nienKhoa.compare(nk) == 0)
							{
								maxpage++;
							}
						}
						if(maxpage < 10)
						{
							maxpage = 0;
						}
						else if(maxpage % 10 == 0)
						{
							maxpage = maxpage/10 - 1;
						}
						else
						{
							maxpage = maxpage/10;
						}
						if (s == PAGEDOWN && sCheck == false)
						{
							if(page < maxpage)
							{
								for(int i = 0; i < 29;i++)
								{
									gotoxy(6,6+i);
									cout << "                                      ";
									gotoxy(46,6+i);
									cout << "                                      ";
									gotoxy(86,6+i);
									cout << "                                      ";
								}
								gotoxy(20+12,5+1);
								page ++;
								InDSLop(tam,page);
							}
						}
						if(s == PAGEUP && sCheck == false)
						{
							if (page > 0 )
							{
								for(int i = 0; i < 29;i++)
								{
									gotoxy(6,6+i);
									cout << "                                      ";
									gotoxy(46,6+i);
									cout << "                                      ";
									gotoxy(86,6+i);
									cout << "                                      ";
								}
								gotoxy(20+12,5+1);
								page--;
								InDSLop(tam,page);
							}
						}
						if(s == UP && sCheck == false)
						{
							if(page == 0)
							{
								if(state > 0)
								{
									gotoxy(wherex()-1,wherey());
									cout << " ";
									state --;
									gotoxy(7,wherey() - 3);
									cout << muiten;
								}
							}
							if(page > 0)
							{
								if((state > 0) )
								{
									gotoxy(wherex()-1,wherey());
									cout << " ";
									state --;
									gotoxy(7,wherey()-3);
									cout << muiten;
								}
								else if(state == 0)
								{
									for(int i = 0; i < 29;i++)
									{
										gotoxy(6,6+i);
										cout << "                                      ";
										gotoxy(46,6+i);
										cout << "                                      ";
										gotoxy(86,6+i);
										cout << "                                      ";
									}
									gotoxy(wherex()-1,wherey());
									cout << " ";
									page --;
									InDSLop(tam,page);
									gotoxy(7,33);
									cout << muiten;
									state = 9;
									
								}
							}
						}
						if(s == DOWN && sCheck == false)
						{
							if(state == 9)
							{
								if(tam.l[state + page*10 + 1] != NULL)
								{
									gotoxy(wherex()-1,wherey());
									cout << " ";
									if(page < tam.solop/10)
									{
									
										for(int i = 0; i < 29;i++)
										{
											gotoxy(6,6+i);
											cout << "                                      ";
											gotoxy(46,6+i);
											cout << "                                      ";
											gotoxy(86,6+i);
											cout << "                                      ";
										}
									}
									page++;
									InDSLop(tam,page);
									state = 0;
									gotoxy(7,6);
									cout << muiten;
								}
							}
							else
							{
								if(tam.l[state + page*10 + 1] != NULL)
								{
									gotoxy(wherex()-1,wherey());
									cout << " ";
									state ++;
									gotoxy(7,wherey() + 3);
									cout << muiten;	
								}
								if(tam.l[state + page*10 + 1] == NULL) 
								{
									gotoxy(wherex()-1,wherey());
									cout << " ";
									gotoxy(7,wherey());
									cout << muiten;
								}
							}
						}
						if(s == ENTER)
						{
							selectFunctionSV(tam.l[state + page*10],page);
							system("cls");
							gotoxy(130,26);
							vekhungTB(10,36);
							gotoxy(5,2);
							ChangeColor(15);
							vekhungDS(34,120,3);
							gotoxy(22,3);
							cout << "TEN LOP";
							gotoxy(63,3);
							cout << "MA LOP";
							gotoxy(101,3);
							cout << "NIEN KHOA";
							gotoxy(45+1,33+6);
							veKhung(5,33);
							gotoxy(45+3,33+8);
							cout << "Nhap nien khoa:";
							gotoxy(45+18,33+7);
							veKhung(3,5);
							gotoxy(45+18+6,33+8);
							cout << "-";
							gotoxy(45+18+6+2,33+7);
							veKhung(3,5);
							InDSLop(tam,page);
							state = 0;
							gotoxy(7,6);
							cout << muiten;
						}
						batPhim(s,sCheck);
					}
				}
				else
				{
					string tb = "Khong tim thay lop co nien khoa yeu cau";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
			}
			gotoxy(45+19,33+8);
			HienConTro();
			nk = "";
		}
	batPhim(s,sCheck);
	}
}
// ==================== IN DANH SACH SINH VIEN ==========================
void InDSSV (lop *l,int page)
{
	if (l->danhsach.First == NULL)
	{
		return;
	}
	int k = 2;
	int sl = DemSV(l->danhsach);
	int maxpage;
	if(sl <= 10)
	{
		maxpage = 0;
	}
	else if (sl % 10 == 0)
	{
		maxpage = sl/10 - 1;
	}
	else maxpage = sl/10;
	nodeSV *j = new nodeSV;
	if (page == 0)
	{
		j = l->danhsach.First;
	}
	else
	{
		j = l->danhsach.First;
		for (int i=0; i<page*10; i++)
		{
			if (j->pNext != NULL)
			{
				j = j->pNext;
			}
		}	
	}
	
	for(int i = 0; i < 10; i++)
	{
		if (j->pNext != NULL) 
		{ 
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(40,4+k);
			cout << j->info.ho << " " << j->info.ten;
			gotoxy(80+(25-j->info.gioiTinh.length())/2,4+k);
			cout << j->info.gioiTinh;
			k += 3;
			j = j->pNext;
		}
		else {
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(40,4+k);
			cout << j->info.ho << " " << j->info.ten;
			gotoxy(80+(25-j->info.gioiTinh.length())/2,4+k);
			cout << j->info.gioiTinh;
			k += 3;
			break;
		}
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage + 1;
}
// ==================== NHAP SINH VIEN ==========================
void NhapSinhVien(lop *&l )
{
	AnConTro();
	int maxpage;
	gotoxy(130,26);
	vekhungTB(10,36);
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(50,3);
	cout << "HO VA TEN";
	gotoxy(88,3);
	cout << "GIOI TINH";
	gotoxy(140-18,22);
	cout << "NHAP SINH VIEN";
	gotoxy(110,2);
	veKhung(20,44);
	gotoxy(112,2+3);
	cout << "Ma SV:";
	gotoxy(122,2+2);
	veKhung(3,30);
	gotoxy(112,2+7);
	cout << "Ho va Ten:";
	gotoxy(122,2+6);
	veKhung(3,30);
	gotoxy(112,2+11);
	cout << "Gioi Tinh:";
	veNut(3,9,123,12,"NAM",240);
	veNut(3,9,142,12,"NU",15);
	gotoxy(112,2+15);
	cout << "Mat khau:";
	gotoxy(122,2+14);
	veKhung(3,30);
	int hd , td;
	int page = 0;
	string mk;
	string masv;
	string hoten;
	string gt = "NAM";
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(124,2+3);
	HienConTro();
	batPhim(s,sCheck);
	while (1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				switch(state)
				{
					case 0:
						{
							gotoxy(124+masv.length(),3+2);
							break;
						}
					case 1:	
						{
							gotoxy(124+hoten.length(),3+6);
							break;
						}
					case 2:
						{
							gotoxy(124+mk.length(),3+14);
							break;
						}	
				}
				HienConTro();
				batPhim(s,sCheck);
				
			}
		}
		if(DemSV(l->danhsach) < 10)
		{
			maxpage = 0;
		}
		else if(DemSV(l->danhsach) % 10 == 0)
		{
			maxpage = DemSV(l->danhsach)/10 - 1;
		}
		else maxpage = DemSV(l->danhsach)/10;
		HienConTro();
		if(s == LEFT )
		{
			hd = wherex();
			td = wherey();
			veNut(3,9,123,12,"NAM",240);
			veNut(3,9,142,12,"NU",15);
			gotoxy(hd,td);
			gt = "NAM";
			
		}
		if(s == RIGHT )
		{
			hd = wherex();
			td = wherey();
			veNut(3,9,123,12,"NAM",15);
			veNut(3,9,142,12,"NU",240);
			gotoxy(hd,td);
			gt = "NU";
		}
		if (s == UP && sCheck == false)
		{
			HienConTro();
			switch(state)
			{
				case 1:
					{
						gotoxy(124+masv.length(),3+2);
						state --;
						break;
					}
				case 2:	
					{
						gotoxy(124+hoten.length(),3+6);
						state --;
						break;
					}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			HienConTro();
			switch(state)
			{
				case 0:
					{
						gotoxy(124+hoten.length(),3+6);
						state ++;
						break;
					}
				case 1:	
					{
						gotoxy(124+mk.length(),3+14);
						state ++;
						break;
					}
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))  && sCheck == true)
		{
			HienConTro();
			switch(state)
			{
				case 0:
					{
						if(masv.length() < 11)
						{
							cout << InHoa(s);
							masv += InHoa(s);
						}
						break;
					}
				case 1:	
					{
						if(hoten.length() < 26)
						{
							cout << InHoa(s);
							hoten += InHoa(s);
						}
						break;
					}
				case 2:
					{
						if(mk.length() < 26)
						{
							cout << s;
							mk += s;	
						}
						break;
					}	
			}
		}
		if(s == ' ')
		{
			if(state == 1)
				{
					if(hoten.length() == 0)
					{
						gotoxy(124+hoten.length()-1,3+6);
					}
					if(hoten[hoten.length()-1]!= ' ')
					{
						cout << InHoa(s);
						hoten += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			switch(state)
			{
				case 0:
					{
						if (masv.length() > 0)
						{
							AnConTro();
							gotoxy(wherex()-1,wherey());
							cout << " ";
							gotoxy(wherex()-1,wherey());
							HienConTro();
							masv.erase(masv.length()-1);
						}
						break;
					}
				case 1:
					{
						if (hoten.length() > 0)
						{
							AnConTro();
							gotoxy(wherex()-1,wherey());
							cout << " ";
							gotoxy(wherex()-1,wherey());
							HienConTro();
							hoten.erase(hoten.length()-1);
						}
						break;
					}
				case 2:
					{
						if (mk.length() > 0)
						{
							AnConTro();
							gotoxy(wherex()-1,wherey());
							cout << " ";
							gotoxy(wherex()-1,wherey());
							HienConTro();
							mk.erase(mk.length()-1);
						}
						break;
					}	
			}	
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page ++;
				InDSSV(l,page);
				gotoxy(124+masv.length(),3+2);
				HienConTro();
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page--;
				InDSSV(l,page);
				gotoxy(124+masv.length(),3+2);
				HienConTro();
			}
		}
		if (s == ENTER)
		{
			for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
			bool ktten = false;
			ChuanHoaTen(hoten);
			sinhVien sv;
			sv.maSV = masv;
			sv.ho = TachHoSV(hoten);
			gotoxy(1,1);
			sv.ten = TachTenSV(hoten);
			sv.password = mk;
			sv.gioiTinh = gt;
			for(int i = 0; i < hoten.length(); i ++)				// can it nhat 1 dau cach de phan biet ho va ten
			{
				if (hoten[i] == ' ')
				{
					ktten = true;
					break;
				}
			}	
			if (masv.length() == 0 || hoten.length() == 0 || mk.length() == 0)
			{
				string tb = "Vui long dien day du thong tin sinh vien";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				if(CheckFormMaSv(masv) == true)
				{
						if(CheckMaSV(l,masv) == false)
						{
							string tb = "Ma sinh vien da co trong danh sach";
							InTB(tb,132,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
						}
						else if(masv.substr(1,2).compare(l->nienKhoa) != 0)
						{
							string tb = "Nien khoa cua ma sinh vien khong khop voi nien khoa cua lop";
							InTB(tb,132,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
						}
						else
						{
							if(ktten == true)
							{
								Them1SinhVien(l,sv);
								string tb = "Them sinh vien vao danh sach thanh cong";
								InTB(tb,132,30);
								AnConTro();
								Sleep(750);
								XoaTB(130,26);
							}
							else
							{
								string tb = "Ho ten khong dung dinh dang, vui long nhap lai";
								InTB(tb,132,30);
								AnConTro();
								Sleep(750);
								XoaTB(130,26);
							}
						} 
				}
				else
				{
					string tb = "Ma sinh vien khong dung dinh dang, vui long nhap lai";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
			}			
			InDSSV(l,page);
			masv = "";
			hoten = "";
			mk = "";
			gotoxy(124+masv.length(),3+2);
			cout << "                           ";
			gotoxy(124+masv.length(),7+2);
			cout << "                           ";
			gotoxy(124+masv.length(),15+2);
			cout << "                           ";
			gotoxy(124+masv.length(),3+2);
			HienConTro();
			state = 0;
		}
	batPhim(s,sCheck);
	}
	for (int i=2; i<23; i++)
	{
		gotoxy(110,i);
		cout << "                                             ";
	}
	AnConTro();
}
// ==================== XOA SINH VIEN ==========================
void XoaSinhVien(lop *&l ,int page)
{
	for (int i=2; i<23; i++)
	{
		gotoxy(110,i);
		cout << "                                             ";
	}
	AnConTro();
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(50,3);
	cout << "HO VA TEN";
	gotoxy(88,3);
	cout << "GIOI TINH";
	gotoxy(110,2);
	gotoxy(7,6);
	cout << muiten;
	int maxpage;
	int state = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(DemSV(l->danhsach) % 10 == 0) 
		{
			maxpage = DemSV(l->danhsach)/10;
		}
		else maxpage = DemSV(l->danhsach)/10 + 1;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSSV(l,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
					
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                      ";
							gotoxy(31,6+i);
							cout << "                                             ";
							gotoxy(81,6+i);
							cout << "                      ";
						}
					}
					page++;
					InDSSV(l,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(k->pNext == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage -1)
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSSV(l,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSSV(l,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			string tb = "Ban co chac chan muon sinh vien nay ? (Y/N)";
			InTB(tb,132,30);
			nodeSV *k = l->danhsach.First;
			for (int i = 0; i < state + page*10; i++)
			{
				if (k->pNext != NULL)
				{
					k = k->pNext;
				}
			}
			batPhim(s,sCheck);
			while(s != ESC)
			{
				AnConTro();
				if((s == 'y' || s == 'Y')&& sCheck == true)
				{
					DeleteInfo_SV(l->danhsach, k->info.maSV);
					XoaTB(130,26);
					gotoxy(132,30);
					tb = "Xoa sinh vien thanh cong";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					break;
					
				}
				else if((s == 'n' || s == 'N') && sCheck == true)
				{
					XoaTB(130,26);
					break;
				}
				batPhim(s,sCheck);
			}
			for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(81,6+i);
						cout << "                      ";
					}	
			page = 0;
			int hd = wherex();
			int td = wherey();
			if (l->danhsach.First != NULL)
			{
				InDSSV(l,page);
				gotoxy(hd,td);
				cout << " ";
				state = 0;
				gotoxy(7,6);
				cout << muiten;	
			}
			else 
			{
				break;
			}
				
		}
	batPhim(s,sCheck);
	}
	
}
// ==================== NHAP MON HOC THEM ==========================
void NhapMonHoc(DSMH &dsm, int page)
{	
	gotoxy(5,40);
	veKhung(5,120);
	gotoxy(7,42);
	cout << "Ma mon :";
	gotoxy(15,41);
	veKhung(3,30);
	gotoxy(80,42);
	cout << "Ten mon :";
	gotoxy(88,41);
	veKhung(3,35);
	int maxpage;
	string tenmon;
	string mamon;
	char s;
	bool state = true;
	bool sCheck;
	string tb;
	int hd;
	int td;
	gotoxy(17,42);
	HienConTro();
	batPhim(s,sCheck);
	while (1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				if (state == true)
				{
					gotoxy(17+mamon.length(),42);
				}
				else gotoxy(90+tenmon.length(),42);
				HienConTro();
				batPhim(s,sCheck);
			}
		}
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+mamon.length(),42);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenmon.length(),42);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')  ) && sCheck == true)
		{
			HienConTro();
			if (state == false )
			{
				if (tenmon.length() < 30)
				{
					cout << InHoa(s);
					tenmon += InHoa(s);
				}
			}
			else 
			{
				if (mamon.length() < 20)
				{
					cout << InHoa(s);
					mamon += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenmon.length() == 0)
					{
						gotoxy(90+tenmon.length(),42);
					}
					else if(tenmon[tenmon.length()-1]!= ' ')
					{
						cout << InHoa(s);
						tenmon += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenmon.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					tenmon.erase(tenmon.length()-1);
				}
			}
			else
			{
				if (mamon.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					mamon.erase(mamon.length()-1);
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				page ++;
				InDSMon(dsm,page);
				
			}
			if(state == true)
			{
				gotoxy(17+mamon.length(),42);
			}
			else
			{
				gotoxy(90+tenmon.length(),42);	
			}
			HienConTro();
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
				page--;
				InDSMon(dsm,page);
			}
			if(state == true)
			{
				gotoxy(17+mamon.length(),42);
			}
			else
			{
				gotoxy(90+tenmon.length(),42);	
			}
			HienConTro();
		}
		if (s == ENTER)
		{
			AnConTro();
			ChuanHoaTen(tenmon);
			if(tenmon.length() == 0 || mamon.length() == 0)
			{
				tb = "Ban chua nhap ten mon hoac ma mon, vui long dien day du thong tin";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(17+mamon.length(),42);
			}
			else
			{
				if(CheckMonNhap(dsm,mamon,tenmon) == false)
				{
					XoaTB(130,26);
					tb = "Ma mon hoac ten mon da bi trung, vui long nhap lai";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(17+mamon.length(),42);
				}
				else
				{
//					int n = dsm.somon;
//					dsm.m[n] = new monHoc;
//					dsm.m[n]->maMH = mamon;
//					dsm.m[n]->tenMH = tenmon;
//					dsm.somon ++;
					monHoc mh ;
					mh.maMH = mamon;
					mh.tenMH = tenmon;
					InsertMon(dsm,mh);
					AnConTro();
					XoaTB(130,26);
					gotoxy(132,30);
					tb = "Them mon vao danh sach thanh cong";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					HienConTro();
				}
			}
			for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
			InDSMon(dsm,page);
			mamon = "";
			tenmon = "";
			gotoxy(17,42);
			cout << "                           ";
			gotoxy(90,42);
			cout << "                           ";
			gotoxy(17+mamon.length(),42);
			HienConTro();
			state = true;
		}
	batPhim(s,sCheck);
	}
	AnConTro();
	for(int i = 0; i < 5; i++)
	{
		gotoxy(5,40+i);
		cout << "                                                                                                                        ";
	}
}
// ==================== THEM MON ==========================
void ThemMonHoc(DSMH &dsm, int page)
{
	ChangeColor(15);
	int n = dsm.somon;
	if(n  == MAXMH)
	{
		gotoxy(130,26);
		string tb = "Khong the them mon hoc, danh sach mon hoc da day";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapMonHoc(dsm,page);
	}
}
// ==================== CHECK MON DA THI ==========================
bool CheckDaThi (string mamon,dslop dsl)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		for(nodeSV *k = dsl.l[i]->danhsach.First;k != NULL ;k=k->pNext)
		{
			for(nodediemThi *p = k->info.diem.First; p != NULL; p=p->pNext)
			{
				if(p->info.maMH.compare(mamon) == 0)
				{
					return true;// co thi roi
				}
			}
		}
	}
	return false;
}
// ==================== CHECK CH DA THI ==========================
bool CheckCHDaThi (dslop dsl, int id)
{
	for(int i = 0; i < dsl.solop; i++)
	{
		for(nodeSV *k = dsl.l[i]->danhsach.First;k != NULL ;k=k->pNext)
		{
			for(nodediemThi *p = k->info.diem.First; p != NULL; p=p->pNext)
			{
				for(int j = 0; j < p->info.ctdt.sct; j++)
				{
					if(p->info.ctdt.bode[j] == id)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool CheckCH_mon(NODECH q, string mamon)
{
	NODECH p;
	p = q;
	if(p != NULL)  
	{ 
		if (p->info.maMH.compare(mamon) == 0)
		{
			return false;
		}
		if(CheckCH_mon(p->pLeft,mamon) == false) return false;
		if(CheckCH_mon(p->pRight,mamon) == false) return false;
	}
	return true;
}
// ==================== NHAP MON XOA ==========================
void NhapMonXoa(DSMH &dsm,int &page, dslop dsl,NODECH &dsch)
{
	string tb;
	int maxpage;
	InDSMon(dsm,page);
	string mamon;
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMon(dsm,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMon(dsm,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsm.m[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			//neu mon da co thi, khong duoc xoa
			if( CheckDaThi(dsm.m[state + page*10]->maMH,dsl) == true)
			{
				tb = "Mon hoc da co thi, khong the xoa!";
				InTB(tb,132,30);
			}
			else if(CheckCH_mon(dsch,dsm.m[state+page*10]->maMH)== false) //mon chua thi nhung co cau hoi trong dsch
			{
				tb = "Mon hoc da co cau hoi,ban co chac chan muon xoa mon nay ? (Y/N)";
				InTB(tb,132,30);
				batPhim(s,sCheck);
				while(s != ESC)
				{
					AnConTro();
					if((s == 'y' || s == 'Y')&& sCheck == true)
					{
						
						NODECH Stack[STACKSIZE];
						NODECH p = dsch;
						int sp = -1;
						do
						{ 
							while (p != NULL)
							{
								Stack[++sp]= p;
								p = p->pLeft;
							}
							if (sp != -1)
							{
								p = Stack[sp--];
								if(p->info.maMH.compare(dsm.m[state +page*10]->maMH) == 0)
								{
									remove(p->id,dsch);
								}
								p = p->pRight;
							}
							else break;
						} while (1);
						for(int i = state + page*10; i < dsm.somon; i++)
						{
							dsm.m[i] = dsm.m[i+1];
						}
						dsm.somon --;
						XoaTB(130,26);
						gotoxy(132,30);
						tb = "Xoa mon hoc thanh cong";
						InTB(tb,132,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						break;
					}
					else if((s == 'n' || s == 'N') && sCheck == true)
					{
						XoaTB(130,26);
						break;
					}
					batPhim(s,sCheck);
				}
			}
			else
			{
				tb = "Ban co chac chan muon xoa mon nay ? (Y/N)";
				InTB(tb,132,30);
				batPhim(s,sCheck);
				while(s != ESC)
				{
					AnConTro();
					if((s == 'y' || s == 'Y')&& sCheck == true)
					{
						for(int i = state + page*10; i < dsm.somon; i++)
						{
							dsm.m[i] = dsm.m[i+1];
						}
						dsm.somon --;
						XoaTB(130,26);
						gotoxy(132,30);
						tb = "Xoa mon hoc thanh cong";
						InTB(tb,132,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						break;
					}
					else if((s == 'n' || s == 'N') && sCheck == true)
					{
						XoaTB(130,26);
						break;
					}
					batPhim(s,sCheck);
				}
			}
			for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}	
			page = 0;
			int hd = wherex();
			int td = wherey();
			InDSMon(dsm,page);
			state = 0;
			gotoxy(7,6);
			cout << muiten;	
		}
	batPhim(s,sCheck);
	}
	for(int i = 0; i < 10; i++)
	{
		gotoxy(7,6+i*3);
		cout << " ";
	}
}
// ==================== XOA MON HOC ==========================
void XoaMonHoc (DSMH &dsm, dslop dsl, NODECH &dsch)
{
	string tb;
	int page = 0;
	if(dsm.somon == 0)
	{
		tb = "Danh sach mon hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapMonXoa(dsm,page,dsl,dsch);
	}
}
// ==================== SUA MON ==========================
void SuaMon(monHoc *&m)
{
	gotoxy(5,40);
	veKhung(5,120);
	gotoxy(7,42);
	cout << "Ma mon :";
	gotoxy(15,41);
	veKhung(3,30);
	gotoxy(80,42);
	cout << "Ten mon :";
	gotoxy(88,41);
	veKhung(3,35);
	bool state = true;
	char s;
	bool sCheck;
	string tenmon = m->tenMH;
	string mamon = m->maMH;
	gotoxy(17,42);
	cout << mamon;
	gotoxy(90,42);
	cout << tenmon;
	gotoxy(17+mamon.length(),42);
	HienConTro();
	batPhim(s,sCheck);
	while(1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				if (state == true)
				{
					gotoxy(17+mamon.length(),42);
				}
				else gotoxy(90+tenmon.length(),42);
				HienConTro();
				batPhim(s,sCheck);
			}
		}
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+mamon.length(),42);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenmon.length(),42);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) && sCheck == true)
		{
			HienConTro();
			if (state == true)
			{
				if (mamon.length() < 10)
				{
					cout << InHoa(s);
					mamon += InHoa(s);
				}
			}
			else
			{
				if (tenmon.length() < 30)
				{
					cout << InHoa(s);
					tenmon += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenmon.length() == 0)
					{
						gotoxy(90+tenmon.length()-1,42);
					}
					if(tenmon[tenmon.length()-1] != ' ')
					{
						cout << InHoa(s);
						tenmon += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenmon.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					tenmon.erase(tenmon.length()-1);
				}
			}
			else
			{
				if (mamon.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					mamon.erase(mamon.length()-1);
				}
			}
		}
		if(s == ENTER)
		{
			if(mamon.length() == 0 || tenmon.length() == 0)
			{
				string tb = "Vui long nhap day du thong tin";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				m->tenMH= tenmon;
				m->maMH = mamon;
				break;
			}
			mamon = "";
			tenmon = "";
			gotoxy(17,42);
			cout << "                           ";
			gotoxy(90,42);
			cout << "                           ";
			gotoxy(17,42);
			state = true;
		}
		batPhim(s,sCheck);
	}
	AnConTro();
	for(int i = 0; i < 5; i++)
	{
		gotoxy(5,40+i);
		cout << "                                                                                                                        ";
	}
}
// ==================== NHAP MON CHINH ==========================
void NhapMonChinh(DSMH &dsm , int &page, NODECH &dsch, dslop dsl)
{
	int maxpage;
	InDSMon(dsm,page);
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMon(dsm,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMon(dsm,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsm.m[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			string tb;
			if( CheckDaThi(dsm.m[state + page*10]->maMH,dsl) == true)
			{
				tb = "Mon hoc da co thi, khong the sua!";
				InTB(tb,132,30);
				Sleep(750);
				XoaTB(130,26);
				gotoxy(7,6+(state*3));
				cout << " ";
				state = 0;
				gotoxy(7,6);
				cout << muiten;
			}
			else if(CheckCH_mon(dsch,dsm.m[state+page*10]->maMH)== false) //mon chua thi nhung co cau hoi trong dsch
			{
				tb = "Mon hoc da co cau hoi,khong the sua!";
				InTB(tb,132,30);
				Sleep(750);
				XoaTB(130,26);
				gotoxy(7,6+(state*3));
				cout << " ";
				state = 0;
				gotoxy(7,6);
				cout << muiten;
			}
			else
			{
				
				SuaMon(dsm.m[state + page * 10]);
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
				page = 0;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
				cout << " ";
				state = 0;
				gotoxy(7,6);
				cout << muiten;
			}
			
		}
	batPhim(s,sCheck);
	}
	for(int i = 0; i < 10; i++)
	{
		gotoxy(7,6+i*3);
		cout << " ";
	}
}

// ==================== CHINH MON ==========================
void ChinhMon(DSMH &dsm, int &page, NODECH dsch,dslop dsl )
{
	int n = dsm.somon;
	if(n  == 0)
	{
		string tb = "Danh sach mon hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapMonChinh(dsm, page,dsch,dsl);
	}
}
// ==================== FUNCTION MON HOC ==========================
void FunctionMon(DSMH &dsm, dslop dsl, NODECH &dsch)
{
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(130,26);
	vekhungTB(10,36);
	int page = 0;
	char s;
	bool sCheck;
	gotoxy(5,2);
	int state = 0;
	vekhungDS(34,120,2);	
	veNut(3,15,150,10,"Them mon",240);
	veNut(3,15,150,15,"Xoa mon",20);
	veNut(3,15,150,20,"Sua mon",20);
	gotoxy(30,3);
	cout << "MA MON HOC";
	gotoxy(90,3);
	cout << "TEN MON HOC";
	if (dsm.somon != 0) 
	{
		InDSMon(dsm,page);
	}
	int maxpage;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if (s == UP && sCheck == false)
		{
			switch(state)
			{
			
			case 0:
				{
					break;
				}
			case 1:
				{
					state--;
					veNut(3,15,150,15,"Xoa mon",20);
					veNut(3,15,150,10,"Them mon",240);
					break;
				}
			case 2:
				{
					state--;
					veNut(3,15,150,20,"Sua mon",20);
					veNut(3,15,150,15,"Xoa mon",240);
					break;
				}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			switch(state)
			{
			case 0:
				{
					state++;
					veNut(3,15,150,10,"Them mon",20);
					veNut(3,15,150,15,"Xoa mon",240);
					break;
				}
			case 1:
				{
					state++;
					veNut(3,15,150,15,"Xoa mon",20);
					veNut(3,15,150,20,"Sua mon",240);
					break;
				}
			case 2:
				{
					break;
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
				page ++;
				InDSMon(dsm,page);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
				page--;
				InDSMon(dsm,page);
			}
		}
		if(s == ENTER)
		{
			switch(state)
			{
				case 0:
					{
						ThemMonHoc(dsm,page);
						AnConTro();
						break;
					}
				case 1:
					{
						XoaMonHoc(dsm,dsl,dsch);
						AnConTro();
						break;
					}
				case 2:
					{
						ChinhMon(dsm,page,dsch,dsl);
						AnConTro();
						break;
					}	
			}
		}
	batPhim(s,sCheck);	
	}
}
// ==================== NHAP LOP XOA ==========================
void NhapLopXoa(dslop &dsl,int &page)
{
//	gotoxy(55,33);
//	veKhung(7,50);
//	gotoxy(55+3,33+3);
//	cout << "Ma lop xoa:";
//	gotoxy(55+17,33+2);
//	veKhung(3,30);
	string tb;
	int maxpage;
	InDSLop(dsl,page);
	string malop;
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 29;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(46,6+i);
							cout << "                                      ";
							gotoxy(86,6+i);
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			if( DemSV(dsl.l[state + page * 10]->danhsach) > 0)
			{
				tb = "Lop ton tai sinh vien, khong the xoa!" ;
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				tb = "Ban co chac chan muon xoa lop nay ? (Y/N)";
				InTB(tb,132,30);
				batPhim(s,sCheck);
				while(s != ESC)
				{
					AnConTro();
					if((s == 'y' || s == 'Y')&& sCheck == true)
					{
						for(int i = state + page*10; i < dsl.solop; i++)
						{
							dsl.l[i] = dsl.l[i+1];
						}
						dsl.solop --;
						XoaTB(130,26);
						gotoxy(132,30);
						tb = "Xoa lop thanh cong";
						InTB(tb,132,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						break;
					}
					else if((s == 'n' || s == 'N') && sCheck == true)
					{
						XoaTB(130,26);
						break;
					}
					batPhim(s,sCheck);
				}
			}
			for(int i = 0; i < 28;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(46,6+i);
				cout << "                                      ";
				gotoxy(86,6+i);
				cout << "                                     ";
			}
				
			page = 0;
			int hd = wherex();
			int td = wherey();
			InDSLop(dsl,page);
			gotoxy(hd,td);
			cout << " ";
			state = 0;
			gotoxy(7,6);
			cout << muiten;	
		}
	batPhim(s,sCheck);
	}
}
// ==================== XOA LOP ==========================
void XoaLop (dslop &dsl, int &page)
{
	int n = dsl.solop;
	string tb;
	if(n  == 0)
	{
		tb = "Danh sach lop hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLopXoa(dsl, page);
	}
}
// ==================== SUA LOP ==========================
void SuaLop(lop *&l)
{
	gotoxy(5,40);
	veKhung(5,120);
	gotoxy(7,42);
	cout << "Ma lop :";
	gotoxy(15,41);
	veKhung(3,30);
	gotoxy(80,42);
	cout << "Ten lop :";
	gotoxy(88,41);
	veKhung(3,35);
	bool state = true;
	char s;
	bool sCheck;
	string tenlop = l->tenLop;
	string malop = l->maLop;
	gotoxy(17,42);
	cout << malop;
	gotoxy(90,42);
	cout << tenlop;
	gotoxy(17+malop.length(),42);
	HienConTro();
	batPhim(s,sCheck);
	while(1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				if(state == true)
				{
					gotoxy(17+malop.length(),42);
				}
				else
				{
					gotoxy(90+tenlop.length(),42);	
				}
				HienConTro();
				batPhim(s,sCheck);
				
			}
		}
		if (s == LEFT && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(17+malop.length(),42);
				state = true;
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(90+tenlop.length(),42);
				state = false;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) && sCheck == true)
		{
			HienConTro();
			if (state == true)
			{
				if (malop.length() < 10)
				{
					cout << InHoa(s);
					malop += InHoa(s);
				}
			}
			else
			{
				if (tenlop.length() < 30)
				{
					cout << InHoa(s);
					tenlop += InHoa(s);
				}
			}
		}
		if(s == ' ')
		{
			if(state == false)
				{
					if(tenlop.length() == 0)
					{
						gotoxy(90+tenlop.length()-1,42);
					}
					if(tenlop[tenlop.length()-1] != ' ')
					{
						cout << InHoa(s);
						tenlop += InHoa(s);	
					}
				}
		}
		if (s == BACKSPACE)
		{
			if (state == false)
			{
				if (tenlop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					tenlop.erase(tenlop.length()-1);
				}
			}
			else
			{
				if (malop.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					malop.erase(malop.length()-1);
				}
			}
		}
		if(s == ENTER)
		{
			if(malop.length() == 0 || tenlop.length() == 0)
			{
				cout << "Khong duoc de thieu thong tin";
			}
			else
			{
				if(CheckFormMaLop(malop) == false)
				{
					cout << "Sai dinh dang ma lop!";
				}
				else
				{
					l->tenLop = tenlop;
					l->maLop = malop;
					l->nienKhoa = l->maLop.substr(1,2);
					break;
				}
			}
			malop = "";
			tenlop = "";
			gotoxy(17,42);
			cout << "                           ";
			gotoxy(90,42);
			cout << "                           ";
			gotoxy(17,42);
			state = true;
		}
		batPhim(s,sCheck);
	}
	AnConTro();
	for(int i = 0; i < 5; i++)
	{
		gotoxy(5,40+i);
		cout << "                                                                                                                        ";
	}
}
// ==================== NHAP LOP CHINH ==========================
void NhapLopChinh(dslop &dsl , int &page)
{
	int maxpage;
	InDSLop(dsl,page);
	string malop;
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 29;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(46,6+i);
							cout << "                                      ";
							gotoxy(86,6+i);
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			if( DemSV(dsl.l[state + page * 10]->danhsach) > 0)
			{
				string tb = "Lop ton tai sinh vien, khong the chinh sua";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else
			{
				// ham nhap thong tin de sua
				SuaLop(dsl.l[state + page * 10]);
			}
			for(int i = 0; i < 28;i++)
			{
				gotoxy(6,6+i);
				cout << "                                      ";
				gotoxy(46,6+i);
				cout << "                                      ";
				gotoxy(86,6+i);
				cout << "                                     ";
			}
			page = 0;
			int hd = wherex();
			int td = wherey();
			InDSLop(dsl,page);
			gotoxy(hd,td);
			cout << " ";
			state = 0;
			gotoxy(7,6);
			cout << muiten;
		}
	batPhim(s,sCheck);
	}
}

// ==================== CHINH LOP ==========================
void ChinhLop(dslop &dsl, int &page)
{
	int n = dsl.solop;
	if(n  == 0)
	{
		string tb = "Danh sach lop hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLopChinh(dsl, page);
	}
}

// ==================== FUNCTION LOP ==========================
void FunctionLop(dslop &dsl)
{
	// ve bang + chuc nang trai phai de qua trang;
	// 3 nut them xoa sua lop + len xuong
	// thong bao
	// bang nhap thong tin
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	int maxpage;
	gotoxy(130,26);
	vekhungTB(10,36);
	int page = 0;
	char s;
	bool sCheck;
	gotoxy(5,2);
	int state = 0;
	vekhungDS(34,120,3);	
	veNut(3,15,150,10,"Them lop",240);
	veNut(3,15,150,15,"Xoa lop",20);
	veNut(3,15,150,20,"Sua lop",20);
	gotoxy(22,3);
	cout << "TEN LOP";
	gotoxy(63,3);
	cout << "MA LOP";
	gotoxy(101,3);
	cout << "NIEN KHOA";
	if (dsl.solop != 0) 
	{
		InDSLop(dsl,page);
	}
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if (s == UP && sCheck == false)
		{
			switch(state)
			{
			
			case 0:
				{
					break;
				}
			case 1:
				{
					state--;
					veNut(3,15,150,15,"Xoa lop",20);
					veNut(3,15,150,10,"Them lop",240);
					break;
				}
			case 2:
				{
					state--;
					veNut(3,15,150,20,"Sua lop",20);
					veNut(3,15,150,15,"Xoa lop",240);
					break;
				}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			switch(state)
			{
			case 0:
				{
					state++;
					veNut(3,15,150,10,"Them lop",20);
					veNut(3,15,150,15,"Xoa lop",240);
					break;
				}
			case 1:
				{
					state++;
					veNut(3,15,150,15,"Xoa lop",20);
					veNut(3,15,150,20,"Sua lop",240);
					break;
				}
			case 2:
				{
					break;
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
				page ++;
				InDSLop(dsl,page);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				page--;
				InDSLop(dsl,page);
			}
		}
		if(s == ENTER)
		{
			switch(state)
			{
				case 0:
					{
						ThemLop(dsl,page);
						AnConTro();
						break;
					}
				case 1:
					{
						XoaLop(dsl,page);
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(46,6+i);
							cout << "                                      ";
							gotoxy(86,6+i);
							cout << "                                      ";
						}
						InDSLop(dsl,page);
						AnConTro();
						break;
					}
				case 2:
					{
						ChinhLop(dsl,page);
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(46,6+i);
							cout << "                                      ";
							gotoxy(86,6+i);
							cout << "                                      ";
						}
						InDSLop(dsl,page);
						AnConTro();
						break;
					}	
			}
		}
	batPhim(s,sCheck);	
	}
}
// ==================== NHAP MA LOP ==========================
void NhapMaLop(dslop &dsl , int page)
{
	string malop;
	int hd;
	int td;
	gotoxy(5,37);
	veKhung(8,40);
	gotoxy(5+3,40);
	cout << "Nhap ma lop :";
	gotoxy(5+17,39);
	veKhung(3,20);
	gotoxy(5+18,40);
	HienConTro();
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) && sCheck == true)
		{
			HienConTro();
			if (malop.length() < 10)
			{
				cout << InHoa(s);
				malop += InHoa(s);
			}
		}
		if (s == BACKSPACE)
		{
			if (malop.length() > 0)
			{
				AnConTro();
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(wherex()-1,wherey());
				HienConTro();
				malop.erase(malop.length()-1);
			}	
		}
		if(s == ENTER)
		{
			//sau khi enter, nhay den trang chua lop do, hien dau >> ra va hien bang chon Them, Xoa
			if(CheckFormMaLop(malop) == true)
			{
				if(CheckMaLop(dsl,malop) == true)
				{
					string tb = "Ma lop khong ton tai";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
				else
				{
					for(int i = 0; i < dsl.solop; i++)
					{
						if(dsl.l[i]->maLop.compare(malop) == 0)
						{
							hd = wherex();
							td = wherey();
							system("cls");
							gotoxy(5,2);
							VeKhungDSLop(34,100,4);
							gotoxy(15,3);
							cout << "MA SV";
							gotoxy(50,3);
							cout << "HO VA TEN";
							gotoxy(88,3);
							cout << "GIOI TINH";
							InDSSV(dsl.l[i],0);
							NhapSinhVien(dsl.l[i]);
							gotoxy(hd,td);
						}
					}
					system("cls");
					gotoxy(5,37);
					veKhung(8,40);
					gotoxy(5+3,40);
					cout << "Nhap ma lop :";
					gotoxy(5+17,39);
					veKhung(3,20);
					gotoxy(22,3);
					cout << "TEN LOP";
					gotoxy(63,3);
					cout << "MA LOP";
					gotoxy(101,3);
					cout << "NIEN KHOA";
					gotoxy(5,2);
					vekhungDS(34,120,3);
				}
			}
			else
			{
				string tb = "Ban nhap sai dinh dang ma lop, vui long nhap lai";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
			malop = "";
			gotoxy(5+18,40);
			cout << "          ";
			gotoxy(5+18,40);
		}
		hd = wherex();
		td = wherey();
		InDSLop(dsl,page);
		gotoxy(hd,td);
		HienConTro();
		batPhim(s,sCheck);
	}
	for(int i = 0; i < 8; i++)
	{
		gotoxy(5,37+i);
		cout << "                                        ";
	}
}
// ====================SELECT FUNCTION SV ==========================
void selectFunctionSV(lop *&l ,int page)
{
	system("cls");
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang	LEFT,RIGHT: Chon gioi tinh";
	gotoxy(130,26);
	vekhungTB(10,36);
	char s;
	bool sCheck;
	gotoxy(5,2);
	int state = 0;
	gotoxy(5,2);
	VeKhungDSLop(34,100,4);
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(50,3);
	cout << "HO VA TEN";
	gotoxy(88,3);
	cout << "GIOI TINH";
	InDSSV(l,page);	
	veNut(3,15,120,10,"Them SV",240);
	veNut(3,15,120,15,"Xoa SV",20);
	int maxpage;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(DemSV(l->danhsach) < 10)
		{
			maxpage = 0;
		}
		else if(DemSV(l->danhsach) % 10 == 0)
		{
			maxpage = DemSV(l->danhsach)/10 - 1;
		}
		else maxpage = DemSV(l->danhsach)/10;
		if (s == UP && sCheck == false)
		{
			switch(state)
			{
			
			case 0:
				{
					break;
				}
			case 1:
				{
					state--;
					veNut(3,15,120,15,"Xoa SV",20);
					veNut(3,15,120,10,"Them SV",240);
					break;
				}
			}
		}
		if (s == DOWN && sCheck == false)
		{
			switch(state)
			{
			case 0:
				{
					state++;
					veNut(3,15,120,10,"Them SV",20);
					veNut(3,15,120,15,"Xoa SV",240);
					break;
				}
			case 1:
				{
					break;
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page ++;
				InDSSV(l,page);
				AnConTro();
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                      ";
					gotoxy(31,6+i);
					cout << "                                             ";
					gotoxy(81,6+i);
					cout << "                      ";
				}
				page--;
				InDSSV(l,page);
				AnConTro();
			}
		}
		if(s == ENTER)
		{
			switch(state)
			{
				case 0:
					{
						gotoxy(120,10);
						cout << "               ";
						cout << "               ";
						cout << "               ";
						gotoxy(120,15);
						cout << "               ";
						cout << "               ";
						cout << "               ";
						NhapSinhVien(l);
						gotoxy(15,3);
						cout << "MA SV";
						gotoxy(50,3);
						cout << "HO VA TEN";
						gotoxy(88,3);
						cout << "GIOI TINH";
						InDSSV(l,page);	
						veNut(3,15,120,10,"Them SV",240);
						veNut(3,15,120,15,"Xoa SV",20);	
						break;
					}
				case 1:
					{
						if (l->danhsach.First == NULL)
						{
							string tb = "Danh sach SV hien dang trong! Khong the xoa!";
							InTB(tb,132,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							break;
						}
						else 
						{
							gotoxy(120,10);
							cout << "               ";
							cout << "               ";
							cout << "               ";
							gotoxy(120,15);
							cout << "               ";
							cout << "               ";
							cout << "               ";
							XoaSinhVien(l,page);	
							gotoxy(15,3);
							cout << "MA SV";
							gotoxy(50,3);
							cout << "HO VA TEN";
							gotoxy(88,3);
							cout << "GIOI TINH";
							if (l->danhsach.First == NULL)
							{
								string tb = "Danh sach SV hien dang trong! Khong the tiep tuc xoa!";
								InTB(tb,132,30);
								AnConTro();
								Sleep(750);
								XoaTB(130,26);
								gotoxy(7,6);
								cout << " ";
								veNut(3,15,120,10,"Them SV",20);
								veNut(3,15,120,15,"Xoa SV",240);
								break;
							}
							else 
							{
								InDSSV(l,page);	
								gotoxy(7,6);
								cout << " ";
								veNut(3,15,120,10,"Them SV",20);
								veNut(3,15,120,15,"Xoa SV",240);	
								break;	
							}							
						}
					}
			}
		}
	batPhim(s,sCheck);	
	}
}
// ==================== FUNCTION SINH VIEN ==========================
void FunctionSV(dslop &dsl)
{
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	F1: Tim Lop	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(130,26);
	vekhungTB(10,36);
	int page = 0;
	int maxpage;
	int hd;
	int td;	
	gotoxy(5,2);
	vekhungDS(34,120,3);
	gotoxy(22,3);
	cout << "TEN LOP";
	gotoxy(63,3);
	cout << "MA LOP";
	gotoxy(101,3);
	cout << "NIEN KHOA";
	InDSLop(dsl,page);
	string malop = "";
	gotoxy(7,6);
	cout << muiten;
	int state = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		ChangeColor(15);
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;	
				}
				
			}
			
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(46,6+i);
							cout << "                                      ";
							gotoxy(86,6+i);
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
			
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				hd = wherex();
				td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				hd = wherex();
				td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == F1 && sCheck == false)
		{
			hd = wherex();
			td = wherey();
			NhapMaLop(dsl,page);
			for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
			InDSLop(dsl,page);	
			gotoxy(hd-1,td);
			cout << muiten;
			AnConTro();	
		}
		if ( s == ENTER)
		{
			//qua phai ve 2 nut them sinh vien, xoa sinh vien, enter chon chuc nang (giong funclop)
			selectFunctionSV(dsl.l[state + page*10],page);
			system("cls"); 
			gotoxy(5,2);
			vekhungDS(34,120,3);
			gotoxy(22,3);
			cout << "TEN LOP";
			gotoxy(63,3);
			cout << "MA LOP";
			gotoxy(101,3);
			cout << "NIEN KHOA";
			InDSLop(dsl,page);
			state = 0;
			AnConTro();
			gotoxy(7,6);
			cout << muiten;	
		}
		batPhim(s,sCheck);
	}
}
// ==================== KHOI TAO MANG RANDOM ==========================
void taoMangRd (int arr[], int min, int max)
{
	for(int i = min; i <= max ; i++)
	{
		if(min == 1 )
		{
			arr[i-1] = i;	
		}
		else if (min == 5001)
		{
			arr[i-5000-1] = i;
		}
	}
}
// ==================== RAMDOM 1 SO ==========================
int random(int minN, int maxN)
{
	srand((int)time(0));
    return minN + rand() % (maxN + 1 - minN);
}
// ==================== DEM NUT CAY ==========================
int countNode(NODECH root)
{
	NODECH Stack[STACKSIZE];
	NODECH p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->pLeft;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			++i;
			p = p->pRight;
		}
		else
			break;
	} while (1);
	return i;
}
// ==================== DUYET KIEM TRA ID ==========================
bool Inorder(NODECH q, int x) //  	LNR	 
{ 
	NODECH p;
	p = q;
	if(p != NULL)  
	{ 
		if (p->id == x)
		{
			return false;
		}
		if(Inorder(p->pLeft,x) == false) return false;
		if(Inorder(p->pRight,x) == false) return false;
	}
	return true;
}
// ==================== INSERT NODE CAU HOI ==========================
void Insert_node(NODECH &p, int x, cauHoi a)
{
	if(x == -1)
	{
		return;
	}
	if(p == NULL) // nút lá
	{
		p = new nodecauHoi;
		p->id = x;
		p->info = a;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	else
	{
		if(x < p->id )
		Insert_node(p->pLeft, x, a);
		else if(x > p->id )
		Insert_node(p->pRight, x, a);
	}
	
}
int rdMang (int arr[], int sch)
{
	int x = random(0,4998-sch);
	swap(arr[x],arr[4998-sch]);
	return arr[4998-sch];
}
// ==================== THEM 1 CAU HOI ==========================
void Them1CauHoi(NODECH &tree, cauHoi ch, int maxid , int arr1[], int arr2[])
{
	int x;
	if (tree == NULL)
	{
		x = maxid/2;
		Insert_node(tree,x,ch);
	}
	else
	{
		// khi = false thi tiep tuc random 1 so cho toi khi khac tat ca id trong dsch
		
		if (countNode(tree->pLeft) < countNode(tree->pRight))
		{
			int nt = countNode(tree->pLeft);
			x =	rdMang(arr1,nt);
		}
		else 
		{
			int np = countNode(tree->pRight);
			x =	rdMang(arr2,np);
		}
		Insert_node(tree,x,ch);
	}
}
void In1CH(NODECH ch, int k)
{
	gotoxy(16,4+k);
	cout << ch->id;
	gotoxy(40,4+k);
	cout << ch->info.maMH;
	gotoxy(55,4+k);
	if(ch->info.noiDung.length() < 63)
	{
		cout << ch->info.noiDung;
	}
	else
	{
		string temp = ch->info.noiDung.substr(0,63);
		cout << temp << "...";
	}
}
// ==================== IN DANH SACH CAU HOI ==========================
void InDSCH(NODECH root, int page, int *arr[])
{
	int k = 2;
	int maxpage;
	int sl = countNode(root);
	if(sl <= 10)
	{
		maxpage = 0;
	}
	else if (sl % 10 == 0)
	{
		maxpage = sl/10 - 1;
	}
	else maxpage = sl/10;
	for(int j = page*10; (j < (page + 1)*10) && (j<sl);j++)
	{
		NODECH temp = Search_CH(root,*arr[j]);
		In1CH(temp,k);
		k += 3;
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage + 1;
}
// ==================== NHAP MON XOA ==========================
void NhapCHXoa(NODECH &dsch,int &page, int *arr[], int&idlonnhat,dslop dsl)
{
	string tb;
	int maxpage;
	InDSCH(dsch,page,arr);
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	int sl = countNode(dsch);
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(sl == 0)
		{
			tb = "Danh sach cau hoi hien tai dang trong";
			InTB(tb,132,30);
			AnConTro();
			Sleep(750);
			XoaTB(130,26);
			break;
		}
		if(sl <= 10)
		{
			maxpage = 0;
		}
		else if(sl % 10 == 0) 
		{
			maxpage = sl/10 -1;
		}
		else maxpage = sl/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSCH(dsch,page,arr);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if((page + 1) * 10 < sl)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                      ";
							gotoxy(31,6+i);
							cout << "                      ";
							gotoxy(54,6+i);
							cout << "                                                                    ";
						}
					}
					page++;
					InDSCH(dsch,page,arr);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else 
			{
				if(state + 1 + page  * 10 < sl)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
//				if(state + (page + 1) * 10 < sl)
//				{
//					gotoxy(wherex()-1,wherey());
//					cout << " ";
//					gotoxy(7,wherey());
//					cout << muiten;
//				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSCH(dsch,page,arr);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSCH(dsch,page,arr);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			//neu cau hoi da co thi, khong duoc xoa
			int id = Search_CH(dsch,*arr[state+(page*10)])->id;
			if(CheckCHDaThi(dsl,id) == true)
			{
				tb = "Cau hoi da co thi, khong the xoa!";
				InTB(tb,132,30);
			}
			else
			{
				tb = "Ban co chac chan muon xoa cau hoi nay ? (Y/N)";
				InTB(tb,132,30);
				batPhim(s,sCheck);
				while(s != ESC)
				{
					AnConTro();
					if((s == 'y' || s == 'Y')&& sCheck == true)
					{
						int id = Search_CH(dsch,*arr[state+(page*10)])->id;
						remove(id,dsch);
						for(int i = state + page*10; i < sl - 1; i++)
						{
							*arr[i] = *arr[i+1];	
						}
						sl--;
						if(sl > 0)
						{
							idlonnhat = *arr[sl-1];	
						}
						XoaTB(130,26);
						gotoxy(132,30);
						tb = "Xoa cau hoi thanh cong";
						InTB(tb,132,30);
						AnConTro();
						Sleep(750);
						XoaTB(130,26);
						if( sl % 10 == 0 && page > 0)
						{
							page--;
						}
						break;
					}
					else if((s == 'n' || s == 'N') && sCheck == true)
					{
						XoaTB(130,26);
						break;
					}
					batPhim(s,sCheck);
				}
				XoaTB(130,26);
			}
			for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
			if(sl == 0)
			{
				tb = "Danh sach cau hoi hien tai dang trong";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				break;
			}
			int hd = wherex();
			int td = wherey();
			InDSCH(dsch,page,arr);
			state = 0;
			gotoxy(7,6);
			cout << muiten;
		}
	batPhim(s,sCheck);
	}
	for(int i = 0; i < 10; i++)
	{
		gotoxy(7,6+i*3);
		cout << " ";
	}
}
// ==================== XOA MON HOC ==========================
void XoaCauHoi (NODECH &dsch, int *arr[], int &idlonnhat,dslop dsl)
{
	string tb;
	int page = 0;
	int sl = countNode(dsch);
	if(sl == 0)
	{
		tb = "Danh sach cau hoi hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapCHXoa(dsch,page,arr,idlonnhat,dsl);
	}
}
// ==================== XEM CAU HOI ==========================
void XemCH(NODECH &dsch,int &page, int *arr[], int&idlonnhat)
{
	string tb;
	int maxpage;
	InDSCH(dsch,page,arr);
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	int sl = countNode(dsch);
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(sl == 0)
		{
			tb = "Danh sach cau hoi hien tai dang trong";
			InTB(tb,132,30);
			AnConTro();
			Sleep(750);
			XoaTB(130,26);
			break;
		}
		if(sl <= 10)
		{
			maxpage = 0;
		}
		else if(sl % 10 == 0) 
		{
			maxpage = sl/10 -1;
		}
		else maxpage = sl/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSCH(dsch,page,arr);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if((page + 1) * 10 < sl)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
					}
					page++;
					InDSCH(dsch,page,arr);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else 
			{
				if(state + 1 + page  * 10 < sl)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
//				if(state + (page + 1) * 10 < sl)
//				{
//					gotoxy(wherex()-1,wherey());
//					cout << " ";
//					gotoxy(7,wherey());
//					cout << muiten;
//				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSCH(dsch,page,arr);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSCH(dsch,page,arr);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			system("cls");
			int i = state + page*10;
			//batPhim(s,sCheck);
			while (s != ESC)
			{
//				if(s == LEFT && sCheck == false)
//				{
//					if(i > 0)
//					{
//						for(int i = 0; i < 30;i++)
//						{
//							gotoxy(20,5+i);
//							if(i == 4) i = 8;
//							if (i == 11) i = 14;
//							if (i == 17) i = 20;
//							if (i == 23) i = 26;
//							cout << "                                                                                                  ";
//						}
//						gotoxy(6,16-2);
//						cout << "DAP AN A: ";
//						gotoxy(19,15-2);
//						veKhung(5,100);
//						gotoxy(6,22-2);
//						cout << "DAP AN B: ";
//						gotoxy(19,21-2);
//						veKhung(5,100);
//						gotoxy(6,28-2);
//						cout << "DAP AN C: ";
//						gotoxy(19,27-2);
//						veKhung(5,100);
//						gotoxy(6,34-2);
//						cout << "DAP AN D: ";
//						i--;
//						NODECH ch = Search_CH(dsch,*arr[i]);
//						InNDCH(ch->info.noiDung);
//						gotoxy(20,14);
//						InDA_XemCH(ch->info.A);
//						gotoxy(20,20);
//						InDA_XemCH(ch->info.B);
//						gotoxy(20,26);
//						InDA_XemCH(ch->info.C);
//						gotoxy(20,32);
//						InDA_XemCH(ch->info.D);
//						if(ch->info.dapAn == "A")
//						{
//							ChangeColor(240);
//							gotoxy(6,16-2);
//							cout << "DAP AN A: ";
//							ChangeColor(15);
//						}
//						else if(ch->info.dapAn == "B")
//						{
//							ChangeColor(240);
//							gotoxy(6,22-2);
//							cout << "DAP AN B: ";
//							ChangeColor(15);
//						}
//						else if(ch->info.dapAn == "C")
//						{
//							ChangeColor(240);
//							gotoxy(6,28-2);
//							cout << "DAP AN C: ";
//							ChangeColor(15);
//						}
//						else if(ch->info.dapAn == "D")
//						{
//							ChangeColor(240);
//							gotoxy(6,34-2);
//							cout << "DAP AN D: ";
//							ChangeColor(15);
//						}
//					}
//					
//				}
//				if(s == RIGHT && sCheck == false)
//				{
//					if(i < sl - 1)
//					{
//						for(int i = 0; i < 30;i++)
//						{
//							gotoxy(20,5+i);
//							if(i == 4) i = 8;
//							if (i == 11) i = 14;
//							if (i == 17) i = 20;
//							if (i == 23) i = 26;
//							cout << "                                                                                                  ";
//						}
//						gotoxy(6,16-2);
//						cout << "DAP AN A: ";
//						gotoxy(19,15-2);
//						veKhung(5,100);
//						gotoxy(6,22-2);
//						cout << "DAP AN B: ";
//						gotoxy(19,21-2);
//						veKhung(5,100);
//						gotoxy(6,28-2);
//						cout << "DAP AN C: ";
//						gotoxy(19,27-2);
//						veKhung(5,100);
//						gotoxy(6,34-2);
//						cout << "DAP AN D: ";
//						i++;
//						NODECH ch = Search_CH(dsch,*arr[i]);
//						InNDCH(ch->info.noiDung);
//						gotoxy(20,14);
//						InDA_XemCH(ch->info.A);
//						gotoxy(20,20);
//						InDA_XemCH(ch->info.B);
//						gotoxy(20,26);
//						InDA_XemCH(ch->info.C);
//						gotoxy(20,32);
//						InDA_XemCH(ch->info.D);
//						if(ch->info.dapAn == "A")
//						{
//							ChangeColor(240);
//							gotoxy(6,16-2);
//							cout << "DAP AN A: ";
//							ChangeColor(15);
//						}
//						else if(ch->info.dapAn == "B")
//						{
//							ChangeColor(240);
//							gotoxy(6,22-2);
//							cout << "DAP AN B: ";
//							ChangeColor(15);
//						}
//						else if(ch->info.dapAn == "C")
//						{
//							ChangeColor(240);
//							gotoxy(6,28-2);
//							cout << "DAP AN C: ";
//							ChangeColor(15);
//						}
//						else if(ch->info.dapAn == "D")
//						{
//							ChangeColor(240);
//							gotoxy(6,34-2);
//							cout << "DAP AN D: ";
//							ChangeColor(15);
//						}
//					}
//				}
				if(s == ENTER)
				{
					NODECH ch = Search_CH(dsch,*arr[state + page*10]);
					gotoxy(132,2);
					veKhung(9,33);
					gotoxy(135,4);
					cout << "MA MON HOC: ";
					gotoxy(150,4);
					cout << ch->info.maMH;
					gotoxy(135,7);
					cout << "ID CAU HOI: ";
					gotoxy(150,7);
					cout << ch->id;
					gotoxy(5,2);
					veKhung(36,125);
					gotoxy(6,7-2);
					cout << "NOI DUNG CH: ";
					gotoxy(19,6-2);
					veKhung(7,100);
					gotoxy(6,16-2);
					cout << "DAP AN A: ";
					gotoxy(19,15-2);
					veKhung(5,100);
					gotoxy(6,22-2);
					cout << "DAP AN B: ";
					gotoxy(19,21-2);
					veKhung(5,100);
					gotoxy(6,28-2);
					cout << "DAP AN C: ";
					gotoxy(19,27-2);
					veKhung(5,100);
					gotoxy(6,34-2);
					cout << "DAP AN D: ";
					gotoxy(19,33-2);
					veKhung(5,100);
					InNDCH(ch->info.noiDung);
					gotoxy(20,14);
					InDA_XemCH(ch->info.A);
					gotoxy(20,20);
					InDA_XemCH(ch->info.B);
					gotoxy(20,26);
					InDA_XemCH(ch->info.C);
					gotoxy(20,32);
					InDA_XemCH(ch->info.D);
					if(ch->info.dapAn == "A")
					{
						ChangeColor(240);
						gotoxy(6,16-2);
						cout << "DAP AN A: ";
						ChangeColor(15);
					}
					else if(ch->info.dapAn == "B")
					{
						ChangeColor(240);
						gotoxy(6,22-2);
						cout << "DAP AN B: ";
						ChangeColor(15);
					}
					else if(ch->info.dapAn == "C")
					{
						ChangeColor(240);
						gotoxy(6,28-2);
						cout << "DAP AN C: ";
						ChangeColor(15);
					}
					else if(ch->info.dapAn == "D")
					{
						ChangeColor(240);
						gotoxy(6,34-2);
						cout << "DAP AN D: ";
						ChangeColor(15);
					}
				}
				batPhim(s,sCheck);
			}
			// in lai
			system("cls");
			gotoxy(130,26);
			vekhungTB(10,36);
			veNut(3,15,150,5,"Them CH",20);
			veNut(3,15,150,10,"Xoa CH",20);
			veNut(3,15,150,15,"Xem CH",240);
			veNut(3,15,150,20,"Xem CH theo mon",20);
			gotoxy(5,2);
			vekhungDSCH(34,120,5);
			InDSCH(dsch,page,arr);
			gotoxy(7,6);
			cout << muiten;
			state = 0;
		}
	batPhim(s,sCheck);
	}
	for(int i = 0; i < 10; i++)
	{
		gotoxy(7,6+i*3);
		cout << " ";
	}
}
// ==================== XEM CAU HOI ==========================
void XemCauHoi (NODECH &dsch, int *arr[], int &idlonnhat)
{
	string tb;
	int page = 0;
	int sl = countNode(dsch);
	if(sl == 0)
	{
		tb = "Danh sach cau hoi hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		XemCH(dsch,page,arr,idlonnhat);
	}
}
// ==================== NHAP MA MON ==========================
monHoc *NhapMaMHThem (NODECH dsch, DSMH dsm, int *arr [])
{
	system("cls");
	gotoxy(5,2);
	vekhungDS(34,120,2);
	gotoxy(30,3);
	cout << "MA MON HOC";
	gotoxy(90,3);
	cout << "TEN MON HOC";
	string tb;
	int page = 0;
	int maxpage;
	InDSMon(dsm,page);
	string mamon;
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMon(dsm,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMon(dsm,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsm.m[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			// chon ma mon, in menu nhap cau hoi them
			return dsm.m[state + page*10];
		}
	batPhim(s,sCheck);
	}
	return NULL;
}	
// ==================== NHAP CAU HOI THEM ==========================
void NhapCHThem(NODECH &dsch,monHoc *mh, int *arr[], int arr1[], int arr2[])
{
	gotoxy(5+(125 - mh->tenMH.length())/2,1);
	cout << mh->tenMH;
	vekhungThemCH();
	gotoxy(130,26);
	vekhungTB(10,36);
	cauHoi ch;
	int state = 0;
	int n;
	int dem;
	string temp;
	char s;
	bool sCheck;
	gotoxy(20,5);
	//gotoxy(20,14);			//A
	//gotoxy(20,20);			//B
	//gotoxy(20,26);			//C
	//gotoxy(20,32);			//D
	int hdnd,tdnd,hda,tda,hdb,tdb,hdc,tdc,hdd,tdd;
	hdnd = 20;
	tdnd = 5;
	hda = 20;
	tda = 14;
	hdb = 20;
	tdb = 20;
	hdc = 20;
	tdc = 26;
	hdd = 20;
	tdd = 32;
	HienConTro();
	batPhim(s,sCheck);
	while(1)
	{
		if(s == ESC)
		{
			if(Exit(s,sCheck) == true)
			{
				break;
			}
			else
			{
				switch(state)
				{
					case 0:
						{
							HienConTro();
							gotoxy(hdnd,tdnd);
							break;
						}
					case 1:
						{
							HienConTro();
							gotoxy(hda,tda);
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(hdb,tdb);
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(hdc,tdc);
							break;
						}
					case 4:
						{
							HienConTro();
							gotoxy(hdd,tdd);
							break;
						}
					case 5:
						{
							veNut(3,11,59,38,"LUU",30);
							HienConTro();
							gotoxy(hdd,tdd);
							state = 4;
							break;
							
						}	
				}
				HienConTro();
				batPhim(s,sCheck);
			}
		}
		if(s == UP && sCheck == false)
		{
			if(state > 0)
			{
				switch(state)
				{
					case 1:
						{
							HienConTro();
							gotoxy(hdnd,tdnd);
							state--;
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(hda,tda);
							state--;
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(hdb,tdb);
							state--;
							break;
						}
					case 4:
						{
							HienConTro();
							gotoxy(hdc,tdc);
							state--;
							break;
						}
					case 5:
						{
							veNut(3,11,59,38,"LUU",30);
							HienConTro();
							gotoxy(hdd,tdd);
							state--;
							break;
						}	
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state < 5)
			{
				switch(state)
				{
					case 0:
						{
							HienConTro();
							gotoxy(hda,tda);
							state ++;
							break;
						}
					case 1:
						{
							HienConTro();
							gotoxy(hdb,tdb);
							state ++;
							break;
						}
					case 2:
						{
							HienConTro();
							gotoxy(hdc,tdc);
							state ++;
							break;
						}
					case 3:
						{
							HienConTro();
							gotoxy(hdd,tdd);
							state ++;
							break;
						}
					case 4:
						{
							AnConTro();
							veNut(3,11,59,38,"LUU",240);
							state ++;
							break;
						}	
				}
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9') || (s == '?') || (s == ','))  && sCheck == true)
		{
			HienConTro();
			switch(state)
			{
				case 0:
					{
						if(ch.noiDung.length() < 280)
						{
							if(wherex() == 115 && wherey() == 5 )
							{
								n = ch.noiDung.length()-1;
								temp = "";
								if(ch.noiDung[n] == ' ')
								{
									gotoxy(20,7);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
								else
								{
									while(ch.noiDung[n] != ' ')
									{
										temp += ch.noiDung[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
										dem = n;
									}
									dem++;
									temp = DaoChuoi(temp);
									gotoxy(20,7);
									cout << temp;
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
							}
							else if (wherex() == 115 && wherey() == 7)
							{
								n = ch.noiDung.length()-1;
								temp = "";
								if(ch.noiDung[n] == ' ')
								{
									gotoxy(20,9);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
								else
								{
									while(ch.noiDung[n] != ' ')
									{
										temp += ch.noiDung[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,9);
									cout << temp;
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.noiDung += InHoa(s);
							}
						}
						hdnd = wherex();
						tdnd = wherey();
						break;
					}
				case 1:	
					{
						if(ch.A.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.A.length()-1;
								temp = "";
								dem = 0;
								if(ch.A[n] == ' ')
								{
									gotoxy(20,16);
									cout << InHoa(s);
									ch.A += InHoa(s);
								}
								else
								{
									while(ch.A[n] != ' ')
									{
										temp += ch.A[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,16);
									cout << temp;
									cout << InHoa(s);
									ch.A += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.A += InHoa(s);
							}
						}
						hda = wherex();
						tda = wherey();
						break;
					}
				case 2:
					{
						if(ch.B.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.B.length()-1;
								temp = "";
								dem = 0;
								if(ch.B[n] == ' ')
								{
									gotoxy(20,22);
									cout << InHoa(s);
									ch.B += InHoa(s);
								}
								else
								{
									while(ch.B[n] != ' ')
									{
										temp += ch.B[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,22);
									cout << temp;
									cout << InHoa(s);
									ch.B += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.B += InHoa(s);
							}	
						}
						hdb = wherex();
						tdb = wherey();
						break;
					}
				case 3:
					{
						if(ch.C.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.C.length()-1;
								temp = "";
								dem = 0;
								if(ch.C[n] == ' ')
								{
									gotoxy(20,28);
									cout << InHoa(s);
									ch.C += InHoa(s);
								}
								else
								{
									while(ch.C[n] != ' ')
									{
										temp += ch.C[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,28);
									cout << temp;
									cout << InHoa(s);
									ch.C += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.C += InHoa(s);
							}	
						}
						hdc = wherex();
						tdc = wherey();
						break;
					}
				case 4:
					{
						if(ch.D.length() < 180)
						{
							if(wherex() == 115)
							{
								n = ch.D.length()-1;
								temp = "";
								dem = 0;
								if(ch.D[n] == ' ')
								{
									gotoxy(20,34);
									cout << InHoa(s);
									ch.D += InHoa(s);
								}
								else
								{
									while(ch.D[n] != ' ')
									{
										temp += ch.D[n];
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(wherex()-1,wherey());
										n--;
									}
									temp = DaoChuoi(temp);
									gotoxy(20,34);
									cout << temp;
									cout << InHoa(s);
									ch.D += InHoa(s);
								}
							}
							else
							{
								cout << InHoa(s);
								ch.D += InHoa(s);
							}	
						}
						hdd = wherex();
						tdd = wherey();
						break;
					}
								
			}
		}
		if(s == ' ')
		{
			switch(state)
				{
					case 0:
						{
							if(ch.noiDung.length() == 0)
							{
								gotoxy(20+ch.noiDung.length()-1,5);
							}
							if(ch.noiDung[ch.noiDung.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.noiDung += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								if(wherey() == 5)
								{
									dem = wherex() - 20;
									gotoxy(20,7);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}
								else if(wherey() == 7)
								{
									gotoxy(20,9);
									cout << InHoa(s);
									ch.noiDung += InHoa(s);
								}									
							}
							hdnd = wherex();
							tdnd = wherey();
							break;	
						}
					case 1:
						{
							if(ch.A.length() == 0)
							{
								gotoxy(20+ch.A.length()-1,14);
							}
							if(ch.A[ch.A.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.A += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,16);
								cout << InHoa(s);
								ch.A += InHoa(s);
							}
							hda = wherex();
							tda = wherey();
							break;	
						}
					case 2:
						{
							if(ch.B.length() == 0)
							{
								gotoxy(20+ch.B.length()-1,20);
							}
							if(ch.B[ch.B.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.B += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,22);
								cout << InHoa(s);
								ch.B += InHoa(s);
							}
							hdb = wherex();
							tdb = wherey();
							break;	
						}
					case 3:
						{
							if(ch.C.length() == 0)
							{
								gotoxy(20+ch.C.length()-1,26);
							}
							if(ch.C[ch.C.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.C += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,28);
								cout << InHoa(s);
								ch.C += InHoa(s);
							}
							hdc = wherex();
							tdc = wherey();
							break;	
						}
					case 4:
						{
							if(ch.D.length() == 0)
							{
								gotoxy(20+ch.D.length()-1,32);
							}
							if(ch.D[ch.D.length()-1]!= ' ')
							{
								cout << InHoa(s);
								ch.D += InHoa(s);	
							}
							if(wherex() == 115 || wherex() == 116 || wherex() == 117)
							{
								gotoxy(20,34);
								cout << InHoa(s);
								ch.D += InHoa(s);
							}
							hdd = wherex();
							tdd = wherey();
							break;	
						}				
				}
		}
		if (s == BACKSPACE)
		{
			switch(state)
			{
				case 0:
					{
						if (ch.noiDung.length() > 0)
						{
							if(wherex() == 20 && wherey() == 7)
							{
								gotoxy(20 + ch.noiDung.length(),5);
								hdnd = wherex();
								tdnd = wherey();
							}
							else if(wherex() == 20 && wherey() == 9)
							{
								gotoxy(20 + ch.noiDung.length() - dem,7);
								hdnd = wherex();
								tdnd = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.noiDung.erase(ch.noiDung.length()-1);
								hdnd = wherex();
								tdnd = wherey();
							}
						}
						break;
					}
				case 1:
					{
						if (ch.A.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.A.length(),14);
								hda = wherex();
								tda = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.A.erase(ch.A.length()-1);
								hda = wherex();
								tda = wherey();
							}
						}
						break;
					}
				case 2:
					{
						if (ch.B.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.B.length(),20);
								hdb = wherex();
								tdb = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.B.erase(ch.B.length()-1);
								hdb = wherex();
								tdb = wherey();
							}
						}
						break;
					}
				case 3:
					{
						if (ch.C.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.C.length(),26);
								hdc = wherex();
								tdc = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.C.erase(ch.C.length()-1);
								hdc = wherex();
								tdc = wherey();
							}
						}
						break;					
					}
				case 4:
					{
						
						if (ch.D.length() > 0)
						{
							if(wherex() == 20)
							{
								gotoxy(20 + ch.D.length(),32);
								hdd = wherex();
								tdd = wherey();
							}
							else
							{
								AnConTro();
								gotoxy(wherex()-1,wherey());
								cout << " ";
								gotoxy(wherex()-1,wherey());
								HienConTro();
								ch.D.erase(ch.D.length()-1);
								hdd = wherex();
								tdd = wherey();
							}
						}
						break;
					}		
			}
		}
		if ( s == ENTER)
		{
			if(state == 5)
			{
				if(ch.noiDung.length() == 0 || ch.A.length() == 0 || ch.B.length() == 0 || ch.C.length() == 0 || ch.D.length() == 0)
				{
					string tb = "Vui long nhap day du thong tin";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
				else
				{
					int state1 = 0;
					string da = "A";
					gotoxy(4,14);
					cout << muiten;
					batPhim(s,sCheck);
					while(1)
					{
						if(s == UP && sCheck == false)
						{
							switch(state1)
							{
								case 1:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(4,14);
										cout << muiten;
										state1--;
										da = "A";
										break;
									}
								case 2:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(4,20);
										cout << muiten;
										state1--;
										da = "B";
										break;
									}
								case 3:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(4,26);
										cout << muiten;
										state1--;
										da = "C";
										break;
									}
							}	
						}
						if(s == DOWN && sCheck == false)
						{
							switch(state1)
							{
								case 0:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(4,20);
										cout << muiten;
										state1++;
										da = "B";
										break;
									}
								case 1:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(4,26);
										cout << muiten;
										state1++;
										da = "C";
										break;
									}
								case 2:
									{
										gotoxy(wherex()-1,wherey());
										cout << " ";
										gotoxy(4,32);
										cout << muiten;
										state1++;
										da = "D";
										break;
									}
							}
						}
						if(s == ENTER)
						{
							ch.maMH = mh->maMH;
							ch.dapAn = da;
							Them1CauHoi(dsch,ch,maxid,arr1,arr2);
							string tb = "Them cau hoi thanh cong!";
							InTB(tb,132,30);
							AnConTro();
							Sleep(750);
							XoaTB(130,26);
							break;
						}
						batPhim(s,sCheck);
					}
					for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				}
				for(int i = 0; i < 30;i++)
				{
					gotoxy(20,5+i);
					if(i == 4) i = 8;
					if (i == 11) i = 14;
					if (i == 17) i = 20;
					if (i == 23) i = 26;
					cout << "                                                                                                  ";
				}
				veNut(3,11,59,38,"LUU",30);
				ch.noiDung = "";
				ch.A = "";
				ch.B = "";
				ch.C = "";
				ch.D = "";
				state = 0;
				gotoxy(20+ch.noiDung.length(),5);
				HienConTro();
				break;
			}
		}
		batPhim(s,sCheck);
	}
}
// ==================== THEM CAU HOI ==========================
void ThemCH(NODECH &dsch, DSMH dsm, int *arr[], int arr1[], int arr2[])
{
	ChangeColor(15);
	int n = countNode(dsch);
	if(n  == 1000)
	{
		gotoxy(130,26);
		string tb = "Khong the them cau hoi, danh sach cau hoi da day";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		monHoc *mh = NhapMaMHThem(dsch,dsm,arr);
		if(mh == NULL)
		{
			return;
		}
		//nhap cau hoi
		NhapCHThem(dsch,mh,arr,arr1,arr2);
	}
}
// ==================== XEM CH THEO MON ==========================
void XemCHtheoMon (DSMH dsm, NODECH dsch)
{
	system("cls");
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(130,26);
	vekhungTB(10,36);
	int page = 0;
	char s;
	bool sCheck;
	gotoxy(5,2);
	int state = 0;
	vekhungDS(34,120,2);	
	gotoxy(30,3);
	cout << "MA MON HOC";
	gotoxy(90,3);
	cout << "TEN MON HOC";
	if (dsm.somon != 0) 
	{
		InDSMon(dsm,page);
	}
	int maxpage;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMon(dsm,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMon(dsm,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsm.m[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			//vao danh sach cau hoi
			int *arr[10000];
			int dem=0;
			NODECH Stack[STACKSIZE];
			NODECH p = dsch;
			int sp = -1;
			do //duyet cay LNR
			{ 
				while (p != NULL)
				{
					Stack[++sp]= p;
					p = p->pLeft;
				}
				if (sp != -1)
				{
					p = Stack[sp--];
					//in vao danh sach ch
					if(p->info.maMH.compare(dsm.m[state + page*10]->maMH) == 0)
					{
						arr[dem] = new int;
						*arr[dem] = p->id;
						dem++;
					}
					p = p->pRight;
				}
				else break;
			} while (1);
			if(dem == 0)
			{
				string tb = "Danh sach cau hoi hien tai dang trong!";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
			}
			else 
			{
				system("cls");
				int index = 0;
				//batPhim(s,sCheck);
				while (s != ESC)
				{
					if(s == LEFT && sCheck == false)
					{
						if(index > 0)
						{
							index--;
							for(int i = 0; i < 30;i++)
							{
								gotoxy(20,5+i);
								if(i == 4) i = 8;
								if (i == 11) i = 14;
								if (i == 17) i = 20;
								if (i == 23) i = 26;
								cout << "                                                                                                  ";
							}
							NODECH ch = Search_CH(dsch,*arr[index]);
							gotoxy(132,2);
							veKhung(9,33);
							gotoxy(135,4);
							cout << "MA MON HOC: ";
							gotoxy(150,4);
							cout << ch->info.maMH;
							gotoxy(135,7);
							cout << "ID CAU HOI: ";
							gotoxy(150,7);
							cout << ch->id;
							gotoxy(5,2);
							gotoxy(6,16-2);
							cout << "DAP AN A: ";
							gotoxy(19,15-2);
							veKhung(5,100);
							gotoxy(6,22-2);
							cout << "DAP AN B: ";
							gotoxy(19,21-2);
							veKhung(5,100);
							gotoxy(6,28-2);
							cout << "DAP AN C: ";
							gotoxy(19,27-2);
							veKhung(5,100);
							gotoxy(6,34-2);
							cout << "DAP AN D: ";
							InNDCH(ch->info.noiDung);
							gotoxy(20,14);
							InDA_XemCH(ch->info.A);
							gotoxy(20,20);
							InDA_XemCH(ch->info.B);
							gotoxy(20,26);
							InDA_XemCH(ch->info.C);
							gotoxy(20,32);
							InDA_XemCH(ch->info.D);
							if(ch->info.dapAn == "A")
							{
								ChangeColor(240);
								gotoxy(6,16-2);
								cout << "DAP AN A: ";
								ChangeColor(15);
							}
							else if(ch->info.dapAn == "B")
							{
								ChangeColor(240);
								gotoxy(6,22-2);
								cout << "DAP AN B: ";
								ChangeColor(15);
							}
							else if(ch->info.dapAn == "C")
							{
								ChangeColor(240);
								gotoxy(6,28-2);
								cout << "DAP AN C: ";
								ChangeColor(15);
							}
							else if(ch->info.dapAn == "D")
							{
								ChangeColor(240);
								gotoxy(6,34-2);
								cout << "DAP AN D: ";
								ChangeColor(15);
							}
						}
						
					}
					if(s == RIGHT && sCheck == false)
					{
						if(index < dem - 1)
						{
							index++;
							for(int i = 0; i < 30;i++)
							{
								gotoxy(20,5+i);
								if(i == 4) i = 8;
								if (i == 11) i = 14;
								if (i == 17) i = 20;
								if (i == 23) i = 26;
								cout << "                                                                                                  ";
							}
							NODECH ch = Search_CH(dsch,*arr[index]);
							gotoxy(132,2);
							veKhung(9,33);
							gotoxy(135,4);
							cout << "MA MON HOC: ";
							gotoxy(150,4);
							cout << ch->info.maMH;
							gotoxy(135,7);
							cout << "ID CAU HOI: ";
							gotoxy(150,7);
							cout << ch->id;
							gotoxy(5,2);
							gotoxy(6,16-2);
							cout << "DAP AN A: ";
							gotoxy(19,15-2);
							veKhung(5,100);
							gotoxy(6,22-2);
							cout << "DAP AN B: ";
							gotoxy(19,21-2);
							veKhung(5,100);
							gotoxy(6,28-2);
							cout << "DAP AN C: ";
							gotoxy(19,27-2);
							veKhung(5,100);
							gotoxy(6,34-2);
							cout << "DAP AN D: ";
							InNDCH(ch->info.noiDung);
							gotoxy(20,14);
							InDA_XemCH(ch->info.A);
							gotoxy(20,20);
							InDA_XemCH(ch->info.B);
							gotoxy(20,26);
							InDA_XemCH(ch->info.C);
							gotoxy(20,32);
							InDA_XemCH(ch->info.D);
							if(ch->info.dapAn == "A")
							{
								ChangeColor(240);
								gotoxy(6,16-2);
								cout << "DAP AN A: ";
								ChangeColor(15);
							}
							else if(ch->info.dapAn == "B")
							{
								ChangeColor(240);
								gotoxy(6,22-2);
								cout << "DAP AN B: ";
								ChangeColor(15);
							}
							else if(ch->info.dapAn == "C")
							{
								ChangeColor(240);
								gotoxy(6,28-2);
								cout << "DAP AN C: ";
								ChangeColor(15);
							}
							else if(ch->info.dapAn == "D")
							{
								ChangeColor(240);
								gotoxy(6,34-2);
								cout << "DAP AN D: ";
								ChangeColor(15);
							}
						}
					}
					if(s == ENTER)
					{
						NODECH ch = Search_CH(dsch,*arr[index]);
						gotoxy(132,2);
						veKhung(9,33);
						gotoxy(135,4);
						cout << "MA MON HOC: ";
						gotoxy(150,4);
						cout << ch->info.maMH;
						gotoxy(135,7);
						cout << "ID CAU HOI: ";
						gotoxy(150,7);
						cout << ch->id;
						gotoxy(5,2);
						veKhung(36,125);
						gotoxy(6,7-2);
						cout << "NOI DUNG CH: ";
						gotoxy(19,6-2);
						veKhung(7,100);
						gotoxy(6,16-2);
						cout << "DAP AN A: ";
						gotoxy(19,15-2);
						veKhung(5,100);
						gotoxy(6,22-2);
						cout << "DAP AN B: ";
						gotoxy(19,21-2);
						veKhung(5,100);
						gotoxy(6,28-2);
						cout << "DAP AN C: ";
						gotoxy(19,27-2);
						veKhung(5,100);
						gotoxy(6,34-2);
						cout << "DAP AN D: ";
						gotoxy(19,33-2);
						veKhung(5,100);
						InNDCH(ch->info.noiDung);
						gotoxy(20,14);
						InDA_XemCH(ch->info.A);
						gotoxy(20,20);
						InDA_XemCH(ch->info.B);
						gotoxy(20,26);
						InDA_XemCH(ch->info.C);
						gotoxy(20,32);
						InDA_XemCH(ch->info.D);
						if(ch->info.dapAn == "A")
						{
							ChangeColor(240);
							gotoxy(6,16-2);
							cout << "DAP AN A: ";
							ChangeColor(15);
						}
						else if(ch->info.dapAn == "B")
						{
							ChangeColor(240);
							gotoxy(6,22-2);
							cout << "DAP AN B: ";
							ChangeColor(15);
						}
						else if(ch->info.dapAn == "C")
						{
							ChangeColor(240);
							gotoxy(6,28-2);
							cout << "DAP AN C: ";
							ChangeColor(15);
						}
						else if(ch->info.dapAn == "D")
						{
							ChangeColor(240);
							gotoxy(6,34-2);
							cout << "DAP AN D: ";
							ChangeColor(15);
						}
					}
					batPhim(s,sCheck);
				}
				//ve lai
				system("cls");
				gotoxy(50,46);
				cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
				gotoxy(130,26);
				vekhungTB(10,36);
				int page = 0;
				char s;
				bool sCheck;
				gotoxy(5,2);
				int state = 0;
				vekhungDS(34,120,2);	
				gotoxy(30,3);
				cout << "MA MON HOC";
				gotoxy(90,3);
				cout << "TEN MON HOC";
			}
			for(int i = 0; i < 10; i++)
			{
				gotoxy(7,6+i*3);
				cout << " ";
			}
			InDSMon(dsm,page);
			state = 0;
			gotoxy(7,6);
			cout << muiten;	
		}
	batPhim(s,sCheck);
	}
	
}
// ==================== FUNCTION CH ==========================
void FunctionCH(NODECH &dsch, DSMH dsm,dslop dsl,int &idlonnhat, int arr1[], int arr2[])
{
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(130,26);
	vekhungTB(10,36);
	veNut(3,15,150,5,"Them CH",240);
	veNut(3,15,150,10,"Xoa CH",20);
	veNut(3,15,150,15,"Xem CH",20);
	veNut(3,15,150,20,"Xem CH theo mon",20);
	int page = 0;
	int maxpage;
	int hd;
	int td;
	int sl = countNode(dsch);
	int *arr [sl];
	for(int i = 0; i < sl; i++)
	{
		arr[i] = new int;
	}
	int i=0;
	NODECH Stack[STACKSIZE];
	NODECH p = dsch;
	int sp = -1;
	do
	{ 
		while (p != NULL)
		{
			Stack[++sp]= p;
			p = p->pLeft;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			//in vao danh sach ch
			*arr[i] = p->id;
			i++;
			p = p->pRight;
		}
		else break;
	} while (1);
	if(sl > 0)
	{
		idlonnhat = *arr[sl-1];	
	}
	gotoxy(5,2);
	vekhungDSCH(34,120,5);
	InDSCH(dsch,page,arr);
	int state = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(sl <= 10)
		{
			maxpage = 0;
		}
		else if(sl % 10 == 0) 
		{
			maxpage = sl/10 -1;
		}
		else maxpage = sl/10;
		if (s == UP && sCheck == false)
		{
			switch(state)
			{
			
			case 0:
				{
					break;
				}
			case 1:
				{
					state--;
					veNut(3,15,150,10,"Xoa CH",20);
					veNut(3,15,150,5,"Them CH",240);
					break;
				}
			case 2:
				{
					state--;
					veNut(3,15,150,15,"Xem CH",20);
					veNut(3,15,150,10,"Xoa CH",240);
					break;	
				}
			case 3:
				{
					state--;
					veNut(3,15,150,20,"Xem CH theo mon",20);
					veNut(3,15,150,15,"Xem CH",240);
					break;	
				}	
			}
		}
		if (s == DOWN && sCheck == false)
		{
			switch(state)
			{
			case 0:
				{
					state++;
					veNut(3,15,150,5,"Them CH",20);
					veNut(3,15,150,10,"Xoa CH",240);
					break;
				}
			case 1:
				{
					state++;
					veNut(3,15,150,10,"Xoa CH",20);
					veNut(3,15,150,15,"Xem CH",240);
					break;	
				}	
			case 2:
				{
					state++;
					veNut(3,15,150,15,"Xem CH",20);
					veNut(3,15,150,20,"Xem CH theo mon",240);
					break;
				}
			case 3:
				{
					break;
				}
			}
		}
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
					}
				page ++;
				InDSCH(dsch,page,arr);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                      ";
						gotoxy(54,6+i);
						cout << "                                                                    ";
						
					}
				page--;
				InDSCH(dsch,page,arr);
			}
		}
		if(s == ENTER)
		{
			switch(state)
			{
				case 0:
					{
						ThemCH(dsch,dsm,arr,arr1,arr2);
						int sl = countNode(dsch);
						for(int i = 0; i < sl; i++)
						{
							arr[i] = new int;
						}
						int i=0;
						NODECH Stack[STACKSIZE];
						NODECH p = dsch;
						int sp = -1;
						do
						{ 
							while (p != NULL)
							{
								Stack[++sp]= p;
								p = p->pLeft;
							}
							if (sp != -1)
							{
								p = Stack[sp--];
								//in vao danh sach ch
								*arr[i] = p->id;
								i++;
								p = p->pRight;
							}
							else break;
						} while (1);
						idlonnhat = *arr[sl-1];
						system("cls");
						AnConTro();
						gotoxy(130,26);
						vekhungTB(10,36);
						veNut(3,15,150,5,"Them CH",240);
						veNut(3,15,150,10,"Xoa CH",20);
						veNut(3,15,150,15,"Xem CH",20);
						veNut(3,15,150,20,"Xem CH theo mon",20);
						gotoxy(5,2);
						vekhungDSCH(34,120,5);
						InDSCH(dsch,page,arr);
						break;
					}
				case 1:
					{
						XoaCauHoi(dsch,arr,idlonnhat,dsl);
						AnConTro();
						break;
					}
				case 2:
					{
						XemCauHoi(dsch,arr,idlonnhat);
						AnConTro();
						break;
					}
				case 3: //goi dsm, chon mon, rot cau hoi theo mon vao, cho phep di chuyen trai phai
					{
						XemCHtheoMon(dsm,dsch);
						AnConTro();
						system("cls");
						AnConTro();
						gotoxy(130,26);
						vekhungTB(10,36);
						veNut(3,15,150,5,"Them CH",20);
						veNut(3,15,150,10,"Xoa CH",20);
						veNut(3,15,150,15,"Xem CH",20);
						veNut(3,15,150,20,"Xem CH theo mon",240);
						gotoxy(5,2);
						vekhungDSCH(34,120,5);
						InDSCH(dsch,page,arr);
						break;					
					}	
			}
		}
	batPhim(s,sCheck);
	}
}

// ==================== CAP NHAP MANG TGIAN DE IN ==========================
void insertarray(char *h, TG *j) 
{
	int temp = 0;
	temp = j->giay;
	h[7] = doichar(temp % 10);
	h[6] = doichar(temp /= 10);

	temp = j->phut;
	h[4] = doichar(temp % 10);
	h[3] = doichar(temp /= 10);

	temp = j->gio;
	h[1] = doichar(temp % 10);
	h[0] = doichar(temp /= 10);

}
// ==================== CAP NHAP THOI GIAN THI ==========================
bool changetime(TG *h)
{
	if (h->giay > 0) --h->giay;
	else if (h->phut > 0)
	{
		h->giay = 59;
		--h->phut;
	}
	else if (h->gio > 0)
	{
		--h->gio;
		h->phut = 59;
		h->giay = 59;
	}
	else return false;
	return true;
}
// ==================== HAM THAY THE COUT IN RA 1 CHUOI ==========================
void WriteBlockChar(char *Arraych,int x, int y,int color)
{
	CHAR_INFO *charater = new CHAR_INFO[8];
	for (int i = 0; i < 8; i++)
	{
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { 8,1 };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + 8 - 1,y + 1 - 1 }; // vung dem
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}
// ==================== IN DONG HO ==========================
void printClock(int tg)
{
	TG h;
	if(tg < 60)
	{
		h = { 0,tg,0};
	}
	else if (tg == 60)
	{
		h = { 1,0,0};
	}
	else
	{
		int gio = tg/60;
		int phut = tg%60;
		h = { gio,phut,0};
	}
	char a[8] = { '0','0',':','0','0',':','0','0'};
	while (stop)
	{
		if (changetime(&h) == false) stop = 0;
		insertarray(a, &h);
		WriteBlockChar(a, 115, 1,0x007|0x000);
		Sleep(1000);
	}
	return;
}
// ==================== NHAP TG THI ==========================
void NhapTG (int &tg, int &sct)
{
	system("cls");
	gotoxy(130,26);
	vekhungTB(10,36);
	string ntg;
	string nsct;
	vekhungNhapTG();
	gotoxy(68,20);
	char s;
	bool sCheck;
	int state = 0;
	HienConTro();
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(s == LEFT && sCheck == false)
		{
			if(state == 1)
			{
				gotoxy(68+ntg.length(),20);
				state --;
			}
		}
		if(s == RIGHT && sCheck == false)
		{
			if(state == 0)
			{
				gotoxy(112+nsct.length(),20);
				state ++;
			}
		}
		if((s >= '0' && s <= '9')  && sCheck == true)
		{
			if(state == 0 && ntg.length() < 3)
			{
				cout << s;
				ntg += s;	
			}
			else if(state == 1 && nsct.length() < 3)
			{
				cout << s;
				nsct +=s;
			}
		}
		if (s == BACKSPACE)
		{
			if (ntg.length() > 0 && state == 0)
			{
				AnConTro();
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(wherex()-1,wherey());
				HienConTro();
				ntg.erase(ntg.length()-1);
			}
			else if(nsct.length() > 0 && state == 1)
			{
				AnConTro();
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(wherex()-1,wherey());
				HienConTro();
				nsct.erase(nsct.length()-1);
			}	
		}
		if(s == ENTER)
		{
			if(ntg.length() == 0 || nsct.length() == 0)
			{
				string tb = "Thoi gian thi hoac so cau thi khong hop le";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);	
			}
			else
			{
				if(StringToInt(ntg) > 0 && StringToInt(nsct) > 0)
					{
						tg = StringToInt(ntg);
						sct = StringToInt(nsct);
						return;	
					}
				else
				{
					string tb = "Thoi gian thi hoac so cau thi phai lon hon '0'";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
				}
			}
			gotoxy(68,20);
			cout << "   ";
			gotoxy(112,20);
			cout << "   ";
			ntg = "";
			nsct = "";
			state = 0;
			gotoxy(68+ntg.length(),20);
			HienConTro();
		}
		batPhim(s,sCheck);
	}
//	return;
}
// ==================== NHAP MON THI ==========================
void NhapMonThi(DSMH dsm, int &tg, int &sct, string &monthi,bool &check)
{
	AnConTro();
	gotoxy(59,1);
	cout << "CHON MON THI";
	gotoxy(5,2);
	vekhungDS(34,120,2);
	gotoxy(30,3);
	cout << "MA MON HOC";
	gotoxy(90,3);
	cout << "TEN MON HOC";
	string tb;
	int maxpage;
	int page = 0;
	InDSMon(dsm,page);
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMon(dsm,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMon(dsm,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsm.m[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			//nhap tg
			NhapTG(tg,sct);
			monthi = dsm.m[state + page*10 ]->maMH;
			if(tg > 0 && sct > 0)
			{
				check = true;
				return;
			}
			gotoxy(59,1);
			cout << "CHON MON THI";
			gotoxy(5,2);
			vekhungDS(34,120,2);
			gotoxy(30,3);
			cout << "MA MON HOC";
			gotoxy(90,3);
			cout << "TEN MON HOC";
			InDSMon(dsm,page);
			state = 0;
			gotoxy(7,6);
			cout << muiten;
			AnConTro();
		}	
	batPhim(s,sCheck);
	}
	check = false;
	return;
}
// ==================== VE KHUNG DAP AN THI SINH DA CHON ==========================
void VeKhungDA(int page, int sct,CTdethi ctdt)
{
	gotoxy(15,38);
	int socau;
	if(sct <= 10)
	{
		socau = sct;
	}
	else if((page + 1)*10 <= sct)
	{
		socau = 10;
	}
	else socau = sct%10;
	int rong = socau*10;
	int x = rong/socau;
	int dem = 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socau)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socau)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == 5)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socau)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socau)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socau)) dem++;
			if(dem == socau) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
	int temp = page*10 + 1;
	for(int i = 0; i < socau ; i++)
	{
		gotoxy(15 + 4 + (i*10),38+1);
		cout << temp;
		temp ++;
	}
	for(int i = 0; i < socau; i++)
	{
		gotoxy(15 + 4 + (i*10),38+3);
		if(ctdt.dapan[(page*10) + i] == 1)
		{
			cout << "A";
		}
		else if (ctdt.dapan[(page*10) + i] == 2)
		{
			cout << "B";
		}
		else if(ctdt.dapan[(page*10) + i] == 3)
		{
			cout << "C";
		}
		else if(ctdt.dapan[(page*10) + i] == 4)
		{
			cout << "D";
		}
		else continue;
	}
}
// ==================== XOA KHUNG DAP AN THI SINH DA CHON ==========================
void XoaDA()
{
	for(int i = 0; i < 6; i++)
	{
		gotoxy(14,38+i);
		cout <<"                                                                                                     "; 
	}
}
// ==================== CAP NHAP BANG DAP AN THI SINH DA CHON ==========================
void InDA(int page, int sct, CTdethi ctdt)
{
	int socau;
	if(sct <= 10)
	{
		socau = sct;
	}
	else if((page + 1)*10 <= sct)
	{
		socau = 10;
	}
	else socau = sct%10;
	for(int i = 0; i < socau; i++)
	{
		gotoxy(15 + 4 + (i*10),38+3);
		if(ctdt.dapan[(page*10) + i] == 1)
		{
			cout << "A";
		}
		else if (ctdt.dapan[(page*10) + i] == 2)
		{
			cout << "B";
		}
		else if(ctdt.dapan[(page*10) + i] == 3)
		{
			cout << "C";
		}
		else if(ctdt.dapan[(page*10) + i] == 4)
		{
			cout << "D";
		}
		else continue;
	}
}
void In1CauThi (NODECH dsch, int id)
{
	for(int i = 0; i < 30;i++)
	{
		gotoxy(20,5+i);
		if(i == 4) i = 8;
		if (i == 11) i = 14;
		if (i == 17) i = 20;
		if (i == 23) i = 26;
		cout << "                                                                                                  ";
	}
	NODECH ch = Search_CH(dsch,id);
	InNDCH(ch->info.noiDung);
	gotoxy(20,14);
	InDA_XemCH(ch->info.A);
	gotoxy(20,20);
	InDA_XemCH(ch->info.B);
	gotoxy(20,26);
	InDA_XemCH(ch->info.C);
	gotoxy(20,32);
	InDA_XemCH(ch->info.D);
}
// ==================== LAY DE THI THEO MA MON HOC ==========================
int *LayDeThi(NODECH dsch, int sct, string mamon)
{
	int temp[10000];
	int *dethi = new int [sct];
	int dem = 0;
	int i=0;
	NODECH Stack[STACKSIZE];
	NODECH p = dsch;
	int sp = -1;
	do
	{ 
		while (p != NULL)
		{
			Stack[++sp]= p;
			p = p->pLeft;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			//in vao danh sach ch
			if(p->info.maMH.compare(mamon) == 0)
			{
				temp[dem] = p->id;
				dem++;
			}
			i++;
			p = p->pRight;
		}
		else break;
	} while (1);
	if(dem < sct)
	{
		string tb = "Khong du cau hoi de thi";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
		return NULL;
	}
	else
	{
		for(int j = 0; j < sct; j++)
		{
			int r = random(0,dem-j-1);
//			dethi[j] = new int;
//			*dethi[j] = temp[r];
			dethi[j] = temp[r];
			//doi vi tri
//			int temp1 = temp[r];
//			temp[r] = temp[dem-1-j];
//			temp[dem-1-j] = temp1;
			swap(temp[r],temp[dem-1-j]); 
		}
	}
//	int *arr = new int[sct];
//	for(int j = 0; j < sct; j++)
//	{
//		arr[j] = *dethi[j];
//	}
	return dethi;
}
// ==================== TINH DIEM ==========================
int TinhDiem(CTdethi ctdt, NODECH dsch)
{
	int socaudung = 0;
	string dapan="";
	for(int i = 0; i < ctdt.sct ; i++)
	{
		NODECH p = Search_CH(dsch,ctdt.bode[i]);
		if(ctdt.dapan[i] == 1)
		{
			dapan = "A";
		}
		else if(ctdt.dapan[i] == 2)
		{
			dapan = "B";
		}
		else if(ctdt.dapan[i] == 3)
		{
			dapan = "C";
		}
		else if(ctdt.dapan[i] == 4)
		{
			dapan = "D";
		}
		if(p->info.dapAn.compare(dapan) == 0)
		{
			socaudung++;
		}
		dapan="";
	}
	return socaudung;
}
void ketThucBaiThi (CTdethi ctdt, NODECH dsch)
{
	system("cls");
	gotoxy(15,7);
	cout << "	 _______  _______  __    _  _______  ______    _______  _______  __   __  ___      _______  _______  ___   _______  __    _  __  ";
	gotoxy(15,8);
	cout << "	|       ||       ||  |  | ||       ||    _ |  |   _   ||       ||  | |  ||   |    |   _   ||       ||   | |       ||  |  | ||  | ";
	gotoxy(15,9);
	cout << "	|       ||   _   ||   |_| ||    ___||   | ||  |  |_|  ||_     _||  | |  ||   |    |  |_|  ||_     _||   | |   _   ||   |_| ||  | ";
	gotoxy(15,10);
	cout << "	|       ||  | |  ||       ||   | __ |   |_||_ |       |  |   |  |  |_|  ||   |    |       |  |   |  |   | |  | |  ||       ||  | ";
	gotoxy(15,11);
	cout << "	|      _||  |_|  ||  _    ||   ||  ||    __  ||       |  |   |  |       ||   |___ |       |  |   |  |   | |  |_|  ||  _    ||__| ";
	gotoxy(15,12);
	cout << "	|     |_ |       || | |   ||   |_| ||   |  | ||   _   |  |   |  |       ||       ||   _   |  |   |  |   | |       || | |   | __  ";
	gotoxy(15,13);
	cout << "	|_______||_______||_|  |__||_______||___|  |_||__| |__|  |___|  |_______||_______||__| |__|  |___|  |___| |_______||_|  |__||__| ";

	string scd = IntToString(TinhDiem(ctdt,dsch)*10);
	string sct = IntToString(ctdt.sct);
	gotoxy(50,25);
	cout << "CHUC MUNG BAN DA HOAN THANH BAI THI!";
	gotoxy(50,30);
	ChangeColor(240);
	cout << "DIEM CUA BAN LA: " << chia(scd,sct);
	ChangeColor(15);
	gotoxy(50,35);
	cout << "Bam phim bat ki de thoat!";
	getch();
}
// ==================== FUNCTION THI ==========================
void FunctionThi(NODECH dsch,int tg, int sct, string monthi,string &diem, CTdethi &ctdt)
{
	if(sct == 0 && tg == 0)
	{
		return ;
	}
	ctdt.sct = sct;
	ctdt.tg = tg;
	for(int i = 0; i < sct; i++)
	{
		ctdt.dapan[i] = 0;
	}
	ctdt.bode = LayDeThi(dsch,sct,monthi);
	if(ctdt.bode == NULL)
	{
		return;
	}
	thread clock;
	clock = thread(printClock,tg);
	gotoxy(40,46);
	cout << "ENTER: Chon       F1: Nop bai       Left/Right: Di chuyen cau hoi     ";
	gotoxy(50,1);
	cout << "BAI THI MON: " << monthi;
	if(ctdt.bode == NULL)
	{
		return ;
	}
	int cauthi = 0;
	int page = 0;
	int maxpage;
	if(sct <= 10)
	{
		maxpage = 0;
	}
	else if(sct > 10 && sct % 10 == 0)
	{
		maxpage = (sct/10) - 1;
	}
	else maxpage = sct/10;
//	for(int i = 0; i < sct; i++)
//	{
//		cout << ctdt.bode[i] << " ";
//	}
//	system("pause");
	gotoxy(5,2);
	veKhung(36,125);
	gotoxy(6,7-2);
	cout << "NOI DUNG CH: ";
	gotoxy(19,6-2);
	veKhung(7,100);
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(19,15-2);
	veKhung(5,100);
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(19,21-2);
	veKhung(5,100);
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(19,27-2);
	veKhung(5,100);
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	gotoxy(19,33-2);
	veKhung(5,100);
	NODECH ch = Search_CH(dsch,ctdt.bode[cauthi]);
	InNDCH(ch->info.noiDung);
	gotoxy(20,14);
	InDA_XemCH(ch->info.A);
	gotoxy(20,20);
	InDA_XemCH(ch->info.B);
	gotoxy(20,26);
	InDA_XemCH(ch->info.C);
	gotoxy(20,32);
	InDA_XemCH(ch->info.D);
	VeKhungDA(page,sct,ctdt);
	gotoxy(7,1);
	cout << "CAU " << cauthi + 1;
	gotoxy(19 + (cauthi%10)*10,44);
	cout << muitenlen;
	gotoxy(4,14);
	cout << muiten;
	AnConTro();
	int state1 = 0;
	char s;
	bool sCheck;
	bool qt = false;
	batPhim(s,sCheck);
	string da = "A";
	gotoxy(19,44);
	cout << muitenlen;
	gotoxy(4,14);
	while ((cauthi < sct ) && s != ESC )
	{
		
		if(s == PAGEUP)
		{
			if(page > 0 )
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi -= 10;
				gotoxy(19 + (cauthi%10)*10,44);
				cout << muitenlen;
				page --;
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(dsch,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					cout << muiten;
				}
			}
		}
		if(s == PAGEDOWN)
		{
			if(page < maxpage )
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				if(cauthi < sct - 10)
				{
					cauthi += 10;
					gotoxy(19 + (cauthi%10)*10,44);
					cout << muitenlen;
				}
				else cauthi += sct - cauthi - 1;
				gotoxy(19 + (cauthi%10)*10,44);
				cout << muitenlen;
				page ++;
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(dsch,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					cout << muiten;
				}
			}
		}
		if (s == LEFT && sCheck == false)
		{
			if(page > 0 && (cauthi + 1) % 10 == 1)
			{
				page--;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				qt = false;
			}
			else InDA(page,sct,ctdt);
			if (cauthi > 0)
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi--;
				gotoxy(19 + (cauthi%10)*10,44);
				cout << muitenlen;
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(dsch,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					cout << muiten;
				}
			}
		}
		if (s == RIGHT && sCheck == false)
		{
			if(page < maxpage && (cauthi + 1) % 10 == 0)
			{
				page++;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,sct,ctdt);
				qt = false;
			}
			else InDA(page,sct,ctdt);
			if (cauthi < sct - 1)
			{
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi++;
				gotoxy(19 + (cauthi%10)*10,44);
				cout << muitenlen;
				gotoxy(10,1);
				cout << "            ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(dsch,ctdt.bode[cauthi]);
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					cout << muiten;
				}
			}
		}
		if(s == UP && sCheck == false)
		{
			switch(state1)
			{
				case 1:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(4,14);
						cout << muiten;
						state1--;
						da = "A";
						break;
					}
				case 2:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(4,20);
						cout << muiten;
						state1--;
						da = "B";
						break;
					}
				case 3:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(4,26);
						cout << muiten;
						state1--;
						da = "C";
						break;
					}
			}	
		}
		if(s == DOWN && sCheck == false)
		{
			switch(state1)
			{
				case 0:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						gotoxy(4,14);
						cout << " ";
						gotoxy(4,20);
						cout << muiten;
						state1++;
						da = "B";
						break;
					}
				case 1:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(4,26);
						cout << muiten;
						state1++;
						da = "C";
						break;
					}
				case 2:
					{
						AnConTro();
						gotoxy(wherex()-1,wherey());
						cout << " ";
						gotoxy(4,32);
						cout << muiten;
						state1++;
						da = "D";
						break;
					}
			}
		}
		if(s == ENTER)
		{
			if(da == "A")
			{
				ctdt.dapan[cauthi] = 1;
			}
			else if(da == "B")
			{
				ctdt.dapan[cauthi] = 2;
			}
			else if(da == "C")
			{
				ctdt.dapan[cauthi] = 3;
			}
			else if (da == "D")
			{
				ctdt.dapan[cauthi] = 4;
			}
			
			/*if (cauthi == ctdt.sct - 1)
			{
				system("cls");
				stop = 0;
				clock.join();
				cout << "Chuc mung ban da hoan thanh bai thi!";
				int socaudung = TinhDiem(ctdt,dsch);
				string s1 = IntToString(socaudung);
				string s2 = IntToString(sct);
				string s = chia(s1,s2);
				cout << "\nDiem cua ban la " << "scd: " << socaudung << " " << s  << endl;
				diem = s;
				for(int i = 0; i < sct; i++)
				{
					cout << ctdt.bode[i] << "." << ctdt.dapan[i] << "    ";
				}
				system("pause");
				return ;
			}
			else */if (cauthi < sct -1)
			{
				if(page < maxpage && (cauthi + 1) % 10 == 0)
				{
					page++;
					qt = true;
				}
				if (qt == true)
				{
					XoaDA();
					VeKhungDA(page,sct,ctdt);
					qt = false;
				}
				else InDA(page,sct,ctdt);
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				cauthi++;
				gotoxy(19 + (cauthi%10)*10,44);
				cout << muitenlen;
				gotoxy(10,1);
				cout << "    ";
				gotoxy(7,1);
				cout << "CAU " << cauthi + 1;
				In1CauThi(dsch,ctdt.bode[cauthi]);
				state1 = 0;
				da = "A";
				for(int i = 0; i < 33; i += 6)
					{
						gotoxy(4,14+i);
						cout << " ";
					}	
				gotoxy(4,14);
				cout << muiten;
			}
			else if(cauthi == sct -1)
			{
				InDA(page,sct,ctdt);
				gotoxy(19 + (cauthi%10)*10,44);
				cout << " ";
				gotoxy(19 + (cauthi%10)*10,44);
				cout << muitenlen;
				gotoxy(10,1);
				switch(ctdt.dapan[cauthi])
				{
					case 1:
						{
							state1 = 0;
							break;
						}
					case 2:
						{
							state1 = 1;
							break;
						}
					case 3:
						{
							state1 = 2;
							break;
						}
					case 4:
						{
							state1 = 3;
							break;
						}			
				}
				if(state1 == 0)
				{
					gotoxy(4,14);
					cout << muiten;	
				}
				else if(state1 == 1)
				{
					gotoxy(4,20);
					cout << muiten;
				}
				else if(state1 == 2)
				{
					gotoxy(4,26);
					cout << muiten;
				}
				else
				{
					gotoxy(4,32);
					cout << muiten;
				}
			}
		}
		if ((s == F1  && sCheck == false) || s == ESC)
		{
			string tb = "Ban chac chan muon nop bai ? (Y/N)";
			InTB(tb,132,30);
			batPhim(s,sCheck);
			while(s != ESC)
			{
				if((s == 'y' || s == 'Y')&& sCheck == true)
				{
					stop = 0;
					clock.join();
					
//					for(int i = 0; i < sct; i++)
//					{
//						if (ctdt.dapan[i] != 1 || ctdt.dapan[i] != 2 || ctdt.dapan[i] != 3 || ctdt.dapan[i] != 4 )
//						{
//							ctdt.dapan[i] = 0;
//						}
//						cout << ctdt.dapan[i] << " ";
//					}
					
					ketThucBaiThi(ctdt,dsch);
					return;
				}
				else if((s == 'n' || s == 'N') && sCheck == true)
				{
					XoaTB(130,26);
					break;
				}
				batPhim(s,sCheck);
				
			}
			InTB(tb,132,30);
		}
		if(s == ESC)
		{
//			for(int i = 0; i < sct; i++)
//			{
//				if (ctdt.dapan[i] != 1 || ctdt.dapan[i] != 2 || ctdt.dapan[i] != 3 || ctdt.dapan[i] != 4 )
//				{
//					ctdt.dapan[i] = 0;
//				}
//			}
			int socaudung = TinhDiem(ctdt,dsch);
			cout << socaudung;
			string s1 = IntToString(socaudung);
			string s2 = IntToString(sct);
			string s = chia(s1,s2);
			diem = s;
			cout << " " << diem;
//			system("pause");
			return ;
		}
		if(stop == 0)
		{
			clock.join();
			string tb = "Het thoi gian lam bai, bam phim bat ky de ket thuc!";
			InTB(tb,132,30);
			ketThucBaiThi(ctdt,dsch);
//			for(int i = 0; i < sct; i++)
//			{
//				if (ctdt.dapan[i] != 1 || ctdt.dapan[i] != 2 || ctdt.dapan[i] != 3 || ctdt.dapan[i] != 4 )
//				{
//					ctdt.dapan[i] = 0;
//				}
//			}
			return;
		}
		batPhim(s,sCheck);
	}
	stop = 0;
	clock.join();
}

// ==================== IN 1 CH + DAN AN CUA SV ==========================
void InCH_DASV(NODECH ch, string da)
{
	for(int i = 0; i < 30;i++)
	{
		gotoxy(20,5+i);
		if(i == 4) i = 8;
		if (i == 11) i = 14;
		if (i == 17) i = 20;
		if (i == 23) i = 26;
		cout << "                                                                                                  ";
	}
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	InNDCH(ch->info.noiDung);
	gotoxy(20,14);
	InDA_XemCH(ch->info.A);
	gotoxy(20,20);
	InDA_XemCH(ch->info.B);
	gotoxy(20,26);
	InDA_XemCH(ch->info.C);
	gotoxy(20,32);
	InDA_XemCH(ch->info.D);
	if(ch->info.dapAn == da)
	{
		if(ch->info.dapAn == "A")
		{
			ChangeColor(175);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(ch->info.dapAn == "B")
		{
			ChangeColor(175);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(ch->info.dapAn == "C")
		{
			ChangeColor(175);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(ch->info.dapAn == "D")
		{
			ChangeColor(175);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}
	}
	else
	{
		if(da == "A")
		{
			ChangeColor(79);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(da == "B")
		{
			ChangeColor(79);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(da == "C")
		{
			ChangeColor(79);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(da == "D")
		{
			ChangeColor(79);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}
		if(ch->info.dapAn == "A")
		{
			ChangeColor(240);
			gotoxy(6,16-2);
			cout << "DAP AN A: ";
			ChangeColor(15);
		}
		else if(ch->info.dapAn == "B")
		{
			ChangeColor(240);
			gotoxy(6,22-2);
			cout << "DAP AN B: ";
			ChangeColor(15);
		}
		else if(ch->info.dapAn == "C")
		{
			ChangeColor(240);
			gotoxy(6,28-2);
			cout << "DAP AN C: ";
			ChangeColor(15);
		}
		else if(ch->info.dapAn == "D")
		{
			ChangeColor(240);
			gotoxy(6,34-2);
			cout << "DAP AN D: ";
			ChangeColor(15);
		}
	}
}
// ==================== IN CHI TIET 1 LAN THI CUA SV ==========================
void InChiTiet1LanThi(nodediemThi *p, NODECH dsch, nodeSV *k)
{
	system("cls");
	int socaudung = TinhDiem(p->info.ctdt,dsch)*10;
	string scd = IntToString(socaudung);
	string sct = IntToString(p->info.ctdt.sct);
	string diem = chia(scd,sct);
	gotoxy(130,2);
	veKhung(21,35);
	gotoxy(133,4);
	cout << "MSSV: ";
	gotoxy(139,4);
	cout << k->info.maSV;
	gotoxy(133,7);
	cout << "HO VA TEN: ";
	gotoxy(144,7);
	cout << k->info.ho << " " << k->info.ten;
	gotoxy(133,10);
	cout << "GIOI TINH: ";
	gotoxy(144,10);
	cout << k->info.gioiTinh;
	gotoxy(133,13);
	cout << "SO CAU DUNG: ";
	gotoxy(150,13);
	cout << TinhDiem(p->info.ctdt,dsch);
	gotoxy(133,16);
	cout << "SO CAU THI: ";
	gotoxy(150,16);
	cout << p->info.ctdt.sct;
	gotoxy(133,19);
	cout << "DIEM: ";
	gotoxy(150,19);
	cout << diem;
	gotoxy(5,2);
	veKhung(36,125);
	gotoxy(6,7-2);
	cout << "NOI DUNG CH: ";
	gotoxy(19,6-2);
	veKhung(7,100);
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(19,15-2);
	veKhung(5,100);
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(19,21-2);
	veKhung(5,100);
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(19,27-2);
	veKhung(5,100);
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	gotoxy(19,33-2);
	veKhung(5,100);
	int page = 0;
	int stt = 0;
	int maxpage;
	VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
	bool qt = false;
	int max = p->info.ctdt.sct;
	if(max <= 10)
	{
		maxpage = 0;
	}
	else if(max > 10 && max % 10 == 0)
	{
		maxpage = (max/10) - 1;
	}
	else maxpage = max/10;
	string da;
	NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
	if(p->info.ctdt.dapan[stt] == 1)
	{
		da = "A";
	}
	else if (p->info.ctdt.dapan[stt] == 2)
	{
		da = "B";
	}
	else if(p->info.ctdt.dapan[stt] == 3)
	{
		da = "C";
	}
	else if(p->info.ctdt.dapan[stt] == 4)
	{
		da = "D";
	}
	else if(p->info.ctdt.dapan[stt] == 0)
	{
		da = "";
	}
	InCH_DASV(ch,da);
	gotoxy(5,1);
	cout << "CAU " << stt + 1;
	gotoxy(19,44);
	cout << muitenlen;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(s == LEFT && sCheck == false)
		{
			if(page > 0 && (stt + 1) % 10 == 1)
			{
				page--;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				qt = false;
			}
			if(stt > 0)
			{
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt--;
				gotoxy(19 + (stt%10)*10,44);
				cout << muitenlen;
				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			}
		}
		if(s == RIGHT && sCheck == false)
		{
			if(page < maxpage && (stt + 1) % 10 == 0)
			{
				page++;
				qt = true;
			}
			if (qt == true)
			{
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				qt = false;
			}
			if(stt < max - 1)
			{
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt++;
				gotoxy(19 + (stt%10)*10,44);
				cout << muitenlen;
				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			} 
		}
		if(s == PAGEUP && sCheck == false)
		{
			if(stt > 9)
			{
				page--;
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt -= 10;
				gotoxy(19 + (stt%10)*10,44);
				cout << muitenlen;
				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			}
			else
			{
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt = 0;
				gotoxy(19 + (stt%10)*10,44);
				cout << muitenlen;
				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			}
		}
		if(s == PAGEDOWN && sCheck == false)
		{
			if(stt < max - 10)
			{
				page++;
				XoaDA();
				VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt);
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt += 10;
				gotoxy(19 + (stt%10)*10,44);
				cout << muitenlen;
				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;	
			}
			else
			{
				if((max - 1)/10 > stt/10)
				{
					page++;
					XoaDA();
					VeKhungDA(page,p->info.ctdt.sct,p->info.ctdt); 
				}
				gotoxy(19 + (stt%10)*10,44);
				cout << " ";
				stt = max - 1;
				gotoxy(19 + (stt%10)*10,44);
				cout << muitenlen;
				NODECH ch = Search_CH(dsch,p->info.ctdt.bode[stt]);
				if(p->info.ctdt.dapan[stt] == 1)
				{
					da = "A";
				}
				else if (p->info.ctdt.dapan[stt] == 2)
				{
					da = "B";
				}
				else if(p->info.ctdt.dapan[stt] == 3)
				{
					da = "C";
				}
				else if(p->info.ctdt.dapan[stt] == 4)
				{
					da = "D";
				}
				else if(p->info.ctdt.dapan[stt] == 0)
				{
					da = "";
				}
				InCH_DASV(ch,da);
				gotoxy(5,1);
				cout << "       ";
				gotoxy(5,1);
				cout << "CAU " << stt + 1;
			}
		}
		batPhim(s,sCheck);
	}
}
// ==================== IN BANG DIEM THI TN 1 MH CUA SV ==========================
void InBangDiemSV (nodeSV *sv, int page, NODECH dsch)
{
	int maxpage;
	int slt = DemLanThi(sv->info.diem);
	if(slt <= 10)
	{
		maxpage = 0;
	}
	else if(slt > 10 && slt % 10 == 0)
	{
		maxpage = (slt/10) - 1;
	}
	else maxpage = slt/10;
	nodediemThi *p;
	if (page == 0)
	{
		p = sv->info.diem.First;
	}
	else
	{
		p = sv->info.diem.First;
		for (int i=0; i < page*10; i++)
		{
			if (p->pNext != NULL)
			{
				p = p->pNext;
			}
		}	
	}
	int dem = 1;
	int k = 0;
	for(int i = 0; i < 10; i++)
	{
		if(p->pNext != NULL)
		{
			gotoxy(20,6+k);
			cout << dem;
			gotoxy(50,6+k);
			cout << p->info.ctdt.sct;
			gotoxy(80,6+k);
			cout << p->info.ctdt.tg;
			gotoxy(109,6+k);
			int socaudung = TinhDiem(p->info.ctdt,dsch)*10;
			string scd = IntToString(socaudung);
			string sct = IntToString(p->info.ctdt.sct);
			string diem = chia(scd,sct);
			cout << diem;
			dem ++;
			k += 3;
			p = p->pNext;
		}
		else
		{
			gotoxy(20,6+k);
			cout << dem;
			gotoxy(50,6+k);
			cout << p->info.ctdt.sct;
			gotoxy(80,6+k);
			cout << p->info.ctdt.tg;
			gotoxy(109,6+k);
			int socaudung = TinhDiem(p->info.ctdt,dsch)*10;
			string scd = IntToString(socaudung);
			string sct = IntToString(p->info.ctdt.sct);
			string diem = chia(scd,sct);
			cout << diem;
			dem ++;
			k += 3;
			break;
		}
	}
	gotoxy(62,37);
	cout << "Trang" << page + 1 << "/" << maxpage + 1;
}
// ==================== XEM BANG DIEM THI TN 1 MH CUA SV ==========================
void XemBangDiemSV(nodeSV *k, NODECH dsch)
{
	system("cls");
	gotoxy(126,2);
	veKhung(11,40);
	gotoxy(128,4);
	cout << "MSSV: ";
	gotoxy(134,4);
	cout << k->info.maSV;
	gotoxy(128,7);
	cout << "HO VA TEN: ";
	gotoxy(139,7);
	cout << k->info.ho << " " << k->info.ten;
	gotoxy(128,10);
	cout << "GIOI TINH: ";
	gotoxy(139,10);
	cout << k->info.gioiTinh;
	gotoxy(5,2);
	vekhungDS(34,120,4);
	gotoxy(17,3);
	cout << "LAN THI";
	gotoxy(46,3);
	cout << "SO CAU THI";
	gotoxy(76,3);
	cout << "THOI GIAN";
	gotoxy(108,3);
	cout << "DIEM";
	int state = 0;
	int maxpage;
	int page = 0;
	InBangDiemSV(k,page,dsch);
	int slt = DemLanThi(k->info.diem);
	char s;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(slt <= 10)
		{
			maxpage = 0;
		}
		else if(slt % 10 == 0) 
		{
			maxpage = slt/10 -1;
		}
		else maxpage = slt/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                             ";
						gotoxy(36,6+i);
						cout << "                             ";
						gotoxy(66,6+i);
						cout << "                             ";
						gotoxy(96,6+i);
						cout << "                            ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InBangDiemSV(k,page,dsch);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				nodediemThi *p = k->info.diem.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (p->pNext != NULL)
					{
						p = p->pNext;
					}
				}
				if(p->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                             ";
							gotoxy(36,6+i);
							cout << "                             ";
							gotoxy(66,6+i);
							cout << "                             ";
							gotoxy(96,6+i);
							cout << "                            ";
						}
					}
					page++;
					InBangDiemSV(k,page,dsch);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				nodediemThi *p = k->info.diem.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (p->pNext != NULL)
					{
						p = p->pNext;
					}
				}
				if(p->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(p->pNext == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                             ";
					gotoxy(36,6+i);
					cout << "                             ";
					gotoxy(66,6+i);
					cout << "                             ";
					gotoxy(96,6+i);
					cout << "                            ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InBangDiemSV(k,page,dsch);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                             ";
					gotoxy(36,6+i);
					cout << "                             ";
					gotoxy(66,6+i);
					cout << "                             ";
					gotoxy(96,6+i);
					cout << "                            ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InBangDiemSV(k,page,dsch);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			nodediemThi *p = k->info.diem.First;
			for (int i = 0; i < state + page*10; i++)
			{
				if (p->pNext != NULL)
				{
					p = p->pNext;
				}
			}
			InChiTiet1LanThi(p,dsch,k);
		}
		batPhim(s,sCheck);
	}
}
// ==================== IN DANH SACH DIEM THEO MH ==========================
void InDSDiemMH (lop *l,int page, monHoc *m,NODECH dsch)
{
	if (l->danhsach.First == NULL)
	{
		return;
	}
	int k = 2;
	int sl = DemSV(l->danhsach);
	int maxpage;
	if(sl <= 10)
	{
		maxpage = 0;
	}
	else if (sl % 10 == 0)
	{
		maxpage = sl/10 - 1;
	}
	else maxpage = sl/10;
	nodeSV *j = new nodeSV;
	if (page == 0)
	{
		j = l->danhsach.First;
	}
	else
	{
		j = l->danhsach.First;
		for (int i=0; i<page*10; i++)
		{
			if (j->pNext != NULL)
			{
				j = j->pNext;
			}
		}	
	}
	nodediemThi *p;
	for(int i = 0; i < 10; i++)
	{
		p = j->info.diem.First;
		int slt = 0;
		if (j->pNext != NULL) //j khong cuoi 
		{
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(32,4+k);
			cout << j->info.ho << " " << j->info.ten;
			if(p == NULL) //j chua thi
			{	
				gotoxy(109,4+k);
				cout << "CHUA THI";
			}
			else //j co thi
			{
				while(p != NULL) //tim slt cua mon
				{
					if(p->info.maMH.compare(m->maMH) == 0)
					{
						slt++;
					}
					p = p->pNext;
				}
				if(slt == 0) //neu chi thi mon
				{
					gotoxy(109,4+k);
					cout << "CHUA THI";
				}
				else //neu co thi mon
				{
					gotoxy(113,4+k);
					cout << slt;
				}
			}
			k += 3;
			j = j->pNext;
		}
		else //j la cuoi
		{
			gotoxy(12,4+k);
			cout << j->info.maSV;
			gotoxy(32,4+k);
			cout << j->info.ho << " " << j->info.ten;
			if(p == NULL)
			{	
				gotoxy(109,4+k);
				cout << "CHUA THI";
			}
			else //j co thi
			{
				while(p != NULL) //tim slt cua mon
				{
					if(p->info.maMH.compare(m->maMH) == 0)
					{
						slt++;
					}
					p = p->pNext;
				}
				if(slt == 0) //neu chi thi mon
				{
					gotoxy(109,4+k);
					cout << "CHUA THI";
				}
				else //neu co thi mon
				{
					gotoxy(113,4+k);
					cout << slt;
				}
			}
			k += 3;
			break;
		}
	}
	gotoxy(125/2,36);
	cout << "Trang " << page + 1 << "/" << maxpage + 1;
}
// ==================== XEM DIEM ==========================
void XemDiem1Lop(lop *l, monHoc *m, NODECH dsch)
{
	AnConTro();
	system("cls");
	gotoxy(10,1);
	cout << "Diem mon : " << m->tenMH;
	gotoxy(105,1);
	cout << "Lop : " << l->maLop;
	gotoxy(5,2);
	VeKhungDSLop1(34,120,10);
	gotoxy(130,26);
	vekhungTB(10,36);
	int page = 0;
	gotoxy(15,3);
	cout << "MA SV";
	gotoxy(60,3);
	cout << "HO VA TEN";
	gotoxy(108,3);
	cout << "SO LAN THI";
	InDSDiemMH(l,page,m, dsch);
	int maxpage;
	int state = 0;
	char s;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while(s != ESC)
	{
		if(DemSV(l->danhsach) % 10 == 0) 
		{
			maxpage = DemSV(l->danhsach)/10;
		}
		else maxpage = DemSV(l->danhsach)/10 + 1;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(79,6+i);
						cout << "                     ";
						gotoxy(103,6+i);
						cout << "                     ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSDiemMH(l,page,m, dsch);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
					
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                      ";
							gotoxy(31,6+i);
							cout << "                                             ";
							gotoxy(79,6+i);
							cout << "                     ";
							gotoxy(103,6+i);
							cout << "                     ";
						}
					}
					page++;
					InDSDiemMH(l,page,m, dsch);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				nodeSV *k= l->danhsach.First;
				for(int i=0; i< state + page*10; i++)
				{
					if (k->pNext != NULL)
					{
						k = k->pNext;
					}
				}
				if(k->pNext != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(k->pNext == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage -1)
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(79,6+i);
						cout << "                     ";
						gotoxy(103,6+i);
						cout << "                     ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSDiemMH(l,page,m, dsch);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                      ";
						gotoxy(31,6+i);
						cout << "                                             ";
						gotoxy(79,6+i);
						cout << "                     ";
						gotoxy(103,6+i);
						cout << "                     ";
					}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSDiemMH(l,page,m, dsch);
				gotoxy(hd,td);
			}
		}
		if(s == ENTER)
		{
			//XEM BANG DIEM SINH VIEN
			nodeSV *k = l->danhsach.First;
			for (int i = 0; i < state + page*10; i++)
			{
				if (k->pNext != NULL)
				{
					k = k->pNext;
				}
			}
			if(k->info.diem.First == NULL)
			{
				gotoxy(wherex()-1,wherey());
				cout << " ";
				string tb = "Sinh vien chua thi lan nao";
				InTB(tb,132,30);
				AnConTro();
				Sleep(750);
				XoaTB(130,26);
				gotoxy(7,6);
				cout << muiten;
				state = 0;
			}
			else
			{
				//In chi tiet bang diem cua 1 sinh vien
				if(CheckSLThi(k->info.diem,m->maMH) == false)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					string tb = "Sinh vien chua thi lan nao";
					InTB(tb,132,30);
					AnConTro();
					Sleep(750);
					XoaTB(130,26);
					gotoxy(7,6);
					cout << muiten;
					state = 0;
				}
				else
				{
					XemBangDiemSV(k,dsch);
					system("cls");
					gotoxy(10,1);
					cout << "Diem mon : " << m->tenMH;
					gotoxy(105,1);
					cout << "Lop : " << l->maLop;
					gotoxy(5,2);
					VeKhungDSLop1(34,120,10);
					gotoxy(130,26);
					vekhungTB(10,36);
					int page = 0;
					gotoxy(15,3);
					cout << "MA SV";
					gotoxy(60,3);
					cout << "HO VA TEN";
					gotoxy(108,3);
					cout << "SO LAN THI";
					InDSDiemMH(l,page,m, dsch);
					gotoxy(7,6);
					cout << muiten;
					state = 0;
				}
			}
		}
	batPhim(s,sCheck);
	}
}
// ==================== NHAP MON XEM DIEM ==========================
void NhapMonXemDiem(lop *l, DSMH dsm, NODECH dsch)
{
	if(dsm.somon == 0)
	{
		string tb = "Danh sach mon hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(850);
		XoaTB(130,26);
		return;
	}
	gotoxy(5,2);
	vekhungDS(34,120,2);
	gotoxy(30,3);
	cout << "MA MON HOC";
	gotoxy(90,3);
	cout << "TEN MON HOC";
	int page = 0;
	int maxpage;
	InDSMon(dsm,page);
	gotoxy(130,26);
	vekhungTB(10,36);
	char s;
	int state = 0;
	bool sCheck;
	string tb = "Vui long chon 1 mon hoc de xem diem";
	InTB(tb,132,30);
	AnConTro();
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsm.somon <= 10)
		{
			maxpage = 0;
		}
		else if(dsm.somon % 10 == 0) 
		{
			maxpage = dsm.somon/10 -1;
		}
		else maxpage = dsm.somon/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 28;i++)
					{
						gotoxy(6,6+i);
						cout << "                                                          ";
						gotoxy(66,6+i);
						cout << "                                                          ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSMon(dsm,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < maxpage)
					{
						for(int i = 0; i < 28;i++)
						{
							gotoxy(6,6+i);
							cout << "                                                          ";
							gotoxy(66,6+i);
							cout << "                                                          ";
						}
					}
					page++;
					InDSMon(dsm,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsm.m[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsm.m[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                                          ";
					gotoxy(66,6+i);
					cout << "                                                          ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSMon(dsm,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			XemDiem1Lop(l, dsm.m[state + page*10], dsch);
			system("cls");
			gotoxy(5,2);
			vekhungDS(34,120,2);
			gotoxy(30,3);
			cout << "MA MON HOC";
			gotoxy(90,3);
			cout << "TEN MON HOC";
			InDSMon(dsm,page);
			state = 0;
			gotoxy(130,26);
			vekhungTB(10,36);
			tb = "Vui long chon 1 mon hoc de xem diem";
			InTB(tb,132,30);
			gotoxy(7,6);
			cout << muiten;
		}
	batPhim(s,sCheck);
	}
	for(int i = 0; i < 10; i++)
	{
		gotoxy(7,6+i*3);
		cout << " ";
	}
}
// ==================== NHAP LOP  ==========================
void NhapLopXemDiem(dslop dsl , DSMH dsm, NODECH dsch)
{
	system("cls");
	gotoxy(130,26);
	vekhungTB(10,36);
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat	PGUP: Qua trang	PGDOWN: Lui trang";
	gotoxy(5,2);
	vekhungDS(34,120,3);
	gotoxy(22,3);
	cout << "TEN LOP";
	gotoxy(63,3);
	cout << "MA LOP";
	gotoxy(101,3);
	cout << "NIEN KHOA";
	int page = 0;
	int maxpage;
	InDSLop(dsl,page);
	char s;
	int state = 0;
	bool sCheck;
	gotoxy(7,6);
	cout << muiten;
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if(dsl.solop <= 10)
		{
			maxpage = 0;
		}
		else if(dsl.solop % 10 == 0) 
		{
			maxpage = dsl.solop/10 -1;
		}
		else maxpage = dsl.solop/10;
		if(s == UP && sCheck == false)
		{
			if(page == 0)
			{
				if(state > 0)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey() - 3);
					cout << muiten;
				}
			}
			if(page > 0)
			{
				if((state > 0) )
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state --;
					gotoxy(7,wherey()-3);
					cout << muiten;
				}
				else if(state == 0)
				{
					for(int i = 0; i < 29;i++)
					{
						gotoxy(6,6+i);
						cout << "                                      ";
						gotoxy(46,6+i);
						cout << "                                      ";
						gotoxy(86,6+i);
						cout << "                                      ";
					}
					gotoxy(wherex()-1,wherey());
					cout << " ";
					page --;
					InDSLop(dsl,page);
					gotoxy(7,33);
					cout << muiten;
					state = 9;
					
				}
			}
		}
		if(s == DOWN && sCheck == false)
		{
			if(state == 9)
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					if(page < dsl.solop/10)
					{
					
						for(int i = 0; i < 29;i++)
						{
							gotoxy(6,6+i);
							cout << "                                      ";
							gotoxy(46,6+i);
							cout << "                                      ";
							gotoxy(86,6+i);
							cout << "                                      ";
						}
					}
					page++;
					InDSLop(dsl,page);
					state = 0;
					gotoxy(7,6);
					cout << muiten;
				}
			}
			else
			{
				if(dsl.l[state + page*10 + 1] != NULL)
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					state ++;
					gotoxy(7,wherey() + 3);
					cout << muiten;	
				}
				if(dsl.l[state + page*10 + 1] == NULL) 
				{
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(7,wherey());
					cout << muiten;
				}
			}
		}	
		if (s == PAGEDOWN && sCheck == false)
		{
			AnConTro();
			if(page < maxpage)
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page ++;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if(s == PAGEUP && sCheck == false)
		{
			AnConTro();
			if (page > 0 )
			{
				for(int i = 0; i < 28;i++)
				{
					gotoxy(6,6+i);
					cout << "                                      ";
					gotoxy(46,6+i);
					cout << "                                      ";
					gotoxy(86,6+i);
					cout << "                                      ";
				}
				gotoxy(wherex()-1,wherey());
				cout << " ";
				gotoxy(7,6);
				cout << muiten;
				state = 0;
				page--;
				int hd = wherex();
				int td = wherey();
				InDSLop(dsl,page);
				gotoxy(hd,td);
			}
		}
		if (s == ENTER)
		{
			if(dsl.l[state + page*10]->danhsach.First == NULL)
			{
				string tb = "Lop khong co sinh vien khong the xem diem !";
				InTB(tb,132,30);
				AnConTro();
				Sleep(850);
				XoaTB(130,26);
				gotoxy(7,6 + state*3);
				cout << " ";
				state = 0;
				gotoxy(7,6);
				cout << muiten;
			}
			else
			{
				NhapMonXemDiem(dsl.l[state + page*10], dsm, dsch);
				system("cls");
				gotoxy(130,26);
				vekhungTB(10,36);
				gotoxy(5,2);
				vekhungDS(34,120,3);
				gotoxy(22,3);
				cout << "TEN LOP";
				gotoxy(63,3);
				cout << "MA LOP";
				gotoxy(101,3);
				cout << "NIEN KHOA";
				InDSLop(dsl,page);
				state = 0;
				gotoxy(7,6);
				cout << muiten;
			}
			
		}
	batPhim(s,sCheck);
	}
}
// ==================== FUNCTION DIEM ==========================
void FunctionDiem(dslop dsl, dssv ds,DSMH dsm, NODECH dsch)
{
	int page = 0;
	gotoxy(130,26);
	vekhungTB(10,36);
	string tb;
	if(dsl.solop == 0)
	{
		string tb = "Danh sach lop hien tai dang trong";
		InTB(tb,132,30);
		AnConTro();
		Sleep(750);
		XoaTB(130,26);
	}
	else
	{
		NhapLopXemDiem(dsl,dsm,dsch);
	}
}
// ==================== DOC FILE CAU HOI ==========================
void DocFileCauHoi (NODECH &tree, int arr1[], int arr2[])
{
	ifstream fileIn;
	fileIn.open("DSCAUHOI.txt", ios_base :: in );
	if(fileIn.fail()) cout << "Nope";
	cauHoi ch;
	while(!fileIn.eof())
	{
		int id;
		string temp;
		getline(fileIn,temp,'\n');
		id = StringToInt(temp); 
		getline(fileIn,ch.maMH,'\n');
		getline(fileIn,ch.noiDung,'\n');
		getline(fileIn,ch.A,'\n');
		getline(fileIn,ch.B,'\n');
		getline(fileIn,ch.C,'\n');
		getline(fileIn,ch.D,'\n');
		getline(fileIn,ch.dapAn,'\n');
		if (id < 5000)
		{
			swap(arr1[id],arr1[4999-countNode(tree->pLeft)]);
			Insert_node(tree,id,ch);
		}
		else if (id > 5000)
		{
			swap(arr2[id-5001],arr2[4999-countNode(tree->pRight)]);
			Insert_node(tree,id,ch);
		}
		else 
		{
			Insert_node(tree,id,ch);
		}
	}
}
// ==================== LUU FILE CAU HOI ==========================
void LuuFileCH(NODECH root, string filename, int idlonnhat) // NLR
{
	NODECH q;
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (!fileOut.is_open())
	{
		cout << "khong mo duoc";
		return;
	}
	else
	{
		if(countNode(root) == 0)
		{
			cout << "DS trong";
			return;		
		}
		NODECH Stack[STACKSIZE];
		int sp= -1; // Khoi tao Stack rong
		NODECH p = root;
		while (p != NULL )
		{
			if(p->id == idlonnhat)
			{
//				cout << "ID lon nhat: " << idlonnhat;
//				system("pause");
				fileOut << p->id << endl;
				fileOut << p->info.maMH << endl;
				fileOut << p->info.noiDung << endl;
				fileOut << p->info.A << endl;
				fileOut << p->info.B << endl;
				fileOut << p->info.C << endl;
				fileOut << p->info.D << endl;
				fileOut << p->info.dapAn;
				break;
			}
			fileOut << p->id << endl;
			fileOut << p->info.maMH << endl;
			fileOut << p->info.noiDung << endl;
			fileOut << p->info.A << endl;
			fileOut << p->info.B << endl;
			fileOut << p->info.C << endl;
			fileOut << p->info.D << endl;
			fileOut << p->info.dapAn << endl;
			if (p->pRight != NULL)
			{
				Stack[++sp]= p->pRight;	
			}
			if (p->pLeft != NULL)
			{
				p = p->pLeft;	
			}
			else if (sp == -1)
			{
				break;	
			}
			else
			{
				p = Stack[sp--];	
			}
		}
	}
	fileOut.close();
	return ;
}
// ==================== LUU FILE LOP ==========================
void LuuFileLop(lop *l, string filename) 
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (fileOut.fail()) 
	{
		cout << "Khong mo duoc file " << filename << endl;
		return;
	}

	for (nodeSV *p = l->danhsach.First; p != NULL; p = p->pNext) 
	{
		fileOut << p->info.maSV << '\n';
		fileOut << p->info.ho << ' ';
		fileOut << p->info.ten << '\n';
		if(p->info.gioiTinh == "NAM")
		{
			fileOut << "1" << '\n';
		}
		else
		{
			fileOut << "0" << '\n';
		}
		fileOut << p->info.password << endl;
	}
	fileOut.close();
	return;
}
// ==================== LUU FILE DIEM 1 LOP ==========================
void LuuFileDiem(lop *l, string filename,NODECH dsch)
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (fileOut.fail())
	{
		cout << "Khong mo duoc file diem " << filename << endl;
		return;
	}
	else
	{
		for (nodeSV *p = l->danhsach.First; p != NULL; p = p->pNext)
		{
			fileOut << p->info.maSV << endl;
			fileOut << DemLanThi(p->info.diem) << endl;
			for (nodediemThi *pd = p->info.diem.First; pd != NULL; pd = pd->pNext)
			{
				string diemthi;
				int scd = TinhDiem(pd->info.ctdt,dsch)*10;
				int sct = pd->info.ctdt.sct;
				diemthi = chia(IntToString(scd),IntToString(sct));
				fileOut << pd->info.maMH << ":" << diemthi << ":" << pd->info.ctdt.sct << ":";
				for(int i = 0; i < pd->info.ctdt.sct; i++)
				{
					fileOut << pd->info.ctdt.bode[i] << "@";
				}
				for(int i = 0; i < pd->info.ctdt.sct; i++)
				{
					fileOut << pd->info.ctdt.dapan[i] << "#";
				}
				if(p->pNext == NULL)
				{
					break;
				}
				else fileOut << endl;
			}
			if(p->pNext == NULL)
			{
				break;
			}
			if( DemLanThi(p->info.diem) != 0)
			{
				continue;
			}
			else
			{
				fileOut << endl;
			}
		}
	}
	fileOut.close();
}
// ==================== LUU FILE DS LOP ==========================
void LuuFileDSlop(dslop dsl, string filename,NODECH dsch)
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (!fileOut.is_open()) 
	{
		cout << "Khong mo duoc file " << filename << endl;
		return;
	}
	fileOut << dsl.solop << endl;
	for (int i = 0; i < dsl.solop; i++) 
	{
		fileOut << dsl.l[i]->tenLop << '\n'<< dsl.l[i]->maLop << '\n';
		LuuFileLop(dsl.l[i], dsl.l[i]->maLop + ".txt");
		LuuFileDiem(dsl.l[i],"DIEM_"+dsl.l[i]->maLop+".txt",dsch);
	}
}
// ==================== LUU FILE MON ==========================
void LuuFileDSMon(DSMH ds, string filename)
{
	ofstream fileOut;
	fileOut.open(filename.c_str(), ios_base::out);
	if (!fileOut.is_open()) {
		cout << "Khong mo duoc file " << filename << endl;
		return;
	}
	for (int i = 0; i < ds.somon; i++)
	{
		if(i == ds.somon -1)
		{
			fileOut << ds.m[i]->maMH << '\n';
			fileOut << ds.m[i]->tenMH;
			break;
		}
		fileOut << ds.m[i]->maMH << '\n';
		fileOut << ds.m[i]->tenMH << '\n';
	}
	fileOut.close();
	return;
}

//=============================DANG NHAP================================
int DangNhap(dslop &dsl ,string &masv)
{
	system("cls");
	InTen();
	gotoxy(20,30);
	cout << " /$$$$$$$$ /$$   /$$ /$$$$$$       /$$$$$$$$ /$$$$$$$   /$$$$$$   /$$$$$$        /$$   /$$  /$$$$$$  /$$   /$$ /$$$$$$ /$$$$$$$$ /$$      /$$";
	gotoxy(20,31);
	cout << "|__  $$__/| $$  | $$|_  $$_/      |__  $$__/| $$__  $$ /$$__  $$ /$$__  $$      | $$$ | $$ /$$__  $$| $$  | $$|_  $$_/| $$_____/| $$$    /$$$";
	gotoxy(20,32);
	cout << "   | $$   | $$  | $$  | $$           | $$   | $$  \\ $$| $$  \\ $$| $$  \\__/      | $$$$| $$| $$  \\__/| $$  | $$  | $$  | $$      | $$$$  /$$$$";
	gotoxy(20,33);
	cout << "   | $$   | $$$$$$$$  | $$           | $$   | $$$$$$$/| $$$$$$$$| $$            | $$ $$ $$| $$ /$$$$| $$$$$$$$  | $$  | $$$$$   | $$ $$/$$ $$";
	gotoxy(20,34);
	cout << "   | $$   | $$__  $$  | $$           | $$   | $$__  $$| $$__  $$| $$            | $$  $$$$| $$|_  $$| $$__  $$  | $$  | $$__/   | $$  $$$| $$";
	gotoxy(20,35);
	cout << "   | $$   | $$  | $$  | $$           | $$   | $$  \\ $$| $$  | $$| $$    $$      | $$\\  $$$| $$  \\ $$| $$  | $$  | $$  | $$      | $$\\  $ | $$";
	gotoxy(20,36);
	cout << "   | $$   | $$  | $$ /$$$$$$         | $$   | $$  | $$| $$  | $$|  $$$$$$/      | $$ \\  $$|  $$$$$$/| $$  | $$ /$$$$$$| $$$$$$$$| $$ \\/  | $$";
	gotoxy(20,37);
	cout << "   |__/   |__/  |__/|______/         |__/   |__/  |__/|__/  |__/ \\______/       |__/  \\__/ \\______/ |__/  |__/|______/|________/|__/     |__/";
                                                                                                                                             
                                                                                                                                             
	gotoxy(55,15);
	veKhung(12,50);
	gotoxy(55+3,15+3);
	cout << "Ten dang nhap";
	gotoxy(55+17,15+2);
	veKhung(3,30);
	gotoxy(55+3,15+7);
	cout << "Mat khau";
	gotoxy(55+17,15+6);
	veKhung(3,30);
	gotoxy(55+21,15+10);
	cout << "DANG NHAP";

	string user;
	string pass;
	char s;
	bool state = false;
	bool sCheck;
	gotoxy(55+18,15+3);
	batPhim(s,sCheck);
	while (s != ESC)
	{
		if (s == UP && sCheck == false)
		{
			if (state == true)
			{
				gotoxy(55+18+user.length(),15+3);
				state = !state;
			}
		}
		if (s == DOWN && sCheck == false)
		{
			if (state == false)
			{
				gotoxy(55+18+pass.length(),15+7);
				state = !state;
			}
		}
		if (((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9')) && sCheck == true)
		{
			HienConTro();
			if (state == true)
			{
				if (pass.length() < 20)
				{
					cout << "*";
					pass += s;
				}
			}
			else
			{
				if (user.length() < 20)
				{
					cout << InHoa(s);
					user += InHoa(s);
				}
			}
		}
		if (s == BACKSPACE)
		{
			if (state == true)
			{
				if (pass.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					pass.erase(pass.length()-1);
				}
			}
			else
			{
				if (user.length() > 0)
				{
					AnConTro();
					gotoxy(wherex()-1,wherey());
					cout << " ";
					gotoxy(wherex()-1,wherey());
					HienConTro();
					user.erase(user.length()-1);
				}
			}
		}
		if (s == ENTER)
		{
			// neu user = "GV" va mat khau = "GV" thi return 1 la quyen giang vien
			if((user == "GV" && pass == "GV") || (user == "GV") && (pass == "gv"))
			{
				return 1;
			}
			// Duyet trong dssv kiem tra masv voi mat khau. neu dung thi return 0 la quyen sv
			else
			{	
				for(int i = 0; i < dsl.solop; i++)
				{
					for(nodeSV *k = dsl.l[i]->danhsach.First; k != NULL; k = k->pNext)
					{
						string x;
						for (int i = 0; i < k->info.maSV.length(); i++)
						{
							x += InHoa(k->info.maSV[i]);
						}
						string y = k->info.password;
						if(x == user && y == pass)
						{
							masv = user;
							return 0;
						}
					}
				}
				return 2;
			}
		}
	batPhim(s,sCheck);
	}
	return -1;
}

//==================================MAIN MENU GIANG VIEN===============================
int mainMenu()
{
	ChangeColor(15);
	system("cls");
	gotoxy(50,46);
	cout << "ENTER: Chon	ESC: Thoat";
	gotoxy(80,10);
	cout << " __   __  _______  __    _  __   __ ";
	gotoxy(80,11);
	cout << "|  |_|  ||       ||  |  | ||  | |  |";
	gotoxy(80,12);
	cout << "|       ||    ___||   |_| ||  | |  |";
	gotoxy(80,13);
	cout << "|       ||   |___ |       ||  |_|  |";
	gotoxy(80,14);
	cout << "|       ||    ___||  _    ||       |";
	gotoxy(80,15);
	cout << "| ||_|| ||   |___ | | |   ||       |";
	gotoxy(80,16);
	cout << "|_|   |_||_______||_|  |__||_______|";
	gotoxy(60,20);
	cout << " _______  ___   _______  __    _  _______    __   __  ___   _______  __    _ ";
	gotoxy(60,21);
	cout << "|       ||   | |   _   ||  |  | ||       |  |  | |  ||   | |       ||  |  | |";
	gotoxy(60,22);
	cout << "|    ___||   | |  |_|  ||   |_| ||    ___|  |  |_|  ||   | |    ___||   |_| |";
	gotoxy(60,23);
	cout << "|   | __ |   | |       ||       ||   | __   |       ||   | |   |___ |       |";
	gotoxy(60,24);
	cout << "|   ||  ||   | |       ||  _    ||   ||  |  |       ||   | |    ___||  _    |";
	gotoxy(60,25);
	cout << "|   |_| ||   | |   _   || | |   ||   |_| |   |     | |   | |   |___ | | |   |";
	gotoxy(60,26);
	cout << "|_______||___| |__| |__||_|  |__||_______|    |___|  |___| |_______||_|  |__|";
	veNutMenu(3,10,6,"Lop",240);
	veNutMenu(3,10,11,"In lop theo nien khoa",31);
	veNutMenu(3,10,16,"Sinh vien",31);
	veNutMenu(3,10,21,"Mon hoc",31);
	veNutMenu(3,10,26,"Cau hoi",31);
	veNutMenu(3,10,31,"Diem",31);
	//veNutMenu(3,10,36,"In chi tiet de thi cua 1 mon hoc",31);
	gotoxy(50,5);
	AnConTro();
	int choose = 0;
	char s;
	bool sCheck;
	batPhim(s,sCheck);
	while(1)
	{
		if (s == ESC)
		{
			if (Exit(s,sCheck) == true)
			{
				return -1;
			}
			else 
			{
				system("cls");
				gotoxy(50,46);
				cout << "ENTER: Chon	ESC: Thoat";
				gotoxy(80,10);
				cout << " __   __  _______  __    _  __   __ ";
				gotoxy(80,11);
				cout << "|  |_|  ||       ||  |  | ||  | |  |";
				gotoxy(80,12);
				cout << "|       ||    ___||   |_| ||  | |  |";
				gotoxy(80,13);
				cout << "|       ||   |___ |       ||  |_|  |";
				gotoxy(80,14);
				cout << "|       ||    ___||  _    ||       |";
				gotoxy(80,15);
				cout << "| ||_|| ||   |___ | | |   ||       |";
				gotoxy(80,16);
				cout << "|_|   |_||_______||_|  |__||_______|";
				gotoxy(60,20);
				cout << " _______  ___   _______  __    _  _______    __   __  ___   _______  __    _ ";
				gotoxy(60,21);
				cout << "|       ||   | |   _   ||  |  | ||       |  |  | |  ||   | |       ||  |  | |";
				gotoxy(60,22);
				cout << "|    ___||   | |  |_|  ||   |_| ||    ___|  |  |_|  ||   | |    ___||   |_| |";
				gotoxy(60,23);
				cout << "|   | __ |   | |       ||       ||   | __   |       ||   | |   |___ |       |";
				gotoxy(60,24);
				cout << "|   ||  ||   | |       ||  _    ||   ||  |  |       ||   | |    ___||  _    |";
				gotoxy(60,25);
				cout << "|   |_| ||   | |   _   || | |   ||   |_| |   |     | |   | |   |___ | | |   |";
				gotoxy(60,26);
				cout << "|_______||___| |__| |__||_|  |__||_______|    |___|  |___| |_______||_|  |__|";
				veNutMenu(3,10,6,"Lop",240);
				veNutMenu(3,10,11,"In lop theo nien khoa",31);
				veNutMenu(3,10,16,"Sinh vien",31);
				veNutMenu(3,10,21,"Mon hoc",31);
				veNutMenu(3,10,26,"Cau hoi",31);
				veNutMenu(3,10,31,"Diem",31);
				choose = 0;
			}
		}
		if (s == UP && sCheck == false )
		{
			if(choose > 0 )
			{
				switch(choose)
				{
					case 1:
						{
							veNutMenu(3,10,6,"Lop",240);
							veNutMenu(3,10,11,"In lop theo nien khoa",31);
							break;
						}
					case 2:
						{
							veNutMenu(3,10,11,"In lop theo nien khoa",240);
							veNutMenu(3,10,16,"Sinh vien",31);
							break;
						}
					case 3:
						{
							veNutMenu(3,10,16,"Sinh vien",240);
							veNutMenu(3,10,21,"Mon hoc",31);
							break;
						}
					case 4:
						{
							veNutMenu(3,10,21,"Mon hoc",240);
							veNutMenu(3,10,26,"Cau hoi",31);
							break;
						}
					case 5:
						{
							veNutMenu(3,10,26,"Cau hoi",240);
							veNutMenu(3,10,31,"Diem",31);
							break;
						}			
				}
				choose --;
			}
		}
		if (s == DOWN && sCheck == false )
		{
			if(choose < 5 )
			{
				switch(choose)
				{
					case 0:
						{
							veNutMenu(3,10,6,"Lop",31);
							veNutMenu(3,10,11,"In lop theo nien khoa",240);
							break;
						}
					case 1:
						{
							veNutMenu(3,10,11,"In lop theo nien khoa",31);
							veNutMenu(3,10,16,"Sinh vien",240);
							break;
						}
					case 2:
						{
							veNutMenu(3,10,16,"Sinh vien",31);
							veNutMenu(3,10,21,"Mon hoc",240);
							break;
						}
					case 3:
						{
							veNutMenu(3,10,21,"Mon hoc",31);
							veNutMenu(3,10,26,"Cau hoi",240);
							break;
						}
					case 4:
						{
							veNutMenu(3,10,26,"Cau hoi",31);
							veNutMenu(3,10,31,"Diem",240);
							break;
						}		
				}
				choose ++;
			}
		}
		if (s == ENTER)
		{
			return choose;
		}
	{
		batPhim(s,sCheck);
	}
	}
	
	return -1;
}


void mainProcess(dslop &dsl, dssv &ds, DSMH &dsm, NODECH &dsch, int arr1[], int arr2[])
{
	string masv;
	DocFileCauHoi(dsch,arr1,arr2);
	DocFileDSLop(dsl);
	DocFileDSMH(dsm);
	int idlonnhat;
	fullscreen();
	while(1)
	{
		HienConTro();
		switch(DangNhap(dsl,masv))
		{
		case 0:
			{
				system("cls");
				int tg = 0;
				int sct = 0;
				string monthi;
				bool check;
				NhapMonThi(dsm,tg,sct,monthi,check);
				if(check == false)
				{
					break;
				}
				//THI
				int sch = countNode(dsch);
				if (sct > sch)
				{
					string tb = "Khong the thi, so cau thi vuot qua so cau hoi trong ngan hang de thi";
					InTB(tb,132,30);
					AnConTro();
					Sleep(1500);
					XoaTB(130,26);
					break;
				}
				string diem;
				CTdethi ctdt;
				ctdt.bode = new int [sct];
				ctdt.dapan = new int [sct];
				FunctionThi(dsch,tg,sct,monthi,diem,ctdt);
				stop = 1;
				if(ctdt.bode != NULL)
				{
					
					float diemthi = StringToFloat(diem);
					cout << diem << " " << stop;
					nodeSV *sv;
					for(int i = 0; i < dsl.solop; i++)
					{
						sv = search_SV(dsl.l[i]->danhsach,masv);
						if(sv == NULL)
						{
							continue;
						}
						else
						{
							break;
						}
					}
					cout << sv->info.maSV;
					diemThi diemsv;
					diemsv.ctdt = ctdt;
					diemsv.diem = diemthi;
					diemsv.maMH = monthi;
					//cout << diemsv.diem;
					if (sv->info.diem.First == NULL) 
					{
						Insert_Diem_First(sv->info.diem.First,diemsv);
					}
					else 
					{
						nodediemThi *p = sv->info.diem.First;
						while (p->pNext != NULL)
						{
							p = p->pNext;
						}
						Insert_Diem_after(p,diemsv);
					}
				}
				else break;
				//system("pause");
				//

				break;
			}
		case 1:
			{
				system("cls");
				bool check = true;
				while(check != false)
				{
					switch(mainMenu())
					{
						case 0: //LOP
						{
							ChangeColor(15);
							system("cls");
							FunctionLop(dsl);
							break;
						}
						case 1:	//IN DANH SACH LOP
						{
							ChangeColor(15);
							system("cls");
							NhapNK(dsl);
							break;
						}
						case 2: //SINH VIEN
						{
							ChangeColor(15);
							system("cls");
							FunctionSV(dsl);
							break;
						}
						case 3://MON HOC
						{
							ChangeColor(15);
							system("cls");
							FunctionMon(dsm,dsl,dsch);
							break;
						}
						case 4://CAU HOI
						{
							ChangeColor(15);
							system("cls");
							FunctionCH(dsch,dsm,dsl,idlonnhat,arr1,arr2);
							break;
						}	
						case 5://DIEM
						{
							ChangeColor(15);
							system("cls");
							FunctionDiem(dsl,ds,dsm,dsch);
							break;	
						}
						case 6:
						{
							ChangeColor(15);
							system("cls");
							break;
						}	
						case -1://THOAT
						{
							check = false;
							break;
						}
					}
				}
				break;
			}
		case 2:
			{
				AnConTro();
				gotoxy(55+13,15+13);
				cout << "Sai ten dang nhap hoac mat khau";
				Sleep(500);
				HienConTro();
				break;
			}	
		case -1:
			{
				char s;
				bool sCheck;
				if(Exit(s,sCheck)== true)
				{
					LuuFileDSlop(dsl,"DSLOP.txt",dsch);
					LuuFileDSMon(dsm,"DSMONHOC.txt");
					LuuFileCH(dsch,"DSCAUHOI.txt",idlonnhat);
					system("cls");
					gotoxy(30,20);
					cout << " _________  ____  ____       _       ____  _____  ___  ____    ____  ____   ___   _____  _____  _  ";
					gotoxy(30,21);
					cout << "|  _   _  ||_   ||   _|     / \\     |_   \\|_   _||_  ||_  _|  |_  _||_  _|.'   `.|_   _||_   _|| | ";
					gotoxy(30,22);
					cout << "|_/ | | \\_|  | |__| |      / _ \\      |   \\ | |    | |_/ /      \\ \\  / / /  .-.  \\ | |    | |  | | ";
    				gotoxy(30,23);
					cout << "    | |      |  __  |     / ___ \\     | |\\ \\| |    |  __'.       \\ \\/ /  | |   | | | '    ' |  | | ";
					gotoxy(30,24);
					cout << "   _| |_    _| |  | |_  _/ /   \\ \\_  _| |_\\   |_  _| |  \\ \\_     _|  |_  \\  `-'  /  \\ \\__/ /   |_| ";
					gotoxy(30,25);
					cout << "  |_____|  |____||____||____| |____||_____|\\____||____||____|   |______|  `.___.'    `.__.'    (_) ";
					getch();
					return;
				}
				else
				{
					break;
				}
			}
		}
			
	}
}
#endif
