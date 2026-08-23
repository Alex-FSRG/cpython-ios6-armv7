# Building from source code
## Requirements to build CPython 3.10.11 for iOS 6 / ARMv7:
* OS X 10.9
* installed Xcode 4.x.x(Tested with Xcode 4.6.3)
* Installed Python 3.10.11 on Mac
* Installed ldid on Mac
## Building
Step 1. Add Xcode toolchain bin and lib folders to PATH
```text
sudo nano /etc/paths
```
Type:
```text
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin
```
Save file.
Step 2. Configure
Run
```text
 CONFIG_SITE="$PWD/ios-config.site" READELF=true ./configure --host=arm-apple-darwin --build=x86_64-apple-darwin --disable-ipv6 CC="/usr/bin/clang" CPP="/usr/bin/clang -E" CXX="/usr/bin/clang++" CFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk -miphoneos-version-min=6.0" CPPFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk" LDFLAGS="-arch armv7 -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS6.1.sdk -miphoneos-version-min=6.0"

```
in main folder of cloned repo.  
Step 3. Disable HAVE_SENDFILE
Run
```text
sed -i '' 's/^#define HAVE_SENDFILE 1$/\/\* #undef HAVE_SENDFILE \*\//' pyconfig.h
```
in main folder of cloned repo.  
Step 4. Build
Run
```text
make
```
in main folder of cloned repo.  
Step 5. Sign binary using ldid
Run
``` text
ldid -S python.exe
```
in main folder of cloned repo
## Optinally you can pack binary and Lib folder to .deb file
Lib folder must be in /usr/local/lib and named python3.10
