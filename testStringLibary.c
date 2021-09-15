#include "string.h"
//#define TEST_BY_CASES
#define TEST_MODE_BrutForce

//#undef TEST_MODE_BrutForce

#define error(x) printf("\n**ERROR AT LINE: %d\n",x)




bool testChar(bool (*func(char)) , int start , int end , int validNumberOfCasses , bool print);

void pause(char * msg , bool clearConsole);

int main(){
  
  
#ifdef TEST_MODE_BrutForce 
    int countValidFunction = 0;
	int numberOfFunctions = 5;
	int max = 0xff;//max_bit 255
	bool print = false;
	bool clearConsole = true;
	
	
	printf("*****Test String Lib*****\n");
	
	printf("**Test char functions**\n");
	
	
	//pause("\nisLowerCase(char c):\n" , clearConsole); 
	if(testChar(&isLowerCase , 0 ,max ,26,print))
		countValidFunction++;
	else error(__LINE__ - 2);
	
	//pause("\nisUpperCase(char c):\n" , clearConsole);
	if(testChar(&isUpperCase , 0 ,max ,26,print))
	   countValidFunction++ ;
    else error(__LINE__ - 2);
	
	  
	//pause("\nisChar(char c):\n" , clearConsole);
	if(testChar(&isChar , 0 ,max ,26+26,print))
	   countValidFunction++;
	else error(__LINE__ - 2);   
	   
	
	//pause("\nisInteger(char c):\n" , clearConsole);
	if(testChar(&isInteger , 0 ,max ,10,print))
	   countValidFunction++;
	else error(__LINE__ - 2);   
	   
	  
	//pause("\nisWhiteSpace(char c):\n" , clearConsole);
	if(testChar(&isWhiteSpace , 0 ,max ,1,print))
	   countValidFunction++;
	else error(__LINE__ - 2);   
	   
	   
	   bool testPased = (countValidFunction == numberOfFunctions);
	   printf("test passed = %d\n",testPased);
	
	//
	/* make pointer to fuction with  return type char
	toLowerCase(char c);
	toUpperCase(char c);
	toInteger(char c);
	getRandomChar();*/
	
	
#endif

#ifdef TEST_BY_CASES
  
  
  //printf("%d\n",__LINE__);
  
  
  
  
  
  printf("%c\n",toLowerCase(getRandomChar()));
   printf("%d\n",strToInteger(""));
   //char * strInt = (char *)malloc(10*sizeof(char));
   char * strInt;// [10];
   //intToString(strInt,123097);
   //strCopy(strInt,"hello");
   strInt = strMerg("he" , "123");
   //free(strInt);
   printf("merge: %s\n",strInt);
   char f[10] = "  hh  9h";
   removeWhiteSpace(f);
   printf("%s\n",f);
   
  printf("word: %d\n",countWord("    hfh8y hhh hhh "));
  printf("boolean %d\n",strEquals("str21786686","str2"));
  printf("contain %d\n",strContain("is" , "ijijihiuyftssssfaisal"));
  char s[10] ;
  
  strTrim(s,"h  j k ");
  printf("%s\n",s); 
  printf("ignore case %d\n",strCompInoreCase("Faisal7","faIsaL") );
  
  char c[38] = "<p>hello there it's html Tag </p>";//html tags
  char e[10];
  //strClean(c, "<\\" , "/>");
  strClean(c, "p>" ,  "</p" );
  printf("c= %s\n",c);
  //checkXml("songs.xml");
  char stest[100] ="hi";
  strReplace(stest,100,3,"hello");
  printf("tset: %s\n",stest);
  
#endif 
 return 0;
}



bool testChar(bool (*func(char)) , int start , int end , int validNumberOfCasses , bool print){

	int jj = 0;
	//int NumberOfChars = 26;
	for(int i = start; i<end; ++i){
	   if(func(i)){
		jj++;
		if(print)
			printf("%c\t",i);
		  
		}
	 }
	 if(print)
	    printf("\nnumber of valid case passed: %d\ntest passed  = %s\n",jj , (jj == validNumberOfCasses?"true":"false") );
	 
	 return validNumberOfCasses == jj;


}


void pause(char * msg , bool clearConsole){
 
 char  * m = "Press Enter to continue";
 printf("%s\n",m); 
 getc(stdin);
 putchar('\n');
 if(clearConsole)
	system("cls");
 puts(msg);
}
