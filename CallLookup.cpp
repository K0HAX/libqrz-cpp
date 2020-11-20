#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include <include/k0hax-qrz.h>

int main(int argc, char* argv[])
{
  k0hax::qrz::Credentials creds;
  if(!creds.Load("credentials.dat"))
  {
    std::string username;
    std::string password;
    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);
    creds = k0hax::qrz::Credentials{username, password};
    creds.Save("credentials.dat");
    std::cout << "Saved Credentials!" << std::endl;
  }
  std::string callsign = std::string{argv[1]};
  std::cout << "Session ID: " << creds.SessionID << std::endl;

  k0hax::qrz::Callsign call = {};
  call = k0hax::qrz::GetCallsign(creds.SessionID, callsign);
  std::cout << "Callsign: " << call.call << std::endl;
  call.Save("calls.dat");

  return 0;
}
