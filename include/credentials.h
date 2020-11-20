#include <cstdlib>
#include <string>

namespace k0hax::qrz
{
  class Credentials {
  private:
    std::string Username;
    std::string Password;
  public:
    std::string SessionID;
    Credentials(const std::string&, const std::string&);
    Credentials(const std::string&);
    Credentials();
    void* Login(const std::string&, const std::string&);
    int Save(const std::string&);
    int Load(const std::string&);
  };
}
