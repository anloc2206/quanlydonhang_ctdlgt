// hangdoi.h - BAN NHAP theo mo ta trong file phan cong. DOI CHIEU voi hangdoi.h trong khung cua leader; neu khac thi DUNG BAN CUA LEADER va sua hangdoi.cpp cho khop.
#ifndef HANGDOI_H
#define HANGDOI_H
#include <string>
#include "dulieu.h"

struct NodeDon
{
    DonHang data;
    NodeDon *next;
};
struct HangDoi
{
    NodeDon *head;
    NodeDon *tail;
    int size;
};

void khoiTao(HangDoi &q);
bool laRong(const HangDoi &q);
int kichThuoc(const HangDoi &q);
void enqueue(HangDoi &q, const DonHang &d);
bool dequeue(HangDoi &q, DonHang &ketQua);
DonHang *timTheoMa(const HangDoi &q, const std::string &ma);
bool xoaTheoMa(HangDoi &q, const std::string &ma);
void giaiPhong(HangDoi &q);
#endif
