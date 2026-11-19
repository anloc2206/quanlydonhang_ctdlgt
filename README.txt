PHAN TV6 - DU LIEU MAU, HIEU NANG VA QA

Cac file:
- dulieumau.h: khai bao 2 ham TV6.
- dulieumau.cpp: sinh du lieu mau va do hieu nang.

YEU CAU TICH HOP
1. Can co cac file cua nhom: dulieu.h, hethong.h, hangdoi.h/.cpp, thongke.h/.cpp.
2. Code nay gia dinh:
   - HeThong co hai thanh vien HangDoi: hangCho va daXuLy.
   - DonHang co maDon, tenKhach, tongTien, ngayTao, trangThai.
   - Ngay co ngay, thang, nam.
   - TrangThai gom CHO_PHE_DUYET, DA_DUYET, HUY, HOAN_THANH.
   - thongke.h khai bao long long tongGiaTri(const HeThong&) va
     int demTheoTrangThai(const HeThong&, TrangThai).
   - hangdoi.h khai bao khoiTao, enqueue, dequeue, kichThuoc, timTheoMa,
     giaiPhong.
3. ZIP project hien tai ma nhom gui chi co hangdoi.h/.cpp, README va test_hangdoi.cpp;
   chua co cac header nen nen chua the xac nhan ghep va bien dich tren project that.
4. Khong thay doi chu ky ham/struct cua TV1. Neu header thuc te khac cac gia dinh tren,
   gui dulieu.h, hethong.h, thongke.h de chinh lai.

CACH THEM VAO PROJECT
- Dat dulieumau.h va dulieumau.cpp cung thu muc voi cac file .cpp/.h khac.
- Bao TV1 them menu goi taoDuLieuMau(ht, soLuong) va danhGiaHieuNang().
- Bien dich theo yeu cau: g++ -std=c++17 -Wall -o quanlydon *.cpp

LUU Y KY THUAT
- maTiepTheo va co khoi tao hat giong la static local, khong phai bien toan cuc.
- Ma MAUxxxxx tiep tuc tang giua cac lan goi ham trong cung mot lan chay.
- Du lieu mau tao 2026; ngay duoc chon trong gioi han ngay cua tung thang.
- danhGiaHieuNang tao HeThong rieng va giai phong hai hang, khong dung du lieu that.
- Thoi gian thuc nghiem phu thuoc may, trinh bien dich va tai he thong; khong ghi so lieu mau vao bao cao.
