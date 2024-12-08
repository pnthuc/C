#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using ll = long long;
int main(){
    fstream f ("OPERATION.TXT", ios::in);
    fstream o ("RESULT.TXT", ios::out);
    string line;
    while(getline(f, line)){
        ll a, b;
        char op;
        stringstream ss(line);
        if((ss >> a >> op >> b).fail())
        {
            o << "Error input" << endl;
            continue;
        };
        switch(op){
            case '+':
                o << a + b << endl;
                break;
            case '-':
                o << a - b << endl;
                break;
            case '*':
                o << a * b << endl;
                break;
            case '/':
                if(b == 0)
                    o << "Divided by zero" << endl;
                else
                    o << a / b << endl;
                break;
            default:
                o << "Error input" << endl;
        }
    }
    f.close();
    o.close();
}