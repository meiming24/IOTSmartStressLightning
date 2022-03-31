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
		
		void set_Doi_Tuong(string t, int s){
			this->ten = t;
			this->so_Luong = s;
		}
		
		string get_Ten(){
			return this->ten;
		}
		int get_So_Luong(){
			return this->so_Luong;
		}
		
		void nhap_Doi_Tuong(){
			cout << endl << "Ten vat can: "; getline(cin, ten);
			cout << endl << "So luong: "; cin >> this->so_Luong;
			this->tong += this->so_Luong;
		}
		
		void in_Doi_Tuong(){
			cout << endl << "| " << setw(11) << this->ten << " | " << setw(11) << this->so_Luong << " |";
		}
};

#endif
