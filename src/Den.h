#ifndef DEN_H
#define DEN_H

class Den {
	protected:
		string trang_Thai;
		float tieu_Thu_Nang_Luong, cong_Suat, pham_Vi, 
		int thoi_Gian_Sang, cuong_Do_Sang;
	public:
		Den(){
			trang_Thai = "Binh thuong";
			cong_Suat = 150;
			pham_Vi = 150;
			thoi_Gian_Sang = 0;
			tieu_thu_Nang_Luong = 0;		
		}
		
		void set_Trang_Thai(string trang_Thai_Moi) {
			this.trang_Thai = trang_Thai_Moi;
		}
		
		string get_Trang_Thai(){
			return trang_Thai;
		}
		
		void setThoi_Gian_Sang(int thoi_Gian_Sang_Moi) {
			this.thoi_Gian_Sang = thoi_Gian_Sang_Moi;
		}
		
		int get_Thoi_Gian_Sang() {
			return thoi_Gian_Sang;
		}
		
		void set_Cong_Suat(float cong_Suat_Moi) {
			this.cong_Suat = cong_Suat_Moi;
		}
		
		float get_Cong_Suat() {
			return cong_Suat;
		}
		
		void set_Pham_Vi(float pham_Vi_Moi) {
			this.pham_Vi = pham_Vi_Moi;
		}
		
		float get_Pham_Vi() {
			return pham_Vi;
		}
		
		void set_Cuong_Do_Sang(int cuong_Do_Sang_Moi) {
			this.cuong_Do_Sang = cuong_Do_Sang_Moi;
		}
		
		int get_Cuong_Do_Sang() {
			return cuong_Do_Sang;
		}
		
		float get_Tieu_Thu_Nang_Luong () {
			this.tieu_Thu_Nang_Luong = this.cong_Suat * this.thoi_Gian_Sang;
			return this.tieu_Thu_Nang_Luong;
		}
};

#endif
