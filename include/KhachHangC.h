#ifndef KHACHHANGC_H
#define KHACHHANGC_H

#include "KhachHang.h"

class KhachHangC : public KhachHang {
public:
    KhachHangC();
    KhachHangC(const std::string& ten, int soLuong, double donGia);

    double tinhTienPhaiTra() const override;
};

#endif // KHACHHANGC_H
