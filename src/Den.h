#ifndef DEN_H
#define DEN_H
#include "Thoi_gian.h"

class Den {
	public:
		Thoi_gian thoi_Gian;
		float nang_Luong_Tieu_Thu, nang_Luong_Mat_Troi;
		bool key;
	protected: 
		string trang_Thai;
		float cong_Suat, pham_Vi;
		int thoi_Gian_Cua_Den;
	public:
		Den(){
			key = true;
			trang_Thai = "OFF";
			cong_Suat = 150;
			pham_Vi = cong_Suat * 0.75;
			nang_Luong_Tieu_Thu = 0;
			nang_Luong_Mat_Troi = 0;
			thoi_Gian.set_Thoi_Gian(00, 00, 00);              
		}
		
		void nhap(){
			fflush(stdin);
			cout <<"\t\tTrang thai (ON/OFF): "; cin >> trang_Thai;
			cout <<"\t\tCong suat: "; cin >> cong_Suat;
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
		
		
		void set_Nang_Luong_Tieu_Thu(float x){
			nang_Luong_Tieu_Thu = x;
		}
		
		float get_Nang_Luong_Tieu_Thu() {
<<<<<<< HEAD
=======
			
//			if(key == true) {
//				if(thoi_Gian.get_Gio() > 5 && thoi_Gian.get_Gio() < 19){
//					thoi_Gian_Cua_Den -= 5 * 60 * 60;
//					nang_Luong_Mat_Troi = cong_Suat * thoi_Gian_Cua_Den * 0.75;
//					nang_Luong_Tieu_Thu = cong_Suat * 5 * 60 * 60;
//				} 
//				else if(thoi_Gian.get_Gio()  >= 18){
//					thoi_Gian_Cua_Den -= 13 * 60 * 60;
//					nang_Luong_Mat_Troi = cong_Suat * 13 * 0.75 * 60 * 60;
//					nang_Luong_Tieu_Thu = cong_Suat * thoi_Gian_Cua_Den;
//				}
//				else {
//					nang_Luong_Tieu_Thu = cong_Suat * thoi_Gian_Cua_Den;
//					nang_Luong_Mat_Troi = 0;
//				}
//			
//				if(nang_Luong_Mat_Troi < nang_Luong_Tieu_Thu){
//						set_Nang_Luong_Tieu_Thu(nang_Luong_Tieu_Thu - nang_Luong_Mat_Troi);
//						set_Nang_Luong_Mat_Troi(0.0);
//				}
//				else {
//					set_Nang_Luong_Mat_Troi( nang_Luong_Mat_Troi - nang_Luong_Tieu_Thu);
//					set_Nang_Luong_Tieu_Thu(0.0);
//				}
//			}
			
>>>>>>> a1e3b176c07785a209c011e6d25b55680a44966d
			return nang_Luong_Tieu_Thu;
		}
		
		void set_Nang_Luong_Mat_Troi (float x){
			nang_Luong_Mat_Troi = x;
		}
		
		float get_Nang_Luong_Mat_Troi(){
			return nang_Luong_Mat_Troi;
		}
		
		void xuat(){
			if(trang_Thai == "ON") {
				cout << endl;
				cout <<"\t\tTrang thai: ON"<< endl;
				cout <<"\t\tCong suat: "<< get_Cong_Suat() <<" W"<< endl;
				cout <<"\t\tPham vi: "<< get_Pham_Vi() <<" m^2"<< endl;
				cout <<"\t\tNang luong tieu thu: "<< fixed << setprecision(2) << get_Nang_Luong_Tieu_Thu() <<" W"<< endl;
				cout <<"\t\tNang luong mat troi: " << fixed << setprecision(2) << get_Nang_Luong_Mat_Troi() <<" W" << endl;
			}
			else if(trang_Thai == "OFF"){
				cout << endl;
				cout <<"\t\tTrang thai: OFF"<< endl;
				cout <<"\t\tCong suat: "<< get_Cong_Suat() <<" W"<< endl;
				cout <<"\t\tPham vi: 0 m^2"<< endl;
				cout <<"\t\tNang luong tieu thu: "<< fixed << setprecision(2) << get_Nang_Luong_Tieu_Thu() <<" Wh"<< endl;
				cout <<"\t\tNang luong mat troi: " << fixed << setprecision(2) << get_Nang_Luong_Mat_Troi() <<" W"<< endl;
			} 
		}
};

#endif
