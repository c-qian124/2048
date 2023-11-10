#include<stdio.h>
#include<conio.h>   //使用getch()函数 
#include<time.h> 
#include <stdlib.h>
//定义函数 
void menu();
void Gameplay();
void add(int *p);
void close();
void appear();
void prin();
void clearstate();
void explation();
void clearstack();
void createstate();
//通过栈来存储数组 
typedef struct {
	
    int array[4][4];
	int score;
	int move;
} ArrayState;

typedef struct ArrayStackNode {
    ArrayState state;
    struct ArrayStackNode* prev;
} ArrayStackNode;

typedef struct {
    ArrayStackNode* top;
} ArrayStack;

//定义全局变量 
int  gameover, ifappear, gamew, gamef,m;
char key;
ArrayStack stack;
ArrayState state; 
ArrayStack stack0;



//加入栈 
void push(ArrayStack* stack, ArrayState state) {
    ArrayStackNode* node = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
    node->state = state;
    node->prev = stack->top;
    stack->top = node;
}

//出栈用于返回上一步 
ArrayState pop(ArrayStack* stack) {
    if (stack->top== NULL) {
        printf("已没有上一步\n");
        printf("按任意键返回菜单\n");
		getch();
		system("cls"); 
		createstate();
		menu();
    }
    ArrayState state = stack->top->state;
    ArrayStackNode* temp = stack->top;
    stack->top = stack->top->prev;
    free(temp);
    return state;
}
//清空栈 
void clearstack(ArrayStack* stack) {
    while (stack->top != NULL) {
        ArrayStackNode* temp = stack->top;  // 保存当前栈顶节点的指针
        stack->top = stack->top->prev;  // 栈顶指针指向下一个节点
        free(temp);  // 释放当前节点的内存
    }
}
	


//主函数 
int main()
{
   createstate();
               
    ifappear = 0;                   //判断是否应该随机出现2或4的变量初始化
                         
    gameover = 0;                 //游戏是否结束的变量初始化
                       
    menu();                     //调用主菜单函数
    return 0;
}
//创建栈 
void createstate()
{
	 ArrayState state = { 
        {{0,0,0,0},
         {0,0,0,0},
         {0,0,0,0},
         {0,0,0,0}},0,0
    };
    
    stack.top = NULL;
    push(&stack,state);
}
//游戏规则 
void explation()
{
    void menu();
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t*****************************************\n");
    printf("\t\t******************游戏规则***************\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("玩家可以选择上、下、左、右或W、A、S、D去移动滑块\n");
    printf("玩家选择的方向上若有相同的数字则合并\n");
    printf("合并所得的所有新生成数字相加即为该步的有效得分\n");
    printf("玩家选择的方向行或列前方有空格则出现位移\n");
    printf("每移动一步，空位随机出现一个2或4\n");
    printf("棋盘被数字填满，无法进行有效移动，判负，游戏结束\n");
    printf("棋盘上出现2048，获胜，游戏结束\n");
    printf("按上下左右去移动滑块\n");
    printf("请按任意键返回主菜单...\n");
    getch();
	system("cls");
    menu();
    
    
}
//显示失败 
void gamefaile()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t*****************************************\n");
    printf("\t\t******************you fail***************\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)
    {
        for (i = 0; i<4; i++)
            if (state.array[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", state.array[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    printf("你的成绩：%d,移动了%d步\n", state.score,state.move);
    printf("请按任意键返回主菜单...\n");
    getch();
    system("cls");
    menu();
 
}
//显示胜利 
void gamewin()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*******************you win***************\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)
    {
        for (i = 0; i<4; i++)
            if (state.array[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", state.array[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    printf("你的成绩：%d,移动了%d步\n", state.score,state.move);
    printf("按E返回上一步\n");
    printf("请按任意键返回主菜单...\n");
    getch();
    system("cls");
    menu(); 
    
}
//游玩界面 
void prin()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");//输出界面
    printf("\t\t*****************************************\n");
    printf("\t\t******************游戏开始***************\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*****************************************\t\t\n");
    
    printf("\t\t      请按a,d,ws或方向键移动滑块\n");//输出操作提示语句
    printf("\t\t\t按E返回上一步\n");
    printf("\t\t\t按Esc返回菜单并清空数据\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)                 //输出4*4的表格
    {
        for (i = 0; i<4; i++)
            if (state.array[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", state.array[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    
    
    printf("你的成绩：%d，移动了%d步\n", state.score,state.move);//输出得分和移动步数
}
//产生种子 
void appear()
{
    int i, j,ran,t[16],x=0,a,b;
    srand((int)time(0));          //随机种子初始化
    for (j = 0; j < 4; j++)      //将空白的区域的坐标保存到中间数组t中
        for (i = 0; i < 4;i++)
            if (state.array[j][i] == 0)
            {
                t[x] = j * 10 + i;
                x++;
            }
    if (x == 1)            //在t中随机取一个坐标
        ran = x - 1;
    else
        ran = rand() % (x - 1);
    a = t[ran] / 10;      //取出这个数值的十位数
    b = t[ran] % 10;     //取出这个数值的个位数
    srand((int)time(0));
    if ((rand() % 9)>2)    //在此空白区域随机赋值2或4
        state.array[a][b] = 2;
    else
        state.array[a][b] = 4;
}
//关闭游戏 
void close()
{
    exit(0);
}

//计算分数 
void add(int *p)
{
     
    int i=0, b;
    while (i<3)
    {
        if (*(p + i) != 0)
        {
            for (b = i + 1; b < 4; b++)
            {
                if (*(p + b) != 0)
                    if (*(p + i) == *(p + b))
                    {
                    state.score = state.score + (*(p + i)) + (*(p + b));
                    *(p + i) = *(p + i) + *(p + b);
                    if (*(p + i) == 2048)
                        gamew = 1;
                    *(p + b) = 0;
                    i = b + i;
                    ++ifappear;
                    break;
                    }
                    else
                    {
                        i = b;
                        break;
                    }
            }
            if (b == 4)
                i++;
        }
        else
            i++;
    }
 
}
//操作过程 
void Gameplay()
{
    int i, j, g, e, a, b[4];
    appear();
    appear();
    while (1)
    {
        ;
        prin();
        key = getch();
        switch (key)
        {
        case 'w':
        case 'W':
        case 72:
        	if (ifappear!=0)
            appear();
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = state.array[i][j];
                    state.array[i][j] = 0;
                }
                add(b);
                e = 0;
                for (g = 0; g < 4; g++)
                {
                    if (b[g] != 0)
                    {
                        state.array[e][j] = b[g];
                        if (g != e)
                            ++ifappear;
                        e++;
                    }
                }
            }
            
            if (ifappear!=0)
                ++state.move;push(&stack, state);
        break;
        case 's':
        case 'S':
        case 80:
        	if (ifappear!=0)
            appear();
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = state.array[i][j];
                    state.array[i][j] = 0;
                }
                add(b);
                e = 3;
                for (g = 3; g>=0; g--)
                {
                    if (b[g] != 0)
                    {
                        state.array[e][j] = b[g];
                        if (g != e)
                            ++ifappear;
                        e--;
                    }
                }
            }
            
            if (ifappear != 0)
                ++state.move;push(&stack, state);
        break;
        case 'a':
        case 'A':
        case  75:
        	if (ifappear!=0)
            appear();
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = state.array[j][i];
                    state.array[j][i] = 0;
                }
                add(b);
                e = 0;
                for (g = 0; g < 4; g++)
                {
                    if (b[g] != 0)
                    {
                        state.array[j][e] = b[g];
                        if (g!=e)
                            ++ifappear;
                        e++;
                    }
                }
            }
            
            if (ifappear != 0)
                ++state.move;push(&stack, state);
        break;
        case 'd':
        case 'D':
        case  77:
        	if (ifappear!=0)
            appear();
            ifappear = 0;
            for (j = 0; j < 4; j++)
            {
                for (i = 0; i < 4; i++)
                {
                    b[i] = state.array[j][i];
                    state.array[j][i] = 0;
                }
                add(b);
                e = 3;
                for (g = 3; g >=0; g--)
                {
                    if (b[g] != 0)
                    {
                        state.array[j][e] = b[g];
                        if (g!=e)
                            ++ifappear;
                        e--;
                    }
                }
            }
            
            if (ifappear != 0)
                ++state.move;push(&stack, state);
        break;
        case 'e':
        case 'E':
		state=pop(&stack);
		break;	
        
        case  27:
        	clearstack(&stack);
        	createstate();
        	system("cls");
        	state=pop(&stack);
        	menu();
        	break;
 
        }
        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 4; i++)
            {
                if (j < 3)
                {
                    if (i < 3)
                    {
                        if (state.array[j][i] == state.array[j + 1][i] || state.array[j][i] == state.array[j][i + 1] || state.array[j][i] == 0)
                        {
                            gamef = 0;
                            break;
                        }
                        else
                            gamef = 1;
                    }
                    else
                    {
                        if (state.array[j][i] == state.array[j + 1][i] || state.array[j][i] == 0)
                        {
                            gamef = 0;
                            break;
                        }
                        else
                            gamef = 1;
                    }
                }
                else
                {
                    if (i < 3)
                    {
                        if (state.array[j][i] == state.array[j][i + 1] || state.array[j][i] == 0 || state.array[j][i + 1] == 0)
                        {
                            gamef = 0;
                            break;
                        }
                        else
                            gamef = 1;
                    }
                }
 
            }
            if (gamef == 0)
                break;
        }
        if (gamef == 1 || gamew == 1)
            break;
 
    }
    if (gamef == 1)
        gamefaile();
    else
        gamewin();
}
//菜单 
void menu()
{
    int n;
    printf("\t\t*****************************************\t\t\n");            //输出游戏菜单的图形
    printf("\t\t*              1、开始游戏              *\n");
    printf("\t\t*              2、游戏规则              *\n");
    printf("\t\t*              3、退出游戏              *\n");
    printf("\t\t*****************************************\n");
    printf("请输入1或2或3:[ ]\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        Gameplay();                                                         //游戏开始函数
        break;
    case 2:
        explation();                                                       //游戏规则函数
        break;
    case 3:
        close();                                                          //关闭游戏函数
        break;
    }
}
