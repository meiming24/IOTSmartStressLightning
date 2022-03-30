#ifndef THOIGIAN_H
#define THOIGIAN_H

class Thoi_gian {

	protected:
		time_t t;
		string thoi_Gian; 
	public:
		
		Thoi_gian(){
			thoi_Gian = "00:00:00";
		}
		
		string get_Thoi_Gian_Thuc(){
			time(&t);
			string res = ctime(&t);
			for(int i=0;i<8;i++){
				thoi_Gian[i] = res[i + 11];
			}
			return thoi_Gian;
		}
		
		string get_Thoi_Gian(){
			return thoi_Gian;
		}
		
		string set_Thoi_Gian(string gio_Phut_Giay){
			thoi_Gian = gio_Phut_Giay;
			return thoi_Gian;
		}	 
		
		int get_Gio (){
			int gio = (thoi_Gian[0] - '0') * 10 +  (thoi_Gian[1] - '0');
			return gio;
		}
		
		int get_Phut (){
			int phut = (thoi_Gian[3] - '0') * 10 +  (thoi_Gian[4] - '0');
			return phut;
		}
		
		int get_Giay (){
			int giay = (thoi_Gian[6] - '0') * 10 +  (thoi_Gian[7] - '0');
			return giay;
		}
		
		int khoang_Thoi_Gian (string t1, string t2) { //00:00:00
			
			int giay1, phut1, gio1;
			
			if(((t2[6] - '0') * 10 +  (t2[7] - '0')) > ((t1[6] - '0') * 10 +  (t1[7] - '0'))){
        		phut1 = (t1[3] - '0') * 10 +  (t1[4] - '0');
				phut1--;
        		giay1 = ((t1[6] - '0') * 10 +  (t1[7] - '0')) + 60;
    		}

    		int giay = giay1 - ((t2[6] - '0') * 10 +  (t2[7] - '0'));
    
			if((t2[3] - '0') * 10 +  (t2[4] - '0') > ((t1[3] - '0') * 10 +  (t1[4] - '0'))){
        		gio1 = (t1[0] - '0') * 10 +  (t1[1] - '0');
				gio1--;
        		phut1 = ((t1[3] - '0') * 10 +  (t1[4] - '0')) + 60;
    		}
    
			int phut = phut1 - (t2[3] - '0') * 10 +  (t2[4] - '0');
    		int gio = gio1 - (t2[0] - '0') * 10 +  (t2[1] - '0');
    		
    		return gio * 60 * 60 + phut * 60 + giay; 
    		
		}
};

#endif
