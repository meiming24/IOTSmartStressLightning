#ifndef DOITUONG_H
#define DOITUONG_H

class Doi_tuong{
	protected:
		string ten;
		int so_Luong;
	public:
		Doi_tuong(){
		}
		
		Doi_tuong(string t, int s){
			ten = t;
			so_Luong = s;
		}
		
		string get_Ten(){
			return ten;
		}
		int get_So_Luong(){
			return so_Luong;
		}
		
		void nhap_Doi_Tuong(){
			cout << endl << "Ten doi tuong: "; 
			fflush(stdin);
			cin >> ten;
			cout << endl << "So luong: "; 
			cin >> so_Luong;
		}
		
		void in_Doi_Tuong(){
			cout << endl << "| " << setw(11) << ten << " | " << setw(11) << so_Luong << " |";
		}
};

#endif
