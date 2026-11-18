// ===== TV3: taoDon, xemTatCaDon, xoaDon (thay than ham TODO trong donhang.cpp) =====

// Tao don moi: nhap ma (khong trung o ca 2 hang), ten, tien, ngay; dat CHO_PHE_DUYET va enqueue vao hangCho. O(n).
void taoDon(HeThong& ht) {
    DonHang don;
    // Lap den khi ma chua ton tai o hangCho lan daXuLy (timDonTheoMa tim ca hai hang)
    while (true) {
        don.maDon = nhapChuoi("Nhap ma don: ");
        if (timDonTheoMa(ht, don.maDon) == nullptr) break;
        cout << "Ma don da ton tai, vui long nhap ma khac.\n";
    }
    don.tenKhach = nhapChuoi("Nhap ten khach hang: ");   // nhapChuoi tu hoi lai neu de trong
    don.tongTien = nhapSoLon("Nhap tong tien (>= 1): ", 1);
    don.ngayTao = nhapNgay("Nhap ngay tao (dd/mm/yyyy): ");
    don.trangThai = CHO_PHE_DUYET;
    enqueue(ht.hangCho, don);
    cout << "Da tao don:\n";
    inTieuDeBang();
    inDon(don);
}

// Xem tat ca don: hangCho (dung thu tu hang) roi daXuLy, duyet bang con tro tu head. O(n).
void xemTatCaDon(const HeThong& ht) {
    int soCho = kichThuoc(ht.hangCho);
    int soXong = kichThuoc(ht.daXuLy);
    if (soCho + soXong == 0) {
        cout << "Chua co don hang nao.\n";
        return;
    }
    inTieuDeBang();
    for (const Node* p = ht.hangCho.head; p != nullptr; p = p->next) inDon(p->data);
    for (const Node* p = ht.daXuLy.head; p != nullptr; p = p->next) inDon(p->data);
    cout << "Tong: " << soCho + soXong << " don (dang cho: " << soCho
         << ", da xu ly: " << soXong << ")\n";
}

// Xoa don theo ma: tim, in don, hoi xac nhan (1 = Co, 2 = Khong), xoa o hangCho hoac daXuLy. O(n).
void xoaDon(HeThong& ht) {
    string ma = nhapChuoi("Nhap ma don can xoa: ");
    DonHang* don = timDonTheoMa(ht, ma);
    if (don == nullptr) {
        cout << "Khong tim thay don co ma " << ma << ".\n";
        return;
    }
    cout << "Don se bi xoa:\n";
    inTieuDeBang();
    inDon(*don);
    int chon = nhapSoNguyen("Xac nhan xoa? (1 = Co, 2 = Khong): ", 1, 2);
    if (chon != 1) {
        cout << "Da huy, khong xoa don nao.\n";
        return;
    }
    // Thu xoa o hangCho truoc; neu khong co thi xoa o daXuLy
    if (xoaTheoMa(ht.hangCho, ma) || xoaTheoMa(ht.daXuLy, ma))
        cout << "Da xoa don " << ma << ".\n";
    else
        cout << "Xoa that bai.\n";
}
eyyy lộn
// De tai 5 - Quan ly don dat hang: ban chay thu 1 FILE cho TV3 (taoDon, xemTatCaDon, xoaDon)
// Phan "KHUNG GIA" ben duoi chi de chay thu rieng. Khi ghep vao du an that, CHI lay 3 ham o phan TV3.
// Bien dich: g++ -std=c++17 -Wall -o quanlydon qld_tv3_mot_file.cpp
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// ===================== KHUNG GIA (du an that co san) =====================
struct Ngay { int ngay, thang, nam; };
enum TrangThai { CHO_PHE_DUYET, DA_DUYET, HUY, HOAN_THANH };
struct DonHang { string maDon, tenKhach; long long tongTien; Ngay ngayTao; TrangThai trangThai; };
struct Node { DonHang data; Node* next; };
struct HangDoi { Node* head; Node* tail; int size; };
struct HeThong { HangDoi hangCho; HangDoi daXuLy; };

void khoiTao(HangDoi& q) { q.head = q.tail = nullptr; q.size = 0; }
int kichThuoc(const HangDoi& q) { return q.size; }
void enqueue(HangDoi& q, const DonHang& d) {
    Node* n = new Node{d, nullptr};
    if (q.head == nullptr) q.head = q.tail = n; else { q.tail->next = n; q.tail = n; }
    q.size++;
}
bool dequeue(HangDoi& q, DonHang& kq) {
    if (q.head == nullptr) return false;
    Node* c = q.head; kq = c->data; q.head = c->next;
    if (q.head == nullptr) q.tail = nullptr;
    delete c; q.size--; return true;
}
DonHang* timTheoMa(HangDoi& q, const string& ma) {
    for (Node* p = q.head; p != nullptr; p = p->next) if (p->data.maDon == ma) return &p->data;
    return nullptr;
}
bool xoaTheoMa(HangDoi& q, const string& ma) {
    Node* truoc = nullptr;
    for (Node* p = q.head; p != nullptr; truoc = p, p = p->next) {
        if (p->data.maDon == ma) {
            if (truoc == nullptr) q.head = p->next; else truoc->next = p->next;
            if (p == q.tail) q.tail = truoc;
            delete p; q.size--; return true;
        }
    }
    return false;
}
void giaiPhong(HangDoi& q) { DonHang d; while (dequeue(q, d)) {} }
DonHang* timDonTheoMa(HeThong& ht, const string& ma) {
    DonHang* p = timTheoMa(ht.hangCho, ma);
    if (p != nullptr) return p;
    return timTheoMa(ht.daXuLy, ma);
}

string nhapChuoi(const string& loiNhac) {              // hoi lai neu de trong / chi khoang trang
    string s;
    while (true) {
        cout << loiNhac;
        if (!getline(cin, s)) exit(0);
        size_t a = s.find_first_not_of(" \t");
        if (a == string::npos) { cout << "Khong duoc de trong, nhap lai.\n"; continue; }
        return s.substr(a, s.find_last_not_of(" \t") - a + 1);
    }
}
long long nhapSoLon(const string& loiNhac, long long min) {
    string s;
    while (true) {
        cout << loiNhac;
        if (!getline(cin, s)) exit(0);
        istringstream is(s); long long v; char thua;
        if (is >> v && !(is >> thua) && v >= min) return v;
        cout << "Phai nhap so nguyen >= " << min << ", thu lai.\n";
    }
}
int nhapSoNguyen(const string& loiNhac, int min, int max) {
    while (true) {
        long long v = nhapSoLon(loiNhac, min);
if (v <= max) return (int)v;
        cout << "Chi duoc nhap tu " << min << " den " << max << ".\n";
    }
}
bool ngayHopLe(int d, int m, int y) {
    int t[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    bool nhuan = (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    if (y < 1900 || y > 2100 || m < 1 || m > 12) return false;
    int max = t[m - 1] + ((m == 2 && nhuan) ? 1 : 0);
    return d >= 1 && d <= max;
}
Ngay nhapNgay(const string& loiNhac) {
    while (true) {
        string s = nhapChuoi(loiNhac);
        int d, m, y; char thua;
        if (sscanf(s.c_str(), "%d/%d/%d%c", &d, &m, &y, &thua) == 3 && ngayHopLe(d, m, y)) return Ngay{d, m, y};
        cout << "Ngay khong hop le, vui long nhap lai dd/mm/yyyy\n";
    }
}
string ngaySangChu(const Ngay& n) {
    char b[16]; snprintf(b, sizeof(b), "%02d/%02d/%04d", n.ngay, n.thang, n.nam); return b;
}
string trangThaiSangChu(TrangThai t) {
    switch (t) { case CHO_PHE_DUYET: return "Cho phe duyet"; case DA_DUYET: return "Da duyet";
                 case HUY: return "Huy"; default: return "Hoan thanh"; }
}
void inTieuDeBang() {
    cout << left << setw(10) << "Ma don" << setw(16) << "Khach hang" << setw(14) << "Tong tien"
         << setw(12) << "Ngay tao" << "Trang thai\n";
}
void inDon(const DonHang& d) {
    cout << left << setw(10) << d.maDon << setw(16) << d.tenKhach << setw(14) << d.tongTien
         << setw(12) << ngaySangChu(d.ngayTao) << trangThaiSangChu(d.trangThai) << "\n";
}

// ===================== PHAN CUA TV3 (lay 3 ham nay) =====================

// Tao don moi: nhap ma (khong trung o ca 2 hang), ten, tien, ngay; dat CHO_PHE_DUYET va enqueue vao hangCho. O(n).
void taoDon(HeThong& ht) {
    DonHang don;
    while (true) {   // lap den khi ma chua ton tai o hangCho lan daXuLy
        don.maDon = nhapChuoi("Nhap ma don: ");
        if (timDonTheoMa(ht, don.maDon) == nullptr) break;
        cout << "Ma don da ton tai, vui long nhap ma khac.\n";
    }
    don.tenKhach = nhapChuoi("Nhap ten khach hang: ");
    don.tongTien = nhapSoLon("Nhap tong tien (>= 1): ", 1);
    don.ngayTao = nhapNgay("Nhap ngay tao (dd/mm/yyyy): ");
    don.trangThai = CHO_PHE_DUYET;
    enqueue(ht.hangCho, don);
    cout << "Da tao don:\n";
    inTieuDeBang();
    inDon(don);
}

// Xem tat ca don: hangCho (dung thu tu hang) roi daXuLy, duyet bang con tro tu head. O(n).
void xemTatCaDon(const HeThong& ht) {
    int soCho = kichThuoc(ht.hangCho);
    int soXong = kichThuoc(ht.daXuLy);
    if (soCho + soXong == 0) {
        cout << "Chua co don hang nao.\n";
        return;
    }
    inTieuDeBang();
    for (const Node* p = ht.hangCho.head; p != nullptr; p = p->next) inDon(p->data);
    for (const Node* p = ht.daXuLy.head; p != nullptr; p = p->next) inDon(p->data);
    cout << "Tong: " << soCho + soXong << " don (dang cho: " << soCho
         << ", da xu ly: " << soXong << ")\n";
}

// Xoa don theo ma: tim, in don, hoi xac nhan (1 = Co, 2 = Khong), xoa o hangCho hoac daXuLy. O(n).
void xoaDon(HeThong& ht) {
string ma = nhapChuoi("Nhap ma don can xoa: ");
    DonHang* don = timDonTheoMa(ht, ma);
    if (don == nullptr) {
        cout << "Khong tim thay don co ma " << ma << ".\n";
        return;
    }
    cout << "Don se bi xoa:\n";
    inTieuDeBang();
    inDon(*don);
    int chon = nhapSoNguyen("Xac nhan xoa? (1 = Co, 2 = Khong): ", 1, 2);
    if (chon != 1) {
        cout << "Da huy, khong xoa don nao.\n";
        return;
    }
    if (xoaTheoMa(ht.hangCho, ma) || xoaTheoMa(ht.daXuLy, ma))
        cout << "Da xoa don " << ma << ".\n";
    else
        cout << "Xoa that bai.\n";
}

// ===================== MENU THU (chi de chay rieng) =====================
int main() {
    HeThong ht; khoiTao(ht.hangCho); khoiTao(ht.daXuLy);
    while (true) {
        cout << "\n1. Tao don\n2. Xem tat ca don\n3. Xoa don\n4. Duyet don dau hang cho (de thu daXuLy)\n0. Thoat\n";
        int c = nhapSoNguyen("Chon: ", 0, 4);
        if (c == 0) break;
        if (c == 1) taoDon(ht);
        else if (c == 2) xemTatCaDon(ht);
        else if (c == 3) xoaDon(ht);
        else {
            DonHang d;
            if (dequeue(ht.hangCho, d)) { d.trangThai = DA_DUYET; enqueue(ht.daXuLy, d); cout << "Da duyet " << d.maDon << ".\n"; }
            else cout << "Khong co don nao dang cho.\n";
        }
    }
    giaiPhong(ht.hangCho); giaiPhong(ht.daXuLy);
    return 0;
}
