#ifndef APPORT_LOG_H
#define APPORT_LOG_H
#include "c_log.h"
// #include "c_date.h"
#include <vector>
#include <cstring>

//base.text
class log_apport:public log // apport log
{
public:std::vector<std::string> pid, time, detail;
    std::string info;
    public :
        log_apport() {
            log();
            path = "/var/log/apport.log";
        }
        int get_info();
};

int log_apport::get_info() {
    for (int i = 0; i < text.length()-22; i++) {
         bool f;
                  f=0;
         if (text.substr(i, 3) == "pid") {
                        i+=4;
            std::string n = "";
            while (text[i] != ')') {
                n += text[i];
                i++;
            }
            pid.push_back(n);
                        f=1;
        }
                 if (f==1){
                        i+=2;
            time.push_back(text.substr(i, 24));

                        i+=26;

            std::string s = "";
            while (text[i] != '\n') {
                s += text[i];
                i++;
            }
            detail.push_back(s);
                        count++;

        }
    }
    std::stringstream str_out;
    //str_out << '\n';
    str_out << "total: " << count << '\n';
    str_out << '\n';
    for (int i = 0; i < time.size(); i++) {
        str_out << "ERROR." << i+1 << '\n';
        str_out << "pid: "<< pid[i] << '\n';
        str_out << "date: "<< time[i] << '\n';
        str_out << "detail: " << detail[i] << '\n';

        str_out << '\n';
    }
    info = str_out.str();
    return 1;
}

//to do...

#endif // APPORT_LOG_H
