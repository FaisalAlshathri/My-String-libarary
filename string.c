#include "string.h"


// char
bool isLowerCase(char c){
 return c >= 97 && c <= 122;
}
bool isUpperCase(char c){
 return c >= 65 && c <= 90;
}
bool isChar(char c){
 return isLowerCase(c) || isUpperCase(c);
}
bool isInteger(char c){

 return c >= 48 && c <= 57;
}

bool isWhiteSpace(char c){

 return c == ' ' && c < 33;
}
char toLowerCase(char c){
 return isUpperCase(c) ? c + 32: c;
}
char toUpperCase(char c){
 return isLowerCase(c)? c - 32 : c;
}

int toInteger(char c){
/*if char of integer is valid return int otherwise return -1*/
 return isInteger(c)? c - 48 : -1;
}
char getRandomChar(){
 srand(time(NULL));
 int r1 = rand() % 26 + 65; //get random lower case char
 int r2 = rand() % 26 + 97; // upper case
 return rand() % 2 == 0 ?r1 : r2;
}

//string
int strLength(char * str){
 int len = 0;
 while(str[len]!='\0')
       len++;
       
 return len;
}
/*
int strToInteger(char * str){
 int len;
 unsigned int digit = 1;
 for(len = 0; str[len]!='\0'; ++len){
     if(!isInteger(str[len]))
	    return -1;
	else
	 digit*=10;
		
 }
 printf("digit = %ld\n",digit);
 int integer = 0;		
 for(int i = 0; str[i]!='\0'; ++i){	
     digit/=10;
     integer += digit*(str[i]-48);
	 
 }
 return integer;
}*/
int power(int base , int expoent){
 int sum = 1;
 for(int i=0; i<expoent; ++i)
    sum*=base;
 return sum;	
}
int strToInteger(char * str){
 

 
 int integer = 0;		
 for(int i = strLength(str) - 1; i>=0; --i){	
     if(!isInteger(str[i]))
	    return -1;
     integer += power(10,i)*(str[i]-48);
	 
 }
 return integer;
}
char * intToStr(int num);

 

void intToString(char * strInt , int number){
 int i = 0;
 /// check length of number and size of string
 for(int n = number; n>0; n/=10){
    strInt[i++] = 48 +(n % 10);
 }
 strInt[i]='\0';
 strReverse(strInt);
 //printf("%s\n",strInt);
    
}

void strCopy(char * destination , char * source){
  //security check
  if(strLength(source) > strLength(destination) ){
     fprintf(stderr,"Error: the size of destination must be >= source");
	 return ;
   }
  int i;
  for( i = 0; source[i]!='\0'; ++i)
      destination [i] = source[i];
  destination [i] = '\0';
 //printf("%s\n",destination);
	  

}

void strReverse(char * str){
  char temp;
  for(int i = 0 , j = strLength(str) - 1; i<j; --j, ++i){
      temp = str[i];
	  str[i] = str[j];
	  str[j] = temp;
  }
}

char * strMerg(char * str1 , char * str2){
  int size = strLength(str1) + strLength(str2) - 1; // size of string with two null
  char * temp = (char *) malloc(size * sizeof(char));// [size];
  int i;
  for(i = 0;  str1[i]!='\0'; ++i)
      temp[i] = str1[i];
  for(int j = 0;  str2[j]!='\0'; ++j)
      temp[i++] = str2[j];
  temp[i] = '\0';
  return temp;
    
}
void strMergArray(char * merg,char * str1 , char * str2){
  //int size = strLength(str1) + strLength(str2) - 1; // size of string with two null
  
  int i;
  for(i = 0;  str1[i]!='\0'; ++i)
      merg[i] = str1[i];
  for(int j = 0;  str2[j]!='\0'; ++j)
      merg[i++] = str2[j];
  merg[i] = '\0';
    
}

void removeWhiteSpace(char * str){
  int j =0;
  for(int i = 0; str[i]!='\0'; ++i)
      if(str[i]!=' ' || str[i]!= '\t')
	     str[j++] = str[i]; 
  str[j]='\0';

}
//unsigned int
int countChar(char * str ){
   int count = 0;
   for(int i = 0; str[i]!='\0'; ++i)
       if(str[i] >= 97 && str[i] <= 122 || str[i] >= 65 && str[i] <= 90/*isChar(str[i])*/ )
	      count++;
   return count;
}

int countWord(char * str){
   int countWords = 0;
   int countChars = 0;
   
   int i = 0;
   do{
       if(str[i++]!=' '|| str[i]!='\t'|| str[i]!='\n')
	      countChars++;
	   else countChars = 0;
	   if(countChars >= 3){
		  countWords++;
		  countChars = 0;
	   }
       
   }while(str[i]!='\0');
   return countWords;
   
}

bool strEquals(char * str1 , char * str2){
   //if( strLength(str1)!= strLength(str2) )return false;	
   for(int i = 0; str1[i]!='\0' || str2[i]!='\0'; ++i)
       if(str1[i]!=str2[i]){
	     //printf("str1[i]= %c , str2[i] = %c \n",str1[i],str2[i]);
	      return false;
		  }
	return true;	  
}

int strComp(char * str1 , char * str2){
  int sum1 = 0 , sum2 = 0;
  for(int i=0;  str1[i]!='\0'; ++i)
     sum1 += str1[i];
  for(int i=0;  str2[i]!='\0'; ++i)
     sum2 += str2[i];

  if(sum1 == sum2 )
     return 0;  
  return sum1>sum2?1:-1;
}

void strToLowerCase(char * str){
  
  for(int i = 0; str[i]!='\0'; ++i)
     
	 if(str[i] >= 65 && str[i]<= 90)
	    str[i] = 32 + str[i];
      
}

void strToUpperCase(char * str){
  
  for(int i = 0; str[i]!='\0'; ++i)
     
	 if(str[i] >= 97 && str[i]<= 122)
	    str[i] = str[i] - 32;
       
}

/*
void strToUpperCase(char * str){
 	for(int i = 0; str[i]!='\0'; ++i)
	   if(isLowerCase(str[i])
	     str[i] = str[i]-32;
}
void strToLowerCase(char * str){
	for(int i = 0; str[i]!='\0'; ++i)
	   if(isUpperCase(str[i])
	     str[i] = str[i]+32;
}
*/
bool strStartWith(char *  prefix , char * string){

    for(int i = 0; prefix[i]!='\0' && string[i]!='\0'; ++i)
	    if ( prefix[i] != string[i] )
		    return false;

 return true;
}

bool strEndWith(char *  suffix , char * string){
    int suffixLen = strLength(suffix);
	/*int strLen = strLength(string);
	if(suffixLen > strLen)
	   return false;*/
	
    for(int i = suffixLen - 1; i>=0; --i)
	    if ( suffix[i] != string[i] )
		    return false;

 return true;

}
bool strContain(char *  subStr , char * string){
 int len = strLength(subStr);
 printf("len = %d\n",len);
 int j = 0;
 for(int i = 0; string[i]!='\0'; ++i){
     if( j<len && subStr[j] == string[i] )
	    j++;
	  else 
	      j = 0;
     if(j == len)
	   return true;
 }
 return false;
}

bool strCompInoreCase(char * str1 , char * str2){
  if(strLength(str1)!= strLength(str2))
     return false;
 char c1 , c2;	 
  for(int i=0;  str1[i]!='\0'/*&& str2[i]!='\0'*/; ++i){
     c1 = str1[i];
	 c2 = str2[i];
     if(str1[i]>=65 && str1[i]<=90)
		c1 = str1[i] + 32;
		  
	 if(str2[i]>=65 && str2[i]<=90)
		c2 = str2[i] + 32;

     if(c1 != c2)
        return false;		
  }
  return true;    
}

void strTrim(char * newStr , char * str){

    int start = 0 , end = strLength(str) - 1;
	bool t1 = false ,t2 = false;
    for(int i = 0; str[i]!='\0'; ++i){
        if(str[i]!=' '&& str[end]!='\t' && str[end]!='\n' && !(t1)){
           start = i;
		   t1 = true;
        }
        if(str[end]!=' ' || str[end]!='\t' || str[end]!='\n'){ 
		   t2 = true;
        }else end--;
        if(t1 && t2)
           break;		
    }
	int j = 0;
	for(int i = start;  i<=end; ++j, ++i)
	    newStr[j] = str[i];
	newStr[j] ='\0';	

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void strRandom(char * randomString ,bool validChar){

 srand(time(NULL));
 if(validChar){
    for(int i = 0; randomString[i]!='\0'; ++i){
       int r1 = rand() % 26 + 65; //get random lower case char
       int r2 = rand() % 26 + 97; // upper case
       randomString[i] = rand() % 2 == 0 ?r1 : r2;
	}
	
 }else{
	
	for(int i = 0; randomString[i]!='\0'; ++i){
       
       randomString[i] = rand() % 95 + 32;// range 32 to 126 from ASCII table
	
	}
 }
}
///////////////////////////////////////////////////////////////
void strClean(char * string , char * start , char * end){
   bool st = false;
   int startIndex = 0;
   bool en = false;
   int endIndex = 0;
   int ss = 0;
   int startSize = strLength(start);
   int endSize = strLength(end);
   for(int i = 0; string[i]!='\0'; ++i){
       if(!st && string[i] == start[startIndex] ){
	       ++startIndex;
		   
		   if(startIndex >= startSize){
		      st = true;
			 // startIndex = 0;
			  continue;
			 }
	
	   }else startIndex = 0;
	   
	   if(/*!en &&*/ string[i] == end[endIndex]  && st ){
	       ++endIndex;
		   
		   if(endIndex >= endSize){
		     // en = true;/////
			  break;
			  //endIndex = 0;
			  //continue;
			 }
	
	   }else /*if(string[i] != end[endIndex] && !en)*/ endIndex = 0;
	   
	   if(st){
	     //end[ss++] = string[i];
	     string[ss++] = string[i];
	     printf("string[%d]= %c\n",i,string[i]);//debug
       }
   }
   printf("endIndex = %d\n",endIndex);
   string[ss-endIndex] ='\0';
   //end[ss] ='\0';
  
}

void strSplit(char ** newString ,int strSize , char * string , char * regex){
 int j = 0;
 int index;
 int ii = 0;
 int size = strLength(regex);
 for(int i = 0; string[i]!='\0'; ++i){
     
     if(regex[j] == string[i]){
	    j++;
		if(j >= size){
		  index = i;
		  break;
		}
	 }else j = 0;
		
  }
  
  
  
  

}

void strReplace(char * string ,int size, int startIndex  , char * replacement){
	
	int stringlength = strLength(string);
	int replaceLength = strLength(replacement);
	if(startIndex  < 0 || startIndex >= size-1 || replaceLength<=0 || replaceLength>=size-1 )
		return ;
	//printf("stringLength %d\n",stringlength);
    //if(startIndex>stringlength && string[stringlength]== '\0')//remove ('\0')null from the string	
	  // string[stringlength]=' ';
	   
	
	int i , j = 0;
	for(i =	stringlength<startIndex?stringlength:startIndex;/*shift array to  left by one*/ i<size-1 && replacement [j]!='\0' ; ++i)
		string[i] = replacement[j++];
	
	string[i]='\0';//end of string	

	

}



	void checkXml(char * fileName){
		
		//if(fileName)
		  //return ;
		
		bool openingTag = false;
		bool closingTag = false;
		/*boolean singleTag = false;
		String openingTagName ="";
		String closingTagName ="";
		String elementContent = ""; // between opening tag and closing tag
		*/
		unsigned int count = 0;
		int countOpeningTag = 0;
		int countClosingTag = 0;
		char array[1000000];
		
		  
		   FILE * br = fopen(fileName ,"r");
		   if(br == NULL)exit(0);
		    int c;
		    while((c = fgetc(br)) != -1){
		    	
		    	if(c == '<' && !openingTag ){//check for tag name
		    		openingTag = true  ;
		    		countOpeningTag++;
		    		
		    	}else if(c == '<' && !closingTag ){
		    		closingTag = true; 
		    	}else if(c == '>' && openingTag){
		    		openingTag = false;
		    		countOpeningTag--;
		    		/*if(singleTag){//////// checking for single tags
		    			//System.out.println("Single tag");// call a method to check for single tag
		    			singleTag = false;
		    		}*/
		    	}else if(c == '>' && closingTag){
		    		closingTag = false;
		    		countClosingTag--;
		    	/*}else if(openingTag){/////// checking tags name
		    		if(c != '/' )
		    		  openingTagName += (char)c;
		    		else  
		    		  singleTag = true;*/ 		
		    	}else if(closingTag){
		    		/*if(c != '/')
		    		  closingTagName += (char)c;
		    		else countClosingTag++;*/
		    		if(c == '/')countClosingTag++;
		    	}else if(!openingTag && !closingTag)
		    	  //elementContent += (char)c;*/
				  array[count++]=c;
		    	    
		    	
		    }//end of while
		
				fclose(br);
		
		
		printf("countOpeningTag %d: ",countOpeningTag);
		printf("countClosingTag: %d ",countClosingTag);
		printf("Number of char: %d ",count);
		//return "";//(xml = elementContent);
	}
