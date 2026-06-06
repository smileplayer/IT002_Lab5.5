#include "KhachHangA.h"

using namespace std;

// ======================================================================
// THIẾT LẬP
// ======================================================================

/* Phương thức: KhachHangA (constructor mặc định)
 * Giải thuật: Gọi constructor mặc định của lớp cha KhachHang.
 * Input : Không có
 * Output: Không có
 */
KhachHangA::KhachHangA() : KhachHang() {}

/* Phương thức: KhachHangA (constructor có tham số)
 * Giải thuật: Chuyển tiếp tham số cho constructor của KhachHang.
 * Input : ten (const string&), soLuong (int), donGia (double)
 * Output: Không có
 */
KhachHangA::KhachHangA(const string& ten, int soLuong, double donGia)
    : KhachHang(ten, soLuong, donGia)
{}

// ======================================================================
// TÍNH TOÁN
// ======================================================================

/* Phương thức: tinhTienPhaiTra
 * Tính tiền khách hàng loại A phải trả (bình thường + VAT 10%).
 * Giải thuật:
 *   1. tongTien = soLuongHang * donGiaHang
 *   2. Cộng thêm VAT 10%: tongTien * 1.10
 * Input : Không có
 * Output: double — số tiền phải trả (VNĐ)
 */
double KhachHangA::tinhTienPhaiTra() const
{
    double tongTien = static_cast<double>(getSoLuong()) * getDonGia();
    return tongTien * 1.10; // + VAT 10%
}
