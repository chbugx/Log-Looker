#ifndef C_LOG3
#define C_LOG3
#include "c_log.h"
// #include "c_date.h"
#include <vector>
#include <cstring>


//base.text
class log_auth:public log // auth log
{
public:std::vector<std::string> time, machine,detail;
    std::string info;
    public :
        log_auth() {
            log();
            path = "/var/log/auth.log";
        }
        int get_info();
};

int log_auth::get_info() {
    for (int i = 0; i < 3000; i++) {

            time.push_back(text.substr(i, 16));
            count++;
                i+=16;

            std::string s = "";
            while (text[i] != ' ') {
                s += text[i];
                i++;
            }
            machine.push_back(s);
                        std::string n = "";
            while (text[i] != '\n') {
                n += text[i];
                i++;
            }
            detail.push_back(n);

    }
    std::stringstream str_out;
    std:: cout << '\n';
    str_out << "total: " << count << '\n';
    str_out << std:: endl;
    for (int i = 0; i < time.size(); i++) {
        str_out << "No." << i+1 << '\n';
        str_out << "data: "<< time[i] << '\n';
        str_out << "machine: " << machine[i] << '\n';
        str_out << "detail: "<< detail[i] << '\n';
        str_out << '\n';
    }
    info = str_out.str();
    return 1;
}

//to do...

#endif
