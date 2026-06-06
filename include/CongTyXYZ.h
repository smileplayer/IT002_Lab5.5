#ifndef CONGTYXYZ_H
#define CONGTYXYZ_H

#include "KhachHangA.h"
#include "KhachHangB.h"
#include "KhachHangC.h"

#include <string>
#include <vector>

class CongTyXYZ {
private:
    std::vector<KhachHang*> danhSach; // Danh sách tất cả khách hàng (đa hình)
    int soA = 0;
    int soB = 0;
    int soC = 0;

public:
    CongTyXYZ();
    ~CongTyXYZ();

    bool docFile(const std::string& tenFile); // Đọc dữ liệu từ XYZ.INP
    bool xuatFile(const std::string& tenFile) const;  // Xuất kết quả ra XYZ.OUT
    double tinhTongThu() const;  // Tổng tiền công ty thu được
    void xoa(); // Giải phóng toàn bộ bộ nhớ
};

#endif // CONGTYXYZ_H
