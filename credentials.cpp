#include <cstdlib>
#include <string>
#include <iostream>

#include <include/k0hax-qrz.h>

namespace k0hax::qrz
{
    Credentials::Credentials(const std::string& username, const std::string& password) {
        GetQrzSession(username, password, &SessionID);
    }

    Credentials::Credentials(const std::string& sessionId) {
        SessionID = sessionId;
    }

    Credentials::Credentials() {
    }

    void* Credentials::Login(const std::string& username, const std::string& password) {
        GetQrzSession(username, password, &SessionID);
        return 0;
    }

    int Credentials::Save(const std::string& filename) {
        std::ofstream file1;
        char sid[32];
        strcpy(sid, SessionID.c_str());
        uint8_t size = strlen(sid);
        file1.open(filename, std::ios::trunc);
        file1.write((char*)&size, sizeof(uint8_t));
        std::cout << "SID: " << sid << std::endl;
        file1.write((char*)&sid, size);
        file1.close();
        return 1;
    }

    int Credentials::Load(const std::string& filename) {
        try {
            std::ifstream file1;
            uint8_t size;
            file1.open(filename, std::ios::in);
            file1.read((char*)&size, sizeof(uint8_t));
            char sid[size];
            if(size == 32) {
                file1.read((char*)&sid, size);
                file1.close();
            } else {
                std::cout << "Error! Size != 32 in credentials.dat header! Size = " << size << std::endl;
                return 0;
            }
            if (!sid) {
                return 0;
            } else {
                SessionID.assign(sid, 32);
                return 1;
            }
        }
        catch (...) {
            return 0;
        }
    }
}
