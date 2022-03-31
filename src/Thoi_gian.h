#ifndef THOIGIAN_H
#define THOIGIAN_H

class Thoi_gian {
	protected:
		int gio;
		int phut;
		int giay;
	public:
		Thoi_gian(){
			int gio = phut = giay = 0;
		}
		
		Thoi_gian(int gio_Moi, int phut_Moi, int giay_Moi){
			gio = gio_Moi;
			phut = phut_Moi;
			giay = giay_Moi;
		}
		
		void set_Thoi_Gian(int a, int b, int c){
			gio = a; phut = b; giay = c;
		}
		
		void nhap_Thoi_Gian(){
			char c;
//			cout << "Nhap thoi gian (gio:phut:giay): ";
			cin >> gio >> c >> phut >> c >> giay;
		}
		
		void chuan_Hoa_Thoi_Gian(){
			phut += giay/60;
			giay %= 60;
			gio += phut/60;
			phut %= 60;
			gio %= 24;
		}
		
		void in_Thoi_Gian(){
			if((giay < 0 || phut < 0 || gio < 0) || (giay > 60 || gio > 60 || gio > 24)) {
				chuan_Hoa_Thoi_Gian();
			}
			if(gio >= 0 && gio <= 10) cout << "0" << gio << ":";
			else cout << gio << ":";
			if(phut >= 0 && phut <= 10) cout << "0" << phut << ":";
			else cout << phut << ":";
			if(giay >= 0 && giay <= 10) cout << "0" << giay << endl;
			else cout << giay << endl;
		}
		
		int get_Gio(){
			return gio;
		}
		
		int get_Phut(){
			return phut;
		}
		
		int get_Giay(){
			return giay;
		}
		
		int get_Khoang_Thoi_Gian (Thoi_gian thoi_Gian){
			return abs((thoi_Gian.get_Gio() * 60 * 60 + thoi_Gian.get_Phut() * 60 + thoi_Gian.get_Giay()) - (get_Gio() * 60 * 60 + get_Phut() * 60 + get_Giay()));
		}
				
};

#endif
