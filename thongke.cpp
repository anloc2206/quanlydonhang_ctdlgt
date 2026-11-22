#include "thongke.h"
#include "donhang.h"
#include "nhapxuat.h"
#include <iostream>
#include <string>
using namespace std;

// Dem tong so don trong hai hang doi. Kich thuoc hang doi da duoc cap nhat khi them/xoa.
int tongSoDon(const HeThong &ht)
{
    return kichThuoc(ht.hangCho) + kichThuoc(ht.daXuLy);
}

// Cong tong tien cua tung don trong ca hangCho va daXuLy.
long long tongGiaTri(const HeThong &ht)
{
    long long tong = 0;

    for (const NodeDon *p = ht.hangCho.head; p != nullptr; p = p->next)
        tong += p->data.tongTien;

    for (const NodeDon *p = ht.daXuLy.head; p != nullptr; p = p->next)
        tong += p->data.tongTien;

    return tong;
}

// Duyet ca hai hang doi va dem cac don co trang thai trung voi t.
int demTheoTrangThai(const HeThong &ht, TrangThai t)
{
    int dem = 0;

    for (const NodeDon *p = ht.hangCho.head; p != nullptr; p = p->next)
        if (p->data.trangThai == t)
            dem++;

    for (const NodeDon *p = ht.daXuLy.head; p != nullptr; p = p->next)
        if (p->data.trangThai == t)
            dem++;

    return dem;
}

// In tong so don, tong gia tri va so don/tong tien cua tung trang thai.
void thongKe(const HeThong &ht)
{
    if (tongSoDon(ht) == 0)
    {
        cout << "Chua co don hang nao.\n";
        cout << "Tong so don: 0\n";
        cout << "Tong gia tri: 0 VND\n";
        return;
    }

    const TrangThai cacTrangThai[] = {
        CHO_PHE_DUYET, DA_DUYET, HUY, HOAN_THANH
    };
    const string tenTrangThai[] = {
        "Cho phe duyet", "Da duyet", "Huy", "Hoan thanh"
    };

    cout << "\n========== THONG KE DON HANG ==========\n";
    cout << "Tong so don hang: " << tongSoDon(ht) << "\n";
    cout << "Tong gia tri don hang: " << tongGiaTri(ht) << " VND\n";

    for (int i = 0; i < 4; i++)
    {
        int soDon = 0;
        long long giaTri = 0;

        for (const NodeDon *p = ht.hangCho.head; p != nullptr; p = p->next)
        {
            if (p->data.trangThai == cacTrangThai[i])
            {
                soDon++;
                giaTri += p->data.tongTien;
            }
        }

        for (const NodeDon *p = ht.daXuLy.head; p != nullptr; p = p->next)
        {
            if (p->data.trangThai == cacTrangThai[i])
            {
                soDon++;
                giaTri += p->data.tongTien;
            }
        }

        cout << "\n" << tenTrangThai[i] << ":\n";
        cout << "So don: " << soDon << "\n";
        cout << "Tong gia tri: " << giaTri << " VND\n";
    }

    cout << "=======================================\n";
}

// Nhap trang thai, duyet hai hang doi va in cac don co trang thai duoc chon.
void xemDonTheoTrangThai(const HeThong &ht)
{
    cout << "\n===== LOC DON HANG THEO TRANG THAI =====\n";
    cout << "1. Cho phe duyet\n";
    cout << "2. Da duyet\n";
    cout << "3. Huy\n";
    cout << "4. Hoan thanh\n";
    int chon = nhapSoNguyen("Chon trang thai (1-4): ", 1, 4);

    TrangThai t;
    string tenTrangThai;
    switch (chon)
    {
    case 1:
        t = CHO_PHE_DUYET;
        tenTrangThai = "Cho phe duyet";
        break;
    case 2:
        t = DA_DUYET;
        tenTrangThai = "Da duyet";
        break;
    case 3:
        t = HUY;
        tenTrangThai = "Huy";
        break;
    default:
        t = HOAN_THANH;
        tenTrangThai = "Hoan thanh";
        break;
    }

    int dem = 0;
    for (const NodeDon *p = ht.hangCho.head; p != nullptr; p = p->next)
    {
        if (p->data.trangThai == t)
        {
            if (dem == 0)
                inTieuDeBang();
            inDon(p->data);
            dem++;
        }
    }

    for (const NodeDon *p = ht.daXuLy.head; p != nullptr; p = p->next)
    {
        if (p->data.trangThai == t)
        {
            if (dem == 0)
                inTieuDeBang();
            inDon(p->data);
            dem++;
        }
    }

    if (dem == 0)
        cout << "Khong co don nao o trang thai " << tenTrangThai << ".\n";
    else
        cout << "Tong so don o trang thai " << tenTrangThai << ": " << dem << "\n";
}