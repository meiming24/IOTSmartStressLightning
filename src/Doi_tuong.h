//#ifndef DOITUONG_H
//#define DOITUONG_H
//#include <string.h>
//#include <iomanip>
//
//class Doi_tuong{
//	protected:
//		string ten;
//		int so_Luong;
//		int tong;
//	public:
//		Doi_tuong(){
//		}
//		
//		Doi_tuong(string t, int s){
//			ten = t;
//			so_Luong = s;
//		}
//		
//		string get_Ten(){
//			return ten;
//		}
//		int get_So_Luong(){
//			return so_Luong;
//		}
//		
//		void nhap_Doi_Tuong(){
//			char tiep = 'c';
//			do{
//				cout << endl << "Ten doi tuong: "; 
//				fflush(stdin);
//				cin >> ten;
//				cout << endl << "So luong: "; 
//				cin >> so_Luong;
//				tong += so_Luong;
//				cout << endl << "Ban muon nhap them doi tuong (YES: c): "; cin >> tiep;
//			} while (tiep == 'c');
//		}
//		
//		void in_Doi_Tuong(){
//			cout << endl << "Ten: " << ten << ", so luong: " << so_Luong;
//		}
//		
//		int tong_Doi_Tuong(){
//			return tong;
//		}
//};
//
//#endif
