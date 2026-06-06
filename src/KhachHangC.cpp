#include "KhachHangC.h"

using namespace std;

// ======================================================================
// THIẾT LẬP
// ======================================================================

/* Phương thức: KhachHangC (constructor mặc định)
 * Giải thuật: Gọi constructor mặc định của lớp cha KhachHang.
 * Input : Không có
 * Output: Không có
 */
KhachHangC::KhachHangC() : KhachHang() {}

/* Phương thức: KhachHangC (constructor có tham số)
 * Giải thuật: Chuyển tiếp tham số cho constructor của KhachHang.
 * Input : ten (const string&), soLuong (int), donGia (double)
 * Output: Không có
 */
KhachHangC::KhachHangC(const string& ten, int soLuong, double donGia)
    : KhachHang(ten, soLuong, donGia)
{}

// ======================================================================
// TÍNH TOÁN
// ======================================================================

/* Phương thức: tinhTienPhaiTra
 * Tính tiền khách hàng loại C phải trả (giảm 50% + VAT 10%).
 * Giải thuật:
 *   1. tongTien = soLuong * donGia
 *   2. sauGiam = tongTien * 0.50  [giảm 50%]
 *   3. Cộng thêm VAT 10%: sauGiam * 1.10
 * Input : Không có
 * Output: double — số tiền phải trả (VNĐ)
 */
double KhachHangC::tinhTienPhaiTra() const
{
    double tongTien = static_cast<double>(getSoLuong()) * getDonGia();
    double sauGiam  = tongTien * 0.50; // Giảm 50%
    return sauGiam * 1.10;             // + VAT 10%
}
