#include <cstdlib>
#include <iostream>
#include <string>

#include <include/k0hax-qrz.h>

namespace k0hax::qrz
{
  int GetQrzSession(std::string username, std::string password, std::string* sessionId)
  {
    auto url = cpr::Url{"https://xmldata.qrz.com/xml/1.33/"};
    auto userParam = cpr::Parameter(std::string{"username"}, std::move(username));
    auto passParam = cpr::Parameter(std::string{"password"}, std::move(password));
    auto parameters = cpr::Parameters{userParam, passParam};
    auto session = cpr::Session{};
    session.SetUrl(url);
    session.SetParameters(parameters);

    auto r = session.Get();

    tinyxml2::XMLDocument doc;
    doc.Parse(r.text.c_str());
    const char* t_sessionId = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Session")->FirstChildElement("Key")->GetText();
    *sessionId = std::string{t_sessionId};
    return 0;
  }

  Callsign GetCallsign(std::string sessionId, std::string s_callsign)
  {
    auto url = cpr::Url{"http://xmldata.qrz.com/xml/1.33/"};
    auto sessionParam = cpr::Parameter(std::string{"s"}, std::move(sessionId));
    auto callSignParam = cpr::Parameter(std::string{"callsign"}, std::move(s_callsign));
    auto parameters = cpr::Parameters{sessionParam, callSignParam};
    auto c_verbose = cpr::Verbose{};
    auto session = cpr::Session{};
    session.SetUrl(url);
    session.SetParameters(parameters);
    session.SetOption(c_verbose.verbose);

    auto r = session.Get();

    tinyxml2::XMLDocument doc;
    doc.Parse(r.text.c_str());
    Callsign r_callsign = {};
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("call"))
        r_callsign.call = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("call")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("aliases"))
        r_callsign.aliases = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("aliases")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("dxcc"))
        r_callsign.dxcc = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("dxcc")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("fname"))
        r_callsign.fname = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("fname")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("name"))
        r_callsign.name = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("name")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("addr1"))
        r_callsign.addr1 = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("addr1")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("addr2"))
        r_callsign.addr2 = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("addr2")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("state"))
        r_callsign.state = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("state")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("zip"))
        r_callsign.zip = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("zip")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("country"))
        r_callsign.country = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("country")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("lat"))
        r_callsign.lat = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("lat")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("lon"))
        r_callsign.lon = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("lon")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("grid"))
        r_callsign.grid = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("grid")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("county"))
        r_callsign.county = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("county")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("ccode"))
        r_callsign.ccode = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("ccode")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("fips"))
        r_callsign.fips = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("fips")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("land"))
        r_callsign.land = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("land")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("efdate"))
        r_callsign.efdate = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("efdate")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("expdate"))
        r_callsign.expdate = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("expdate")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("class"))
        r_callsign.cclass = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("class")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("codes"))
        r_callsign.codes = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("codes")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("qslmgr"))
        r_callsign.qslmgr = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("qslmgr")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("email"))
        r_callsign.email = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("email")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("u_views"))
        r_callsign.u_views = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("u_views")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("bio"))
        r_callsign.bio = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("bio")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("biodate"))
        r_callsign.biodate = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("biodate")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("image"))
        r_callsign.image = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("image")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("imageinfo"))
        r_callsign.imageinfo = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("imageinfo")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("moddate"))
        r_callsign.moddate = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("moddate")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("MSA"))
        r_callsign.MSA = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("MSA")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("AreaCode"))
        r_callsign.AreaCode = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("AreaCode")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("TimeZone"))
        r_callsign.TimeZone = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("TimeZone")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("GMTOffset"))
        r_callsign.GMTOffset = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("GMTOffset")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("DST"))
        r_callsign.DST = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("DST")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("eqsl"))
        r_callsign.eqsl = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("eqsl")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("mqsl"))
        r_callsign.mqsl = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("mqsl")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("cqzone"))
        r_callsign.cqzone = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("cqzone")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("ituzone"))
        r_callsign.ituzone = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("ituzone")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("lotw"))
        r_callsign.lotw = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("lotw")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("user"))
        r_callsign.user = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("user")->GetText();
    if(doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("geoloc"))
        r_callsign.geoloc = doc.FirstChildElement("QRZDatabase")->FirstChildElement("Callsign")->FirstChildElement("geoloc")->GetText();
    return r_callsign;
  }
}
