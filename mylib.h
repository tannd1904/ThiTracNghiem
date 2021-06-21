#ifndef _MYLIB_H
#define _MYLIB_H



#include<iostream>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<ctime>
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define BACKSPACE 8
#define SPACE 32
#define ESC 27
#define PAGEUP 73
#define PAGEDOWN 81
#define F1 59


#define doc (char)179
#define ngang (char)196
#define traitren (char)218
#define phaitren (char)191
#define traiduoi (char)192
#define phaiduoi (char)217
#define docphai (char)195
#define doctrai (char)180
#define ngangxuong (char)194
#define nganglen (char) 193
#define giua (char) 197
#define muiten (char) 175
#define muitenlen (char) 94
using namespace std;
// ==================== FULL SCREEN ==========================
void fullscreen()
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

// ==================== BAT PHIM ==========================
void batPhim(char &s, bool &Check)
{
	s = getch();
	if (s==-32 || s == 0)
	{
		s = getch();
		Check = false;
	}
	else
	{
		Check = true;
	}
}
//=============================HAM GOTOXY==========================
void gotoxy(int x, int y) // Di chuyen toa do con tro trong he toa do De-cat
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
//=============================HAM TEXTCOLOR==========================
void TextColor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
//=============================DOI INT==========================
int StringToInt(string x)
{
	if (x.length() == 0) return -1;
	int res = 0;
	for (int i = 0; i < x.length(); i++)
	{
		res = res*10 + (int)(x[i] - 48);
	}
	return res;
}
//=============================DOI FLOAT==========================
float StringToFloat (string s)
{
	int i = 0;
	string s1;
	while(s[i] != '.')
	{
		s1.push_back(s[i]);
		i++; 
	}
	float p = StringToInt(s1);
	i++;
	string s2;
	while(i < s.length())
	{
		s2.push_back(s[i]);
		i++;
	}
	float p1 = StringToInt(s2) / pow(10,s2.length());
	p = p + p1;
	return p;
}
//=====================TRA VE VI TRI X CUA CON TRO==============================
int wherex()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}
//=========================TRA VE VI TRI Y CUA CON TRO============================
int wherey( void )
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
// ==================== VE KHUNG ==========================
void veKhung(int rong, int dai)
{
	for (int i = 0; i < rong; i++)
	{
		for (int j = 0; j < dai; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == dai-1) cout << phaitren;
				else cout << ngang;
			}
			else if (i == rong-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == dai-1) cout << phaiduoi;
				else cout << ngang;
			}
			else
			{
				if (j == 0 || j == dai-1) cout << doc;
				else cout << " ";
			}
		}
		gotoxy(wherex()-dai,wherey()+1);
	}
}
//======================= VE KHUNG TEN SV =======================
void VeKhungTenSV(int dai, int rong, int socot)
{
	int x = rong/socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if(dem == 1)
			{
				dem = 3;
			}
			if(dem == 4)
			{
				dem = 8;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socot)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socot)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socot)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socot)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socot)) dem++;
			if(dem == socot) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
// ====================== VE KHUNG XEM DIEM =======================
void VeKhungXemDiem(int dai, int rong, int socot)
{
	
	int x = rong/socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if(dem == 1)
			{
				dem++;
			}
			if(dem == 3)
			{
				dem = 8;
			}
			if( dem == 9)
			{
				dem = 10;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socot)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socot)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socot)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socot)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socot)) dem++;
			if(dem == socot) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
//==============================AN CO TRO MAN HINH CONSOLE=======================
void AnConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
//==============================HIEN CON TRO MAN HINH CONSOLE================
void HienConTro()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// ============= DOI MAU CHU ================
void ChangeColor(int k)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, k);
}
//============================DO DAI SO DUONG==================
int DoDaiSoDuong(int a)
{
	if (a == 0) return 1;
	int dem = 0;
	while (a != 0)
	{
		a = a/10;
		dem++;
	}
	return dem;
}
//=========================LOC LAY SO=================================
int LaySo(int giatri, bool DiChuyenDeThoat, char &a) // Kiem tra Di chuyen co thoat khong va nhan phim vua nhan
{
	int i = DoDaiSoDuong(giatri); // Chong tran bit + khong cho backspace khong hop le
	HienConTro();
	unsigned int so = giatri;
	int b;
//	if (a <= 0) a = getch(); // clear a
	a = getch();
	while (a != 13)
	{
		if  ((DiChuyenDeThoat && a == -32) || a == 27 || a == 19)
		{
			break;
		}
		if ((a >= 48 && a <= 57) && i < 10) // nuot phim khi khong phai la so
		{
			if (so == 0 && a == 48)
			{
				
			}
			else
			{
				i++;
				b = a - 48;
				cout << b;
				so = so * 10 + b;
			}
		}
		if (a == 8 && i > 0) // Nguoi dung nhan backspace
		{
			i--;
			so = so/10;
			int x = wherex();
   			int y = wherey();
			gotoxy(x-1, y);
			cout << " ";
			if (!x) gotoxy(0,0);
			else gotoxy(x-1,y);
		}
		a = getch();
	}
	return so;
}


//=================================CHU IN HOA=====================
char InHoa(char a)
{
	if (a >= 97 && a <= 122) // tu 'a' toi 'z'
	{
		a = a - 32;
	}
	return a;
}

void InHoaChuoi(string &s)
{
	for(int i=0;i<s.length();i++)
    {
    	s[i]=toupper(s[i]);
	}
}
// ====================== SO SANH CHUOI SO =======================
int SoSanhChuoiSo(string &a, string &b)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		if (a[i] < b[i])
		{
			return -1;
		}
	}
	return 0;
}
// ==================== VE NUT ==========================
void veNut(int dai, int rong, int x, int y, string text, int mau )
{
	for(int i = 0; i < dai; i++)
	{
		for(int j = 0; j < rong; j++)
		{
			ChangeColor(mau);
			gotoxy(x+j,y+i);
			cout << " ";
		}
	}
	ChangeColor(mau);
	gotoxy(x+(rong-text.length())/2,y+(dai/2));
	cout << text;
	ChangeColor(15);
}
// ==================== VE NUT MAIN MENU ==========================
void veNutMenu(int dai, int x, int y, string text, int mau )
{
	for(int i = 0; i < dai; i++)
	{
		ChangeColor(mau);
		gotoxy(x,y+i);
		cout << "                                        ";
		
	}
	ChangeColor(mau);
	gotoxy(x+(40-text.length())/2,y+(dai/2));
	cout << text;
	ChangeColor(15);
}
// ====================== VE KHUNG THEO SO COT =======================
void vekhungDS(int dai, int rong, int socot)
{
	int x = rong/socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socot)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socot)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socot)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socot)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socot)) dem++;
			if(dem == socot) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
// ====================== VE KHUNG LOP THEO SO COT =======================
void VeKhungDSLop(int dai, int rong, int socot)
{
	
	int x = rong/socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if(dem == 2)
			{
				dem++;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socot)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socot)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socot)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socot)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socot)) dem++;
			if(dem == socot) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
// ====================== VE KHUNG LOP THEO SO COT =======================
void VeKhungDSLop1(int dai, int rong, int socot)
{
	
	int x = rong/socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if(dem == 1)
			{
				dem++;
			}
			if(dem == 3)
			{
				dem = 8;
			}
			if( dem == 9)
			{
				dem ++;
			}
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socot)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socot)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socot)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socot)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socot)) dem++;
			if(dem == socot) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
// ====================== VE KHUNG THONG BAO =======================
void vekhungTB(int dai, int rong)
{
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else cout << ngang;
			}
			else if (i == 1)
			{
				if (j == 0 || j == rong-1) cout << doc;
				else if(j == (rong - 9)/2)
				{
					cout << "THONG BAO";
					j = j+8;
				}
				else cout << " ";
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else cout << ngang;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			//sleep(1);
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
// ====================== IN THONG BAO =======================
void InTB(string text, int x, int y)
{
	int i = 0;
	int j = 0;
	int dem = 0;
	string temp;
	gotoxy(x,y);
	if(text.length() <= 33)
	{
		cout << text;
	}
	else
	{
		while(text.length() > 33)
		{
			gotoxy(x,y+dem);
			for(i = 0; i < 33; i++)
			{
				if (text[i] == ' ')
				{
					j = i;
				}
			}
			if(text [32] != ' ')
			{
				temp = text.substr(0,j);
				text.erase(0,j+1);
				cout << temp;
			}
			else
			{
				temp = text.substr(0,i);
				text.erase(0,i);
				cout << temp;
			}
			dem++;
		}
		gotoxy(x,y+dem);
		cout << text;
	}
}
// ====================== XOA THONG BAO =======================
void XoaTB(int x, int y)
{
	for (int i = 0; i < 6;i++)
	{
		gotoxy(x+1,y+3+i);
		cout << "                                  ";
	}
}

// ====================== IN NOI DUNG CAU HOI =======================
void InNDCH (string text)
{
	int i = 0;
	int j = 0;
	int k = 0;
	string temp1;
	gotoxy(20,5);
	if (text.length() < 95)
	{
		gotoxy(20,5);
		cout << text;
	}
	else
	{
		while(text.length() >= 95)
		{
			for(i = 0; i < 96; i++)
			{
				if (text[i] == ' ')
				{
					j = i;
				}
			}
			if(text [95] != ' ')
			{
				temp1 = text.substr(0,j);
				text.erase(0,j+1);
				gotoxy(20,5+k);
				cout << temp1;
			}
			else
			{
				temp1 = text.substr(0,i);
				text.erase(0,i);
				gotoxy(20,5+k);
				cout << temp1;
			}
			k += 2;
			if (k > 5)
			{
				break;
			}
		}
		if(k < 5)
		{
			gotoxy(20,5+k);
			cout << text;
		}
	}
}
// ====================== IN NOI DUNG CAU HOI =======================
void InDA_XemCH (string text)
{
	int i = 0;
	int j = 0;
	int k = 0;
	string temp1;
	if (text.length() < 95)
	{
		cout << text;
	}
	else
	{
		while(text.length() >= 95)
		{
			for(i = 0; i < 96; i++)
			{
				if (text[i] == ' ')
				{
					j = i;
				}
			}
			if(text [95] != ' ')
			{
				temp1 = text.substr(0,j);
				text.erase(0,j+1);
				gotoxy(20,wherey()+k);
				cout << temp1;
			}
			else
			{
				temp1 = text.substr(0,i);
				text.erase(0,i);
				gotoxy(20,wherey()+k);
				cout << temp1;
			}
			k += 2;
			if (k > 3)
			{
				break;
			}
		}
		if(k < 3)
		{
			gotoxy(20,wherey()+k);
			cout << text;
		}
	}
}
// ====================== VE KHUNG CH THEO SO COT =======================
void vekhungDSCH(int dai, int rong, int socot)
{
	int x = rong/socot;
	int dem = 1;
	for (int i = 0; i < dai; i++)
	{
		for (int j = 0; j < rong; j++)
		{
			if (i == 0)
			{
				if (j == 0) cout << traitren;
				else if (j == rong-1) cout << phaitren;
				else if (j == (rong/socot)*dem) cout << ngangxuong;
				else cout << ngang;
			}
			else if(i == 1)
			{
				if (j == 0|| j == 24 || j== 48 || j == rong-1) cout << doc;
				else if(j == 11)
				{
					cout << "ID";
					j += 1;
				}
				else if(j == 24+ 10)
				{
					cout << "MA MH";
					j += 4;
				}
				else if(j == 48 + 28)
				{
					cout << "NOI DUNG CAU HOI";
					j += 15;
				}
				else cout << " ";
			}
			else if(i == 2)
			{
				if(j == 0) cout << docphai;
				else if (j == rong -1) cout << doctrai;
				else if (j == (rong/socot)*dem) cout << giua;
				else cout << ngang;
			}
			else if (i == dai-1)
			{
				if (j == 0) cout << traiduoi;
				else if (j == rong-1) cout << phaiduoi;
				else if (j == (rong/socot)*dem) cout << nganglen;
				else cout << ngang;
			}
			else if(j == (rong/socot)*dem)
			{
				cout << doc;
			}
			else
			{
				if (j == 0 || j == rong-1) cout << doc;
				else cout << " ";
			}
			if(j == dem*(rong/socot)) dem++;
			if(dem == 3) dem = 1;
		}
		gotoxy(wherex()-rong,wherey()+1);
	}
}
// ====================== DAO CHUOI =======================
string DaoChuoi(string text)
{
	int i = 0;
	string temp = text;
	for(int j = text.length()-1; j > -1; j--)
	{
		temp[i] = text[j];
		i++;
	}
	return temp;
}
// ====================== VE KHUNG NHAP CAU HOI =======================
void vekhungThemCH()
{
	gotoxy(5,2);
	veKhung(36,125);
	gotoxy(6,7-2);
	cout << "NOI DUNG CH: ";
	gotoxy(18,6-2);
	veKhung(7,101);
	gotoxy(6,16-2);
	cout << "DAP AN A: ";
	gotoxy(18,15-2);
	veKhung(5,101);
	gotoxy(6,22-2);
	cout << "DAP AN B: ";
	gotoxy(18,21-2);
	veKhung(5,101);
	gotoxy(6,28-2);
	cout << "DAP AN C: ";
	gotoxy(18,27-2);
	veKhung(5,101);
	gotoxy(6,34-2);
	cout << "DAP AN D: ";
	gotoxy(18,33-2);
	veKhung(5,101);
	veNut(3,11,59,38,"LUU",30);
}
void vekhungNhapTG()
{
	gotoxy(45,16);
	veKhung(9,80);
	gotoxy(52,20);
	cout << "NHAP THOI GIAN: ";
	gotoxy(67,19);
	veKhung(3,7);
	gotoxy(75,20);
	cout << "(PHUT)";
	gotoxy(95,20);
	cout << "NHAP SO CAU THI: ";
	gotoxy(111,19);
	veKhung(3,7);
}
void InTen()
{
	gotoxy(120,45);
	cout << "N17DCCN150 - NGUYEN DUY TAN";
}
#endif
