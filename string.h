
//#pragma once

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
/*
#ifdef _WIN32 // compiler target
    #define NEWLINE "\n"//"\r\n"
#elif defined macintosh // OS 9
    #define NEWLINE "\r"
#else
    #define NEWLINE "\n" // Mac OS X uses \n
#endif
//#define STR_COMBINE(x,y) x ## y //concatenate symbols

//#define space_conc(str1,str2) #str1 " " #str2 //for string
*/
// char 9
//FOR ASCII table and UTF-8
bool isLowerCase(char c);
bool isUpperCase(char c);
bool isChar(char c);
bool isInteger(char c);
bool isWhiteSpace(char c);
char toLowerCase(char c);
char toUpperCase(char c);
int toInteger(char c);
char getRandomChar();

//string 21
int strToInteger(char * str);// convert a (string integer) to integer
char * intToStr(int num);//convert integer to String Integer
void intToString(char * strInt , int number); //convert integer to String Integer
int strLength(char * str);// get the length of a String
void strCopy(char * destination , char * source);//copy a String source to destination String
void strReverse(char * str);//reverse a string Ex. ABC to CBA
char * strMerg(char * str1 , char * str2);// merge two string in one ( str1 + str2) and return string 
void removeWhiteSpace(char * str);//remove all white space and tap '\t'
int countChar(char * str );// return number of char in a string
int countWord(char * str);// return number of words
int strComp(char * str1 , char * str2);// compare two string if str1>str2 return 1 , str1<str2 return -1 and str1 == str2 return 0
bool strEquals(char * str1 , char * str2);// return boolean true if the two string match ,otherwise return false
bool strCompInoreCase(char * str1 , char * str2);//ignore lower case and upper case difference and compare two string  
bool strStartWith(char *  prefix , char * string);// check if string start with a prefix
bool strEndWith(char *  suffix , char * string);// check if a string end with prefix
bool strContain(char *  subStr , char * string); //check if @parm1 a sub-string in @parm2 a string
void strTrim(char * newStr , char * str);//trim a string remove the first white space , tap , newline and last white space , tap newline 
void strRandom(char * randomString ,bool validChar);//get a random string
void strClean(char * string , char * start , char * end);//remove a block of string from start to end 
void strReplace(char * string ,int size, int startIndex  , char * replacement);
void strToUpperCase(char * str);
void strToLowerCase(char * str);
