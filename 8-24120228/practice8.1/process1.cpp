#include <iostream>
#include <string.h>
#include "process1.h"
using namespace std;
void input(char *&s, char *&f, char *&r){
    char line[1000];
    cout << "Enter a sentence = ";
    cin.getline(line, 1000);
    s = new char[strlen(line) + 1]();
    strcpy(s, line);
    cout << "Enter find word = ";
    cin.getline(line, 1000);
    f = new char[strlen(line) + 1]();
    strcpy(f, line);
    cout << "Enter replacing word = ";
    cin.getline(line, 1000);
    r = new char[strlen(line) + 1]();
    strcpy(r, line);
}
bool invalidword(char *s, char *f, char *r, char *q) {
    return (isspace(*(q + strlen(f))) or *(q + strlen(f)) == '\0' or !isalpha(*(q + strlen(f)))) 
                and (q == s ? 1 : (isspace(*(q - 1)) or !isalpha(*(q - 1))));
}
void output(char *s, char *f, char *r) {
    int cnt = 0; 
    for(char *p = s; (p = strstr(p, f)); p += strlen(f), cnt ++);
    char *result = new char[strlen(s) + cnt * (strlen(r) - strlen(f)) + 1]();
    int len = 0;
    char *p = s;
    for(char *q = p ;(q = strstr(p, f)); p = q + strlen(f)) {
        strncpy(result + len, p, q - p);
        len += q - p;
        if(invalidword(s, f, r, q))
            strcpy(result + len, r), len += strlen(r);
        else strcpy(result + len, f), len += strlen(f);
    }
    strcpy(result + len, p);
    cout << result;
    delete []result, p;
}