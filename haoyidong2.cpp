# include <stdio.h>
# include <string.h>
# include <iostream>
# include <string.h.>
# include <windows.h>
using namespace std;
int file(FILE *fp);
int shuxing()
{
    system("cls");//����
    system("color 1E"); //��
    printf("********************************************************************************");
    printf("**********************************ʹ��˵��**************************************");
    printf("********************************************************************************\n\n\n\n\n");
    printf("\n\n>>>>>>>>>>>>>>>>>ʹ��ǰ���Ƚ����ļ���\n");
    printf("\n\n>>>>>>>>>>>>>>>>>�ļ�û�����밴 1 ��������,���������밴�����(������1)��\n");
    char n[1000];
    printf("\t\t\t\t");
    gets(n);
    if(strcmp(n,"1")==0)
    {
        printf("\n\nn>>>>>>>>>>>>>>>>>ллʹ�ã��ټ�!\n");
        system("pause");//����
        exit(0);
    }

    return 0;

}
int start()
{
    system("cls");//����
    system("color 1E"); //����������ɫΪ��ɫ ����ɫ��ɫ
    printf("\n\n\n\n\n\n");
    printf("********************************************************************************");
    printf("*******************************��ӭʹ�ôʷ�������*******************************");
    printf("********************************************************************************\n\n\n\n\n");
    printf("\t\t\t\t    ����: �ι��� \n\n");
    printf("\t\t\t\t\t       2014��10��\n\n\n\n");

    printf("\t\t\t\t\t***�����������***\n");
    return 0;
}


int file(FILE *fp)
{
    char str1[1000][1000];
    int i,j;
    i=0;
    j=0;
    char ch;
    while(!feof(fp))
    {
        if((ch=fgetc(fp))!='\n')
            str1[i][j++]=ch;
        else
        {

            str1[i][j]='\0';
            i++;
            j=0;
        }
    }
    system("cls");//����
    system("color 1E"); //��
    printf("\n>>>>>>>>>>�ļ��еĳ����ǣ�\n\n\n");
    for(int a=0; a<i; a++)
        printf("%s\n",str1[a]);
    printf("\t\t\t\t\t***�����������***\n");
    getchar();
    char word[1000][100];
    int a=0;
    int b=0;

    bool flag1;
    int n=i;
    for(i=0; i<n; i++)
    {
        flag1=0;
        for(j=0; (str1[i][j])!='\0'; j++)
        {
            while(str1[i][j]==' ')
            {
                j++;
                flag1=0;
            }
            char ch=str1[i][j];
            if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
            {
                if(flag1)
                {
                    word[a][b]=ch;
                    b++;
                    word[a][b]='\0';
                }
                else
                {
                    a++;              //��һ��a��1��ʼȡ
                    b=0;
                    word[a][b]=ch;
                    b++;
                    word[a][b]='\0';
                    flag1=1;
                }
            }
            else
            {
                a++;              //��һ��a��1��ʼȡ
                b=0;
                word[a][b]=ch;
                b++;
                word[a][b]='\0';
                flag1=0;
            }
        }
    }
    system("cls");//����
    system("color 1E"); //��
    printf("\n>>>>>>>>>��ֺ󵥴�Ϊ��\n\n\n");
    for(int i=1; i<a; i++)
    {
        printf("%10s",word[i]);
        if(i%6==0)
            printf("\n");
    }
    printf("\n\n\t\t\t\t\t***�����������***\n");
    getchar();
    system("cls");//����
    system("color 1E");
    printf("\n>>>>>>>>>>��ֺ󵥴ʵ�����:\n\n");
    char biao[100][30]=
    {
        "void","int","float","double","char","if","else","while","do","return","for",
        "auto","break","case","const","continue","default","switch","enum","extern","goto","long",
        "register","short","signed","sizoef","static","struct","switch","typedef","union","unsigned","volatile","include"
    };
    bool flag=0;
    for(int i=1; i<a; i++)
    {
        flag=1;
        if(strcmp(word[i],"main")==0)
            printf("%8s  : <1,������>\n",word[i]);
        else
        {
            for(int j=0; j<34; j++)
                if(strcmp(word[i],biao[j])==0)
                {
                    printf("%8s  : <2,�ؼ���>\n",word[i]);
                    flag=0;
                    break;
                }
            if(flag)
            {
                if(strcmp(word[i],"+")==0||strcmp(word[i],"-")==0)
                {
                    if(strcmp(word[i],word[i+1])==0)
                    {
                        strcat(word[i],word[i+1]);
                        printf("%8s  : <3,���������>\n",word[i]);
                        i++;
                    }
                    else
                        printf("%8s  : <4,��ͨ�����>\n",word[i]);
                }
                else if(strcmp(word[i],"%")==0)
                {
                    if(word[i+1][0]>='0'&&word[i+1][0]<='9')
                        printf("%8s  : <5,ȡ�������>\n",word[i]);
                    else
                        printf("%8s  : <6,��ʽ���ַ���>\n",word[i]);
                }
                else if(strcmp(word[i],"*")==0||strcmp(word[i],"/")==0)
                    printf("%8s  :<4,��ͨ�����>\n",word[i]);
                else if(strcmp(word[i],">")==0||strcmp(word[i],"<")==0||strcmp(word[i],"=")==0)
                {
                    if(strcmp(word[i+1],"=")==0)
                    {
                        strcat(word[i],word[i+1]);
                        printf("%8s  : <7,��ϵ�����>\n",word[i]);
                        i++;
                    }
                    else if(strcmp(word[i],"=")==0)
                        printf("%8s  : <8,��ֵ�����>\n",word[i]);
                    else
                        printf("%8s  : <7,��ϵ�����>\n",word[i]);
                }
                else if(strcmp(word[i],"!")==0)
                {
                    if(strcmp(word[i],"=")==0)
                    {
                        strcat(word[i],word[i+1]);
                        printf("%8s  : <7,��ϵ�����>\n",word[i]);
                        i++;
                    }
                    else
                        printf("%8s  : <9,�߼���>\n",word[i]);
                }
                else if (strcmp(word[i],"&")==0||strcmp(word[i],"|")==0)
                {
                    if(word[i][0]=='&'||word[i][0]=='|')
                    {
                        strcat(word[i],word[i+1]);
                        printf("%8s  : <7,��ϵ�����>\n",word[i]);
                        i++;
                    }
                    else
                        printf("%8s  : <10,�߼�����ķ�>\n",word[i]);
                }
                else if(strcmp(word[i],"(")==0||strcmp(word[i],")")==0||strcmp(word[i],"[")==0||strcmp(word[i],"]")==0||strcmp(word[i],"}")==0||strcmp(word[i],"{")==0||strcmp(word[i],";")==0||strcmp(word[i],",")==0)
                    printf("%8s  : <11,���>\n",word[i]);
                else if(strlen(word[i])<=1)
                {
                    if((word[i][0]>='0'&&word[i][0]<='9'))
                        printf("%8s  : <12,����>\n",word[i]);
                    else if((word[i][0]>='A'&&word[i][0]<='Z')||(word[i][0]>='a'&&word[i][0]<='z'))
                        printf("%8s  : <13,��ʶ��>\n",word[i]);
                }
                else
                {
                    bool z=1;
                    bool f=0;
                    if(word[i][0]=='0')
                    {
                        for(int h=1; word[i][h]!='\0'; h++)
                        {
                            if((word[i][h]>='A'&&word[i][h]<='Z')||(word[i][h]<='z'&&word[i][h]>='a')||(word[i][h]=='_'))
                            {
                                printf("%8s  :error �����ϱ�ʾ���Ķ���\n",word[i]);
                                z=0;
                                break;
                            }
                            else if(word[i][h]=='.')
                                f=1;
                        }
                        if(z)
                        {
                            if(f)
                                printf("%8s  : <4,ʵ��>\n",word[i]);
                            else
                                printf("%8s  : <12,����>\n",word[i]);
                        }
                    }
                    else
                    {
                        bool l=0;
                        for(int h=1; word[i][h]!='\0'; h++)
                        {
                            if((word[i][h]>='0'&&word[i][h]<='9')||(word[i][h]<='z'&&word[i][h]>='a')||(word[i][h]<='Z'&&word[i][h]>='A')||word[i][h]=='_')
                                ;
                            else
                            {
                                l=1;
                                printf("%8s  :error �����ϱ�ʾ�����壬�������������ϱ�׼�ķ���\n",word[i]);
                            }
                        }
                        if(!l)
                            printf("%8s  : <13,��ʾ��>\n",word[i]);
                    }
                }
            }
        }
    }

    return 0;
}
int main()
{
    char str[100];

    FILE *fp;
    start();
    getchar();
    shuxing();
    system("cls");//����
    system("color 1E"); //��
    printf("\n\n\n\n>>>>>>>>>>>>>�������ļ�λ��!\n");
    for(;;)
    {
        scanf("%s",str);
        if((fp=fopen(str,"r"))==NULL)
            printf("\n\n>>>>>>>>>>>>>�����������������!\n");
        else
        {
            printf("\n\n>>>>>>>>>>>>>����ɹ���\n");
            break;
        }
    }
    printf("\n\n\t\t\t\t\t***�����������***\n");
    getchar();

    file(fp);

    fclose(fp);

    return 0;

}

