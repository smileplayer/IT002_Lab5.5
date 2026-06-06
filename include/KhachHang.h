#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iosfwd>
#include <string>

class KhachHang {
protected:
    std::string tenKhachHang; // Tên khách hàng
    int soLuongHang;  // Số lượng hàng mua (>= 0)
    double donGiaHang;   // Đơn giá hàng (VNĐ, >= 0)

public:
    KhachHang();
    KhachHang(const std::string& ten, int soLuong, double donGia);
    virtual ~KhachHang() = default;

    const std::string& getTen() const; // Trả về tên khách hàng (by const-ref)
    int getSoLuong()  const; // Trả về số lượng hàng
    double getDonGia()   const; // Trả về đơn giá

    virtual double tinhTienPhaiTra() const = 0; // Tính tiền phải trả (thuần ảo)
    virtual void docThongTin  (std::istream& is); // Đọc thông tin từ stream
    virtual void xuatThongTin (std::ostream& os) const; // Xuất thông tin ra stream
};

#endif // KHACHHANG_H
