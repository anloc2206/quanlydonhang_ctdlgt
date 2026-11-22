#ifndef HETHONG_H
#define HETHONG_H

#include <string>
#include "hangdoi.h"

// ===== HE THONG DON HANG + XU LY DON - CHU SO HUU: TV1 (LEADER) =====
//   hangCho : cac don dang CHO_PHE_DUYET (FIFO: don tao truoc duoc xu ly truoc)
//   daXuLy  : cac don da DUYET / HUY / HOAN_THANH (theo thu tu duoc xu ly)

struct HeThong {
    HangDoi hangCho;
    HangDoi daXuLy;
};

// ----- DA VIET SAN -----
void khoiTaoHeThong(HeThong& ht);
void giaiPhongHeThong(HeThong& ht);
DonHang* timDonTheoMa(HeThong& ht, const std::string& ma);   // tim o CA HAI hang; nullptr neu khong co

// ----- TV1 CAI DAT -----
void xuLyDon(HeThong& ht);        // chuc nang 4
void hoanThanhDon(HeThong& ht);   // chuc nang 5

#endif
