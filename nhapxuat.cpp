#include "nhapxuat.h"

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

// Doc 1 dong tu ban phim. Neu het du lieu (Ctrl+Z / Ctrl+D) thi thoat chuong trinh.
static string docDong() {
    string s;
    if (!getline(cin, s)) {
        cout << "\n[Thong bao] Het du lieu nhap. Thoat chuong trinh.\n";
        exit(0);
    }
    return s;
}

// Cat khoang trang o dau va cuoi chuoi.
static string catKhoangTrang(const string& s) {
    size_t dau = s.find_first_not_of(" \t\r\n");
    if (dau == string::npos) return "";
    size_t cuoi = s.find_last_not_of(" \t\r\n");
    return s.substr(dau, cuoi - dau + 1);
}

string nhapChuoi(const string& loiNhac) {
    while (true) {
        cout << loiNhac;
        string s = catKhoangTrang(docDong());
        if (!s.empty()) return s;
        cout << "  [Loi] Khong duoc de trong. Moi nhap lai.\n";
    }
}

int nhapSoNguyen(const string& loiNhac, int nhoNhat, int lonNhat) {
    while (true) {
        cout << loiNhac;
        istringstream iss(docDong());
        int x;
        // Doc duoc 1 so, phia sau khong con ky tu thua, va nam trong khoang cho phep
        if (iss >> x && (iss >> ws).eof() && x >= nhoNhat && x <= lonNhat) return x;
        cout << "  [Loi] Hay nhap so nguyen tu " << nhoNhat << " den " << lonNhat << ".\n";
    }
}

long long nhapSoLon(const string& loiNhac, long long nhoNhat) {
    while (true) {
        cout << loiNhac;
        istringstream iss(docDong());
        long long x;
        if (iss >> x && (iss >> ws).eof() && x >= nhoNhat) return x;
        cout << "  [Loi] Hay nhap so nguyen >= " << nhoNhat << ".\n";
    }
}
