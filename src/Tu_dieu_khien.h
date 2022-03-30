#ifndef TUDIEUKHIEN_H
#define TUDIEUKHIEN_H

class Tu_dieu_khien{
	protected:
		Den *den;
		int so_Luong;
	public:
		Tu_dieu_khien(){
			
		}
		
		void dieu_Chinh_Cong_Suat(){
			int cong_Suat_Thay_Doi;
			for(int i = 0; i < this->so_Luong; i++){
				cout << endl << "Nhap luong cong suat thay doi cua den so " << i+1 << " :" ; cin >> cong_Suat_Thay_Doi;
				if(cong_Suat_Thay_Doi >= 0){
					den[i].cong_Suat += cong_Suat_Thay_Doi;
				} 
				else {
					den[i].cong_Suat -= cong_Suat_Thay_Doi;
				}
			}
			cout << endl << "Sau khi dieu chinh cong suat cua " << this->so_Luong << "den, thi cong suat tung den la: ";
			for(int i = 0; i < this->so_Luong; i++){
				cout << endl << "Den " << i << ": " << den[i].get_Cong_Suat();
			}
		}
		
		void dieu_Chinh_Trang_Thai(){
			string trang_Thai_Thay_Doi;
			for(int i = 0; i < this->so_Luong; i++){
				cout << endl << "Nhap trang thai thay doi cua den so " << i+1 << " (ON/OFF):"; cin >> trang_Thai_Thay_Doi;
				den[i].trang_Thai = trang_Thai_Thay_Doi;
			}
		}
		
		void tong_Tieu_Thu(){
			float tong_Tieu_Thu_Nang_Luong;
			for(int i = 0; i < this->so_Luong; i++){
				tong_Tieu_Thu_Nang_Luong += den[i].get_Tieu_Thu_Nang_Luong();
			}
			cout << endl << "Tong luong tieu thu nang luong cua " << this->so_Luong << " den la: " << tong_Tieu_Thu_Nang_Luong;
		}
};

#endif
