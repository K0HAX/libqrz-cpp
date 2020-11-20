#include <cstdlib>
#include <iostream>
#include <string>

namespace k0hax::qrz
{
    class Callsign {
        public:
            Callsign() = default;
            std::string call;
            std::string aliases;
            std::string dxcc;
            std::string fname;       // first name
            std::string name;        // last name
            std::string addr1;
            std::string addr2;
            std::string state;
            std::string zip;
            std::string country;
            std::string lat;
            std::string lon;
            std::string grid;
            std::string county;
            std::string ccode;
            std::string fips;
            std::string land;
            std::string efdate;
            std::string expdate;
            std::string cclass;
            std::string codes;
            std::string qslmgr;
            std::string email;
            std::string u_views;
            std::string bio;
            std::string biodate;
            std::string image;
            std::string imageinfo;
            std::string moddate;
            std::string MSA;
            std::string AreaCode;
            std::string TimeZone;
            std::string GMTOffset;
            std::string DST;
            std::string eqsl;
            std::string mqsl;
            std::string cqzone;
            std::string ituzone;
            std::string lotw;
            std::string user;
            std::string geoloc;
            void* Save(std::string);
    };
}
