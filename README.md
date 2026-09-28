# CPython 3.10.11 for iOS 6 / ARMv7

An unofficial port of CPython 3.10.11 to iOS 6 ARMv7 devices.

This project provides a native Python 3.10.11 interpreter for legacy
jailbroken iOS devices.

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
pip and basic modules also working.

## Missing modules

The following optional/extension modules are currently unavailable:

* nis
* ossaudiodev
* spwd
* tkinter

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

## Install  

You can install this port from Cydia repo https://alex-fsrg.github.io/repo, install .deb file from releases, or build it from Source

### Install pip after installing

To install pip, run
""" sh
python3 -m ensurepip --user
"""

## Building from Source

See [build.md](build.md)

## Contributing

If you manage to port additional modules or Python packages to iOS 6 /
ARMv7, contributions are welcome.

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
