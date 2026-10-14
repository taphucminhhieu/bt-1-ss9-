#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay ds[50];
    int n, i, found = 0;
    char searchPNR[10];

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");
    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
    } while (n < 1 || n > 50);

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);
        printf("Nhap ma PNR: ");
        scanf("%s", ds[i].maPNR);
        while (getchar() != '\n');
        
        printf("Nhap ho ten hanh khach: ");
        fgets(ds[i].tenHanhKhach, sizeof(ds[i].tenHanhKhach), stdin);
        ds[i].tenHanhKhach[strcspn(ds[i].tenHanhKhach, "\n")] = 0;
        
        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        scanf("%s", ds[i].hangVe);
        
        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ds[i].trongLuongHanhLy);

        if (ds[i].trongLuongHanhLy > 7.0) {
            ds[i].phiPhuThu = (long)((ds[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ds[i].phiPhuThu = 0;
        }
    }

    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-4s %-10s %-25s %-12s %-14s %-15s\n", "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
    printf("-----------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-4d %-10s %-25s %-12s %-14.1f %-15ld\n", i + 1, ds[i].maPNR, ds[i].tenHanhKhach, ds[i].hangVe, ds[i].trongLuongHanhLy, ds[i].phiPhuThu);
    }
    printf("-----------------------------------------------------------------------------------------\n");

    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma
