#ifndef THOITIET_H
#define THOITIET_H

class Thoi_tiet
{
	protected:
//<<<<<<< HEAD
		int do_Am, nhiet_Do;
		float toc_Do_Gio;
	public:
		Thoi_tiet() {
			nhiet_Do = 0;
			do_Am = 0;
			toc_Do_Gio = 0;
		}
		
		void nhap(){
			cout<<"Nhap nhiet do hien tai: "; 
			cin >> nhiet_Do;
			cout<<"Nhap do am hien tai: "; 
			cin >> do_Am;
			cout<<"Nhap toc do gio hien tai: "; 
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
		
		void xuat(){
			if (nhiet_Do<=20 && do_Am>=80 && toc_Do_Gio<=3) {
				cout<<"Nhiet do hien tai la: "<< nhiet_Do <<" do C"<< endl;
				cout<<"Do am hien tai la: "<< do_Am <<"%"<< endl;
				cout<<"Toc do gio hien tai la: "<< fixed << setprecision(1) << toc_Do_Gio <<" m/s"<< endl;
				cout<<"Xuat hien suong mu, can bat den!"<<endl;
			}
			else{
				cout<<"Nhiet do hien tai la: "<< nhiet_Do <<" do C"<< endl;
				cout<<"Do am hien tai la: "<< do_Am <<"%"<< endl;
				cout<<"Toc do gio hien tai la: "<< fixed << setprecision(1) << toc_Do_Gio <<" m/s"<< endl;
				cout<<"Khong xuat hien suong mu, khong can bat den!"<<endl;
			} 
=======
		int do_Am;
		int cur_do_Am = 0;
	public:
		void nhap_Do_Am(){
			cout<< "\nNhap do am hien tai: " ; cin>>cur_do_Am ;
		}
		void get_Do_Am() {
			showThoi_tiet();
			cout<<endl<<"Do am hien tai la: "<< cur_do_Am<<"%";
			bool check = true;
			
			while(check){
		 		if (cur_do_Am  > do_Am) {
			 		cout <<endl<<"Do am hien tai lon -Can tang  them do sang";
			 		check=false;
		 		}
				else {
					cout<<"\nKhong can tang  them do sang ";
					break;
				}
			}

		}
        void showThoi_tiet() {
        	cout<<endl<<"Do am ly tuong : "<< do_Am<< "%";
>>>>>>> 9f12610a352dd67a6c3cb319fa0f967d342700fd
		}
};

#endif
