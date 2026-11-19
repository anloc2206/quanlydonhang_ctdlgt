#include "ngay.h"

#include <cassert>
#include <iostream>
using namespace std;

// Kiem thu cac ham xu ly ngay doc lap voi he thong don hang.
int main() {
    Ngay n;

    assert(laNamNhuan(2024) == true);
    assert(laNamNhuan(2026) == false);
    assert(laNamNhuan(2000) == true);
    assert(laNamNhuan(1900) == false);

    Ngay hopLe1 = {29, 2, 2024};
    Ngay khongHopLe1 = {29, 2, 2026};
    Ngay hopLe2 = {29, 2, 2000};
    Ngay khongHopLe2 = {29, 2, 1900};
    Ngay khongHopLe3 = {31, 4, 2026};
    Ngay khongHopLe4 = {0, 1, 2026};
    Ngay khongHopLe5 = {15, 13, 2026};
    Ngay ngoaiKhoang1 = {1, 1, 1899};
    Ngay ngoaiKhoang2 = {1, 1, 2101};

    assert(ngayHopLe(hopLe1));
    assert(!ngayHopLe(khongHopLe1));
    assert(ngayHopLe(hopLe2));
    assert(!ngayHopLe(khongHopLe2));
    assert(!ngayHopLe(khongHopLe3));
    assert(!ngayHopLe(khongHopLe4));
    assert(!ngayHopLe(khongHopLe5));
    assert(!ngayHopLe(ngoaiKhoang1));
    assert(!ngayHopLe(ngoaiKhoang2));

    assert(docNgay("5/3/2026", n));
    assert(n.ngay == 5 && n.thang == 3 && n.nam == 2026);
    assert(ngaySangChu(n) == "05/03/2026");

    assert(docNgay("05/03/2026", n));
    assert(!docNgay("2026-03-05", n));
    assert(!docNgay("5/3/2026abc", n));
    assert(!docNgay("abc", n));
    assert(!docNgay("", n));
    assert(!docNgay("//", n));

    Ngay cungNgay = {5, 3, 2026};
    Ngay khacNgay = {6, 3, 2026};
    assert(ngayBang(n, cungNgay));
    assert(!ngayBang(n, khacNgay));

    cout << "Tat ca kiem thu ngay deu DAT.\n";
    return 0;
}
