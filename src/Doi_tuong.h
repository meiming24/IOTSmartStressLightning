#ifndef DOITUONG_H
#define DOITUONG_H

class Doi_tuong{
	protected:
		string ten;
		int so_Luong;
	public:
		static int tong;
		Doi_tuong(){
			so_Luong = 0;
		}
		
		void set_Vat_Can(string t, int s){
			this->ten = t;
			this->so_Luong = s;
		}
		
		string get_Ten(){
			return this->ten;
		}
		int get_So_Luong(){
			return this->so_Luong;
		}
		
		void nhap_Vat_Can(){
			cout << endl << "Ten vat can: "; getline(cin, ten);
			cout << endl << "So luong: "; cin >> this->so_Luong;
			this->tong += this->so_Luong;
		}
		
		void in_Vat_Can(){
			cout << endl << "| " << setw(11) << this->ten << " | " << setw(11) << this->so_Luong << " |";
		}
};

#endif
