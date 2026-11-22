#ifndef DULIEU_H
#define DULIEU_H

#include <string>

// ===== MO HINH DU LIEU CHUNG - CHI TV1 (LEADER) DUOC SUA =====
// Da chot. Khong ai tu y doi ten / them / bot truong. Can doi thi bao TV1.

enum TrangThai {
    CHO_PHE_DUYET = 0,
    DA_DUYET      = 1,
    HUY           = 2,
    HOAN_THANH    = 3
};

struct Ngay {
    int ngay;
    int thang;
    int nam;
};

struct DonHang {
    std::string maDon;      // vi du "DH001"; khong rong, khong trung, phan biet hoa/thuong
    std::string tenKhach;   // khong rong
    long long   tongTien;   // >= 1, don vi dong
    Ngay        ngayTao;    // phai la ngay hop le
    TrangThai   trangThai;
};

#endif
