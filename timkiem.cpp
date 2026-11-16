#include "timkiem.h"
#include "donhang.h"
#include "nhapxuat.h"

#include <iostream>
using namespace std;

// Duyet ca hai hang doi va dem don co ngay tao trung ngay can tim.
int timDonTheoNgay(const HeThong& ht, const Ngay& n) {
    int dem = 0;

    for (const NodeDon* p = ht.hangCho.head;
         p != nullptr; p = p->next) {
        if (ngayBang(p->data.ngayTao, n)) {
            dem++;
        }
    }

    for (const NodeDon* p = ht.daXuLy.head;
         p != nullptr; p = p->next) {
        if (ngayBang(p->data.ngayTao, n)) {
            dem++;
        }
    }

    return dem;
}

// Nhap ngay, hien thi cac don khop va thong bao tong so ket qua.
void giaoDienTimDonTheoNgay(const HeThong& ht) {
    Ngay ngayCanTim = nhapNgay("Nhap ngay can tim (dd/mm/yyyy): ");
    int tongSoDon = timDonTheoNgay(ht, ngayCanTim);

    if (tongSoDon == 0) {
        cout << "Khong tim thay don hang nao trong ngay "
             << ngaySangChu(ngayCanTim) << ".\n";
        return;
    }

    bool daInTieuDe = false;

    // Hien thi cac don trong hang cho.
    for (const NodeDon* p = ht.hangCho.head;
         p != nullptr; p = p->next) {
        if (ngayBang(p->data.ngayTao, ngayCanTim)) {
            if (!daInTieuDe) {
                cout << "\nCac don hang duoc tao ngay "
                     << ngaySangChu(ngayCanTim) << ":\n";
                inTieuDeBang();
                daInTieuDe = true;
            }
            inDon(p->data);
        }
    }

    // Hien thi tiep cac don trong hang da xu ly.
    for (const NodeDon* p = ht.daXuLy.head;
         p != nullptr; p = p->next) {
        if (ngayBang(p->data.ngayTao, ngayCanTim)) {
            if (!daInTieuDe) {
                cout << "\nCac don hang duoc tao ngay "
                     << ngaySangChu(ngayCanTim) << ":\n";
                inTieuDeBang();
                daInTieuDe = true;
            }
            inDon(p->data);
        }
    }

    cout << "Tong so don tim thay: " << tongSoDon << "\n";
}
