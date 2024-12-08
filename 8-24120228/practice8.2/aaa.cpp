#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

struct Fraction {
	int num, den;
};

bool inside(char c){
    return c >= '0' && c <= '9' or (c == '/');
}
Fraction parseFraction(const char s[]){
    Fraction frac = {0, 0};
    bool flag = false;
    bool flagnum = false;
    bool flagden = false;
    for(int i = 0; s[i]; i ++){
        if(!inside(s[i])){
            break;
        }else if(s[i] == '/'){
            flag = true;
        }else if(!flag){
            flagnum = true;
            frac.num = frac.num * 10 + (s[i] - '0');
        }else if(flag){
            flagden = true;
            frac.den = frac.den * 10 + (s[i] - '0');
        }
    }
    if(!flagnum)
        frac.num = 1;
    if(!flagden)
        frac.den = 1;
    if(frac.den == 0)
        frac.num = 0 , frac.den = 1;
    
    return frac;
}
// Bắt đầu viết các hàm cho câu trả lời từ đây, KHÔNG VIẾT HÀM main()...
