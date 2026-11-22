#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include "dulieu.h"
#include "hethong.h"

// ===== MODULE DON HANG: tao / xoa / xem don - CHU SO HUU: TV3 =====

// ----- DA VIET SAN (dung chung ca nhom khi in don) -----
std::string trangThaiSangChu(TrangThai t);   // CHO_PHE_DUYET -> "Cho phe duyet", ...
void inTieuDeBang();                         // in dong tieu de + gach ngang cua bang don hang
void inDon(const DonHang& d);                // in 1 don tren 1 dong, thang cot voi tieu de

// ----- TV3 CAI DAT -----
void taoDon(HeThong& ht);                    // chuc nang 1
void xemTatCaDon(const HeThong& ht);         // chuc nang 2
void xoaDon(HeThong& ht);                    // chuc nang 3

#endif
