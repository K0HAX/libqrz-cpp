#include <cstdlib>
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdint.h>

#include <include/k0hax-qrz.h>

namespace k0hax::qrz
{
    void* Callsign::Save(std::string filename) {
        std::ofstream file1(filename, std::ios::out | std::ios::binary);

        uint8_t sizeCall = strlen(call.c_str());
        char *dCall = strdup(call.c_str());

        uint8_t sizeAliases = strlen(aliases.c_str());
        char *dAliases = strdup(aliases.c_str());

        uint8_t sizeDxcc = strlen(dxcc.c_str());
        char *dDxcc = strdup(dxcc.c_str());

        uint8_t sizeFname = strlen(fname.c_str());
        char *dFname = strdup(fname.c_str());

        uint8_t sizeName = strlen(name.c_str());
        char *dName = strdup(name.c_str());

        uint8_t sizeAddr1 = strlen(addr1.c_str());
        char *dAddr1 = strdup(addr1.c_str());

        uint8_t sizeAddr2 = strlen(addr2.c_str());
        char *dAddr2 = strdup(addr2.c_str());

        uint8_t sizeState = strlen(state.c_str());
        char *dState = strdup(state.c_str());

        uint8_t sizeZip = strlen(zip.c_str());
        char *dZip = strdup(zip.c_str());

        uint8_t sizeCountry = strlen(country.c_str());
        char *dCountry = strdup(country.c_str());

        uint8_t sizeLat = strlen(lat.c_str());
        char *dLat = strdup(lat.c_str());

        uint8_t sizeLon = strlen(lon.c_str());
        char *dLon = strdup(lon.c_str());

        uint8_t sizeGrid = strlen(grid.c_str());
        char *dGrid = strdup(grid.c_str());

        uint8_t sizeCounty = strlen(county.c_str());
        char *dCounty = strdup(county.c_str());

        uint8_t sizeCcode = strlen(ccode.c_str());
        char *dCcode = strdup(ccode.c_str());

        uint8_t sizeFips = strlen(fips.c_str());
        char *dFips = strdup(fips.c_str());

        uint8_t sizeLand = strlen(land.c_str());
        char *dLand = strdup(land.c_str());

        uint8_t sizeEfdate = strlen(efdate.c_str());
        char *dEfdate = strdup(efdate.c_str());

        uint8_t sizeExpdate = strlen(expdate.c_str());
        char *dExpdate = strdup(expdate.c_str());

        uint8_t sizeCclass = strlen(cclass.c_str());
        char *dCclass = strdup(cclass.c_str());

        uint8_t sizeCodes = strlen(codes.c_str());
        char *dCodes = strdup(codes.c_str());

        uint8_t sizeQslmgr = strlen(qslmgr.c_str());
        char *dQslmgr = strdup(qslmgr.c_str());

        uint8_t sizeEmail = strlen(email.c_str());
        char *dEmail = strdup(email.c_str());

        uint8_t sizeU_views = strlen(u_views.c_str());
        char *dU_views = strdup(u_views.c_str());

        uint8_t sizeBio = strlen(bio.c_str());
        char *dBio = strdup(bio.c_str());

        uint8_t sizeBiodate = strlen(biodate.c_str());
        char *dBiodate = strdup(biodate.c_str());

        uint8_t sizeImage = strlen(image.c_str());
        char *dImage = strdup(image.c_str());

        uint8_t sizeImageinfo = strlen(imageinfo.c_str());
        char *dImageinfo = strdup(imageinfo.c_str());

        uint8_t sizeModdate = strlen(moddate.c_str());
        char *dModdate = strdup(moddate.c_str());

        uint8_t sizeMSA = strlen(MSA.c_str());
        char *dMSA = strdup(MSA.c_str());

        uint8_t sizeAreaCode = strlen(AreaCode.c_str());
        char *dAreaCode = strdup(AreaCode.c_str());

        uint8_t sizeTimeZone = strlen(TimeZone.c_str());
        char *dTimeZone = strdup(TimeZone.c_str());

        uint8_t sizeGMTOffset = strlen(GMTOffset.c_str());
        char *dGMTOffset = strdup(GMTOffset.c_str());

        uint8_t sizeDST = strlen(DST.c_str());
        char *dDST = strdup(DST.c_str());

        uint8_t sizeEqsl = strlen(eqsl.c_str());
        char *dEqsl = strdup(eqsl.c_str());

        uint8_t sizeMqsl = strlen(mqsl.c_str());
        char *dMqsl = strdup(mqsl.c_str());

        uint8_t sizeCqzone = strlen(cqzone.c_str());
        char *dCqzone = strdup(cqzone.c_str());

        uint8_t sizeItuzone = strlen(ituzone.c_str());
        char *dItuzone = strdup(ituzone.c_str());

        uint8_t sizeLotw = strlen(lotw.c_str());
        char *dLotw = strdup(lotw.c_str());

        uint8_t sizeUser = strlen(user.c_str());
        char *dUser = strdup(user.c_str());

        uint8_t sizeGeoloc = strlen(geoloc.c_str());
        char *dGeoloc = strdup(geoloc.c_str());

        file1.write((char*)&sizeCall, sizeof(uint8_t));
        file1.write(dCall, sizeCall);

        file1.write((char*)&sizeAliases, sizeof(uint8_t));
        file1.write(dAliases, sizeAliases);

        file1.write((char*)&sizeDxcc, sizeof(uint8_t));
        file1.write(dDxcc, sizeDxcc);

        file1.write((char*)&sizeFname, sizeof(uint8_t));
        file1.write(dFname, sizeFname);

        file1.write((char*)&sizeName, sizeof(uint8_t));
        file1.write(dName, sizeName);

        file1.write((char*)&sizeAddr1, sizeof(uint8_t));
        file1.write(dAddr1, sizeAddr1);

        file1.write((char*)&sizeAddr2, sizeof(uint8_t));
        file1.write(dAddr2, sizeAddr2);

        file1.write((char*)&sizeState, sizeof(uint8_t));
        file1.write(dState, sizeState);

        file1.write((char*)&sizeZip, sizeof(uint8_t));
        file1.write(dZip, sizeZip);

        file1.write((char*)&sizeCountry, sizeof(uint8_t));
        file1.write(dCountry, sizeCountry);

        file1.write((char*)&sizeLat, sizeof(uint8_t));
        file1.write(dLat, sizeLat);

        file1.write((char*)&sizeLon, sizeof(uint8_t));
        file1.write(dLon, sizeLon);

        file1.write((char*)&sizeGrid, sizeof(uint8_t));
        file1.write(dGrid, sizeGrid);

        file1.write((char*)&sizeCounty, sizeof(uint8_t));
        file1.write(dCounty, sizeCounty);

        file1.write((char*)&sizeCcode, sizeof(uint8_t));
        file1.write(dCcode, sizeCcode);

        file1.write((char*)&sizeFips, sizeof(uint8_t));
        file1.write(dFips, sizeFips);

        file1.write((char*)&sizeLand, sizeof(uint8_t));
        file1.write(dLand, sizeLand);

        file1.write((char*)&sizeEfdate, sizeof(uint8_t));
        file1.write(dEfdate, sizeEfdate);

        file1.write((char*)&sizeExpdate, sizeof(uint8_t));
        file1.write(dExpdate, sizeExpdate);

        file1.write((char*)&sizeCclass, sizeof(uint8_t));
        file1.write(dCclass, sizeCclass);

        file1.write((char*)&sizeCodes, sizeof(uint8_t));
        file1.write(dCodes, sizeCodes);

        file1.write((char*)&sizeQslmgr, sizeof(uint8_t));
        file1.write(dQslmgr, sizeQslmgr);

        file1.write((char*)&sizeEmail, sizeof(uint8_t));
        file1.write(dEmail, sizeEmail);

        file1.write((char*)&sizeU_views, sizeof(uint8_t));
        file1.write(dU_views, sizeU_views);

        file1.write((char*)&sizeBio, sizeof(uint8_t));
        file1.write(dBio, sizeBio);

        file1.write((char*)&sizeBiodate, sizeof(uint8_t));
        file1.write(dBiodate, sizeBiodate);

        file1.write((char*)&sizeImage, sizeof(uint8_t));
        file1.write(dImage, sizeImage);

        file1.write((char*)&sizeImageinfo, sizeof(uint8_t));
        file1.write(dImageinfo, sizeImageinfo);

        file1.write((char*)&sizeModdate, sizeof(uint8_t));
        file1.write(dModdate, sizeModdate);

        file1.write((char*)&sizeMSA, sizeof(uint8_t));
        file1.write(dMSA, sizeMSA);

        file1.write((char*)&sizeAreaCode, sizeof(uint8_t));
        file1.write(dAreaCode, sizeAreaCode);

        file1.write((char*)&sizeTimeZone, sizeof(uint8_t));
        file1.write(dTimeZone, sizeTimeZone);

        file1.write((char*)&sizeGMTOffset, sizeof(uint8_t));
        file1.write(dGMTOffset, sizeGMTOffset);

        file1.write((char*)&sizeDST, sizeof(uint8_t));
        file1.write(dDST, sizeDST);

        file1.write((char*)&sizeEqsl, sizeof(uint8_t));
        file1.write(dEqsl, sizeEqsl);

        file1.write((char*)&sizeMqsl, sizeof(uint8_t));
        file1.write(dMqsl, sizeMqsl);

        file1.write((char*)&sizeCqzone, sizeof(uint8_t));
        file1.write(dCqzone, sizeCqzone);

        file1.write((char*)&sizeItuzone, sizeof(uint8_t));
        file1.write(dItuzone, sizeItuzone);

        file1.write((char*)&sizeLotw, sizeof(uint8_t));
        file1.write(dLotw, sizeLotw);

        file1.write((char*)&sizeUser, sizeof(uint8_t));
        file1.write(dUser, sizeUser);

        file1.write((char*)&sizeUser, sizeof(uint8_t));
        file1.write(dUser, sizeUser);

        file1.write((char*)&sizeGeoloc, sizeof(uint8_t));
        file1.write(dGeoloc, sizeGeoloc);

        file1.close();
        return 0;
    }
}

