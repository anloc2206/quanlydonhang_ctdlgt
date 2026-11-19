#include "dulieumau.h"
#include "hangdoi.h"
#include "thongke.h"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
using namespace chrono;

// Tao ngay hop le ngau nhien trong nam 2026.
static Ngay taoNgayNgauNhien()
{
    Ngay n;
    int soNgayMoiThang[12] = {31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
    n.thang = rand() % 12 + 1;
    n.ngay = rand() % soNgayMoiThang[n.thang - 1] + 1;
    n.nam = 2026;
    return n;
}

// Sinh du lieu mau, ma don tang dan de cac lan goi khong trung nhau.
void taoDuLieuMau(HeThong& ht, int soLuong)
{
    if (soLuong <= 0)
    {
        cout << "So luong phai la so nguyen duong.\n";
        return;
    }

    // Chi khoi tao hat giong mot lan de ket qua lap lai duoc.
    static bool daKhoiTaoHatGiong = false;
    if (!daKhoiTaoHatGiong)
    {
        srand(2026);
        daKhoiTaoHatGiong = true;
    }

    // Bien dem static giu gia tri giua cac lan goi ham.
    static int maTiepTheo = 1;
    const string tenKhach[] = {
        "Nguyen An", "Tran Binh", "Le Chi", "Pham Dung",
        "Hoang Giang", "Vo Hanh", "Dang Khoa", "Bui Lan",
        "Do Minh", "Ngo Phuc", "Vu Quan", "Mai Trang",
        "Cao Uyen", "Truong Yen", "Ly Nam"};
    const int soTen = 15;

    // Tao toan bo don trong hangCho truoc.
    for (int i = 0; i < soLuong; i++)
    {
        DonHang d;
        d.maDon = "MAU";
        string so = to_string(maTiepTheo++);
        while (so.length() < 5)
            so = "0" + so;
        d.maDon += so;
        d.tenKhach = tenKhach[rand() % soTen];
        d.tongTien = (rand() % 49991 + 10) * 1000LL;
        d.ngayTao = taoNgayNgauNhien();
        d.trangThai = CHO_PHE_DUYET;
        enqueue(ht.hangCho, d);
    }

    // Giu lai khoang 30% don cho phe duyet.
    int soDonCho = soLuong * 30 / 100;
    int soDonXuLy = soLuong - soDonCho;

    // Dua 70% con lai sang daXuLy, chia deu cho ba trang thai.
    for (int i = 0; i < soDonXuLy; i++)
    {
        DonHang d;
        if (!dequeue(ht.hangCho, d))
            break;

        if (i % 3 == 0)
            d.trangThai = DA_DUYET;
        else if (i % 3 == 1)
            d.trangThai = HUY;
        else
            d.trangThai = HOAN_THANH;

        enqueue(ht.daXuLy, d);
    }

    cout << "Da tao them " << soLuong << " don hang mau.\n";
    cout << "Don cho phe duyet: " << kichThuoc(ht.hangCho) << "\n";
    cout << "Don da xu ly: " << kichThuoc(ht.daXuLy) << "\n";
}

// Do hieu nang tren HeThong tam, khong tac dong du lieu nguoi dung.
void danhGiaHieuNang()
{
    const int cacMucN[3] = {1000, 10000, 100000};
    const int SO_LAN_DO = 100;

    cout << "\n========== DANH GIA HIEU NANG ==========" << "\n";
    cout << left << setw(12) << "So don"
         << setw(18) << "Enqueue (ms)"
         << setw(18) << "Tim cuoi (us)"
         << setw(18) << "Tong gia tri (us)"
         << setw(18) << "Dem trang thai (us)" << "\n";

    for (int muc = 0; muc < 3; muc++)
    {
        int n = cacMucN[muc];
        HeThong tam;
        khoiTao(tam.hangCho);
        khoiTao(tam.daXuLy);

        DonHang d;
        d.tenKhach = "Khach mau";
        d.tongTien = 100000;
        d.ngayTao.ngay = 1;
        d.ngayTao.thang = 1;
        d.ngayTao.nam = 2026;
        d.trangThai = CHO_PHE_DUYET;

        // Do tong thoi gian them N don vao hangCho.
        auto batDau = steady_clock::now();
        for (int i = 1; i <= n; i++)
        {
            d.maDon = "TEST" + to_string(i);
            enqueue(tam.hangCho, d);
        }
        auto ketThuc = steady_clock::now();
        double thoiGianEnqueue =
            duration<double, milli>(ketThuc - batDau).count();

        // Tim don cuoi hang nhieu lan va lay thoi gian trung binh.
        string maCuoi = "TEST" + to_string(n);
        volatile int soLanTimThay = 0;
        batDau = steady_clock::now();
        for (int i = 0; i < SO_LAN_DO; i++)
        {
            if (timTheoMa(tam.hangCho, maCuoi) != nullptr)
                soLanTimThay++;
        }
        ketThuc = steady_clock::now();
        double thoiGianTim =
            duration<double, micro>(ketThuc - batDau).count() / SO_LAN_DO;

        // Do trung binh hai ham thong ke cua TV4.
        volatile long long ketQuaTong = 0;
        batDau = steady_clock::now();
        for (int i = 0; i < SO_LAN_DO; i++)
            ketQuaTong += tongGiaTri(tam);
        ketThuc = steady_clock::now();
        double thoiGianTong =
            duration<double, micro>(ketThuc - batDau).count() / SO_LAN_DO;

        volatile int ketQuaDem = 0;
        batDau = steady_clock::now();
        for (int i = 0; i < SO_LAN_DO; i++)
            ketQuaDem += demTheoTrangThai(tam, CHO_PHE_DUYET);
        ketThuc = steady_clock::now();
        double thoiGianDem =
            duration<double, micro>(ketThuc - batDau).count() / SO_LAN_DO;

        cout << left << setw(12) << n
             << setw(18) << fixed << setprecision(3) << thoiGianEnqueue
             << setw(18) << thoiGianTim
             << setw(18) << thoiGianTong
             << setw(18) << thoiGianDem << "\n";

        // Giai phong ca hai hang cua HeThong tam sau moi muc do.
        giaiPhong(tam.hangCho);
        giaiPhong(tam.daXuLy);
    }

    cout << "========================================\n";
}
