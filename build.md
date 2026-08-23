# Building from Source
## Requirements for building CPython 3.10.11 for iOS 6 / ARMv7:
* OS X 10.9
* Xcode 4.x.x (Tested with Xcode 4.6.3)
* Python 3.10.11 installed the on Mac
* ldid installed on the Mac
## Building
### Step 1. Add Xcode toolchain bin and lib folders to PATH  
Run:
```sh
sudo nano /etc/paths
```
Type:
```text
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib
```
Save file.
### Step 2. Configure  
```sh
chmod +x configure
CONFIG_SITE="$PWD/ios-config.site" READELF=true ./configure --host=arm-apple-darwin --build=x86_64-apple-darwin --disable-ipv6 CC="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang" CPP="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang -E" CXX="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++" CFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk -miphoneos-version-min=6.0" CPPFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk" LDFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk -miphoneos-version-min=6.0"

```
Run this command from the root directory fo the cloned repository.  
### Step 3. Disable HAVE_SENDFILE  
```sh
sed -i '' 's/^#define HAVE_SENDFILE 1$/\/\* #undef HAVE_SENDFILE \*\//' pyconfig.h
```
Run this command from the root directory fo the cloned repository.  
### Step 4. Build  
```sh
make
```
Run this command from the root directory fo the cloned repository.  
### Step 5. Sign the binary using ldid  
``` sh
ldid -S python.exe
```
Run this command from the root directory fo the cloned repository  
### Optional: Create a .deb package
You can optionally package the Python binary and the Lib directory into a .deb package  
Files from build/lib.darwin-arm-3.10 must be placed in Lib directory  
Lib folder must be installed to
```text
/usr/local/lib/python3.10
```
