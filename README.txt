TV4 - THONG KE VA LOC THEO TRANG THAI

Files:
- thongke.h: declarations for the five TV4 functions.
- thongke.cpp: implementations.

This code is based on the assignment document. The currently supplied ZIP only
contains hangdoi.h/cpp and does not include dulieu.h, hethong.h, donhang.h,
nhapxuat.h, so compilation against the group's actual project cannot yet be
verified.

Assumed interface names, based on the assignment:
- HeThong has members hangCho and daXuLy, both HangDoi.
- NodeDon has data and next.
- DonHang has tongTien and trangThai.
- TrangThai values: CHO_PHE_DUYET, DA_DUYET, HUY, HOAN_THANH.
- kichThuoc(const HangDoi&)
- nhapSoNguyen(const string& prompt)
- inTieuDeBang() and inDon(const DonHang&)

If the leader's headers use different names/signatures, adjust those names to
match the leader's files. Do not change the group's shared data structures.
