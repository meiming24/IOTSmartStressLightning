#ifndef TUDIEUKHIEN_H
#define TUDIEUKHIEN_H

class Tu_dieu_khien{
	protected:
		Den *den;
		Thoi_gian dong_Ho;
		int so_Luong;
	public:
		
		
		void nhap_So_Luong(){
			cout << endl << "Nhap so luong den thuc hien yeu cau cua ban: "; cin >> this->so_Luong;
		}
		
		void dieu_Chinh_Cong_Suat(){
			this->nhap_So_Luong();
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
			this->nhap_So_Luong();
			string trang_Thai_Thay_Doi;
			for(int i = 0; i < this->so_Luong; i++){
				cout << endl << "Nhap trang thai thay doi cua den so " << i+1 << " (ON/OFF):"; cin >> trang_Thai_Thay_Doi;
				den[i].trang_Thai = trang_Thai_Thay_Doi;
			}
		}
		
		void nhap_Thoi_Gian_Kiem_Tra(){
			this->nhap_So_Luong();
			cout << endl << "Nhap vao thoi gian ban muon kiem tra he thong den: ";
			dong_Ho.nhap_Thoi_Gian();
		}
		
		void tong_Tieu_Thu(){
			this->nhap_So_Luong();
			float tong_Tieu_Thu_Nang_Luong;
			for(int i = 0; i < this->so_Luong; i++){
				cout << endl << "Luong tieu thu nang luong cua den" << i+1 << " :" << den[i].get_Tieu_Thu_Nang_Luong();
				tong_Tieu_Thu_Nang_Luong += den[i].get_Tieu_Thu_Nang_Luong();
			}
			cout << endl << "Tong luong tieu thu nang luong cua " << this->so_Luong << " den la: " << tong_Tieu_Thu_Nang_Luong;
		}
		
		void thong_Tin_Den(){
			this->nhap_So_Luong();
			for(int i = 0; i < this->so_Luong; i++){
				den[i].xuat();
			}
		}
		
		void he_Thong_Dieu_Khien(){
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
				cout << endl << "|  (3): Nhap thoi gian kiem tra den               |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (4): Xem nang luong tieu thu dien cua den      |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (5): Xem thong tin den                         |";
				cout << endl << "|-------------------------------------------------|";
				cout << endl << "|                                                 |";
				cout << endl << "|  (0): Thoat chuong trinh                        |";
				cout << endl << "|_________________________________________________|";
				
				int lua_Chon;
				cout << endl << "Nhap lua chon cua ban(0 -> 4): "; cin >> lua_Chon;
				switch(lua_Chon){
					case 1: 
						this->dieu_Chinh_Cong_Suat(); 
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch();
						break;
					case 2: 
						this->dieu_Chinh_Trang_Thai();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch();
						break;
					case 3: 
						this->nhap_Thoi_Gian_Kiem_Tra();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch();
						break;
					case 4: 
						this->tong_Tieu_Thu();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch();
						break;
					case 5: 
						this->thong_Tin_Den();
						cout << endl << "Nhap phim bat ky de tiep tuc."; getch();
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
