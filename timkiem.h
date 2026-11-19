#ifndef TIMKIEM_H
#define TIMKIEM_H

#include "hethong.h"
#include "ngay.h"

// Dem so don co ngay tao trung voi ngay can tim.
int timDonTheoNgay(const HeThong& ht, const Ngay& n);

// Giao dien nhap ngay va hien thi cac don tim thay.
void giaoDienTimDonTheoNgay(const HeThong& ht);

#endif
