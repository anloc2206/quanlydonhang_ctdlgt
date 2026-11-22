#ifndef NHAPXUAT_H
#define NHAPXUAT_H

#include <string>

// ===== NHAP DU LIEU AN TOAN - CHU SO HUU: TV1 (DA VIET SAN) =====
// Moi ham deu HOI LAI khi nhap sai, khong lam chuong trinh bi treo hay loi.
// Ca nhom CHI dung cac ham nay de nhap tu ban phim (khong tu y dung cin >> ...).

// Nhap 1 chuoi khong rong (tu cat khoang trang hai dau).
std::string nhapChuoi(const std::string& loiNhac);

// Nhap so nguyen trong khoang [nhoNhat, lonNhat].
int nhapSoNguyen(const std::string& loiNhac, int nhoNhat, int lonNhat);

// Nhap so nguyen lon >= nhoNhat (dung cho tien).
long long nhapSoLon(const std::string& loiNhac, long long nhoNhat);

#endif
