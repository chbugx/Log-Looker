#ifndef DPKG_LOG_H
#define DPKG_LOG_H
#include "c_log.h"
// #include "c_date.h"
#include <vector>
#include <cstring>


//base.text
class log_dpkg:public log // dpkg log
{
public:std::vector<std::string> time, detail;
    std::string info;
    public :
        log_dpkg() {
            log();
            path = "/var/log/dpkg.log";
        }
        int get_info();
};

int log_dpkg::get_info() {
    for (int i = 0; i < 3000; i++) {

            time.push_back(text.substr(i, 20));
                        i+=20;

            std::string s = "";
            while (text[i] != '\n') {
                s += text[i];
                i++;
            }
            detail.push_back(s);
                        count++;

    }
    std::stringstream str_out;
    str_out << "total: " << count << '\n';
    str_out<< std:: endl;
    for (int i = 0; i < time.size(); i++) {
        str_out << "No." << i+1 << '\n';
        str_out << "data: "<< time[i] << '\n';
        str_out << "detail: " << detail[i] << '\n';

        str_out << '\n';
    }
    info = str_out.str();
    return 1;
}

//to do...

#endif // DPKG_LOG_H
