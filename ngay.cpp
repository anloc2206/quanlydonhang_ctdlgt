#include "ngay.h"
#include "nhapxuat.h"

#include <iomanip>
#include <iostream>
#include <sstream>

// Kiem tra nam nhuan theo quy tac lich Gregorian.
bool laNamNhuan(int nam) {
    if (nam % 400 == 0) {
        return true;
    }
    if (nam % 100 == 0) {
        return false;
    }
    return nam % 4 == 0;
}

// Kiem tra gioi han nam, thang va so ngay cua thang.
bool ngayHopLe(const Ngay& n) {
    if (n.nam < 1900 || n.nam > 2100) {
        return false;
    }

    if (n.thang < 1 || n.thang > 12) {
        return false;
    }

    if (n.ngay < 1) {
        return false;
    }

    int soNgayTrongThang[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (n.thang == 2 && laNamNhuan(n.nam)) {
        soNgayTrongThang[1] = 29;
    }

    return n.ngay <= soNgayTrongThang[n.thang - 1];
}

// So sanh day du ba thanh phan cua ngay.
bool ngayBang(const Ngay& a, const Ngay& b) {
    return a.ngay == b.ngay &&
           a.thang == b.thang &&
           a.nam == b.nam;
}

// Chuyen mot doan chi gom chu so thanh so nguyen.
static bool docPhanSo(const string& s, int batDau, int ketThuc, int& giaTri) {
    if (batDau >= ketThuc) {
        return false;
    }

    giaTri = 0;
    for (int i = batDau; i < ketThuc; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
        giaTri = giaTri * 10 + (s[i] - '0');
    }
    return true;
}

// Phan tich chuoi ngay, chi chap nhan ngay/thang 1-2 chu so va nam 4 chu so.
bool docNgay(const string& s, Ngay& kq) {
    int viTriDau = -1;
    int viTriHai = -1;
    int soDauGachCheo = 0;

    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == '/') {
            soDauGachCheo++;
            if (soDauGachCheo == 1) viTriDau = i;
            else if (soDauGachCheo == 2) viTriHai = i;
            else return false;
        }
    }

    if (soDauGachCheo != 2) return false;
    if (viTriDau < 1 || viTriDau > 2) return false;
    if (viTriHai - viTriDau - 1 < 1 || viTriHai - viTriDau - 1 > 2) return false;
    if ((int)s.length() - viTriHai - 1 != 4) return false;

    Ngay tam;
    if (!docPhanSo(s, 0, viTriDau, tam.ngay)) return false;
    if (!docPhanSo(s, viTriDau + 1, viTriHai, tam.thang)) return false;
    if (!docPhanSo(s, viTriHai + 1, (int)s.length(), tam.nam)) return false;
    if (!ngayHopLe(tam)) return false;

    kq = tam;
    return true;
}

// Dinh dang ngay theo dd/mm/yyyy.
string ngaySangChu(const Ngay& n) {
    stringstream ss;
    ss << setfill('0')
       << setw(2) << n.ngay << "/"
       << setw(2) << n.thang << "/"
       << setw(4) << n.nam;

    return ss.str();
}

// Su dung ham nhapChuoi cua module nhapxuat de nhap lai khi sai.
Ngay nhapNgay(const string& loiNhac) {
    string chuoiNhap;
    Ngay ketQua;

    while (true) {
        chuoiNhap = nhapChuoi(loiNhac);

        if (docNgay(chuoiNhap, ketQua)) {
            return ketQua;
        }

        cout << "Ngay khong hop le, vui long nhap lai dd/mm/yyyy.\n";
    }
}
