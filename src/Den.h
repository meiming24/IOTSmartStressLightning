#ifndef DEN_H
#define DEN_H
#include "Thoi_gian.h"

class Den {
	public:
		Thoi_gian dong_Ho;.
	protected:
		bool trang_Thai;
		float cong_Suat, pham_Vi, nang_Luong_Tieu_Thu, nang_Luong_Mat_Troi; 
		int thoi_Gian_Cua_Den;
		string thoi_Gian;
	public:
		Den(){
			trang_Thai = false;
			cong_Suat = 150;
			pham_Vi = cong_Suat * 0.75;
			thoi_Gian_Cua_Den = 0;
			nang_Luong_Tieu_Thu = 0;
			nang_Luong_Mat_Troi = 0;
			thoi_Gian = dong_Ho.get_Thoi_Gian();		
		}
		
		void nhap(){
			cout <<"Nhap trang thai cua den (1: bat / 0: tat): "; cin >> trang_Thai;
			cout <<"Nhap cong suat cua den: "; cin >> cong_Suat;
		}
		
		void set_Trang_Thai(bool trang_Thai_Moi) {
			this->trang_Thai = trang_Thai_Moi;
		}
		
		bool get_Trang_Thai(){
			return trang_Thai;
		}
		
		void set_Cong_Suat(float cong_Suat_Moi) {
			this->cong_Suat = cong_Suat_Moi;
		}
		
		float get_Cong_Suat() {
			return cong_Suat;
		}
		
		float get_Pham_Vi() {
			return pham_Vi;
		}
		
		float get_Nang_Luong_Tieu_Thu () {
			this->nang_Luong_Tieu_Thu = this->cong_Suat * get_Thoi_Gian_Cua_Den();
			return this->nang_Luong_Tieu_Thu;
		}
		
		int get_Thoi_Gian_Cua_Den(){
			return dong_Ho.khoang_Thoi_Gian(thoi_Gian, dong_Ho.get_Thoi_Gian());
		}
		
		void hoat_Dong() {
			
			if(dong_Ho.get_Gio() >= 5 && dong_Ho.get_Gio() <= 16) {
				trang_Thai = false;
				nang_Luong_Tieu_Thu = 0;
				nang_Luong_Mat_Troi += (float) get_Thoi_Gian_Cua_Den() * 0.75 * cong_Suat;
			}
			
			else {
				trang_Thai = true;
				
				if(nang_Luong_Mat_Troi > 0 && nang_Luong_Mat_Troi >= get_Nang_Luong_Tieu_Thu()){
					nang_Luong_Mat_Troi -= get_Nang_Luong_Tieu_Thu();
				}
				else {
					nang_Luong_Tieu_Thu += get_Nang_Luong_Tieu_Thu();
				}
			}
		}
		
		void xuat(){
			hoat_Dong();
			if(trang_Thai = true) {
				cout << endl;
				cout <<"Den dang bat"<< endl;
				cout <<"Cong suat cua den la "<< cong_Suat <<" W"<< endl;
				cout <<"Pham vi hien tai cua den la "<< pham_Vi <<" m^2"<< endl;
				cout <<"Nang luong tieu thu cua den la "<< fixed << setprecision(2) << nang_Luong_Tieu_Thu <<" Wh"<< endl;
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
