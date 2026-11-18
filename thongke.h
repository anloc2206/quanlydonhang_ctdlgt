#ifndef THONGKE_H
#define THONGKE_H

#include "hethong.h"

// Dem tong so don hang trong ca hai hang doi.
int tongSoDon(const HeThong &ht);

// Tinh tong gia tri cua tat ca don hang con trong he thong.
long long tongGiaTri(const HeThong &ht);

// Dem so don hang co trang thai t.
int demTheoTrangThai(const HeThong &ht, TrangThai t);

// In bao cao tong hop so luong va gia tri theo tung trang thai.
void thongKe(const HeThong &ht);

// Cho nguoi dung chon trang thai va in cac don thuoc trang thai do.
void xemDonTheoTrangThai(const HeThong &ht);

#endif
