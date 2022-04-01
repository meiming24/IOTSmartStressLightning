#ifndef DEN_H
#define DEN_H
#include "Thoi_gian.h"

class Den {
	protected: 
		Thoi_gian thoi_Gian;
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
			thoi_Gian.set_Thoi_Gian(00, 00, 00);              //9h => dong_Ho(09:00:00)
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
		
		void set_Thoi_Gian_Cua_Den(int x){
			thoi_Gian_Cua_Den = x;
		}
		
		
		
		float get_Nang_Luong_Tieu_Thu () {
			nang_Luong_Tieu_Thu = cong_Suat * get_Thoi_Gian_Cua_Den ();
			return nang_Luong_Tieu_Thu;
		}
		
		Thoi_gian get_Thoi_Gian(){
			return thoi_Gian;
		}
		
//		void hoat_Dong() {
//			
//		}
		
		void xuat(){
//			hoat_Dong();
			if(trang_Thai == "ON") {
				cout << endl;
				cout <<"Den dang bat"<< endl;
				cout <<"Cong suat cua den la "<< get_Cong_Suat() <<" W"<< endl;
				cout <<"Pham vi hien tai cua den la "<< get_Pham_Vi() <<" m^2"<< endl;
				cout <<"Nang luong tieu thu cua den la "<< fixed << setprecision(2) << get_Nang_Luong_Tieu_Thu() <<" Wh"<< endl;
				cout << endl;
			}
			else {
				cout << endl;
				cout <<"Den dang tat"<< endl;
				cout << endl;
			} 
		}
};

#endif

