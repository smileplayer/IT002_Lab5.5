#include "KhachHangB.h"

#include <algorithm>
#include <istream>

using namespace std;

// ======================================================================
// THIẾT LẬP
// ======================================================================

/* Phương thức: KhachHangB (constructor mặc định)
 * Giải thuật: Khởi tạo soNamThanThiet = 0, gọi constructor cha.
 * Input : Không có
 * Output: Không có
 */
KhachHangB::KhachHangB() : KhachHang(), soNamThanThiet(0) {}

/* Phương thức: KhachHangB (constructor có tham số)
 * Giải thuật: Chuyển tiếp tham số chung cho KhachHang, khởi tạo soNam.
 * Input : ten (const string&), soLuong (int), donGia (double),
 *         soNam (int) — số năm thân thiết
 * Output: Không có
 */
KhachHangB::KhachHangB(const string& ten, int soLuong, double donGia, int soNam)
    : KhachHang(ten, soLuong, donGia), soNamThanThiet(soNam) {}

// ======================================================================
// GETTER
// ======================================================================

/* Phương thức: getSoNamThanThiet
 * Trả về số năm gắn bó của khách hàng.
 * Input : Không có
 * Output: int — số năm thân thiết
 */
int KhachHangB::getSoNamThanThiet() const { return soNamThanThiet; }

// ======================================================================
// TÍNH TOÁN
// ======================================================================

/* Phương thức: tinhPhanTramKhuyenMai
 * Tính phần trăm khuyến mãi.
 * Giải thuật:
 *   phanTramTheoNam = soNamThanThiet * 0.05
 *   Kết quả = max(phanTramTheoNam, 0.50)
 * Input : Không có
 * Output: double — tỷ lệ khuyến mãi
 */
double KhachHangB::tinhPhanTramKhuyenMai() const
{
    double phanTramTheoNam = soNamThanThiet * 0.05;
    return max(phanTramTheoNam, 0.50); // Tối đa 50%
}

/* Phương thức: tinhTienPhaiTra
 * Tính tiền khách hàng loại B phải trả (có khuyến mãi + VAT 10%).
 * Giải thuật:
 *   1. tongTien = soLuong * donGia
 *   2. sauKhuyenMai = tongTien * (1.0 - %KM)
 *   3. Cộng thêm VAT 10%: sauKhuyenMai * 1.10
 * Input : Không có
 * Output: double — số tiền phải trả (VNĐ)
 */
double KhachHangB::tinhTienPhaiTra() const
{
    double tongTien      = static_cast<double>(getSoLuong()) * getDonGia();
    double sauKhuyenMai  = tongTien * (1.0 - tinhPhanTramKhuyenMai());
    return sauKhuyenMai * 1.10; // + VAT 10%
}

// ======================================================================
// NHẬP XUẤT
// ======================================================================

/* Phương thức: docThongTin
 * Đọc thông tin khách hàng loại B từ stream.
 * Giải thuật:
 *   1. Gọi KhachHang::docThongTin() để đọc tên, số lượng, đơn giá.
 *   2. Đọc thêm soNamThanThiet.
 * Input : is (istream&) — stream nguồn
 * Output: Không có
 */
void KhachHangB::docThongTin(istream& is)
{
    KhachHang::docThongTin(is);
    is >> soNamThanThiet;
}
