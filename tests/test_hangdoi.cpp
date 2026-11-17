// test_hangdoi.cpp - Test doc lap cho hangdoi (TV2)
// Bien dich: g++ -std=c++17 -Wall -Istub test_hangdoi.cpp hangdoi.cpp -o test_hangdoi
#include <iostream>
#include <string>
#include "hangdoi.h"
using namespace std;

int soDat = 0, soLoi = 0;

void kiemTra(bool dieuKien, const string &ten)
{
    if (dieuKien)
    {
        soDat++;
        cout << "[DAT]  " << ten << endl;
    }
    else
    {
        soLoi++;
        cout << "[LOI]  " << ten << endl;
    }
}

DonHang taoDon(const string &ma)
{
    DonHang d;
    d.maDon = ma;
    d.tenKhach = "Khach " + ma;
    d.tongTien = 1000;
    d.ngayTao = {1, 1, 2026};
    d.trangThai = CHO_PHE_DUYET;
    return d;
}

// Lay lan luot ra het, ghep ma thanh 1 chuoi de so sanh thu tu (vd "A,B,C,")
string layHetThanhChuoi(HangDoi &q)
{
    string kq = "";
    DonHang d;
    while (dequeue(q, d))
        kq += d.maDon + ",";
    return kq;
}

int main()
{
    HangDoi q;
    DonHang d;

    // T1: enqueue vao hang rong
    khoiTao(q);
    enqueue(q, taoDon("A"));
    kiemTra(q.head == q.tail && q.head != nullptr && kichThuoc(q) == 1, "T1 enqueue vao hang rong: head==tail, size==1");

    // T2: dequeue tu hang rong
    HangDoi rong;
    khoiTao(rong);
    kiemTra(!dequeue(rong, d) && laRong(rong) && kichThuoc(rong) == 0, "T2 dequeue hang rong: false, hang khong doi");

    // T3: enqueue A,B,C roi dequeue 3 lan -> A,B,C; sau do rong, tail == nullptr
    HangDoi q3;
    khoiTao(q3);
    enqueue(q3, taoDon("A"));
    enqueue(q3, taoDon("B"));
    enqueue(q3, taoDon("C"));
    string thuTu = layHetThanhChuoi(q3);
    kiemTra(thuTu == "A,B,C," && laRong(q3) && q3.tail == nullptr && kichThuoc(q3) == 0, "T3 FIFO A,B,C roi hang rong, tail==nullptr");

    // T4: xoa dau / giua / cuoi
    HangDoi q4;
    khoiTao(q4);
    string ma[] = {"A", "B", "C", "D", "E"};
    for (int i = 0; i < 5; i++)
        enqueue(q4, taoDon(ma[i]));
    bool x1 = xoaTheoMa(q4, "A"); // dau
    bool x2 = xoaTheoMa(q4, "C"); // giua
    bool x3 = xoaTheoMa(q4, "E"); // cuoi
    kiemTra(x1 && x2 && x3 && kichThuoc(q4) == 2, "T4a xoa dau/giua/cuoi: size giam dung");
    kiemTra(layHetThanhChuoi(q4) == "B,D,", "T4b thu tu con lai giu nguyen (B,D)");

    // T5: xoa phan tu cuoi roi enqueue tiep -> kiem tra tail
    HangDoi q5;
    khoiTao(q5);
    enqueue(q5, taoDon("A"));
    enqueue(q5, taoDon("B"));
    enqueue(q5, taoDon("C"));
    xoaTheoMa(q5, "C");
    enqueue(q5, taoDon("D"));
    kiemTra(layHetThanhChuoi(q5) == "A,B,D,", "T5 xoa cuoi roi enqueue: noi dung cho (A,B,D)");

    // T6: xoa phan tu duy nhat roi enqueue lai
    HangDoi q6;
    khoiTao(q6);
    enqueue(q6, taoDon("A"));
    bool xoaDuoc = xoaTheoMa(q6, "A");
    bool rongSauXoa = laRong(q6) && q6.tail == nullptr && kichThuoc(q6) == 0;
    enqueue(q6, taoDon("B"));
    kiemTra(xoaDuoc && rongSauXoa && kichThuoc(q6) == 1 && q6.head == q6.tail, "T6 xoa phan tu duy nhat roi enqueue lai");

    // T7: ma khong ton tai
    HangDoi q7;
    khoiTao(q7);
    enqueue(q7, taoDon("A"));
    kiemTra(!xoaTheoMa(q7, "ZZ") && timTheoMa(q7, "ZZ") == nullptr && kichThuoc(q7) == 1, "T7 ma khong ton tai: false / nullptr");
    DonHang *tim = timTheoMa(q7, "A");
    kiemTra(tim != nullptr && tim->maDon == "A", "T7b timTheoMa ma co ton tai");

    // T8: giaiPhong roi dung lai
    HangDoi q8;
    khoiTao(q8);
    enqueue(q8, taoDon("A"));
    enqueue(q8, taoDon("B"));
    giaiPhong(q8);
    bool rongSauGiaiPhong = laRong(q8) && q8.tail == nullptr && kichThuoc(q8) == 0;
    enqueue(q8, taoDon("X"));
    kiemTra(rongSauGiaiPhong && layHetThanhChuoi(q8) == "X,", "T8 giaiPhong roi dung lai duoc");

    // T9: 10.000 phan tu vao roi ra het dung thu tu
    HangDoi q9;
    khoiTao(q9);
    const int N = 10000;
    for (int i = 0; i < N; i++)
        enqueue(q9, taoDon("DH" + to_string(i)));
    bool dungThuTu = (kichThuoc(q9) == N);
    for (int i = 0; i < N; i++)
    {
        if (!dequeue(q9, d) || d.maDon != "DH" + to_string(i))
        {
            dungThuTu = false;
            break;
        }
    }
    kiemTra(dungThuTu && laRong(q9), "T9 10000 phan tu: ra dung thu tu, hang rong");

    giaiPhong(q); // don dep cac hang con lai
    giaiPhong(q6);
    giaiPhong(q7);
    giaiPhong(q8);

    cout << "\nKet qua: " << soDat << " dat, " << soLoi << " loi" << endl;
    return soLoi == 0 ? 0 : 1;
}