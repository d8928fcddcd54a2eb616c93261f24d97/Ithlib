### Build & run instructions

Build:

```batch
git clone https://github.com/d8928fcddcd54a2eb616c93261f24d97/ithlib
cd ithlib
vcpkg install boost:x64-windows-static-md
vcpkg install pegtl:x64-windows-static-md
vcpkg install utfcpp:x64-windows-static-md
vcpkg install fmt:x64-windows-static-md
msbuild
```
Run:

```
\x64\Debug\Ithlib.exe
```

type in a formative, press \<Enter\>, get results.
