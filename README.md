# QRZ.com XML C++ Tools
## Notice
This tool is **NOT** official. It was a project I used to teach myself some C++. Use at your own risk!

## Build Process
```shell
mkdir build
cd build
cmake ..
make
```

## Copyright and License
Copyright © 2020 Michael Englehorn 

This program is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by 
the Free Software Foundation, either version 3 of the License, or 
(at your option) any later version. 

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
GNU General Public License for more details. 

You should have received a copy of the GNU General Public License 
along with this program.  If not, see <https://www.gnu.org/licenses/>. 

## Usage
```shell
./CallLookup <callsign>
```

On the first run, the tool will ask for your callsign and qrz.com password. This generates `credentials.dat`. 
The `credentials.dat` file **DOES NOT** contain your username or password, it contains a session key which it receives from the qrz.com API.

On each subsequent run, the tool will recover the session key from `credentials.dat` and attempt to use it. It will most likely crash if the session key doesn't work or is expired. This is a bug to be fixed in future releases. To mitigate this issue, delete `credentials.dat`.

## Classes
### k0hax::qrz::Callsign
This class is a data structure that contains all the data returned by QRZ's XML API about a call sign. 
It can be initialized only as an empty object, but does contain a `void* Save(std::string Filename)` function, which saves the structure to a binary data blob with a very simple format. 
The format can be described as follows, each set of curly brackets is a single byte, each set of square brackets is a char[] array.

```
{size of following field}[value of field]
```

### k0hax::qrz::Credentials
This class is a data structure that deals with QRZ's API session key. It has three initializers.

`k0hax::qrz::Credentials{}`  
This is the empty initializer, it creates an empty Credentials object.

`k0hax::qrz::Credentials{const std::string& SessionID}`  
This initialization is useful if you already have a SessionID you want to use.

`k0hax::qrz::Credentials{const std::string& username, const std::string& password}`  
This initialization will immediately retreive a new SessionID from the QRZ API. It is safe to assume that the Credentials object will be ready to use immediately upon being initalized with this constructor.

`k0hax::qrz::Credentials.Load(const std::string& filename)`  
This class function will load a SessionID from the file name given into the current object.

`k0hax::qrz::Credentials.Save(const std::string& filename)`  
This class function will save the SessionID stored by the class object into the file named, overwriting any existing data stored in that file.

`k0hax::qrz::Credentials.SessionID`  
This class attribute stores the SessionID for use by the rest of the library.

## Functions
### k0hax::qrz::GetCallsign(std::string sessionId, std::string callsign)
This function will take a QRZ API SessionID and a callsign, and return a `k0hax::qrz::Callsign` class object.

### k0hax::qrz::GetQrzSession(std::string username, std::string password, std::string* sessionId)
This function takes a username and password, as well as a pointer to a std::string. It will use the username and password to request a SessionID from the QRZ API, and return a pointer to the std::string containing the new SessionID.

It is not recommended to use this function on its own, you should use the provided k0hax::qrz::Credentials class instead.

