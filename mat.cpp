#include "mat.hpp"
#include  <iostream>
using namespace std;

namespace ariel{

	string mat(int w, int h, char c1, char c2){
		if(w<=0 || h<=0)
			throw std::invalid_argument("Width and height must be > 0");
		else if(w%2==0 || h%2==0)
			throw std::invalid_argument("Width and height must be odd");
		else if(c1 == ' ' || c1 == '\t' ||c1 == '\n' ||c1 == '\r')
			throw std::invalid_argument("Invalid character input");
		else if(c2 == ' ' || c2 == '\t' ||c2 == '\n' ||c2 == '\r')
			throw std::invalid_argument("Invalid character input");
		string str1 = "";
		string str2 = "";
		for(int i = 0; i<w; i++){
			str1 = str1 + c1;
			str2 = str2 + c2;
		}
		
		int rowsDone = 0;
		string top = "";
		string bot = "";
		bool line = true;
		
		for(int i = 0; i<(h-1)/2; i++){
			string s = "";
			if(line)
				s = str1;
			else
				s = str2;
				
			top = top + s + "\n";
			if(i != 0)
				bot = s + "\n"+ bot;
			else
				bot = s + "\n";
				
			if(i<(w+1)/2){
				if(line){
					str2[i] = c1;
					str2[w-1-i] = c1;
				}
				else{
					str1[i] = c2;
					str1[w-1-i] = c2;
				}
			}
			rowsDone += 1;
			line = !line;
		}
		
		string s = "";
		if(line)
			s = str1;
		else
			s = str2;
		top = top + s + "\n";
		rowsDone += 1;
		
	
	return top + bot;
	
	}

}




