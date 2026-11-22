#include <iostream>

#include "dulieu.h"
#include "nhapxuat.h"
#include "ngay.h"
#include "hangdoi.h"
#include "hethong.h"
#include "donhang.h"
#include "thongke.h"
#include "timkiem.h"
#include "dulieumau.h"

using namespace std;

// ===== CHUONG TRINH CHINH - CHU SO HUU: TV1 =====

static void hienMenu() {
    cout << "\n=========== QUAN LY DON DAT HANG TRUC TUYEN ===========\n";
    cout << "  1. Tao don hang moi\n";
    cout << "  2. Xem tat ca don hang\n";
    cout << "  3. Xoa don hang\n";
    cout << "  4. Xu ly don hang (duyet / huy don dau hang cho)\n";
    cout << "  5. Hoan thanh don hang\n";
    cout << "  6. Thong ke\n";
    cout << "  7. Tim don hang theo ngay tao\n";
    cout << "  8. Xem don hang theo trang thai\n";
    cout << "  9. Tao du lieu mau\n";
    cout << " 10. Danh gia hieu nang\n";
    cout << "  0. Thoat\n";
    cout << "=========================================================\n";
}

int main() {
    HeThong ht;
    khoiTaoHeThong(ht);

    int chon;
    do {
        hienMenu();
        chon = nhapSoNguyen("Chon chuc nang (0-10): ", 0, 10);
        cout << "\n";

        switch (chon) {
            case 1: taoDon(ht); break;
            case 2: xemTatCaDon(ht); break;
            case 3: xoaDon(ht); break;
            case 4: xuLyDon(ht); break;
            case 5: hoanThanhDon(ht); break;
            case 6: thongKe(ht); break;
            case 7: {
                giaoDienTimDonTheoNgay(ht);
                break;
            }
            case 8: xemDonTheoTrangThai(ht); break;
            case 9: {
                int sl = nhapSoNguyen("Nhap so don mau can tao (1-100000): ", 1, 100000);
                taoDuLieuMau(ht, sl);
                break;
            }
            case 10: danhGiaHieuNang(); break;
            case 0: cout << "Tam biet!\n"; break;
        }
    } while (chon != 0);

    giaiPhongHeThong(ht);
    return 0;
}
