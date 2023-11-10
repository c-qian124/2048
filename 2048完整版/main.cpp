#include<stdio.h>
#include<conio.h>   //ʹ��getch()���� 
#include<time.h> 
#include <stdlib.h>
//���庯�� 
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
//ͨ��ջ���洢���� 
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

//����ȫ�ֱ��� 
int  gameover, ifappear, gamew, gamef,m;
char key;
ArrayStack stack;
ArrayState state; 
ArrayStack stack0;



//����ջ 
void push(ArrayStack* stack, ArrayState state) {
    ArrayStackNode* node = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
    node->state = state;
    node->prev = stack->top;
    stack->top = node;
}

//��ջ���ڷ�����һ�� 
ArrayState pop(ArrayStack* stack) {
    if (stack->top== NULL) {
        printf("��û����һ��\n");
        printf("����������ز˵�\n");
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
//���ջ 
void clearstack(ArrayStack* stack) {
    while (stack->top != NULL) {
        ArrayStackNode* temp = stack->top;  // ���浱ǰջ���ڵ��ָ��
        stack->top = stack->top->prev;  // ջ��ָ��ָ����һ���ڵ�
        free(temp);  // �ͷŵ�ǰ�ڵ���ڴ�
    }
}
	


//������ 
int main()
{
   createstate();
               
    ifappear = 0;                   //�ж��Ƿ�Ӧ���������2��4�ı�����ʼ��
                         
    gameover = 0;                 //��Ϸ�Ƿ�����ı�����ʼ��
                       
    menu();                     //�������˵�����
    return 0;
}
//����ջ 
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
//��Ϸ���� 
void explation()
{
    void menu();
    system("cls");
    printf("\t\t*****************************************\t\t\n");
    printf("\t\t*****************************************\n");
    printf("\t\t******************��Ϸ����***************\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*****************************************\t\t\n");
    printf("��ҿ���ѡ���ϡ��¡����һ�W��A��S��Dȥ�ƶ�����\n");
    printf("���ѡ��ķ�����������ͬ��������ϲ�\n");
    printf("�ϲ����õ�����������������Ӽ�Ϊ�ò�����Ч�÷�\n");
    printf("���ѡ��ķ����л���ǰ���пո������λ��\n");
    printf("ÿ�ƶ�һ������λ�������һ��2��4\n");
    printf("���̱������������޷�������Ч�ƶ����и�����Ϸ����\n");
    printf("�����ϳ���2048����ʤ����Ϸ����\n");
    printf("����������ȥ�ƶ�����\n");
    printf("�밴������������˵�...\n");
    getch();
	system("cls");
    menu();
    
    
}
//��ʾʧ�� 
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
    printf("��ĳɼ���%d,�ƶ���%d��\n", state.score,state.move);
    printf("�밴������������˵�...\n");
    getch();
    system("cls");
    menu();
 
}
//��ʾʤ�� 
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
    printf("��ĳɼ���%d,�ƶ���%d��\n", state.score,state.move);
    printf("��E������һ��\n");
    printf("�밴������������˵�...\n");
    getch();
    system("cls");
    menu(); 
    
}
//������� 
void prin()
{
    int i, j;
    system("cls");
    printf("\t\t*****************************************\t\t\n");//�������
    printf("\t\t*****************************************\n");
    printf("\t\t******************��Ϸ��ʼ***************\n");
    printf("\t\t*****************************************\n");
    printf("\t\t*****************************************\t\t\n");
    
    printf("\t\t      �밴a,d,ws������ƶ�����\n");//���������ʾ���
    printf("\t\t\t��E������һ��\n");
    printf("\t\t\t��Esc���ز˵����������\n");
    printf("\t\t\t---------------------\n\t\t\t");
    for (j = 0; j<4; j++)                 //���4*4�ı��
    {
        for (i = 0; i<4; i++)
            if (state.array[j][i] == 0)
                printf("|    ");
            else
                printf("|%4d", state.array[j][i]);
        printf("|\n");
        printf("\t\t\t---------------------\n\t\t\t");
    }
    
    
    printf("��ĳɼ���%d���ƶ���%d��\n", state.score,state.move);//����÷ֺ��ƶ�����
}
//�������� 
void appear()
{
    int i, j,ran,t[16],x=0,a,b;
    srand((int)time(0));          //������ӳ�ʼ��
    for (j = 0; j < 4; j++)      //���հ׵���������걣�浽�м�����t��
        for (i = 0; i < 4;i++)
            if (state.array[j][i] == 0)
            {
                t[x] = j * 10 + i;
                x++;
            }
    if (x == 1)            //��t�����ȡһ������
        ran = x - 1;
    else
        ran = rand() % (x - 1);
    a = t[ran] / 10;      //ȡ�������ֵ��ʮλ��
    b = t[ran] % 10;     //ȡ�������ֵ�ĸ�λ��
    srand((int)time(0));
    if ((rand() % 9)>2)    //�ڴ˿հ����������ֵ2��4
        state.array[a][b] = 2;
    else
        state.array[a][b] = 4;
}
//�ر���Ϸ 
void close()
{
    exit(0);
}

//������� 
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
//�������� 
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
//�˵� 
void menu()
{
    int n;
    printf("\t\t*****************************************\t\t\n");            //�����Ϸ�˵���ͼ��
    printf("\t\t*              1����ʼ��Ϸ              *\n");
    printf("\t\t*              2����Ϸ����              *\n");
    printf("\t\t*              3���˳���Ϸ              *\n");
    printf("\t\t*****************************************\n");
    printf("������1��2��3:[ ]\b\b");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        Gameplay();                                                         //��Ϸ��ʼ����
        break;
    case 2:
        explation();                                                       //��Ϸ������
        break;
    case 3:
        close();                                                          //�ر���Ϸ����
        break;
    }
}
