/** multi-function upgrade version
 * author: ICEORY
 * email: z.zhuangwei@mail.scut.edu.cn
 * last modified: 2017.6.11
 */
#include <stdlib.h>
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

char zhibiao(int c,int a[]);//制作表格
char intc();//数据类型的参考值为1
char charc();//数据类型的参考值为2
char floc();//数据类型的参考值为3
char boolc();//数据类型的参考值为4
char getlen_intc(int intn,int n);//获取int类型数据的长度
char getlen_float(float flon,int n_c,int n_r);//获取float类型数据的长度
int col=0;//表格列数
int num[100][20];//储存int类型的数据
int len_int[20];//int类型数据长度最大值
int len_cha[20];//char类型数据长度最大值
int len_float[20];//float类型数据长度最大值
int len_bool[20];//bool类型数据长度最大值
float floac[100][20];//储存float类型数据
int len_flo[100][20];//储存单个float类型数据长度
bool booc[100][20];//储存bool类型数据
char xianshi_2(int r,int a[]);//排序处理函数
string chac[100][20];//定义string类型的字符数组
string colname[20];//定义每一列数据的组名
int row=1;//列数
int b[4];//储存每一类数据使用次数
void pai_xu(int a[],int p_dz);
void shaixuan(int a[]);

char getlen_intc(int intn,int n)
{
    int i=0;
    int amp=1;
    while(amp<=intn){amp=amp*10;i++;}
    if(i>=len_int[n]){len_int[n]=i;}
}
char getlen_float(float flon,int n_c,int n_r)
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
    floac[n_r][n_c]=f_in+f_a[0]*0.1+f_a[1]*0.01+f_a[2]*0.001+f_a[3]*0.0001;
    len_flo[n_r][n_c]=s_in+s_f;
    if(len_flo[n_r][n_c]>=len_float[n_c]){len_float[n_c]=len_flo[n_r][n_c];}
}
char intc()
{
    static int in=0;
    cout<<"int类型数据"<<endl;
    cin>>num[row-1][in];
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;cin>>num[row-1][in];}
    if(in>=b[0]-1){in=0;getlen_intc(num[row-1][in],in);}
    else{getlen_intc(num[row-1][in],in);in++;}
}
char charc()
{
    static int cha=0;
    cout<<"char类型数据"<<endl;
    cin>>chac[row-1][cha];
    if(cha>=b[1]-1){cha=0;if(len_cha[cha]<=chac[row-1][cha].size()){len_cha[cha]=chac[row-1][cha].size();}}
    else{if(len_cha[cha]<=chac[row-1][cha].size()){len_cha[cha]=chac[row-1][cha].size();}cha++;}
}
char floc()
{
    static int flo=0;
    cout<<"float类型数据"<<endl;
    cin>>floac[row-1][flo];
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入float类型的数据，OK?"<<endl;cin>>floac[row-1][flo];}
    if(flo>=b[2]-1){flo=0;getlen_float(floac[row-1][flo],flo,row-1);}
    else{getlen_float(floac[row-1][flo],flo,row-1);flo++;}
}
char boolc()
{
    static int boo=0;
    cout<<"bool类型数据"<<endl;
    cin>>booc[row-1][boo];
    while(booc[row-1][boo]!=0&&booc[row-1][boo]!=1){cout<<"请输入bool类型的数据，OK?"<<endl;cin>>booc[row-1][boo];}
    if(boo>=b[3]-1){boo=0;}
    else{boo++;}
}
char zhibiao(int c,int a[])
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
                    cout<<"|"<<num[r][ni];
                    chazhi=1;
                    len=0;
                    while(chazhi<=num[r][ni]){chazhi=chazhi*10;len++;}
                    chazhi=len_int[ni]-len;
                    while(len_int[ni]>colname[i].size()){colname[i]=colname[i]+' ';}ni++;
                }
                if(a[i]==2)
                {
                    cout<<"|"<<chac[r][ci];
                    len=chac[r][ci].size();chazhi=len_cha[ci]-len;
                    while(len_cha[ci]>colname[i].size()){colname[i]=colname[i]+' ';}ci++;
                }
                if(a[i]==3)
                {
                    cout<<"|"<<floac[r][fi];
                    chazhi=len_float[fi]-len_flo[r][fi];
                    while(len_float[fi]>colname[i].size()){colname[i]=colname[i]+' ';}fi++;
                }
                if(a[i]==4){cout<<"|"<<booc[r][bi];chazhi=len_bool[bi]-1;bi++;}
                for(len=1;len<=chazhi;len++){cout<<" ";}
            }
        }
        else
        {
            for(i=0;i<=c;i++)
            {
                if(a[i]==1)
                {
                    cout<<"|"<<num[r][ni];
                    chazhi=1;
                    len=0;
                    while(chazhi<=num[r][ni]){chazhi=chazhi*10;len++;}
                    chazhi=len_int[ni]-len;
                    while(len_int[ni]>colname[i].size()){colname[i]=colname[i]+' ';}ni++;
                    }
                if(a[i]==2)
                {
                    cout<<"|"<<chac[r][ci];
                    len=chac[r][ci].size();chazhi=len_cha[ci]-len;
                    while(len_cha[ci]>colname[i].size()){colname[i]=colname[i]+' ';}ci++;
                }
                if(a[i]==3)
                {
                    cout<<"|"<<floac[r][fi];
                    chazhi=len_float[fi]-len_flo[r][fi];
                    while(len_float[fi]>colname[i].size()){colname[i]=colname[i]+' ';}fi++;
                }
                if(a[i]==4){cout<<"|"<<booc[r][bi];chazhi=len_bool[bi]-1;bi++;}
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
char xianshi_2(int r,int a[])
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
            cout<<"|"<<num[r][ni];
            chazhi=1;
            len=0;
            while(chazhi<=num[r][ni]){chazhi=chazhi*10;len++;}
            chazhi=len_int[ni]-len;ni++;
        }
        if(a[i]==2)
        {
            cout<<"|"<<chac[r][ci];
            len=chac[r][ci].size();chazhi=len_cha[ci]-len;ci++;
        }
        if(a[i]==3)
        {
            cout<<"|"<<floac[r][fi];
            chazhi=len_float[fi]-len_flo[r][fi];fi++;
        }
        if(a[i]==4){cout<<"|"<<booc[r][bi];chazhi=len_bool[bi]-1;bi++;}
        for(len=1;len<=chazhi;len++){cout<<" ";}
    }
    cout<<endl;
    ni=0;
    ci=0;
    fi=0;
    bi=0;
}
void pai_xu(int a[],int p_dz)
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
    if(a[p_n-1]==1){for(i=0;i<row-1;i++){p_p[i]=num[i][p_c-1];}}
    if(a[p_n-1]==3){for(i=0;i<row-1;i++){p_p[i]=floac[i][p_c-1];}}
    if(a[p_n-1]==4){for(i=0;i<row-1;i++){p_p[i]=booc[i][p_c-1];}}
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
        for(i=0;i<row-1;i++){xianshi_2(p_xu[i],a);}
    }
    else
    {
        for(i=row-2;i>=0;i--){xianshi_2(p_xu[i],a);}
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
void shaixuan(int a[])
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
    if(a[shai_col-1]==1){for(i=0;i<row-1;i++){shai_cun[i]=num[i][shai_ji-1];}}
    if(a[shai_col-1]==3){for(i=0;i<row-1;i++){shai_cun[i]=floac[i][shai_ji-1];}}
    if(a[shai_col-1]==4){for(i=0;i<row-1;i++){shai_cun[i]=booc[i][shai_ji-1];}}
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
        for(i=0;i<shai_ji;i++){xianshi_2(shai_xu[i],a);}
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
        for(i=0;i<row-1;i++){xianshi_2(i,a);}
        goto hereshai_1;
    }
}
int main()
{
    int i=0;
    int i_1=0;
    char name[60];
    cout<<"输入表格名称"<<"\n";
    cin.get(name,60);
    cout<<"输入表格列数"<<"\n";
    cin>>col;
    while(!cin){cin.clear();cin.ignore(1000,'\n');cout<<"请输入int类型的数据，OK?"<<endl;cin>>col;}
    while(col>20){cout<<"您输入的列数超过20列，请重新输入"<<endl;cin>>col;}
    int a[col];
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
        cin>>r;
        if(r>=1&&r<=4)
        {
            a[i-1]=r;
            if(r==1){len_int[b[r-1]]=colname[i-1].size();}
            if(r==2){len_cha[b[r-1]]=colname[i-1].size();}
            if(r==3){len_float[b[r-1]]=colname[i-1].size();}
            if(r==4){len_bool[b[r-1]]=colname[i-1].size();}
            b[r-1]++;
        }
        else{i--;cout<<"error!!!";}
        system("cls");
    }
    for(i_1=0;i_1<col;i_1++){cout<<"|"<<colname[i_1];}
    cout<<"\n"<<endl;
    while(ok)
    {
        for(i=0;i<col;i++)
        {
            cout<<"输入第"<<row<<"行"<<"第"<<i+1<<"列";
            if(a[i]==1){intc();}
            if(a[i]==2){charc();}
            if(a[i]==3){floc();}
            if(a[i]==4){boolc();}
            system("cls");
            cout<<name<<"\n";
            for(i_1=0;i_1<col;i_1++){cout<<"|"<<colname[i_1];}cout<<"\n";
            zhibiao(i,a);
        }
        cout<<"------退出-------(0)"<<"\n";
        cout<<"-----增加一行----(1)"<<"\n";
        cin>>ok;
        row++;//begin at 1
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
        if(ok==1||ok==2)pai_xu(a,ok);
        if(ok==3)shaixuan(a);
        system("cls");
        for(i=0;i<col;i++){cout<<"|"<<colname[i];}
        cout<<endl;
        for(i=0;i<row-1;i++){xianshi_2(i,a);}
    }
    cout<<"万能表格服务到此结束，感谢您的使用！"<<endl;
    cout<<"-------------ICEORY-------------"<<endl;
    cout<<"--------------SAIL--------------"<<endl;
    cout<<"--------------SCUT--------------"<<endl;
    system("pause");
}
