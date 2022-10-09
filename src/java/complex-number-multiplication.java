/*Question:-A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].
imaginary is the imaginary part and is an integer in the range [-100, 100].
i2 == -1.
Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.*/


//Solution



class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        
    int a = Integer.parseInt(num1.substring(0,num1.indexOf('+')));
    int b = Integer.parseInt(num1.substring(num1.indexOf('+')+1,num1.length()-1));
    int c = Integer.parseInt(num2.substring(0,num2.indexOf('+')));
    int d = Integer.parseInt(num2.substring(num2.indexOf('+')+1,num2.length()-1));
    
    return "" + (a*c - b*d) + "+" + (a*d + c*b)+"i";
        
        
    }
}

//Submission link:-https://leetcode.com/submissions/detail/618995919/
