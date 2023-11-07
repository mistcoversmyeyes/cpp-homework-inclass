#include <cs50.h>
#include <stdio.h>
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void) {


    string text = get_string("Text: ");
    int letter_num = count_letters(text);
    printf("Grade %i",letter_num);

}


int get_arr_length(string text){
    int length = 0;
    char c ='a';
    char character ='a';

    for(int i =0 ; character !='\0';i++){
        length = i;
        c = text[i];
    }
    return length;
}



int count_letters(string text){
    int letter_num = 0 ;
    int length = 0;//初始化文本长度（包括空格和符号）
    length = get_arr_length(text);
    //遍历所有char筛选出ASCII中‘a'-’z'的字符,并存储到letter_num变量中
    for (int i = 0; i<length; ++i){
        char character_i = text[i];
        if (character_i >='a'||character_i <= 'z'||character_i >='A'||character_i <= 'Z'){
            letter_num++;
        }

    }
    return letter_num;
}