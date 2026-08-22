# CPython 3.10 for iOS 6 / ARMv7

Unofficial port of CPython 3.10.11 to iOS 6 ARMv7 devices.

This project provides a native Python 3.10.11 interpreter for legacy
jailbroken iOS devices, including devices such as the iPad 2.

## What is this?

This is a port of CPython 3.10.11 for the legacy iOS 6 / ARMv7 environment.

The original CPython source code does not build out of the box with the
old Xcode/iOS SDK toolchain required for iOS 6. Several parts of CPython
had to be modified or replaced with compatibility code.

The resulting interpreter runs natively on ARMv7 devices running iOS 6.

### Tested on

- iPad 2 on iOS 6

## Current status

The Python 3.10.11 interpreter itself is working on iOS 6.

Example:

```text
iPad:~ root# python3
Python 3.10.11 (...)
>>> print("Hello from iPad 2")
Hello from iPad 2
>>>
```

## Missing modules

The following optional/extension modules are currently unavailable:

* bz2
* curses
* curses_panel
* dbm
* gdbm
* hashlib
* lzma
* sqlite3
* ssl
* nis
* ossaudiodev
* readline
* spwd
* zlib
* ctypes

Python signal handling is also currently disabled and replaced with a
minimal compatibility layer required to build the interpreter for the
legacy ARMv7/iOS 6 toolchain.

This means that Python programs depending on these modules may not work
without additional porting.

## Why?

Modern Python versions are generally unavailable on very old jailbroken
iOS devices.

This project attempts to bring a modern Python runtime to legacy iOS
hardware and provide a foundation for running and porting Python
software on devices that are no longer supported by current Python
releases.

## Limitations

This is an experimental legacy platform port.

Many Python packages will require additional work because:

* some standard-library extension modules are missing;
* third-party packages may require unavailable native dependencies;
* iOS 6 has a very old system environment;
* ARMv7 is a 32-bit architecture;
* the available compiler and SDK are significantly older than those
    normally used to build CPython 3.10.

## Contributing

If you manage to port additional modules or Python packages to iOS 6 /
ARMv7, contributions are welcome.

Useful areas for future work include:

* zlib
* ssl
* hashlib
* sqlite3
* ctypes
* readline
* bz2
* lzma

# Credits

This project is based on CPython.

CPython:
https://github.com/python/cpython

Python:
https://www.python.org/

This is an unofficial community port and is not affiliated with or
endorsed by the Python Software Foundation.

## License

CPython is distributed under the Python Software Foundation License.
See the original CPython source tree and LICENSE file for the complete
license text.