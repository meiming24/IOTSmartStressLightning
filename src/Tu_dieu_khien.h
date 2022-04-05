#ifndef TUDIEUKHIEN_H
#define TUDIEUKHIEN_H
#include "Den.h"
#include "Thoi_tiet.h"
//#include "Doi_tuong.h"
#include <conio.h>

class Tu_dieu_khien: protected Den{
	protected:
		Thoi_tiet thoi_Tiet;
//		Doi_tuong doi_Tuong;
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
			char tiep = 'c';
			do{
				cout << endl << "Ten doi tuong: "; 
				fflush(stdin);
				cin >> ten;
				cout << endl << "So luong: "; 
				cin >> so_Luong;
				tong_Doi_Tuong += so_Luong;
				cout << endl << "Ban muon nhap them doi tuong (YES: c): "; cin >> tiep;
			} while (tiep == 'c');
		}
		
		int get_Tong_Doi_Tuong(){
			return tong_Doi_Tuong;
		}
		
		void che_Do_Tu_Dong(){
			nhap_Thong_So_Kiem_Tra();
			xu_Ly_Trang_Thai_Den();
		}
		
		void nhap_Thong_Tin_Den(){
			cout << endl << "Nhap so luong den thuc hien yeu cau cua ban: "; 
			cin >> so_Luong_Den;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl;
				cout << "Moi ban nhap thong tin den " << i + 1 <<" : " << endl;
				den[i].nhap();
			}
		}
		
		void dieu_Chinh_Cong_Suat(){
			int cong_Suat_Thay_Doi;
			char c;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "Ban co muon thay doi cong suat den " << i+1 <<" khong (Y: Yes/N: No): ";
				cin >> c;
				if(c == 'N') continue;
				else {
					do{					
						cout << endl << "Nhap cong suat moi cua den so " << i+1 << " : " ; 
						cin >> cong_Suat_Thay_Doi;
						if(cong_Suat_Thay_Doi < 0){
							cout << endl << "Cong suat khong the am !!!";
						}
					} while(cong_Suat_Thay_Doi < 0);
					den[i].set_Cong_Suat(cong_Suat_Thay_Doi);
				}
			}
			cout << endl << "Sau khi dieu chinh cong suat cua " << so_Luong_Den << "den, thi cong suat tung den la: ";
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "Den " << i << ": " << den[i].get_Cong_Suat();
			}
		}
		
		void dieu_Chinh_Trang_Thai(){
			string trang_Thai_Thay_Doi;
			char x;
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "Ban co muon thay doi trang thai den " << i+1 << " khong (Y:Yes / N:No): ";
				cin >> x;
				if (x == 'N') continue;
				else {
					cout << endl << "Nhap trang thai thay doi cua den so " << i+1 << " (ON/OFF):"; cin >> trang_Thai_Thay_Doi;
					den[i].set_Trang_Thai(trang_Thai_Thay_Doi);
				}
			}
			cout << endl << "Trang thai cua tung den sau khi thay doi la: ";
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "Den " << i << ": " << den[i].get_Trang_Thai();
			}
		}
		
		void nhap_Thong_So_Kiem_Tra(){
			cout << endl << "Nhap vao thoi gian ban muon kiem tra he thong den !!!" << endl;
			dong_Ho.nhap_Thoi_Gian();
			cout << endl << "Nhap cac chi so thoi tiet hien tai !!!"; 
			thoi_Tiet.nhap();
			cout << endl << "Nhap doi tuong !!!";
			nhap_Doi_Tuong();
			cout << endl << "Vay tong so doi tuong la: " << get_Tong_Doi_Tuong();
		}
		
		void xu_Ly_Trang_Thai_Den(){
			for(int i = 0; i < so_Luong_Den; i++){
				if(den[i].get_Trang_Thai() == "OFF"){
					if(thoi_Tiet.get_Trang_Thai_Thoi_Tiet()){
						den[i].set_Trang_Thai("ON");
					}
				}
				if(den[i].get_Trang_Thai() == "ON"){
					cout << endl << "Den " << i+1 << " se co cong suat moi la: " << den[i].get_Cong_Suat() + get_Tong_Doi_Tuong() << "W, va se tro lai binh thuong sau khi doi tuong di qua !";
				}
			}
		}
		
		void tong_Tieu_Thu(){
			for(int i = 0; i < so_Luong_Den; i++){
				cout << endl << "Luong tieu thu nang luong cua den " << i+1 << " :" << den[i].get_Nang_Luong_Tieu_Thu();
				tong_Tieu_Thu_Nang_Luong += den[i].get_Nang_Luong_Tieu_Thu();
			}
			cout << endl << "Tong luong tieu thu nang luong cua " << so_Luong_Den << " den la: " << tong_Tieu_Thu_Nang_Luong;
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
			for(int i = 0; i < so_Luong_Den; i++){
				hoat_Dong(den[i]);
				xu_Ly_Trang_Thai_Den();
				den[i].set_Thoi_Gian_Cua_Den(den[i].thoi_Gian.get_Khoang_Thoi_Gian(dong_Ho));
				den[i].thoi_Gian = dong_Ho;
				den[i].xuat();
				den[i].thoi_Gian.in_Thoi_Gian();
			}
		}
		
		void he_Thong_Dieu_Khien(){
			nhap_Thong_Tin_Den();
			while(true){
				cout << "__________________________________________________";
				cout << endl << "|                                                 |";
				cout << endl << "|              HE THONG DIEU KHIEN                |";
				cout << endl << "|_________________________________________________|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (1): Dieu chinh cong suat den                  |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (2): Dieu chinh trang thai den(ON/OFF)         |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (3): Nhap thong so kiem tra den                |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (4): Xem thong tin den                         |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (5): Xem nang luong tieu thu dien cua den      |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (0): Thoat chuong trinh                        |";
				cout << endl << "|_________________________________________________|";
				
				
				int lua_Chon;
				cout << endl << "Nhap lua chon cua ban(0 -> 5): "; cin >> lua_Chon;
				switch(lua_Chon){
					case 1: 
						dieu_Chinh_Cong_Suat(); 
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch(); cout << endl;
						break;
					case 2: 
						dieu_Chinh_Trang_Thai();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch(); cout << endl;
						break;
					case 3: 
						nhap_Thong_So_Kiem_Tra();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch(); cout << endl;
						break;
					case 4: 
						tong_Tieu_Thu();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch(); cout << endl;
						break;
					case 5: 
						xuat_Thong_Tin_Den();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch(); cout << endl;
						break;
					case 0: return; break;
					default: 
						cout << endl << "Khong co chuc nang nay!";
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch();
				}
			}
		}
};

#endif
