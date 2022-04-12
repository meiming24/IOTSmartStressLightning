#ifndef THOITIET_H
#define THOITIET_H

class Thoi_tiet{
	protected:
		int do_Am, nhiet_Do;
		float toc_Do_Gio;
		bool trang_Thai;
	public:
		Thoi_tiet() {
			nhiet_Do = 0;
			do_Am = 0;
			toc_Do_Gio = 0;
		}
		
		void nhap(){
			cout<<endl<<"\t\tNhiet do: "; 
			cin >> nhiet_Do;
			cout<<"\t\tDo am: "; 
			cin >> do_Am;
			cout<<"\t\tToc do gio: "; 
			cin >> toc_Do_Gio;
		}
		
		void set_Nhiet_Do(int nhiet_Do_Moi) {
			this->nhiet_Do = nhiet_Do_Moi;
		}
		
		int get_Nhiet_Do(){
			return nhiet_Do;
		}
		
		void set_Do_Am(int do_Am_Moi) {
			this->do_Am = do_Am_Moi;
		}
		
		int get_Do_Am(){
			return do_Am;
		}
		
		void set_Toc_Do_Gio(float toc_Do_Gio_Moi) {
			this->toc_Do_Gio = toc_Do_Gio_Moi;
		}
		
		float get_Toc_Do_Gio(){
			return toc_Do_Gio;
		}
		
		bool get_Trang_Thai_Thoi_Tiet(){
			if (nhiet_Do<=20 && do_Am>=80 && toc_Do_Gio<=3) {
				trang_Thai = true;
			}
			else{
				trang_Thai = false;
			}
			return trang_Thai; 
		}
		
};

#endif
