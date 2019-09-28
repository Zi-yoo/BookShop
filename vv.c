#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
#define MAXNUM 2000

typedef struct
{
	char vno[10];
	char vname[20];
	int vlevel;
} VIP;
int TotalVip;
VIP vip[MAXNUM];

typedef struct
  {
   char isbn[10];		
   char bkname[20];	
   char author[10];		
   float price; 		
   int num;			
  } BOOK;
int TotalBook;
BOOK bk[MAXNUM];

RData()
{
FILE *vp;
if ((vp=fopen(".\\vipdata.txt","rb"))==NULL)
    {printf("Can not open the file!\n");return;}

fread(&TotalVip,sizeof(int),1,vp);
fread(vip,sizeof(VIP),TotalVip,vp);

fclose(vp);
}

SData()
{
FILE *vp;
if ( (vp=fopen(".\\vipdata.txt","wb"))==NULL)
    {printf("Can not open the file!\n");return;}
fwrite(&TotalVip, sizeof(int) , 1 ,vp);	
fwrite(vip,sizeof(VIP),TotalVip,vp);
fclose(vp);
}

ReadData()
{
FILE *fp;
if ((fp=fopen(".\\bookdata.txt","rb"))==NULL)
    {printf("Can not open the file!\n");return;}

fread(&TotalBook,sizeof(int),1,fp);
fread(bk,sizeof(BOOK),TotalBook,fp);

fclose(fp);
}

SaveData()
{
FILE *fp;
if ( (fp=fopen(".\\bookdata.txt","wb"))==NULL)
    {printf("Can not open the file!\n");return;}
fwrite(&TotalBook, sizeof(int) , 1 ,fp);	
fwrite(bk,sizeof(BOOK),TotalBook,fp);
fclose(fp);
}

booklist()
{
 int i;
 printf("  \t\t%-8s%-20s%-10s%-8s%-4s\n",
        "书号","书名","作者","价格","数量");
 printf("\t\t---------------------------------------------------------\n");        
 for (i=0;i<TotalBook;i++)
 	printf("\t\t| %-8s%-20s%-10s%-8.2f%-4d\t|\n",bk[i].isbn,bk[i].bkname,
	    bk[i].author,bk[i].price,bk[i].num );
 printf("\t\t---------------------------------------------------------\n");
 printf("\n\n\n\n\n\t\t按任意键返回\n\n");
}

Find()
{     int i,k,a,n;  char bkgj[10];

     printf("\t\t-------------------商品查找界面---------------------\n");
     for(k=0;;k++)
	 { 
    
	
       
       
       		
     		printf("\n\t\t请输入书号,作者，书名查找\n\t\t(000的时候退出查找）：");
			 fflush(stdin);gets(bkgj);
		 	if(strcmp(bkgj,"000")==0) break;
		
		 		for(n=0;n<TotalBook;n++)
				{
						for(i=0;i<TotalBook;i++) 
						{
							if(strcmp(bkgj,bk[i].bkname)==0) break;
							if(strcmp(bkgj,bk[i].author)==0) break;	
							if(strcmp(bkgj,bk[i].isbn)==0)   break;			  
						}
				
					if(i<TotalBook)
	  				{
	   					system("cls");
					  	 printf("\t\t-------------------商品查找界面------------------\n");
	   						printf("\t\t\t\t该书的相关信息\n");
	   					printf("\t\t%-8s%-20s%-10s%-8s%-4s\n",
        				"书号","书名","作者","价格","数量");
 						printf("\t\t--------------------------------------------------\n");
 	
		 				printf("\t\t%-8s%-20s%-10s%-8.2f%-4d\n",bk[i].isbn,bk[i].bkname,
	   		 			bk[i].author,bk[i].price,bk[i].num ); 
					}	
	    			else
					{ 
	   		 			system("cls");
						printf("\t\t-----------------商品查找界面--------------------\n");
						printf("\t\t\t该关键字不存在，请重新输入\n");
					}	
		 		}
		 			
		 	
		 			
		
		 		
		 	
				 
		
	
	 }
}

int showsel()
{
 int sel;
 printf("\t\t\t简易书店管理系统\n\n");
 printf("\t-------------------------------------------------\n");
 printf("\t|\t                                        |\n");
 printf("\t|\t [1]. 书籍列表\t\t[2]. 书籍入库\t|\n");
 printf("\t|\t                                        |\n");
 printf("\t|\t [3]. 书籍销售\t\t[4]. 会员注册\t|\n");
 printf("\t|\t                                        |\n");
 printf("\t|\t [5]. 会员列表\t\t[6]. 删除书籍\t|\n");
 printf("\t|\t                                        |\n");
 printf("\t|\t [7]. 删除会员\t\t[8]. 查找书籍\t|\n");
 printf("\t|\t                                        |\n"); 
 printf("\t|\t 退出后自动保存  \t[0]. 退出\t|\n");
 printf("\t|\t                                        |\n"); 
 printf("\t-------------------------------------------------\n");
 printf("\t   请输入要选择功能的编号：");
 scanf("%d",&sel);  return sel;
}

vipin()
{
	char vno[10];int n1,i,men;
	 VIP newvip;
	 printf("\t\t\t请输入会员编号:\t");
	 scanf("%s",vno);
	 for(i=0;i<TotalVip;i++)
			if(strcmp(vno,vip[i].vno)==0) break;
	 if(i<TotalVip)
	 	{
				printf("\n\t\t\t你已经是本店永久会员\n\n\t\t\t请享受你个的购物之旅");
		}
	 else
	 { 
	 system("cls");
	 printf("\t\t\t欢迎注册成为本店荣誉会员\n\n\t\t\t请输入会员信息：\n\n\t\t\t会员编号:\t");
	 scanf("%s",newvip.vno);
	 printf("\n\t\t\t会员名:\t\t");
	 scanf("%s",newvip.vname);
	 system("cls");
	 printf("\t\t\t本店会员分2级，充值100为普通会员\n\n\t\t\t充值100以上为高级会员\n\n\t\t\t不同会员购书优惠不同\n\n\t");

	 printf("\t\t请输入充值金额：\t");
	 scanf("%d",&men);
	 	if(men>100)
	 	{
	 		printf("\n\t\t\t恭喜成为本店高级会员\t\n");
	 		newvip.vlevel=1;
	 	}
	 	else
		 {
	 		printf("\n\t\t\t恭喜成为本店普通会员\t\n");
	 		newvip.vlevel=0;
	 	 }
	 	 vip[TotalVip]=newvip;
		 TotalVip++;
		 printf("\n\t\t\t按任意键返回购书\t");
	 } 	 
}

viplist()
{
	int i;
	printf("\t-----------------------本店会员列表-----------------------\n\n");
	printf("\t会员编号\t\t会员名\t\t\t  会员等级\n\n");
	for(i=0;i<TotalVip;i++)
		printf("\t%s\t\t\t%s\t\t\t\t%d\n",vip[i].vno,vip[i].vname,vip[i].vlevel);
	printf("\n\n\n\n\n\t(0为普通会员\t1为高级会员\t按任意键返回)\n\n");

}

bookin()
{	
	int n1,i;char bkno[10];
	BOOK newbk;
	printf("请输入书号(000停止入库)：");scanf("%s",bkno);
	while(strcmp(bkno,"000")!=0)
	{
		for(i=0;i<TotalBook;i++)
			if(strcmp(bkno,bk[i].isbn)==0) break;
		if(i<TotalBook)
			{
				printf("该书已经找到，请输入数量:");
				scanf("%d",&n1);
				bk[i].num+=n1;
			}
		else
			{
				printf("未找到该书，输入该书信息\n");
				
				strcpy(newbk.isbn,bkno);
				printf("请添加书本信息:\n书名:");scanf("%s",newbk.bkname);
				printf("作者:");scanf("%s",newbk.author);
				printf("单价:");scanf("%f",&newbk.price);
				printf("数量:");scanf("%d",&newbk.num);
				printf("按enter确认所输入书籍信息");
				getch();
				bk[TotalBook]=newbk;
				TotalBook++;
			}
		system("cls");
		printf("        请输入书号(000停止入库)：");scanf("%s",bkno);
	}	
}

booksale()
{
	int i,j,salenum=0;char bkno[10],vino[10];float tpr=0,m,men;BOOK salelist[30];
			printf("\t\t\t购书输入书号\n\t\t\t");
			scanf("%s",bkno);
					system("cls");
					while(strcmp(bkno,"000")!=0)
					{
						for(i=0;i<TotalBook;i++)
							if(strcmp(bkno,bk[i].isbn)==0) break;
						if(i<TotalBook)
							if(bk[i].num>0)
							{
							salelist[salenum]=bk[i];
							salenum++;
							tpr+=bk[i].price;
							bk[i].num--;
							}
							else {printf("\n\n\t\t\t该书已经售罄!");getch();}
		
						else {printf("\n\n\t\t\t图书未入库，不能正常销售");getch();};
						system("cls");
						printf("\t\t----------图书销售界面----------\n\n");
						for(i=0;i<salenum;i++)
							printf("\t\t%-20s%-8.2f\n",salelist[i].bkname,salelist[i].price);
							printf("\n\n\t\t\t 总金额是:%8.2f\n\n",tpr);
							printf("\t\t\t继续购买请输入书号:   \n\n\t\t\t结束购买000\n\n\t\t\t");
							scanf("%s",bkno);
					} 
						system("cls");
						printf("\t\t---------------收银台---------------\n\n");
						printf("\n\n\t\t\t 总金额是:%8.2f\n\n",tpr);
						printf("\n\t\t实收金额：\t");
						scanf("%f",&men);
						printf("\n\t\t会员请输入会员编号\n\n\t\t非会员输入000结账\t");
						scanf("%s",vino);					
						if(strcmp(vino,"000")!=0)
						{
								for(j=0;j<TotalVip;j++)
									if(strcmp(vino,vip[j].vno)==0) break;
								if(j<TotalVip)
							{
								if(vip[j].vlevel==1)
								{
									printf("\n\t\t您是本店高级会员，将享受7折优惠");
									m=men-0.7*tpr;
									printf("\n\n\t\t找零：%8.2f\n\n\t\t\t谢谢惠顾！",m);
								}	
								else
								{
									printf("\n\t\t您是本店普通会员，将享受8折优惠");	
									m=men-0.8*tpr;
									printf("\n\n\t\t找零：%8.2f\n\n\t\t\t谢谢惠顾！",m);
								}	
							}	
							else
							{
								printf("\n\t\t对不起，您不是本店会员，已经为您结账\n");	
								m=men-tpr;
								printf("\n\n\t\t找零：%8.2f\n\n\t\t\t谢谢惠顾！",m);
							}
						}
						else
						{
							m=men-tpr;
							printf("\n\n\t\t找零：%8.2f\n\n\t\t\t谢谢惠顾！",m);
						}
						
					
}	

Deletebook()
{  char bkno[10]; int i,k;
  for(k=0;;k++)
  {
  	
   system("cls");
   	printf("\n\t\t----------------书店书籍删除系统----------------\t");
 	printf("\n\t\t\t请输入要删除书籍的书号\n\t\t\t退出请按000\t");  scanf("%s",bkno);
 	 if(strcmp(bkno,"000")==0) break;
    	 for(i=0;i<TotalBook;i++)
     	{ if(strcmp(bkno,bk[i].isbn)==0)  break;}
      	if(i<TotalBook) { for(;i<TotalBook+1;i++)
        	 {   strcpy(bk[i].isbn,bk[i+1].isbn);
          	   strcpy(bk[i].bkname,bk[i+1].bkname);
          	   strcpy(bk[i].author,bk[i+1].author);
          	   bk[i].price=bk[i+1].price;
           	  bk[i].num=bk[i+1].num;
             
         	}
                  
     	 } TotalBook--;
     	printf("\t\t\t删除成功!\n");getch();
 }
}

Deletevip()
{
	 char vino[10]; int i,k;
  for(k=0;;k++)
  {
  	
   system("cls");
   	printf("\n\t\t----------------书店会员删除系统----------------\t");
 	printf("\n\t\t\t请输入要删除会员的编号\n\t\t\t退出请按000\t");  scanf("%s",vino);
 	 if(strcmp(vino,"000")==0) break;
    	 for(i=0;i<TotalVip;i++)
     	{ if(strcmp(vino,vip[i].vno)==0)  break;}
      		if(i<TotalVip) { for(;i<TotalVip+1;i++)
        	 {   strcpy(vip[i].vno,vip[i+1].vno);
          	   strcpy(vip[i].vname,vip[i+1].vname);
          	   vip[i].vlevel=vip[i+1].vlevel;
         	}
                  
     	 } TotalVip--;
     	printf("\t\t\t删除成功!\n");getch();
 }
}				

main()
{
	int sel;
 	ReadData();
 	RData();
 	do
	{system("cls");sel=showsel();
 		switch(sel)
 		{	case 0: break;
 	 		case 1: system("cls");booklist();getch();break;
 	 		case 2: system("cls");bookin();getch();break;
 	 		case 3: system("cls");booksale();getch();break;
 	 		case 4: system("cls");vipin();getch();break;
 	 		case 5: system("cls");viplist();getch();break;
 	 		case 6: system("cls");Deletebook();getch();break;
 	 		case 7: system("cls");Deletevip();getch();break;
 	 		case 8: system("cls");Find();getch();break;
		}
 	}
	 while(sel);
	 SaveData();
	 SData(); 
	 printf("\n   \t已经自动为您保存操作！感谢使用！");
	 getch();
 }

