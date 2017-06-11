/** print hello world on screen
 * author: ICEORY
 * email: z.zhuangwei@mail.scut.edu.cn
 * last modified: 2017.6.11
 */
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class biaoge
{
    public:
            void waicaozuo();
    private:
            void zong();
            void caozuo();
            void xianshi_3();
            void getlen_intc(int intn,int n);
            void getlen_float(float flon,int n_c,int n_r);
            void int_f();
            void string_f();
            void float_f();
            void bool_f();
            void paixu(int p_dz);
            void shaixuan();
            void xianshi_1(int c);
            void xianshi_2(int r);
            int col;
            int row;
            int b[4];
            int a[80];
            int len_int[20];
            int len_cha[20];
            int len_float[20];
            int len_bool[20];
            int len_flo[100][20];
            char name[60];
            int int_n[100][20];
            string string_n[100][20];
            float float_n[100][20];
            bool bool_n[100][20];
            string colname[20];
};

void biaoge::getlen_intc(int intn,int n)
{
    int i=0;
    int amp=1;
    while(amp<=intn){amp=amp*10;i++;}
    if(i>=len_int[n]){len_int[n]=i;}
}
void biaoge::getlen_float(float flon,int n_c,int n_r)
{
    int s_in=0;
    int s_f=5;
    int i=0;
    float f_bi=0;
    int amp_in=1;
    int f_in=(int)flon;
    int t=10;
    int f_a[4];
    float f_ci=0;
    while(amp_in<=f_in){amp_in=amp_in*10;s_in++;}
    if(f_in==0){s_in++;}
    f_ci=(flon-f_in)*t;
    f_a[0]=(int)f_ci;
    for(i=1;i<=3;i++)
    {
        f_ci=(f_ci-f_a[i-1])*t;
        f_a[i]=(int)f_ci;
    }
    for(i=3;i>=0;i--){if(f_a[i]!=0){break;}s_f--;}
    if(s_f==1){s_f--;}
    float_n[n_r][n_c]=f_in+f_a[0]*0.1+f_a[1]*0.01+f_a[2]*0.001+f_a[3]*0.0001;
    len_flo[n_r][n_c]=s_in+s_f;
    if(len_flo[n_r][n_c]>=len_float[n_c]){len_float[n_c]=len_flo[n_r][n_c];}
}

void biaoge::int_f()
{
    static int in=0;
    cout<<"int类型数据"<<endl;
    cin>>int_n[row-1][in];
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;cin>>int_n[row-1][in];}
    if(in>=b[0]-1){in=0;getlen_intc(int_n[row-1][in],in);}
    else{getlen_intc(int_n[row-1][in],in);in++;}
}

void biaoge::string_f()
{
    static int cha=0;
    cout<<"char类型数据"<<endl;
    cin>>string_n[row-1][cha];
    if(cha>=b[1]-1){cha=0;if(len_cha[cha]<=string_n[row-1][cha].size()){len_cha[cha]=string_n[row-1][cha].size();}}
    else{if(len_cha[cha]<=string_n[row-1][cha].size()){len_cha[cha]=string_n[row-1][cha].size();}cha++;}
}

void biaoge::float_f()
{
    static int flo=0;
    cout<<"float类型数据"<<endl;
    cin>>float_n[row-1][flo];
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入float类型的数据，OK?"<<endl;cin>>float_n[row-1][flo];}
    if(flo>=b[2]-1){flo=0;getlen_float(float_n[row-1][flo],flo,row-1);}
    else{getlen_float(float_n[row-1][flo],flo,row-1);flo++;}
}

void biaoge::bool_f()
{
    static int boo=0;
    cout<<"bool类型数据"<<endl;
    cin>>bool_n[row-1][boo];
    while(bool_n[row-1][boo]!=0&&bool_n[row-1][boo]!=1){cout<<"请输入bool类型的数据，OK?"<<endl;cin>>bool_n[row-1][boo];}
    boo++;
    if(boo>=b[3])boo=0;
}

void biaoge::xianshi_1(int c)
{
    int r=0;
    int i=0;
    int ni=0;
    int ci=0;
    int fi=0;
    int bi=0;
    int len=0;
    int chazhi=1;
    for(r=0;r<=row-1;r++)
    {
        if(r<row-1)
        {
            for(i=0;i<=col-1;i++)
            {
                if(a[i]==1)
                {
                    cout<<"|"<<int_n[r][ni];
                    chazhi=1;
                    len=0;
                    while(chazhi<=int_n[r][ni]){chazhi=chazhi*10;len++;}
                    chazhi=len_int[ni]-len;
                    while(len_int[ni]>colname[i].size()){colname[i]=colname[i]+' ';}ni++;
                }
                if(a[i]==2)
                {
                    cout<<"|"<<string_n[r][ci];
                    len=string_n[r][ci].size();chazhi=len_cha[ci]-len;
                    while(len_cha[ci]>colname[i].size()){colname[i]=colname[i]+' ';}ci++;
                }
                if(a[i]==3)
                {
                    cout<<"|"<<float_n[r][fi];
                    chazhi=len_float[fi]-len_flo[r][fi];
                    while(len_float[fi]>colname[i].size()){colname[i]=colname[i]+' ';}fi++;
                }
                if(a[i]==4){cout<<"|"<<bool_n[r][bi];chazhi=len_bool[bi]-1;bi++;}
                for(len=1;len<=chazhi;len++){cout<<" ";}
            }
        }
        else
        {
            for(i=0;i<=c;i++)
            {
                if(a[i]==1)
                {
                    cout<<"|"<<int_n[r][ni];
                    chazhi=1;
                    len=0;
                    while(chazhi<=int_n[r][ni]){chazhi=chazhi*10;len++;}
                    chazhi=len_int[ni]-len;
                    while(len_int[ni]>colname[i].size()){colname[i]=colname[i]+' ';}ni++;
                    }
                if(a[i]==2)
                {
                    cout<<"|"<<string_n[r][ci];
                    len=string_n[r][ci].size();chazhi=len_cha[ci]-len;
                    while(len_cha[ci]>colname[i].size()){colname[i]=colname[i]+' ';}ci++;
                }
                if(a[i]==3)
                {
                    cout<<"|"<<float_n[r][fi];
                    chazhi=len_float[fi]-len_flo[r][fi];
                    while(len_float[fi]>colname[i].size()){colname[i]=colname[i]+' ';}fi++;
                }
                if(a[i]==4){cout<<"|"<<bool_n[r][bi];chazhi=len_bool[bi]-1;bi++;}
                for(len=1;len<=chazhi;len++){cout<<" ";}
            }
        }
        cout<<endl;
        ni=0;
        ci=0;
        fi=0;
        bi=0;
    }
}

void biaoge::xianshi_2(int r)
{
    int i=0;
    int ni=0;
    int ci=0;
    int fi=0;
    int bi=0;
    int len=0;
    int chazhi=1;
    for(i=0;i<=col-1;i++)
    {
        if(a[i]==1)
        {
            cout<<"|"<<int_n[r][ni];
            chazhi=1;
            len=0;
            while(chazhi<=int_n[r][ni]){chazhi=chazhi*10;len++;}
            chazhi=len_int[ni]-len;ni++;
        }
        if(a[i]==2)
        {
            cout<<"|"<<string_n[r][ci];
            len=string_n[r][ci].size();chazhi=len_cha[ci]-len;ci++;
        }
        if(a[i]==3)
        {
            cout<<"|"<<float_n[r][fi];
            chazhi=len_float[fi]-len_flo[r][fi];fi++;
        }
        if(a[i]==4){cout<<"|"<<bool_n[r][bi];chazhi=len_bool[bi]-1;bi++;}
        for(len=1;len<=chazhi;len++){cout<<" ";}
    }
    cout<<endl;
    ni=0;
    ci=0;
    fi=0;
    bi=0;
}

void biaoge::xianshi_3()
{
    int i=0;
    cout<<name<<endl;
    for(i=0;i<col;i++){cout<<"|"<<colname[i];}
    cout<<endl;
    for(i=0;i<row-1;i++)xianshi_2(i);
    cout<<endl;
}

void biaoge::caozuo()
{
    int i=0;
    int adj_2=0;
    caozuogo_1:
    for(i=0;i<col;i++){cout<<"|"<<colname[i];}
    cout<<endl;
    for(i=0;i<row-1;i++){xianshi_2(i);}
    cout<<"------退出------(0)"<<endl;
    cout<<"----倒序排序----(1)"<<endl;
    cout<<"----正序排序----(2)"<<endl;
    cout<<"------筛选------(3)"<<endl;
    cin>>adj_2;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;goto caozuogo_1;}
    if(adj_2>=4){cout<<"输入错误，请重新输入。。。"<<endl;goto caozuogo_1;}
    if(adj_2==1||adj_2==2)paixu(adj_2);
    if(adj_2==3)shaixuan();
    if(adj_2==0)goto caozuogo_2;
    system("cls");
    goto caozuogo_1;
    caozuogo_2:
    system("cls");
}
void biaoge::paixu(int p_dz)
{
    herepai_1:
    int i=0;
    int i_1=0;
    int p_n=0;
    int p_c=0;
    int p_num=0;
    float p_p[row-2];
    int p_xu[row-2];
    float min=0;
    float max=0;
    cout<<"请输入要排序的列(1~"<<col<<")"<<endl;
    cin>>p_n;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;goto herepai_1;}
    if(p_n==0){cout<<"应输入大于0的数，请重新输入"<<endl;goto herepai_1;}
    if(a[p_n-1]==2){cout<<"不能针对char类型数据进行排序，请重新输入"<<endl;goto herepai_1;}
    system("cls");
    for(i=0;i<=p_n-1;i++){if(a[i]==a[p_n-1]){p_c++;}}
    if(a[p_n-1]==1){for(i=0;i<row-1;i++){p_p[i]=int_n[i][p_c-1];}}
    if(a[p_n-1]==3){for(i=0;i<row-1;i++){p_p[i]=float_n[i][p_c-1];}}
    if(a[p_n-1]==4){for(i=0;i<row-1;i++){p_p[i]=bool_n[i][p_c-1];}}
    min=p_p[0];
    for(i=0;i<row-1;i++){if(min>p_p[i]){min=p_p[i];}}
    for(p_num=0;p_num<row-1;p_num++)
    {
        max=min-1;
        for(i=0;i<row-1;i++){if(max<p_p[i]){max=p_p[i];}}
        for(i=0;i<row-1;i++){if(p_p[i]==max){p_p[i]=min-1;break;}}
        p_xu[p_num]=i;
    }
    for(i_1=0;i_1<col;i_1++){cout<<"|"<<colname[i_1];}
    cout<<endl;
    if(p_dz==2)
    {
        for(i=0;i<row-1;i++){xianshi_2(p_xu[i]);}
    }
    else
    {
        for(i=row-2;i>=0;i--){xianshi_2(p_xu[i]);}
    }
    cout<<"----排序结束----"<<endl;
    cout<<"----倒序排序----(1)"<<endl;
    cout<<"----正序排序----(2)"<<endl;
    cout<<"------退出------(3)"<<endl;
    herepai_2:
    cin>>p_dz;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;goto herepai_2;}
    if(p_dz>=4||p_dz==0){cout<<"输入错误，请重新输入"<<endl;goto herepai_2;}
    if(p_dz==1||p_dz==2)goto herepai_1;
}
void biaoge::shaixuan()
{
    hereshai_1:
    int shai_col=0;
    float shai_num=0;
    float shai_cun[row-2];
    int shai_xu[row-2];
    int shai_ji=0;
    int i=0;
    int shai_pan=0;
    cout<<"---请输入要筛选的列---(1~"<<col<<")";
    cin>>shai_col;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;goto hereshai_1;}
    if(shai_col==0){cout<<"应输入大于0的数，请重新输入"<<endl;goto hereshai_1;}
    if(a[shai_col-1]==2){cout<<"--本系统暂不支持char类型的数据筛选，请期待下次升级--";goto hereshai_1;}
    hereshai_2:
    cout<<"---请输入筛选的数---";
    cin>>shai_num;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入对应类型的数据，OK?"<<endl;goto hereshai_2;}
    for(i=0;i<=shai_col-1;i++){if(a[i]==a[shai_col-1]){shai_ji++;}}
    if(a[shai_col-1]==1){for(i=0;i<row-1;i++){shai_cun[i]=int_n[i][shai_ji-1];}}
    if(a[shai_col-1]==3){for(i=0;i<row-1;i++){shai_cun[i]=float_n[i][shai_ji-1];}}
    if(a[shai_col-1]==4){for(i=0;i<row-1;i++){shai_cun[i]=bool_n[i][shai_ji-1];}}
    shai_ji=0;
    system("cls");
    for(i=0;i<row-1;i++){if(shai_cun[i]==shai_num){shai_xu[shai_ji]=i;shai_ji++;}}
    if(shai_ji==0)
    {
        cout<<"---没有符合的数据---"<<endl;
        cout<<"-----重新筛选-----(1)"<<endl;
        cout<<"-------退出-------(2)"<<endl;
    }
    else
    {
        for(i=0;i<col;i++){cout<<"|"<<colname[i];}
        cout<<endl;
        for(i=0;i<shai_ji;i++){xianshi_2(shai_xu[i]);}
        cout<<"------筛选完毕------"<<endl;
        cout<<"------继续筛选-----(1)"<<endl;
        cout<<"--------退出-------(2)"<<endl;
    }
    hereshai_3:
    cin>>shai_pan;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;goto hereshai_3;}
    if(shai_pan!=1&&shai_pan!=2){cout<<"输入错误，请重新输入"<<endl;goto hereshai_3;}
    if(shai_pan==1)
    {
        system("cls");
        for(i=0;i<col;i++){cout<<"|"<<colname[i];}
        cout<<endl;
        for(i=0;i<row-1;i++){xianshi_2(i);}
        goto hereshai_1;
    }
}

void biaoge::zong()
{
    int i=0;
    int i_1=0;
    row=1;
    //cin.clear();
    //cin.ignore(1000,'\n');
    cout<<"输入表格名称"<<"\n";
    cin.getline(name,60);
    cout<<"输入表格列数"<<"\n";
    cin>>col;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;cin>>col;}
    while(col>20){cout<<"您输入的列数超过20列，请重新输入"<<endl;cin>>col;}
    for(i=0;i<col;i++){system("cls");cout<<"输入第"<<i+1<<"列的名称"<<endl;cin>>colname[i];}
    for(i=0;i<=3;i++){b[i]=0;}
    for(i=0;i<=19;i++){len_int[i]=0;len_cha[i]=0;len_float[i]=0;}
    int ok=1;
    int r=0;
    system("cls");
    for(i=1;i<=col;i++)
    {
        cout<<name<<"\n";
        for(i_1=0;i_1<col;i_1++){cout<<"|"<<colname[i_1];}
        cout<<endl;
        cout<<"请输入第"<<i<<"列的数据类型"<<"\n";
        cout<<"-----int-----(1)"<<endl;
        cout<<"-----char----(2)"<<endl;
        cout<<"-----float---(3)"<<endl;
        cout<<"-----bool----(4)"<<endl;
        zonggo_1:
        cin>>r;
        while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请在(1~4)中选择"<<endl;goto zonggo_1;}
        if(r==0||r>4){cout<<"请在(1~4)中选择"<<endl;goto zonggo_1;}
        if(r>=1&&r<=4)
        {
            a[i-1]=r;
            if(r==1){len_int[b[r-1]]=colname[i-1].size();}
            if(r==2){len_cha[b[r-1]]=colname[i-1].size();}
            if(r==3){len_float[b[r-1]]=colname[i-1].size();}
            if(r==4){len_bool[b[r-1]]=colname[i-1].size();}
            b[r-1]++;
        }
        system("cls");
    }
    for(i_1=0;i_1<col;i_1++){cout<<"|"<<colname[i_1];}
    cout<<"\n"<<endl;
    while(ok)
    {
        for(i=0;i<col;i++)
        {
            cout<<"输入第"<<row<<"行"<<"第"<<i+1<<"列";
            if(a[i]==1){int_f();}
            if(a[i]==2){string_f();}
            if(a[i]==3){float_f();}
            if(a[i]==4){bool_f();}
            system("cls");
            cout<<name<<"\n";
            for(i_1=0;i_1<col;i_1++){cout<<"|"<<colname[i_1];}cout<<"\n";
            xianshi_1(i);
        }
        cout<<"------退出-------(0)"<<"\n";
        cout<<"-----增加一行----(1)"<<"\n";
        zonggo_2:
        cin>>ok;
        while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请做出正确选择"<<endl;goto zonggo_2;}
        if(ok>=2){cout<<"请做出正确选择"<<endl;goto zonggo_2;}
        row++;
    }
    ok=1;
    while(ok)
    {
        heretoo:
        cout<<"------退出------(0)"<<endl;
        cout<<"----倒序排序----(1)"<<endl;
        cout<<"----正序排序----(2)"<<endl;
        cout<<"------筛选------(3)"<<endl;
        cin>>ok;
        while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;goto heretoo;}
        if(ok>=4){cout<<"输入错误，请重新输入。。。"<<endl;goto heretoo;}
        if(ok==1||ok==2)paixu(ok);
        if(ok==3)shaixuan();
        system("cls");
        for(i=0;i<col;i++){cout<<"|"<<colname[i];}
        cout<<endl;
        for(i=0;i<row-1;i++){xianshi_2(i);}
    }
}

void biaoge::waicaozuo()
{
    int i_2=0;
    int ok=1;
    int number=0;
    int adj_1=0;
    biaoge biao[10];
    while(ok)
    {
        biao[i_2].zong();
        number++;
        system("cls");
        maingo_1:
        cout<<"---------结束---------(0)"<<endl;
        cout<<"-------操作表格-------(1)"<<endl;
        cout<<"-------继续制表-------(2)"<<endl;
        cout<<"-----显示所有表格-----(3)"<<endl;
        maingo_2:
        cin>>ok;
        while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请从(0~3)中进行选择"<<endl;goto maingo_2;}
        if(ok>=4){cout<<"请从(0~3)中进行选择"<<endl;goto maingo_2;}
        if(ok==0)break;
        if(ok==1)
        {
            cout<<"请输入要操作的表格序号(1~"<<number<<")"<<endl;
            maingo_3:
            cin>>adj_1;
            while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请从(1~"<<number<<")中进行选择"<<endl;goto maingo_3;}
            if(adj_1>number){cout<<"请从(0~"<<number<<")中进行选择"<<endl;goto maingo_3;}
            system("cls");
            biao[adj_1-1].caozuo();
            goto maingo_1;
        }
        if(ok==2)i_2++;
        if(ok==3)
        {
            system("cls");
            for(i_2=0;i_2<number;i_2++)biao[i_2].xianshi_3();
            goto maingo_1;
        }
    }
    cout<<"万能表格服务到此结束，感谢您的使用！"<<endl;
    cout<<"-------------ICEORY-------------"<<endl;
    cout<<"--------------SAIL--------------"<<endl;
    cout<<"--------------SCUT--------------"<<endl;
}

int main()
{
    biaoge biao;
    biao.waicaozuo();
    system("pause");
}
