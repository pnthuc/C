#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
using ll = long long;
struct Student{
    string name;
    string id;
    float gpa;
};
void capitalize(string &s){
    char prev = ' ';
    for(int i = 0; i < s.size(); ++ i){
        if(prev == ' ' && s[i] != ' ')
            if(islower(s[i]))
                s[i] = toupper(s[i]);
        prev = s[i];
    }
}
void getNameAndID(string s, string &name, string &id){
    bool flag = false;
    for(char c: s){
        if(c == '|'){
            flag = !flag;
            continue;
        }
        if(flag)
            id.push_back(c);
        else
            name.push_back(c);
    }
}
int main(){
    fstream f ("STUDENT.TXT", ios::in);
    fstream o ("GPA.TXT", ios::out);
    Student student[1000];
    string line;
    int INDEX = 0;
    while(getline(f, line)){
        // Name & ID
        string Name, ID;
        Name.clear();
        ID.clear();
        getNameAndID(line, Name, ID);
        capitalize(Name);
        student[INDEX].name = Name;
        student[INDEX].id = ID;
        // Cal GPA
        getline(f, line);
        stringstream ss(line);
        float SumOfPoint = 0;
        float Point = 0;
        ll cnt = 0;
        while(ss >> Point)
            ++ cnt, SumOfPoint += Point;
        student[INDEX].gpa = SumOfPoint / cnt ;
        INDEX ++;
    }
    for(int i = 0; i < INDEX; ++ i)
        for(int j = 0; j < i; ++ j)
            if(student[i].gpa > student[j].gpa)
                swap(student[i], student[j]);
    for(int i = 0; i < INDEX; ++ i)
        o << student[i].id << '|' << student[i].name << '|' << fixed << setprecision(1) << student[i].gpa << endl;
    f.close();
    o.close();
}