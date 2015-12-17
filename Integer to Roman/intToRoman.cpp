class Solution {
public:
    string intToRoman(int num) {
        if(num>=1000){
            return string("M").append(intToRoman(num-1000));
        }
        if(num>=900){
            return string("CM").append(intToRoman(num-900));
        }
        if(num>=500){
            return string("D").append(intToRoman(num-500));
        }
        if(num>=400){
            return string("CD").append(intToRoman(num-400));
        }
        if(num>=100){
            return string("C").append(intToRoman(num-100));
        }
        if(num>=90){
            return string("XC").append(intToRoman(num-90));
        }
        if(num>=50){
            return string("L").append(intToRoman(num-50));
        }
        if(num>=40){
            return string("XL").append(intToRoman(num-40));
        }
        if(num>=10){
            return string("X").append(intToRoman(num-10));
        }
        if(num>=9){
            return string("IX").append(intToRoman(num-9));
        }
        if(num>=5){
            return string("V").append(intToRoman(num-5));
        }
        if(num>=4){
            return string("IV").append(intToRoman(num-4));
        }
        if(num>=1){
            return string("I").append(intToRoman(num-1));
        }
        if(num==0){
            return "";
        }
    }
};i
