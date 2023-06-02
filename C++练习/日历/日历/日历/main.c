#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int leap_year(int y, int i)//��������꣬����1�������ƽ�귵��0
{
    if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))//�ܹ���400�������������꣬�ܱ�4������������100�ı�������ͨ����
    {
        i = 1;
    }
    return i;
}
void month_english(int M)     //�����·�����תӢ�ĺ����������·ݣ����Ӣ��
{
    switch (M)
    {
    case 1:printf("%s", "Jan"); break;
    case 2:printf("%s", "Feb"); break;
    case 3:printf("%s", "Mar"); break;
    case 4:printf("%s", "Apr"); break;
    case 5:printf("%s", "May"); break;
    case 6:printf("%s", "Jun"); break;
    case 7:printf("%s", "Jul"); break;
    case 8:printf("%s", "Aug"); break;
    case 9:printf("%s", "Sep"); break;
    case 10:printf("%s", "Oct"); break;
    case 11:printf("%s", "Nov"); break;
    case 12:printf("%s", "Dec"); break;

    }
}
int month_one_w(int d, int y, int m, int w)//�жϸ��·�ÿһ�ŵ�����//ѧ��һ����ķ����ɭ��ʽ/dΪ����
{
    if (m == 01 || m == 02)//�����һ�»�����2�£������һ���13�»�14��
    {
        m += 12;
        y--;
    }
    w = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;//���w=0���������죬
    return w;
}
void Appear_number(int y, int m, int w, int md)//����Ϊ�·ݺ���ݣ������β�ҲҪ�������ͣ�������������
{
    int i = 1;
    for (i = 1; i <= md; i++)
    {
        w = month_one_w(i, y, m, w);//�жϸ��·�ÿһ������ڣ��Ա��ڽ��пո��������໥��Ӧ��
        if (i == 1 && w != 0)
        {
            switch (w)
            {
            case 1:printf(" "); break;
            case 2:printf("        "); break;
            case 3:printf("               "); break;
            case 4:printf("                      "); break;
            case 5:printf("                             "); break;
            case 6:printf("                                    "); break;
            }
        }

        switch (w)//�������ڶ����ݽ��пո�ʵ�ֶ�Ӧ
        {
        case 0:printf("%d", i); break;//������Ľ��Ϊ0
        case 1:if (i == 10)
        {           //������10�ŵ�ʱ������ǰ��ĵ������ڣ�����ֿո������е���
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 2:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 3:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 4:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 5:if (i == 10)
        {
            printf("%8d", i);
            break;
        }
              else
        {
            printf("%7d", i); break;
        }
        case 6:if (i == 10)
        {
            printf("%8d\n", i);
            break;
        }
              else
        {
            printf("%7d\n", i); break;
        }
        }

    }
    printf("\n");

}
void around_message(int M, int Y)
{
    printf("\n");
    printf("\t%d���%d�µ�����\n", Y, M);
    month_english(M); //�����������תӢ�ĺ���
    printf("%42d\n", Y);// �����Ӧ�����
    printf("%s    %s    %s    %s    %s    %s    %s\n", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT");//��������һ�У�����֮����3���ַ�
}
int main()
{
    int Y, YD, M, MD, judje_year, W; //Y���꣬YD�����ܹ���������M�·ݣ�MD�µ�������judje_year�ж�����ƽ��ı���ֵ��W����
    judje_year = 0;
    W = 0;
    int i;
    YD = 365;
    //�ڽ���һ�������ж�������������Ǿ����·ݣ�ʹ��if�����зֿ�
    printf("������ѯ��������ز�ѯ��Ϣ��������֧��1921����9999�����������\n");
loop:
    printf("��������Ҫ��ѯ�����\n");
    scanf("%4d", &Y);
    //��������ȷ�Խ��м��
    if (Y >= 9999)
    {
        printf("�����������̫���ˣ��������޸�\n");
        goto loop;
    }
    else if (Y <= 1912)
    {
        printf("ˡС�����ܣ������ǰ��δʵ�й���������������\n");
        goto loop;
    }
    printf("��������Ҫ��ѯ���·ݣ�����ѯ��������������0\n");
    scanf("%d", &M);
    if (M > 12)
    {
        printf("�������Ŷ��һ��ֻ��12����,����������\n");
        goto loop;
    }
    else if (M < 0)
    {
        printf("�·�û�и���Ŷ������������\n");
        goto loop;
    }
    //����ÿ���µ�����һά����
    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    //�ж������껹��ƽ��
    if (leap_year(Y, judje_year) == 1)  //����1���·�29�죬ƽ��0���·�28��
    {
        month[1] = 29;
        YD = 366;
    }
    printf("\t%s\n\n", "����ѯ����������");


    if (M == 0)//����·�Ϊ�����������������
    {
        for (i = 0; i < 12; i++)// ѭ��ÿһ�µ�����
        {
            around_message(i + 1, Y);//�����ص�������Ϣ������ɺ���
            Appear_number(Y, i + 1, W, month[i]); //�����ĳһ���������ֳ��ֺ���
        }
    }
    else if (M != 0)
    {
        around_message(M, Y);//�����ص�������Ϣ������ɺ���
        Appear_number(Y, M, W, month[M - 1]);
    }

}