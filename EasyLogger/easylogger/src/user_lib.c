#include <user_lib.h>
#include <elog.h>
#include <windows.h>
#include <string.h>
#define MAXSIZE 100
#define STRING_SIZE 3
#define STRING_1   "first string"
#define STRING_2   "second string"
#define STRING_3   "third string"
void test_Func(int num){
    
    log_a("第%d次打印 : Hello EasyLogger!", num);

}
void ch_string(){
    char *string[3] = {NULL};
    int i;
    for (i = 0; i < STRING_SIZE; i++ ) {
        string[i] = (char*)malloc(sizeof(char) * 100);
        log_e("string[%d] address: 0x%x", i, string[i]);
    }
    strcpy(string[0], STRING_1);
    strcpy(string[1], STRING_2);
    strcpy(string[2], STRING_3);
    log_e("string[1]: %s", string[0]);
    log_e("string[2]: %s", string[1]);
    log_e("string[3]: %s", string[2]);
    
    
}
/**
 * EasyLogger demo
 */
void test_elog(void) {
    int i = 0;
    while(true) {

        /* test log output for all level */
        log_a("number%d : Hello EasyLogger!", i);
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");
//        elog_raw("Hello EasyLogger!");
        Sleep(1000);
        i++;
    }
}