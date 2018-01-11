#include<stdio.h>
struct GPA
{
    char name[20];
    float credit;
    float Gpoint;
};
struct GPA G[18];
int main()
{
    int i;
    float a=0,b=0,AG;
    struct GPA G[18]={
        {"程序设计基础",4.0,3.00},{"计算机导论",2.0,2.00},{"高等数学I",6.0,3.00},{"大学英语C",4.0,1.33},
        {"线性代数",3.5,2.00},{"中国近代史纲要",2.0,3.67},{"军事理论",1.0,2.67},{"体育I    ",1.0,1.33},
        {"军事训练",1.0,3.00},{"大学英语B",4.0,2.33},{"高等数学II",6.0,2.67},{"离散数学I",2.5,3.67},
        {"金工实习",1.0,3.33},{"思修    ",3.0,3.33},{"体育II    ",1.0,3.67},
        {"普通物理实验I",1.5,3.00},{"普通物理I",4.0,2.67},{"程序设计实训",1.0,2.67}
                     };
    printf("名称\t      学分\t绩点\n");
    for(i=0;i<18;i++)
        printf("%s\t%.2f\t%.2f\n",G[i].name,G[i].credit,G[i].Gpoint);
    for(i=0;i<18;i++)
        a=(G[i].credit)*(G[i].Gpoint)+a;
    for(i=0;i<18;i++)
        b=G[i].credit+b;
    AG=a/b;
    printf("平均绩点为%.2f",AG);
    return 0;
}
