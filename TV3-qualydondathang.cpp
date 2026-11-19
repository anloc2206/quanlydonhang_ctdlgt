#include "donhang.h"
#include "hangdoi.h"
#include "nhapxuat.h"
#include "ngay.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Tao don moi: nhap ma (khong trung o ca 2 hang), ten, tien, ngay; dat CHO_PHE_DUYET va enqueue vao hangCho. O(n).
void taoDon(HeThong& ht) {
    DonHang don;
    while (true) {   // lap den khi ma chua ton tai o hangCho lan daXuLy
        don.maDon = nhapChuoi("Nhap ma don: ");
        if (timDonTheoMa(ht, don.maDon) == nullptr) break;
        cout << "Ma don da ton tai, vui long nhap ma khac.\n";
    }
    don.tenKhach = nhapChuoi("Nhap ten khach hang: ");
    don.tongTien = nhapSoLon("Nhap tong tien (>= 1): ", 1);
    don.ngayTao = nhapNgay("Nhap ngay tao (dd/mm/yyyy): ");
    don.trangThai = CHO_PHE_DUYET;
    enqueue(ht.hangCho, don);
    cout << "Da tao don:\n";
    inTieuDeBang();
    inDon(don);
}

// Xem tat ca don: hangCho (dung thu tu hang) roi daXuLy, duyet bang con tro tu head. O(n).
void xemTatCaDon(const HeThong& ht) {
    int soCho = kichThuoc(ht.hangCho);
    int soXong = kichThuoc(ht.daXuLy);
    if (soCho + soXong == 0) {
        cout << "Chua co don hang nao.\n";
        return;
    }
    inTieuDeBang();
    for (const NodeDon* p = ht.hangCho.head; p != nullptr; p = p->next) inDon(p->data);
    for (const NodeDon* p = ht.daXuLy.head; p != nullptr; p = p->next) inDon(p->data);
    cout << "Tong: " << soCho + soXong << " don (dang cho: " << soCho
         << ", da xu ly: " << soXong << ")\n";
}

// Xoa don theo ma: tim, in don, hoi xac nhan (1 = Co, 2 = Khong), xoa o hangCho hoac daXuLy. O(n).
void xoaDon(HeThong& ht) {
string ma = nhapChuoi("Nhap ma don can xoa: ");
    DonHang* don = timDonTheoMa(ht, ma);
    if (don == nullptr) {
        cout << "Khong tim thay don co ma " << ma << ".\n";
        return;
    }
    cout << "Don se bi xoa:\n";
    inTieuDeBang();
    inDon(*don);
    int chon = nhapSoNguyen("Xac nhan xoa? (1 = Co, 2 = Khong): ", 1, 2);
    if (chon != 1) {
        cout << "Da huy, khong xoa don nao.\n";
        return;
    }
    if (xoaTheoMa(ht.hangCho, ma) || xoaTheoMa(ht.daXuLy, ma))
        cout << "Da xoa don " << ma << ".\n";
    else
        cout << "Xoa that bai.\n";
}
