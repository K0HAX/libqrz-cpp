#include <cstdlib>
#include <iostream>
#include <string>

namespace k0hax::qrz
{
  int GetQrzSession(std::string username, std::string password, std::string* sessionId);
  Callsign GetCallsign(std::string sessionId, std::string s_callsign);
}
