BAN THU TV5 - XU LY NGAY THANG VA TIM KIEM THEO NGAY

1. Cac file
- ngay.h / ngay.cpp: kiem tra nam nhuan, ngay hop le, so sanh, doc chuoi,
  dinh dang va nhap ngay.
- timkiem.h / timkiem.cpp: dem va hien thi don hang theo ngay tao.
- test_ngay.cpp: kiem thu rieng cac ham xu ly ngay.

2. Gia dinh ve cau truc du lieu de viet ban thu
Ban nay dua tren hop dong du lieu trong tai lieu phan cong:
- dulieu.h co struct Ngay voi cac truong int ngay, thang, nam.
- HeThong co hai truong HangDoi: hangCho va daXuLy.
- HangDoi co con tro head.
- NodeDon co DonHang data va con tro next.
- DonHang co truong Ngay ngayTao.
- donhang.h khai bao void inTieuDeBang() va void inDon(const DonHang&).
- nhapxuat.h khai bao string nhapChuoi(const string& loiNhac).

CAC GIA DINH TREN PHAI DUOC DOI CHIEU VOI BO KHUNG ZIP CUA NHOM.
Neu ten truong, kieu du lieu hoac chu ky ham khac, chi sua phan tuong ung
theo header chinh thuc cua nhom; khong tu y sua cac header cua TV1-TV3.

3. Cach kiem thu ngay
Dat cac file ngay.h, ngay.cpp, test_ngay.cpp cung voi dulieu.h va nhapxuat.h
cua nhom. Bien dich vi test_ngay.cpp khong goi nhapNgay, nhung ngay.cpp van
tham chieu nhapxuat.h va ham nhapChuoi, nen can lien ket nhapxuat.cpp:

g++ -std=c++17 -Wall test_ngay.cpp ngay.cpp nhapxuat.cpp -o test_ngay
./test_ngay

4. Tich hop tim kiem
- Them #include "timkiem.h" vao noi can goi chuc nang tim kiem.
- Goi giaoDienTimDonTheoNgay(ht).
- Neu main.cpp cua nhom da co ten ham/menu rieng, bao TV1 va thong nhat ten
  ham goi; khong doi ten ham trong header cua TV1 mot cach tu y.

5. Luu y
Day la ban khoi dau theo tai lieu phan cong, chua the xac nhan bien dich voi
bo khung that vi chua co DeTai5_QuanLyDonHang_KhungDuAn.zip va cac header
chinh thuc trong phien lam viec nay.
