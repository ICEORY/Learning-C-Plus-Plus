/** print hello world on screen
 * author: ICEORY
 * email: z.zhuangwei@mail.scut.edu.cn
 * last modified: 2017.6.11
 */

#include <iostream>
using namespace std;

const char graph_1[2][2]={" ","O"};
const char graph_2[2][2]={"O"," "};

// delay function
void delay(int t){
    int i=0 , j=0, k=0;
    for(i=0;i<=t;i++)
    {
        for(j=0;j<=10000;j++)
        {
            for(k=0;k<=1000;k++);
        }
    }
}

int main(){
    int i=0, j=0;
	int graph_matrix[10][60]={
	    1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,
        1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,1,
        1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,
        1,0,0,1,0,0,1,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1,
        1,0,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,
        1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,
        1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,
        1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,
        1,0,0,1,0,0,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,
        1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1,1,1,1};

    while(1)
    {
        for(j=0;j<=9;j++)
        {
            for(i=0;i<=59;i++)
            {
                cout<<graph_1[graph_matrix[j][i]];
            }
            cout<<"\n";
        }
        delay(1);

        for(j=0;j<=9;j++)
        {
            for(i=0;i<=59;i++)
            {
                cout<<graph_2[graph_matrix[j][i]];
            }
            cout<<"\n";
        }
        delay(1);
    }
}

