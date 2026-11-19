// hangdoi.cpp - Queue bang danh sach lien ket don (TV2)
#include "hangdoi.h"
using namespace std;

// Khoi tao hang rong: head = tail = nullptr, size = 0
void khoiTao(HangDoi &q)
{
    q.head = nullptr;
    q.tail = nullptr;
    q.size = 0;
}

// Kiem tra hang co rong khong
bool laRong(const HangDoi &q)
{
    return q.head == nullptr;
}

// Tra ve so don trong hang - O(1)
int kichThuoc(const HangDoi &q)
{
    return q.size;
}

// Them don vao CUOI hang - O(1) nho co con tro tail
void enqueue(HangDoi &q, const DonHang &d)
{
    NodeDon *node = new NodeDon; // moi new phai co delete tuong ung
    node->data = d;
    node->next = nullptr;
    if (laRong(q))
    {
        q.head = node; // hang rong: node vua la dau vua la cuoi
        q.tail = node;
    }
    else
    {
        q.tail->next = node; // noi vao sau node cuoi hien tai
        q.tail = node;       // tail doi sang node moi
    }
    q.size++;
}

// Lay don o DAU hang ra (FIFO) - O(1)
// Vao: q. Ra: ketQua = don vua lay. Tra ve false neu hang rong.
bool dequeue(HangDoi &q, DonHang &ketQua)
{
    if (laRong(q))
        return false;
    NodeDon *cu = q.head; // luu node dau de con delete
    ketQua = cu->data;
    q.head = cu->next;     // dich head sang node ke tiep
    if (q.head == nullptr) // vua lay het -> hang rong -> tail cung phai ve nullptr
        q.tail = nullptr;
    delete cu;
    q.size--;
    return true;
}

// Tim don theo ma - O(n). Tra ve con tro toi du lieu don, khong co thi nullptr
DonHang *timTheoMa(const HangDoi &q, const string &ma)
{
    for (NodeDon *p = q.head; p != nullptr; p = p->next)
    {
        if (p->data.maDon == ma)
            return &p->data;
    }
    return nullptr;
}

// Xoa don theo ma - O(n). Dung 2 con tro: truoc (node truoc) va hienTai (node can xoa)
// Ba truong hop: xoa dau, xoa giua, xoa cuoi. Tra ve false neu khong co ma do.
bool xoaTheoMa(HangDoi &q, const string &ma)
{
    NodeDon *truoc = nullptr;
    NodeDon *hienTai = q.head;
    while (hienTai != nullptr && hienTai->data.maDon != ma)
    {
        truoc = hienTai;
        hienTai = hienTai->next;
    }
    if (hienTai == nullptr)
        return false; // khong tim thay

    if (truoc == nullptr)
    { // TH1: xoa node DAU
        q.head = hienTai->next;
        if (q.head == nullptr)
            q.tail = nullptr; // hang chi co 1 phan tu
    }
    else
    {                                // TH2 + TH3: xoa GIUA hoac CUOI
        truoc->next = hienTai->next; // bo qua hienTai
        if (hienTai == q.tail)
            q.tail = truoc; // TH3: xoa CUOI -> tail lui ve truoc
    }
    delete hienTai;
    q.size--;
    return true;
}

// Giai phong toan bo node, dua hang ve rong (dung lai duoc)
void giaiPhong(HangDoi &q)
{
    NodeDon *p = q.head;
    while (p != nullptr)
    {
        NodeDon *ke = p->next; // luu truoc khi delete
        delete p;
        p = ke;
    }
    khoiTao(q);
}
///