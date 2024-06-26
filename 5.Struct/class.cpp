#include <bits/stdc++.h>
using namespace std;

void menuChoice(){
    cout << "1. Nhan xe vao bai \n"
        << "2. Xuat xe ra bai \n"
        << "3. Thong ke \n";
}


struct Xe{
    int id;
    time_t thoiGianVao;
    bool theoThang;
};  

class baiXe{
    private : 
        vector <Xe> danhSachXe;
        int tienThuDuoc;
    public :
        void baixe(){
            tienThuDuoc =0;
        }
        void nhanXeVao(Xe xe){
            danhSachXe.push_back(xe);
        }
        void xuatXe(int id){
            time_t thoiGianRa = time(0);
            for(int i=0;i<danhSachXe.size();i++){
                if(danhSachXe[i].id == id){
                    if(!danhSachXe[i].theoThang){
                        double thoiGian = thoiGianRa - danhSachXe[i].thoiGianVao;
                        int tien =0;
                        if(thoiGian <=60){
                            tien = 50000;
                        } else {
                            tien = 50000 + ((thoiGian - 60)/ 30 * 20000);
                        }
                        tienThuDuoc += tien; 
                    }
                    danhSachXe.erase(danhSachXe.begin()+i);
                    break;
                }
            }
        }
        void thongKe(){
            cout << "So luong xe dang co trong bai: " <<danhSachXe.size() << endl;
            cout << "So tien da thu duoc: " << tienThuDuoc;
        }
};

int main(){
    baiXe baixe;
    Xe xe1 = {1,time(0),true};
    Xe xe2 = {2,time(0),false};
    Xe xe3 = {3,time(0),false};
    Xe xe4 = {4,time(0),false};

    baixe.nhanXeVao(xe1);
    baixe.nhanXeVao(xe2);
    baixe.nhanXeVao(xe3);
    baixe.nhanXeVao(xe4);


    baixe.xuatXe(2);

    baixe.thongKe();




    return 0;
}