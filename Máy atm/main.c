#include <stdio.h>
#include <string.h>

int Login(int sodubandau, int password2, char username2[]){
    int password1;
    char username1[150];
    printf("Mời bạn nhập tên chủ tài khoản: ");
    scanf("%s", username1);
    printf("Mời bạn nhập mật khẩu của tài khoản: ");
    scanf("%d", &password1);
if (strcmp(username1, username2)==0 && password2==password1){
    printf("Tên chủ tài khoản là: %s\n", username2);
    printf("Đúng thông tin.\n");
    printf("Số dư tài khoản của quý khách là: %d\n", sodubandau);
    printf("Mời quý khách lựa chọn loại giao dịch.\n");
        return 1;
    }
    else
        printf("Sai thông tin.\n");
        printf("Kết thúc giao dịch.\n");
        return 0;
}
int Withdraw(int sodubandau, int phirut){
    int tmp = sodubandau;
    int num;
    char answer;
    printf("Nhập số tiền bạn muốn rút: ");
    scanf("%d", &num);
    if (num%50==0 && num<=3000 && num<sodubandau) {
        printf("Giao dịch này mất phí bạn có muốn tiếp tục thực hiện hay không(Y or N): \t");
        scanf("%c", &answer);
        scanf("%c", &answer);
        if (answer=='y' || answer=='Y') {
            printf("Đang thực hiện giao dịch... \n");
            tmp = sodubandau-num-phirut;
            printf("Giao dịch thành công.\n");
            printf("\n");
        }
        else
            printf("Kết thúc giao dịch\n");
    }
    return tmp;
}
int Transfer(int sodubandau, int phichuyen){
    int id, num;
    int tmp = sodubandau;
    printf("Nhập số id tài khoản bạn muốn chuyển tiền đến: ");
    scanf("%d", &id);
    printf("Nhập số tiền bạn muốn chuyển khoản: ");
    scanf("%d", &num);
    if (num%50==0 && num<=3000 && num<sodubandau) {
        printf("Giao dịch này mất phí bạn có muốn tiếp tục thực hiện hay không(Y or N): \t");
        char answer;
        scanf("%c", &answer);
        scanf("%c", &answer);
        if (answer=='y' || answer=='Y') {
            printf("Đang thực hiện giao dịch... \n");
            tmp = sodubandau-num-phichuyen;
            printf("Giao dịch thành công.\n");
            printf("Số tiền được chuyển vào tài tài khoản: %d là +%d\n", id, num);
            printf("\n");
        }
        else
            printf("Kết thúc giao dịch\n");
    }
    return tmp;
}
void Check(int sodubandau){
    printf("Số dư tài khoản hiện tại: %d", sodubandau);
}

int main(){
    int sodubandau, chon=0, phirut, phichuyen, password2;
    char username2[150];
    while (chon==0) {
        printf("Thông tin ban đầu của khách hàng:\n");
        printf("Nhập tên tài khoản của khách hàng: ");
        scanf("%s", username2);
        printf("Nhập mật khẩu tài khoản của khách hàng: ");
        scanf("%d", &password2);
        printf("Nhập số dư tài khoản ban đầu của khách hàng: ");
        scanf("%d", &sodubandau);
        printf("Nhập phí rút tiền của ngân hàng: ");
        scanf("%d", &phirut);
        printf("Nhập phí chuyển tiền của ngân hàng: ");
        scanf("%d", &phichuyen);
        printf("\n");
        printf("================================\n");
        printf("Welcome to the ĐÔ MẬP bank:\n");
        printf("1. Kiểm tra số dư tài khoản của bạn.\n");
        printf("2. Rút tiền.\n");
        printf("3. Chuyển khoản.\n");
        printf("4. Kiểm tra số dư tài khoản hiện tại của bạn.\n");
        printf("5. Thoát.\n");
        printf("\n");
        while (1) {
            printf("Lựa chọn: ");
            scanf("%d", &chon);
         
            switch (chon) {
                case 1:
                    Login(sodubandau, password2, username2);
                    break;
                case 2:
                    sodubandau = Withdraw(sodubandau, phirut);
                    break;
                case 3:
                    sodubandau = Transfer(sodubandau, phichuyen);
                    break;
                case 4:
                    Check(sodubandau);
                    break;
                case 5:
                    printf("Kết thúc giao dịch.\n");
                    printf("Thank You.\n");
                default:
                    break;
            }
            printf("\n");
        }
    }
}
    
