#ifndef KHACHHANGA_H
#define KHACHHANGA_H

#include "KhachHang.h"

class KhachHangA : public KhachHang {
public:
    KhachHangA();
    KhachHangA(const std::string& ten, int soLuong, double donGia);

    double tinhTienPhaiTra() const override;
};

#endif // KHACHHANGA_H
