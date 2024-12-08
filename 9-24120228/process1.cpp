#include "process1.h"

#ifndef _COPY_FILE
#define _COPY_FILE
void copy_file(const char* src, const char* dest, bool type);
#endif

#ifndef _ADD_FILE
#define _ADD_FILE
void add_file(const char* src1, const char* src2, const char* dest_path);
#endif

#ifndef _COPY_PATH
#define _COPY_PATH
void copy_path(const char* src, const char* dest_path);
#endif

#ifndef _HELP
#define _HELP
void help();
#endif

#ifndef _CALL
#define _CALL
void call(int32_t argc, char **dest);
#endif

#ifndef _ERROR_SYNTAX
#define _ERROR_SYNTAX
void error_syntax();
#endif

#ifndef _ERROR_FILE
#define _ERROR_FILE
void error_file();
#endif

void error_file(){
    cout << "Error: File not found\n";
    return;
}

void error_syntax(){
    cout << "Error: Invalid syntax\n";
    return;
}

void copy_file(const char* src, const char* dest, bool type){
    FILE *f = fopen(src, "rb");
    FILE *o = fopen(dest, (type ? "ab" : "wb"));
    if(!f or !o)
        return error_file();
    char * buffer = new char[GB]();
    while(!feof(f))
        fwrite(buffer, 1, fread(buffer, 1, GB, f), o);
    delete[] buffer; 
    fclose(f);
    fclose(o);
    return;
}

void help(){
    cout << "COPY <source file > <destination file>                       : copy source file to destination file\n"
         << "COPY <source file> <destination path>/                       : copy source file to destination path (keep filename)\n"
         << "COPY <file 1> + <file 2> <destination file>                  : join file 1 and file 2 to destination file\n"
         << "COPY -?                                                      : show help";
    return;
}

void add_file(const char* src1, const char* src2, const char* dest){
    copy_file(src1, dest, 0);
    copy_file(src2, dest, 1);
    return;
}

void copy_path(const char* src, const char* dest_path){
    char* filename = (strrchr(src, '/') ? strrchr(src, '/') : strrchr(src, '\\'));
    if(!filename)
        return error_file();
    char *dest = new char[strlen(dest_path) + strlen(filename + 1) + 1]();
    strcpy(dest, dest_path);
    strcpy(dest + strlen(dest_path), filename + 1);
    copy_file(src, dest, 0);
    delete[] dest;
    return;
}

void call(int32_t argc, char **dest){
    switch(argc){
        case 5:
            (strcmp(*(dest + 2), "+") == 0 ? add_file(*(dest + 1), *(dest + 3), *(dest + 4)) : error_syntax());
            break;
        case 4:
            if((*(dest + 2))[0] == '+')
                add_file(*(dest + 1), *(dest + 2) + 1, *(dest + 3));
            else
                ((*(dest + 1))[strlen(*(dest + 1)) - 1] == '+' 
                    ? (*(dest + 1))[strlen(*(dest + 1)) - 1] = '\0', add_file(*(dest + 1), *(dest + 2), *(dest + 3))
                    : error_syntax()
                );
            break;
        case 3:
            if(strrchr(*(dest + 1), ':') == *(dest + 1) + 1)
                ((*(dest + 2))[strlen(*(dest + 2)) - 1] == '/' or (*(dest + 2))[strlen(*(dest + 2)) - 1] == '\\'
                    ? copy_path(*(dest + 1), *(dest + 2)) 
                    : copy_file(*(dest + 1), *(dest + 2), 0)
                );
            else{
                char *q = strrchr(*(dest + 1), ':');
                if(q == NULL or q - *(dest + 1) < 2)
                    return error_file();
                if(*(q - 2) == '+' )
                     *(q - 2) = '\0', add_file(*(dest + 1), q - 1, *(dest + 2));
                else error_syntax();
            }
            break;
        case 2:
            (strcmp(*(dest + 1), "-?") == 0 ? help() : error_syntax());
            break;
        default:
            error_syntax();
            break;
    }
    return;
}