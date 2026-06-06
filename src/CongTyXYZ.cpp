#include "CongTyXYZ.h"

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

// ======================================================================
// THIẾT LẬP / DỌN DẸP
// ======================================================================

/* Phương thức: CongTyXYZ (constructor)
 * Giải thuật: Khởi tạo đối tượng với danh sách rỗng (vector tự khởi tạo).
 * Input : Không có
 * Output: Không có
 */
CongTyXYZ::CongTyXYZ() {}

/* Phương thức: ~CongTyXYZ (destructor)
 * Giải thuật: Gọi xoa() để giải phóng toàn bộ bộ nhớ heap đã cấp phát.
 * Input : Không có
 * Output: Không có
 */
CongTyXYZ::~CongTyXYZ()
{
    xoa();
}

/* Phương thức: xoa
 * Giải phóng toàn bộ bộ nhớ heap của danh sách và xóa vector.
 * Giải thuật: Duyệt qua từng con trỏ trong danhSach, gọi delete, sau đó clear.
 * Input : Không có
 * Output: Không có
 */
void CongTyXYZ::xoa()
{
    for (KhachHang* kh : danhSach)
        delete kh;
    danhSach.clear();
}

// ======================================================================
// ĐỌC FILE
// ======================================================================

/* Phương thức: docFile
 * Đọc danh sách khách hàng từ file XYZ.INP.
 * Định dạng file:
 *   Dòng 1: x y z  (số lượng KH loại A, B, C)
 *   Tiếp theo: x dòng KH loại A (TenKH / SoLuong DonGia)
 *              y dòng KH loại B (TenKH / SoLuong DonGia SoNam)
 *              z dòng KH loại C (TenKH / SoLuong DonGia)
 * Giải thuật:
 *   1. Mở file; báo lỗi nếu không mở được.
 *   2. Đọc x, y, z.
 *   3. Tạo và đọc x KhachHangA, y KhachHangB, z KhachHangC vào danhSach.
 * Input : tenFile (const string&) — đường dẫn file đầu vào
 * Output: bool — true nếu đọc thành công, false nếu không mở được file
 */
bool CongTyXYZ::docFile(const string& tenFile)
{
    ifstream fin(tenFile);
    if (!fin.is_open()) {
        cerr << "Loi: Khong mo duoc file " << tenFile << '\n';
        return false;
    }

        // ── Đọc và validate x, y, z ─────────────────────────────────────────
    int x = 0, y = 0, z = 0;
    if (!(fin >> x >> y >> z)) {
        cerr << "Loi: Dong dau file \"" << tenFile
             << "\" phai co dang: x y z (3 so nguyen).\n";
        return false;
    }

    // Đề ràng buộc: 0 < x, y, z < 1000
    bool hopLe = true;
    if (x <= 0 || x >= 1000) {
        cerr << "Loi: So luong KH loai A (x = " << x
             << ") phai thoa: 0 < x < 1000.\n";
        hopLe = false;
    }
    if (y <= 0 || y >= 1000) {
        cerr << "Loi: So luong KH loai B (y = " << y
             << ") phai thoa: 0 < y < 1000.\n";
        hopLe = false;
    }
    if (z <= 0 || z >= 1000) {
        cerr << "Loi: So luong KH loai C (z = " << z
             << ") phai thoa: 0 < z < 1000.\n";
        hopLe = false;
    }
    if (!hopLe) return false;

    // ── Đọc dữ liệu từng khách hàng ─────────────────────────────────────
    // Lưu lại để xuatFile dùng
    soA = x;
    soB = y;
    soC = z;

    // ── Đọc dữ liệu từng khách hàng ─────────────────────────────────────
    danhSach.reserve(static_cast<size_t>(x + y + z));

    for (int i = 0; i < x; ++i) {
        KhachHangA* kh = new KhachHangA();
        kh->docThongTin(fin);
        danhSach.push_back(kh);
    }

    for (int i = 0; i < y; ++i) {
        KhachHangB* kh = new KhachHangB();
        kh->docThongTin(fin);
        danhSach.push_back(kh);
    }

    for (int i = 0; i < z; ++i) {
        KhachHangC* kh = new KhachHangC();
        kh->docThongTin(fin);
        danhSach.push_back(kh);
    }

    return true; // fin đóng tự động khi ra khỏi scope (RAII)
}

// ======================================================================
// XUẤT FILE
// ======================================================================

/* Phương thức: xuatFile
 * Xuất kết quả (tên + tiền phải trả của từng KH, tổng cộng) ra file XYZ.OUT.
 * Định dạng file:
 *   TenKhachHang1
 *   SoTienPhaiTra1
 *   ...
 *   TongSoTienCongTyThuDuoc <tong>
 * Giải thuật:
 *   1. Mở file ghi; báo lỗi nếu không mở được.
 *   2. Duyệt danh sách, gọi xuatThongTin() của từng khách hàng.
 *   3. In dòng tổng cộng.
 * Input : tenFile (const string&) — đường dẫn file đầu ra
 * Output: bool — true nếu ghi thành công, false nếu không mở được file
 */
bool CongTyXYZ::xuatFile(const string& tenFile) const
{
    ofstream fout(tenFile);
    if (!fout.is_open())
    {
        cerr << "Loi: Khong mo duoc file " << tenFile << '\n';
        return false;
    }

    fout << soA << ' ' << soB << ' ' << soC << "\n\n";

    double tong = 0.0;
    for (int i = 0; i < soA; ++i) {
        danhSach[i]->xuatThongTin(fout);
        tong += danhSach[i]->tinhTienPhaiTra();
    }

    fout << '\n';
    for (int i = soA; i < soA + soB; ++i)
    {
        danhSach[i]->xuatThongTin(fout);
        tong += danhSach[i]->tinhTienPhaiTra();
    }

    fout << '\n';
    for (int i = soA + soB; i < soA + soB + soC; ++i)
    {
        danhSach[i]->xuatThongTin(fout);
        tong += danhSach[i]->tinhTienPhaiTra();
    }

    fout << fixed << setprecision(2);
    fout << "Tong so tien cong ty thu duoc: " << tong << '\n';

    return true;
}

// ======================================================================
// TÍNH TOÁN
// ======================================================================

/* Phương thức: tinhTongThu
 * Tính tổng số tiền công ty thu được từ toàn bộ khách hàng.
 * Giải thuật: Duyệt danh sách, cộng dồn kết quả tinhTienPhaiTra() của từng KH.
 * Input : Không có
 * Output: double — tổng tiền thu được (VNĐ)
 */
double CongTyXYZ::tinhTongThu() const
{
    double tong = 0.0;
    for (const KhachHang* kh : danhSach)
        tong += kh->tinhTienPhaiTra();
    return tong;
}
