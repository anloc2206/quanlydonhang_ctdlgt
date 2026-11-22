#include "hethong.h"

#include <iostream>
#include "donhang.h"
#include "nhapxuat.h"

using namespace std;

// ---------- DA VIET SAN ----------
void khoiTaoHeThong(HeThong& ht) {
    khoiTao(ht.hangCho);
    khoiTao(ht.daXuLy);
}

void giaiPhongHeThong(HeThong& ht) {
    giaiPhong(ht.hangCho);
    giaiPhong(ht.daXuLy);
}

DonHang* timDonTheoMa(HeThong& ht, const string& ma) {
    DonHang* p = timTheoMa(ht.hangCho, ma);
    if (p != nullptr) return p;
    return timTheoMa(ht.daXuLy, ma);
}

// ---------- TV1 CAI DAT ----------

// XU LY DON: lay don dau hangCho (FIFO), hoi Duyet/Huy, chuyen sang daXuLy. O(1)
void xuLyDon(HeThong& ht) {
    DonHang don;
    if (!dequeue(ht.hangCho, don)) {
        cout << "Khong co don nao dang cho phe duyet.\n";
        return;
    }
    cout << "Don o dau hang cho:\n";
    inTieuDeBang();
    inDon(don);
    int chon = nhapSoNguyen("Chon xu ly (1 = Duyet, 2 = Huy): ", 1, 2);
    don.trangThai = (chon == 1) ? DA_DUYET : HUY;
    enqueue(ht.daXuLy, don);
    cout << "Da " << (chon == 1 ? "duyet" : "huy") << " don " << don.maDon << ".\n";
}

// HOAN THANH DON: chi don DA_DUYET (nam trong daXuLy) moi duoc chuyen sang HOAN_THANH. O(n)
void hoanThanhDon(HeThong& ht) {
    string ma = nhapChuoi("Nhap ma don can hoan thanh: ");
    DonHang* d = timTheoMa(ht.daXuLy, ma);
    if (d == nullptr) {
        if (timTheoMa(ht.hangCho, ma) != nullptr)
            cout << "Don dang cho phe duyet, chua the hoan thanh.\n";
        else
            cout << "Khong tim thay don co ma " << ma << ".\n";
        return;
    }
    if (d->trangThai == HUY) {
        cout << "Don da bi huy, khong the hoan thanh.\n";
        return;
    }
    if (d->trangThai == HOAN_THANH) {
        cout << "Don nay da hoan thanh truoc do.\n";
        return;
    }
    d->trangThai = HOAN_THANH;
    cout << "Da hoan thanh don " << ma << ".\n";
    inTieuDeBang();
    inDon(*d);
}
