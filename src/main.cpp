#include "CongTyXYZ.h"

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    CongTyXYZ congTy;

    if (!congTy.docFile("XYZ.INP"))
    {
        cerr << "Khong the doc file XYZ.INP!\n";
        return 1;
    }

    if (!congTy.xuatFile("XYZ.OUT"))
    {
        cerr << "Khong the ghi file XYZ.OUT!\n";
        return 1;
    }

    cout << "Hoan thanh! Ket qua da duoc xuat ra XYZ.OUT\n"
              << fixed << setprecision(2)
              << "Tong so tien cong ty thu duoc: "
              << congTy.tinhTongThu() << " VND\n";

    return 0;
}
