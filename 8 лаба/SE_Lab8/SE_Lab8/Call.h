#pragma once

namespace Call {



    int _cdecl cdevl(int i, int b, int c) {

        return i + b + c;
    };

    int _stdcall cstd(int& i, int b, int c) {

        return i * b * c;
    };

    int _fastcall cfst(int i, int b, int c, int d) {

        return i + b + c + d;
    };
}