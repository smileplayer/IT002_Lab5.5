#include "KhachHang.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// ======================================================================
// THIẾT LẬP
// ======================================================================

/* Phương thức: KhachHang (constructor mặc định)
 * Giải thuật: Khởi tạo các thành viên về giá trị trống/0 qua initializer list.
 * Input : Không có
 * Output: Không có
 */
KhachHang::KhachHang()
    : tenKhachHang(""), soLuongHang(0), donGiaHang(0.0)
{}

/* Phương thức: KhachHang (constructor có tham số)
 * Giải thuật: Khởi tạo trực tiếp qua initializer list.
 * Input : ten (const string&), soLuong (int), donGia (double)
 * Output: Không có
 */
KhachHang::KhachHang(const string& ten, int soLuong, double donGia)
    : tenKhachHang(ten), soLuongHang(soLuong), donGiaHang(donGia)
{}

// ======================================================================
// GETTER
// ======================================================================

/* Phương thức: getTen
 * Trả về tên khách hàng qua const reference (không copy).
 * Input : Không có
 * Output: const string& — tên khách hàng
 */
const string& KhachHang::getTen() const { return tenKhachHang; }

/* Phương thức: getSoLuong
 * Trả về số lượng hàng.
 * Input : Không có
 * Output: int — số lượng hàng
 */
int    KhachHang::getSoLuong() const { return soLuongHang; }

/* Phương thức: getDonGia
 * Trả về đơn giá hàng.
 * Input : Không có
 * Output: double — đơn giá (VNĐ)
 */
double KhachHang::getDonGia() const { return donGiaHang; }

// ======================================================================
// NHẬP XUẤT
// ======================================================================

/* Phương thức: docThongTin
 * Đọc thông tin cơ bản của khách hàng từ stream (dùng cho file I/O).
 * Giải thuật:
 *   1. Đọc tên bằng getline (với ws để bỏ whitespace đầu dòng).
 *   2. Đọc số lượng và đơn giá bằng >>.
 * Input : is (istream&) — stream nguồn (file hoặc cin)
 * Output: Không có
 */
void KhachHang::docThongTin(istream& is)
{
    getline(is >> ws, tenKhachHang);
    is >> soLuongHang >> donGiaHang;
}

/* Phương thức: xuatThongTin
 * Xuất tên và số tiền phải trả ra stream, định dạng 2 chữ số thập phân.
 * Giải thuật:
 *   1. Đặt fixed + setprecision(2) trực tiếp trên stream os.
 *   2. In tên khách hàng, xuống dòng, in số tiền, xuống dòng.
 * Input : os (ostream&) — stream đích (file hoặc cout)
 * Output: Không có
 */
void KhachHang::xuatThongTin(ostream& os) const
{
    os << fixed << setprecision(2);
    os << tenKhachHang << '\n'
       << tinhTienPhaiTra() << '\n';
}
