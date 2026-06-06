#ifndef KHACHHANGB_H
#define KHACHHANGB_H

#include "KhachHang.h"

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet; // Số năm gắn bó với công ty (>= 0)

public:
    KhachHangB();
    KhachHangB(const std::string& ten, int soLuong, double donGia, int soNam);

    int getSoNamThanThiet() const; // Trả về số năm thân thiết
    double tinhPhanTramKhuyenMai() const; // Tính % KM (0.0 – 0.50)

    double tinhTienPhaiTra() const override;
    void docThongTin(std::istream& is) override;
};

#endif // KHACHHANGB_H
