#ifndef TUDIEUKHIEN_H
#define TUDIEUKHIEN_H
#include "Den.h"
#include "Thoi_tiet.h"
#include <conio.h>
#include <windows.h>
#include <iomanip>

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
			getline(cin, ten);
			cout << "\t\tSo luong: "; 
			cin >> so_Luong;
			tong_Doi_Tuong += so_Luong;
		}
		
		int get_Tong_Doi_Tuong(){
			return tong_Doi_Tuong;
		}
		
<<<<<<< HEAD
=======
		void che_Do_Tu_Dong(){
			nhap_Thong_So_Kiem_Tra();
			xu_Ly_Den();
		}
		
>>>>>>> a1e3b176c07785a209c011e6d25b55680a44966d
		void nhap_Thong_Tin_Den(){
			cout << endl << "\tNhap so luong den thuc hien yeu cau cua ban: "; 
			cin >> so_Luong_Den;
			cout << endl << "\tNhap thong tin tung den: ";
			cout << endl;
			float x;
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
			for(int i = 0; i < so_Luong_Den; i++){
				den[i].key = true;
			}
			cout << endl << "\tCac thong so can nhap: Thoi gian, Thoi tiet, Doi tuong." << endl;
			cout << endl << "\t*Thoi gian: " << endl;
			dong_Ho.nhap_Thoi_Gian();
			cout << endl << "\t*Thoi tiet:"; 
			thoi_Tiet.nhap();
			cout << endl << "\t*Doi tuong:" << endl;
			nhap_Doi_Tuong();
			cout << endl << endl << endl << endl << "\tHe thong da nhan du lieu kiem tra !";
			getch();
			cout << endl << endl <<  "\tDang phan tich du lieu..." << endl;
			getch();
			system("cls");
			cout << endl << "                       KET QUA";
			cout << endl << "           ___________________________________";
			cout << endl << "          | Thoi gian | Thoi tiet | Doi tuong |";
			cout << endl << "          |-----------|-----------|-----------|";
			xu_Ly_Thong_So_Kiem_Tra();
		}
		
		void xu_Ly_Thong_So_Kiem_Tra(){
			
			int gio_Trong_Ngay[24];

			for(int i = 0; i < 24; i++){
				if(i > 5 && i < 19) gio_Trong_Ngay[i] = 0;
				else gio_Trong_Ngay[i] = 1;
			}
			string x;
			if(gio_Trong_Ngay[dong_Ho.get_Gio()] == 0){
				x = "Ngay";
				if(thoi_Tiet.get_Trang_Thai_Thoi_Tiet()){
					cout << endl << "          |" << setw(7) << x << "    |     X     |" << setw(6) << get_Tong_Doi_Tuong() << "     |";
				}
				else cout << endl << "          |" << setw(7) << x << "    |     O     |" << setw(6) << get_Tong_Doi_Tuong() << "     |";
			}
			else {
				x = "Dem";
				if(thoi_Tiet.get_Trang_Thai_Thoi_Tiet()){
					cout << endl << "          |" << setw(7) << x << "    |     X     |" << setw(6) << get_Tong_Doi_Tuong() << "     |";
				}
				else cout << endl << "          |" << setw(7) << x << "    |     O     |" << setw(6) << get_Tong_Doi_Tuong() << "     |";
			}	
			cout << endl << "          !===================================!" << endl << endl;
			
<<<<<<< HEAD
=======
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\t\tThoi gian: "; den[i].get_Thoi_Gian().in_Thoi_Gian(); cout <<" - "; dong_Ho.in_Thoi_Gian();
			}
			
>>>>>>> a1e3b176c07785a209c011e6d25b55680a44966d
			xu_Ly_Den();
			cout << endl << "\tCu the: " << endl;
			for(int i = 0; i < so_Luong_Den; i++){
				float x;
				x = den[i].get_Cong_Suat() + get_Tong_Doi_Tuong();
<<<<<<< HEAD
				if(x >= 400) x = 400;
=======
				if(x > 400) x = 400;
>>>>>>> a1e3b176c07785a209c011e6d25b55680a44966d
				cout << endl << "\t*Den[" << i+1 << "]:";
				cout << endl << "\t\tTrang thai: " << den[i].get_Trang_Thai();				
				cout << endl << "\t\tCong suat: " << x;
				cout << endl;
			}
			
			cout << endl << endl << endl << endl << "------------------------------------------------------";
			cout << endl << "\t- Ghi chu -";
			cout << endl << endl << "\t*Thoi gian:";
			cout << endl << "\t\t6h -> 19h (cung ngay) : Ban ngay.";
			cout << endl << "\t\t19h -> 6h (hom sau) : Ban dem.";
			cout << endl << endl << "\t*Thoi tiet:";
			cout << endl << "\t\tX : Xuat hien suong mu, gay can tro tam nhin, he thong se tu dong bat den !";
			cout << endl << "\t\tO : Thoi tiet o trang thai binh thuong.";
			cout << endl << endl << "\t*Doi tuong:";
			cout << endl << "\t\tCong suat cua cac den se tu dong tang them 1 luong bang voi tong so doi tuong, va se tro lai ban dau khi khong con doi tuong nao !";
			cout << endl << "\t\t(Cong suat toi da: 400W)";
			tong_Tieu_Thu();
		}
		
		void xu_Ly_Den(){
			for(int i = 0; i < so_Luong_Den; i++){
				
				hoat_Dong(den[i]);
<<<<<<< HEAD
				den[i].set_Thoi_Gian_Cua_Den(den[i].thoi_Gian.get_Khoang_Thoi_Gian(dong_Ho));
=======
				
>>>>>>> a1e3b176c07785a209c011e6d25b55680a44966d
				
				if(den[i].get_Trang_Thai() == "OFF"){
					if(thoi_Tiet.get_Trang_Thai_Thoi_Tiet()){
						den[i].set_Trang_Thai("ON");
					}
				}
<<<<<<< HEAD
				
				float thoi_Gian_Bat_Dau = (float)den[i].thoi_Gian.get_Gio() + (float)den[i].thoi_Gian.get_Phut() / 60 + (float)den[i].thoi_Gian.get_Giay() / 3600;
				float thoi_Gian_Ket_Thuc = (float)dong_Ho.get_Gio() + (float)dong_Ho.get_Phut() / 60 + (float)dong_Ho.get_Giay() / 3600;
				if(thoi_Gian_Bat_Dau >= 0 && thoi_Gian_Bat_Dau < 6){
					float x, y, z;
					x = 6 - thoi_Gian_Bat_Dau;
					
					if(thoi_Gian_Ket_Thuc >= 6 && thoi_Gian_Ket_Thuc <= 18){
						y = 0;
						z = thoi_Gian_Ket_Thuc - 5;
					}
					else if(thoi_Gian_Ket_Thuc > 18 && thoi_Gian_Ket_Thuc < 24){
						y = thoi_Gian_Ket_Thuc - 18;
						z = 14;
					}
					else if(thoi_Gian_Ket_Thuc > 0){
						if(thoi_Gian_Ket_Thuc <= thoi_Gian_Bat_Dau){
							y = thoi_Gian_Ket_Thuc;
							z = 14;
						}
						else{
							x = 0;
							y = thoi_Gian_Ket_Thuc - thoi_Gian_Bat_Dau;
							z = 0;
						}
					}
					if(den[i].get_Cong_Suat() + get_Tong_Doi_Tuong() >= 400){
						den[i].set_Nang_Luong_Tieu_Thu((x + y) * 400);
						den[i].set_Nang_Luong_Mat_Troi(z * 400);
					}
					else{
						den[i].set_Nang_Luong_Tieu_Thu((x + y) * (den[i].get_Cong_Suat() + get_Tong_Doi_Tuong()));
						den[i].set_Nang_Luong_Mat_Troi(z * 0.75 * (den[i].get_Cong_Suat() + get_Tong_Doi_Tuong()));
					} 
				}
				else if(thoi_Gian_Bat_Dau >= 6 &&  thoi_Gian_Bat_Dau <= 18){
					float x, y, z;
					x = 0;
					
					if(thoi_Gian_Ket_Thuc >= 6 && thoi_Gian_Ket_Thuc <= 18){
						y = 0;
						if(thoi_Gian_Bat_Dau > thoi_Gian_Ket_Thuc){
							z = (19 - thoi_Gian_Bat_Dau) + (thoi_Gian_Ket_Thuc - 5);
						}
						else{
							z = thoi_Gian_Ket_Thuc - thoi_Gian_Bat_Dau;
						}
					}
					else if(thoi_Gian_Ket_Thuc > 18 && thoi_Gian_Ket_Thuc < 24){
						y = thoi_Gian_Ket_Thuc - 18;
						z = 19 - thoi_Gian_Bat_Dau;
						
					}
					else if(thoi_Gian_Ket_Thuc > 0){
						y = thoi_Gian_Ket_Thuc;
						z = 19 - thoi_Gian_Bat_Dau;
					}
					
					if(den[i].get_Cong_Suat() + get_Tong_Doi_Tuong() >= 400){
						den[i].set_Nang_Luong_Tieu_Thu((x + y) * 400);
						den[i].set_Nang_Luong_Mat_Troi(z * 400);
					}
					else{
						den[i].set_Nang_Luong_Tieu_Thu((x + y) * (den[i].get_Cong_Suat() + get_Tong_Doi_Tuong()));
						den[i].set_Nang_Luong_Mat_Troi(z * 0.75 * (den[i].get_Cong_Suat() + get_Tong_Doi_Tuong()));
					} 
				}
				else if(thoi_Gian_Bat_Dau > 18 &&  thoi_Gian_Bat_Dau < 24){
					float x, y, z;
					x = 24 - thoi_Gian_Bat_Dau;
					
					if(thoi_Gian_Ket_Thuc >= 6 && thoi_Gian_Ket_Thuc <= 18){
						y = 0;
						z = thoi_Gian_Ket_Thuc - 5;
					}
					else if(thoi_Gian_Ket_Thuc > 18 && thoi_Gian_Ket_Thuc < 24){
						if(thoi_Gian_Ket_Thuc >= thoi_Gian_Bat_Dau){
							x = 0;
							y = thoi_Gian_Ket_Thuc - thoi_Gian_Bat_Dau;
							z = 0;
						}
						else{
							y = thoi_Gian_Ket_Thuc - 18;
							z = 14;
						}
					}
					else if(thoi_Gian_Ket_Thuc > 0){
						y = thoi_Gian_Ket_Thuc;
						z = 0;
					}
					
					if(den[i].get_Cong_Suat() + get_Tong_Doi_Tuong() >= 400){
						den[i].set_Nang_Luong_Tieu_Thu((x + y) * 400);
						den[i].set_Nang_Luong_Mat_Troi(z * 400);
					}
					else{
						den[i].set_Nang_Luong_Tieu_Thu((x + y) * (den[i].get_Cong_Suat() + get_Tong_Doi_Tuong()));
						den[i].set_Nang_Luong_Mat_Troi(z * 0.75 * (den[i].get_Cong_Suat() + get_Tong_Doi_Tuong()));
					} 
=======
				 
				if(thoi_Tiet.get_Trang_Thai_Thoi_Tiet()){
					
				}
				else {
					
					int thoi_Gian_Bat_Dau = den[i].get_Thoi_Gian().get_Gio();
					int thoi_Gian_Ket_Thuc = dong_Ho.get_Gio();
					
					int gio_Trong_Ngay[24];
					float dem_Ngay(0);
					float dem_Dem(0);

					for(int i = 0; i < 24; i++){
						if(i > 5 && i < 19) gio_Trong_Ngay[i] = 0;
						else gio_Trong_Ngay[i] = 1;
					}
					
					//Neu thoi gian bat dau nho hon thoi gian ket thuc (TH: Bthg)
					if(thoi_Gian_Bat_Dau < thoi_Gian_Ket_Thuc){
						for(int i = thoi_Gian_Bat_Dau; i < thoi_Gian_Ket_Thuc; i++){
							if(gio_Trong_Ngay[i] == 0) dem_Ngay++;
							else dem_Dem++;
						}							
						
						//Neu bat dau la ban ngay						
						if(thoi_Gian_Bat_Dau > 5 && thoi_Gian_Bat_Dau < 19){
							//Neu ket thuc la ban ngay
							if(thoi_Gian_Ket_Thuc < 5 && thoi_Gian_Ket_Thuc > 19){
								dem_Ngay += ((float)den[i].thoi_Gian.get_Phut() / 60) + ((float)den[i].thoi_Gian.get_Giay() / 3600) + ((float)dong_Ho.get_Phut() / 60) + ((float)dong_Ho.get_Giay() / 3600);
							}
							//Neu ket thuc la ban dem
							else {
								dem_Ngay += ((float)den[i].thoi_Gian.get_Phut() / 60) + ((float)den[i].thoi_Gian.get_Giay() / 3600);
								dem_Dem += ((float)dong_Ho.get_Phut() / 60) + ((float)dong_Ho.get_Giay() / 3600);
							}
						}
						//Neu bat dau la ban dem
						else {
							//Neu ket thuc la ban ngay
							if(thoi_Gian_Ket_Thuc < 5 && thoi_Gian_Ket_Thuc > 19){
								dem_Ngay += ((float)dong_Ho.get_Phut() / 60) + ((float)dong_Ho.get_Giay() / 3600);
								dem_Dem += ((float)den[i].thoi_Gian.get_Phut() / 60) + ((float)den[i].thoi_Gian.get_Giay() / 3600);
							}
							//Neu ket thuc la ban dem
							else {
								dem_Dem += ((float)den[i].thoi_Gian.get_Phut() / 60) + ((float)den[i].thoi_Gian.get_Giay() / 3600) + ((float)dong_Ho.get_Phut() / 60) + ((float)dong_Ho.get_Giay() / 3600);
							}
						}
					
						den[i].set_Nang_Luong_Tieu_Thu(den[i].get_Cong_Suat() * dem_Dem);
						den[i].set_Nang_Luong_Mat_Troi(den[i].get_Cong_Suat() * dem_Ngay * 0.75);	
					}
					//Neu thoi gian bat dau lon hon thoi gian ket thuc (TH: DB)
					else {
						//Reset bien dem
						dem_Ngay = 0, dem_Dem = 0;
						for(int i = 0; i < thoi_Gian_Ket_Thuc; i++){
							if(gio_Trong_Ngay[i] == 0) dem_Ngay++;
							else dem_Dem++;
						}
						for(int i = thoi_Gian_Bat_Dau; i < 24; i++){
							if(gio_Trong_Ngay[i] == 0) dem_Ngay++;
							else dem_Dem++;
						}
						den[i].set_Nang_Luong_Tieu_Thu(den[i].get_Cong_Suat() * dem_Dem);
						den[i].set_Nang_Luong_Mat_Troi(den[i].get_Cong_Suat() * dem_Ngay * 0.75);
					}
					
>>>>>>> a1e3b176c07785a209c011e6d25b55680a44966d
				}
				den[i].thoi_Gian = dong_Ho;
			}
		}
		
		void tong_Tieu_Thu(){
			tong_Tieu_Thu_Nang_Luong = 0;
			for(int i = 0; i < so_Luong_Den; i++){
				tong_Tieu_Thu_Nang_Luong += den[i].get_Nang_Luong_Tieu_Thu();
				den[i].key = false;
			}
		}
		
		void in_Tong_Tieu_Thu(){
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "\tLuong tieu thu nang luong cua Den [" << i+1 << "]: " << fixed << setprecision(2) << den[i].get_Nang_Luong_Tieu_Thu();
			}
			cout << endl << "\tTong luong tieu thu nang luong cua " << so_Luong_Den << " den la: " << fixed << setprecision(2) << tong_Tieu_Thu_Nang_Luong;
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
		}
		
		void xuat_Thong_Tin_Den(){
			cout << endl;
			cout << "                                                     ---- BANG THONG TIN DEN ----" << endl;
			cout << "                _____________________________________________________________________________________________________________" << endl;
			cout << "               |  Den[i]  |  Trang thai  |  Cong suat  |  Pham vi  |     NN mat troi     |     NN tieu thu     |   Dong ho   |" << endl;
			cout << "               |==========|==============|=============|===========|=====================|=====================|=============|" << endl;
			for(int i = 0; i < so_Luong_Den; i++){
				float x;
				x = den[i].get_Cong_Suat() + get_Tong_Doi_Tuong();
				if(x > 400) x = 400;
				cout << "               |" << setw(5) << i+1 << "     |" << setw(8) << den[i].get_Trang_Thai() << "      |" << setw(8) << x << "     |" << setw(8) << den[i].get_Pham_Vi();
				cout << "   |" << setw(15) << fixed << setprecision(2) << den[i].get_Nang_Luong_Mat_Troi() << " Wh   |" << setw(15) << fixed << setprecision(2) << den[i].get_Nang_Luong_Tieu_Thu() << " Wh   |  "; 
				den[i].thoi_Gian.in_Thoi_Gian();
				cout << "   |" << endl;
				den[i].key = false;
			cout << "               |----------|--------------|-------------|-----------|---------------------|---------------------|-------------|" << endl;
			}
			cout << "               ===============================================================================================================" << endl;
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
				cout << endl << "                           |  (4): Xem nang luong tieu thu dien cua den      |";
				cout << endl << "                           |-------------------------------------------------|";
				cout << endl << "                           |                                                 |";
				cout << endl << "                           |  (5): Xem thong tin den                         |";
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
						in_Tong_Tieu_Thu();
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
						cout << endl << endl;
						return; break;
					default: 
						cout << endl << "\tKhong co chuc nang nay!";
						cout << endl << "\tNhan phim bat ky de quay lai he thong."; getch(); system("cls");
				}
			}
		}
};

#endif
