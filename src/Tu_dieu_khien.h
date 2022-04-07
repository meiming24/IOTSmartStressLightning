#ifndef TUDIEUKHIEN_H
#define TUDIEUKHIEN_H
#include "Den.h"
#include "Thoi_tiet.h"
#include <conio.h>
#include <windows.h>

class Tu_dieu_khien: protected Den{
	protected:
		Thoi_tiet thoi_Tiet;
		Thoi_gian dong_Ho;
		int so_Luong_Den;   
		int tong_Doi_Tuong;
		float tong_Tieu_Thu_Nang_Luong;
		Den *den = new Den[so_Luong_Den];
	public:

		Tu_dieu_khien(){
		}
		
		void nhap_Doi_Tuong(){
			tong_Doi_Tuong = 0;
			string ten;
			int so_Luong;
			cout << "\t\tTen doi tuong: "; 
			fflush(stdin);
			cin >> ten;
			cout << "\t\tSo luong: "; 
			cin >> so_Luong;
			tong_Doi_Tuong += so_Luong;
		}
		
		int get_Tong_Doi_Tuong(){
			return tong_Doi_Tuong;
		}
		
		void che_Do_Tu_Dong(){
			nhap_Thong_So_Kiem_Tra();
			xu_Ly_Trang_Thai_Den();
		}
		
		void nhap_Thong_Tin_Den(){
			cout << endl << "\tNhap so luong den thuc hien yeu cau cua ban: "; 
			cin >> so_Luong_Den;
			cout << endl << "\tNhap thong tin tung den: ";
			cout << endl;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << "\tDen[" << i + 1 <<"]: " << endl;
				den[i].nhap();
			}
		}
		
		void dieu_Chinh_Cong_Suat(){
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\tCong suat hien tai cua Den[" << i+1 << "] :" << den[i].get_Cong_Suat() << " W";
			}
			cout << endl;
			int cong_Suat_Thay_Doi;
			char c;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\tBan co muon thay doi cong suat Den[" << i+1 <<"] khong (Y: Yes/N: No): ";
				cin >> c;
				if(c == 'N') continue;
				else {
					do{					
						cout << endl << "\t\tCong suat moi cua Den[" << i+1 << "]: "; 
						cin >> cong_Suat_Thay_Doi;
						cout << endl;
						if(cong_Suat_Thay_Doi < 0){
							cout << endl << "\t\tCong suat khong the am !!!";
						}
					} while(cong_Suat_Thay_Doi < 0);
					den[i].set_Cong_Suat(cong_Suat_Thay_Doi);
				}
			}
			cout << endl << "\tSau khi dieu chinh cong suat cua " << so_Luong_Den << " den, thi cong suat tung den la: " << endl;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\t\tDen[" << i+1 << "]: " << den[i].get_Cong_Suat() << " W";
			}
		}
		
		void dieu_Chinh_Trang_Thai(){
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\tTrang thai hien tai cua Den[" << i+1 << "] :" << den[i].get_Trang_Thai();
			}
			cout << endl;
			string trang_Thai_Thay_Doi;
			char x;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\tBan co muon thay doi trang thai Den[" << i+1 << "] khong (Y:Yes / N:No): ";
				cin >> x;
				if (x == 'N') continue;
				else {
					cout << endl << "\t\tTrang thai moi cua Den[" << i+1 << "] (ON/OFF):"; 
					cin >> trang_Thai_Thay_Doi;
					cout << endl;
					den[i].set_Trang_Thai(trang_Thai_Thay_Doi);
				}
			}
			cout << endl << "\tTrang thai cua tung den sau khi thay doi la: " << endl;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\t\tDen[" << i+1 << "]: " << den[i].get_Trang_Thai();
			}
		}
		
		void nhap_Thong_So_Kiem_Tra(){
			cout << endl << "\tCac thong so can nhap: Thoi gian, Thoi tiet, Doi tuong." << endl;
			cout << endl << "\t*Thoi gian: " << endl;
			dong_Ho.nhap_Thoi_Gian();
			cout << endl << "\t*Thoi tiet:"; 
			thoi_Tiet.nhap();
			cout << endl << "\t*Doi tuong:" << endl;
			nhap_Doi_Tuong();
			cout << endl << endl << "\tHe thong da nhan cac thong so kiem tra !...";
		}
		
		void xu_Ly_Trang_Thai_Den(){
			for(int i = 0; i < so_Luong_Den; i++){
				if(den[i].get_Trang_Thai() == "OFF"){
					if(thoi_Tiet.get_Trang_Thai_Thoi_Tiet()){
						den[i].set_Trang_Thai("ON");
					}
				}
				if(den[i].get_Trang_Thai() == "ON"){
					cout << endl << "\tDen " << i+1 << " se co cong suat moi la: " << den[i].get_Cong_Suat() + get_Tong_Doi_Tuong() << "W, va se tro lai binh thuong sau khi doi tuong di qua !";
				}
			}
		}
		
		void tong_Tieu_Thu(){
			tong_Tieu_Thu_Nang_Luong = 0;
			for(int i = 0; i < so_Luong_Den; i++){
				hoat_Dong(den[i]);
				cout << endl << "\tLuong tieu thu nang luong cua Den [" << i+1 << "]: " << den[i].get_Nang_Luong_Tieu_Thu();
				tong_Tieu_Thu_Nang_Luong += den[i].get_Nang_Luong_Tieu_Thu();
			}
			cout << endl << "\tTong luong tieu thu nang luong cua " << so_Luong_Den << " den la: " << tong_Tieu_Thu_Nang_Luong;
		}
		
		void hoat_Dong(Den &den){
			
			int gio_Trong_Ngay[24];

			for(int i = 0; i < 24; i++){
				if(i > 5 && i < 19) gio_Trong_Ngay[i] = 0;
				else gio_Trong_Ngay[i] = 1;
			}
			
			int start = den.get_Thoi_Gian().get_Gio();
			int end = dong_Ho.get_Gio();
			
			if(gio_Trong_Ngay[end] == 1)  den.set_Trang_Thai("ON");
			else den.set_Trang_Thai("OFF");
			
			int dem1(0), dem0(0);
			
			for(int i = start; i < end; i++){
				if(gio_Trong_Ngay[i] == 1) dem1++;
				else dem0++;
			}		
			
			
			float NLTT = dem1 * 60 * 60 * den.get_Cong_Suat();
			float NLMT = dem0 * 60 * 60 * den.get_Cong_Suat() * 0.75;
			
			if(NLMT >= NLTT){
				den.set_Nang_Luong_Tieu_Thu(0);
				den.set_Nang_Luong_Mat_Troi(NLMT - NLTT);
			}
			else {
				den.set_Nang_Luong_Mat_Troi(0);
				den.set_Nang_Luong_Tieu_Thu(NLTT - NLMT);
			}
		}
		
		void xuat_Thong_Tin_Den(){
			cout << endl << "\tThong tin cac den: " << endl;
			for(int i = 0; i < so_Luong_Den; i++){
				hoat_Dong(den[i]);
//				xu_Ly_Trang_Thai_Den();
				den[i].set_Thoi_Gian_Cua_Den(den[i].thoi_Gian.get_Khoang_Thoi_Gian(dong_Ho));
				den[i].thoi_Gian = dong_Ho;
				cout << endl << endl << "\t* Den [" << i+1 <<"] : " << endl;
				den[i].xuat();
				cout << "\t\tDong ho: ";
				den[i].thoi_Gian.in_Thoi_Gian();
			}
		}
		
		void he_Thong_Dieu_Khien(){
			cout << endl << "                                      ----- THUC HIEN HE THONG -----                         ";
			cout << endl << "                      ______________________________________________________________         ";
			cout << endl << endl;
			nhap_Thong_Tin_Den();
			cout << endl << "Nhan phim bat ky de bat dau he thong !";
			getch();
			system("cls");
			cout << endl << "                                                                                             ";
			cout << endl << "                                              ...WELLCOME...                                 "; 
			cout << endl << "                      Chao mung ban den voi he thong mo phong den duong thong minh!          ";
			cout << endl << "                                     - SMART STRESS LIGHTNING SYSTEM-                        ";
			cout << endl << "                                                                                             ";
			cout << endl << "                                                                                             ";
			cout << endl << "                      ----------------------------START------------------------------        ";
			while(true){
				cout << endl;
				cout << endl << "                            _________________________________________________";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |              HE THONG DIEU KHIEN                |";
				cout << endl << "                           |_________________________________________________|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (1): Dieu chinh cong suat den                  |";
				cout << endl << "                           |-------------------------------------------------|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (2): Dieu chinh trang thai den(ON/OFF)         |";
				cout << endl << "                           |-------------------------------------------------|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (3): Nhap thong so kiem tra den                |";
				cout << endl << "                           |-------------------------------------------------|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (4): Xem thong tin den                         |";
				cout << endl << "                           |-------------------------------------------------|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (5): Xem nang luong tieu thu dien cua den      |";
				cout << endl << "                           |-------------------------------------------------|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (0): Thoat chuong trinh                        |";
				cout << endl << "                           |_________________________________________________|";
				
				int lua_Chon;
				cout << endl << endl << "\tNhap lua chon cua ban(0 -> 5): "; cin >> lua_Chon;
				system("cls");
				switch(lua_Chon){
					case 1: 
						dieu_Chinh_Cong_Suat(); 
						cout << endl << endl << "Nhan phim bat ky de tiep tuc."; getch(); system("cls");
						break;
					case 2: 
						dieu_Chinh_Trang_Thai();
						cout << endl << endl << "Nhan phim bat ky de tiep tuc."; getch(); system("cls");
						break;
					case 3: 
						nhap_Thong_So_Kiem_Tra();
						cout << endl << endl << "Nhan phim bat ky de tiep tuc."; getch(); system("cls");
						break;
					case 4: 
						tong_Tieu_Thu();
						cout << endl << endl << "Nhan phim bat ky de tiep tuc."; getch(); system("cls");
						break;
					case 5: 
						xuat_Thong_Tin_Den();
						cout << endl << endl << "Nhan phim bat ky de tiep tuc."; getch(); system("cls");
						break;
					case 0:
						cout << endl << endl;
						cout << endl << "                                         ----- KET THUC HE THONG -----                         ";
						cout << endl << "                       ------------------------------END------------------------------         ";
						cout << endl << "            __________________________________________________________________________________";
						return; break;
					default: 
						cout << endl << "\tKhong co chuc nang nay!";
						cout << endl << "\tNhan phim bat ky de quay lai he thong."; getch(); system("cls");
				}
			}
		}
};

#endif
