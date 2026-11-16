#ifndef NGAY_H
#define NGAY_H

#include <string>
#include "dulieu.h"

using namespace std;

// Kiem tra nam co phai nam nhuan hay khong.
bool laNamNhuan(int nam);

// Kiem tra ngay co hop le trong khoang nam 1900-2100 hay khong.
bool ngayHopLe(const Ngay& n);

// So sanh hai ngay theo ngay, thang va nam.
bool ngayBang(const Ngay& a, const Ngay& b);

// Doc chuoi ngay dang d/m/yyyy hoac dd/mm/yyyy va chuyen thanh Ngay.
bool docNgay(const string& s, Ngay& kq);

// Chuyen Ngay thanh chuoi dd/mm/yyyy co so 0 dem.
string ngaySangChu(const Ngay& n);

// Nhap ngay den khi nguoi dung nhap dung dinh dang va ngay hop le.
Ngay nhapNgay(const string& loiNhac);

#endif
