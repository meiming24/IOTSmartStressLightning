#ifndef DEN_H
#define DEN_H
#include "Thoi_gian.h"

class Den {
	public:
		Thoi_gian thoi_Gian;
	protected: 
		string trang_Thai;
		float cong_Suat, pham_Vi, nang_Luong_Tieu_Thu, nang_Luong_Mat_Troi;
		int thoi_Gian_Cua_Den;
	public:
		Den(){
			trang_Thai = "OFF";
			cong_Suat = 150;
			pham_Vi = cong_Suat * 0.75;
			nang_Luong_Tieu_Thu = 0;
			nang_Luong_Mat_Troi = 0;
			thoi_Gian.set_Thoi_Gian(00, 00, 00);              
		}
		
		void nhap(){
			fflush(stdin);
			cout << endl <<"Nhap trang thai cua den (ON/OFF): "; cin >> trang_Thai;
			cout <<"Nhap cong suat cua den: "; cin >> cong_Suat;
		}
		
		void set_Trang_Thai(string trang_Thai_Moi) {
			trang_Thai = trang_Thai_Moi;
		}
		
		string get_Trang_Thai(){
			return trang_Thai;
		}
		
		void set_Cong_Suat(float cong_Suat_Moi) {
			cong_Suat = cong_Suat_Moi;
		}
		
		float get_Cong_Suat() {
			return cong_Suat;
		}
		
		float get_Pham_Vi() {
			pham_Vi = cong_Suat * 0.75;
			return pham_Vi;
		}
		
		int get_Thoi_Gian_Cua_Den () {
			return thoi_Gian_Cua_Den;
		}
		
		void set_Thoi_Gian_Cua_Den (int x){
			thoi_Gian_Cua_Den = x;
		}
		
		void set_Thoi_Gian(int x, int y, int z){
			thoi_Gian = Thoi_gian(x, y, z);
		}
		
		Thoi_gian get_Thoi_Gian(){
			return thoi_Gian;
		}
		
		
		float get_Nang_Luong_Tieu_Thu () {
			nang_Luong_Tieu_Thu = cong_Suat * thoi_Gian_Cua_Den;
			return nang_Luong_Tieu_Thu;
		}
		
		void set_Nang_Luong_Mat_Troi (float x){
			nang_Luong_Mat_Troi = x;
		}
		
		float get_Nang_Luong_Mat_Troi(){
			nang_Luong_Mat_Troi = cong_Suat * thoi_Gian_Cua_Den * 0.75;
			return nang_Luong_Mat_Troi;
		}
		
		void set_Nang_Luong_Tieu_Thu(float x){
			nang_Luong_Tieu_Thu = x;
		}
		
		void xuat(){
			if(trang_Thai == "ON") {
				cout << endl;
				cout <<"Den dang bat"<< endl;
				cout <<"Cong suat cua den la "<< get_Cong_Suat() <<" W"<< endl;
				cout <<"Pham vi hien tai cua den la "<< get_Pham_Vi() <<" m^2"<< endl;
				cout <<"Nang luong tieu thu cua den la "<< fixed << setprecision(2) << get_Nang_Luong_Tieu_Thu() <<" W"<< endl;
				cout << "Nang luong mat troi cua den la: " << fixed << setprecision(2) << get_Nang_Luong_Mat_Troi() <<" W" << endl << endl;
			}
			else if(trang_Thai == "OFF"){
				cout << endl;
				cout <<"Den dang tat"<< endl;
				cout << endl;
				cout <<"Nang luong tieu thu cua den la "<< fixed << setprecision(2) << get_Nang_Luong_Tieu_Thu() <<" Wh"<< endl;
				cout << "Nang luong mat troi cua den la: " << fixed << setprecision(2) << get_Nang_Luong_Mat_Troi() <<" W"<< endl << endl;
			} 
		}
};

#endif

