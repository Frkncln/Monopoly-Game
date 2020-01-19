#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define PROPERTY_COUNT 12
typedef enum player_type{none=-1,cap,car
}player_type; 

typedef enum blocktype{start,property,tax,punish,fortune
}blocktype; 

typedef struct player{
player_type type;
int current_block_id;
int owned_block_ids[PROPERTY_COUNT];
int account;//parayý tutacak
int turn_to_wait;
char *name;
	
}player;

typedef struct block{
	int block_id;
	char *name;
	int price;
	int rent;
	int rent1;
	int rent2;
	int rent3;
	int house_price;
	int house_count;
	blocktype type;
	player owner;
	struct block *next;
}block ;


void init_the_board(block *board){
  	int i=0;
	//start
	board->block_id=i;
	board->name="Start";
	board->price=0;
	board->rent=0;
	board->rent1=0;
	board->rent2=0;
	board->rent3=0;
	board->house_price=0;
	board->type=0;
	board->house_count=0;
	board->owner.type=none;
  	block *iter;//linked list içinde dolasmak icin iter tanýmladýk
  	iter=board;
  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	//esenyurt
	iter->block_id=i;
  	iter->name="Esenyurt";
	iter->price=16000;
	iter->rent=800;
	iter->rent1=4000;
	iter->rent2=9000;
	iter->rent3=25000;
	iter->house_price=10000;
	iter->type=1;
	iter->house_count=0;
	iter->owner.type=none;
  iter->next=(block*)malloc(sizeof(block));
	iter=iter->next;
	i++;
  //car park
	iter->block_id=i;
  	iter->name="Car Park";
	iter->price=0;
	iter->rent=1500;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=2;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	//fortune card  id 3
	iter->block_id=i;
	iter->name="FortuneCard";
	iter->price=0;
	iter->rent=0;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=4;
  	iter->house_count=0;
	iter->owner.type=none;

	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//tuzla
  	iter->block_id=i;
	iter->name="Tuzla";
	iter->price=16400;
	iter->rent=850;
	iter->rent1=4250;
	iter->rent2=9500;
	iter->rent3=26000;
	iter->house_price=12000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//arnavutköy
  	iter->block_id=i;
	iter->name="Arnavutkoy";
	iter->price=17000;
	iter->rent=875;
	iter->rent1=4500;
	iter->rent2=10000;
	iter->rent3=28000;
	iter->house_price=12000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//wait 2 turn    block5
  	iter->block_id=i;
	iter->name="Wait 2turn";
	iter->price=0;
	iter->rent=2;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=3;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//Çatalca
  	iter->block_id=i;
	iter->name="Catalca";
	iter->price=20000;
	iter->rent=1000;
	iter->rent1=5000;
	iter->rent2=12000;
	iter->rent3=30000;
	iter->house_price=13000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//Beykoz
  	iter->block_id=i;
	iter->name="Beykoz";
	iter->price=23000;
	iter->rent=1100;
	iter->rent1=5500;
	iter->rent2=12500;
	iter->rent3=33000;
	iter->house_price=13000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  
  	//fortune card  id 9
	iter->block_id=i;
	iter->name="FortuneCard";
	iter->price=0;
	iter->rent=0;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=4;
  	iter->house_count=0;
	iter->owner.type=none;

	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	
	 //Car Fix
	iter->block_id=i;
	iter->name="Car Fix";
	iter->price=0;
	iter->rent=1750;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=2;
  	iter->house_count=0;
	iter->owner.type=none;

 	 iter->next=(block*)malloc(sizeof(block));
 	 iter=iter->next;
  	i++;
 	//Maltepe
  	iter->block_id=i;
	iter->name="Maltepe";
	iter->price=30000;
	iter->rent=1350;
	iter->rent1=7000;
	iter->rent2=15000;
	iter->rent3=40000;
	iter->house_price=15000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

	iter->next=(block*)malloc(sizeof(block));
	iter=iter->next;
	i++;
	 //Bils
	iter->block_id=i;
	iter->name="Bills";
	iter->price=0;
	iter->rent=2000;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=2;
  	iter->house_count=0;
	iter->owner.type=none;
  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	//Þiþli
	iter->block_id=i;
  	iter->name="Sisli";
	iter->price=33000;
	iter->rent=1500;
	iter->rent1=8000;
	iter->rent2=16000;
	iter->rent3=42000;
	iter->house_price=16000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	 //oil
  	iter->block_id=i;
  	iter->name="Oil";
	iter->price=0;
	iter->rent=2250;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=2;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//fortune card  id 15
	iter->block_id=i;
	iter->name="FortuneCard";
	iter->price=0;
	iter->rent=0;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=4;
  	iter->house_count=0;
	iter->owner.type=none;

	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	//Ataþehir
  	iter->block_id=i;
	iter->name="Atasehir";
	iter->price=35000;
	iter->rent=1600;
	iter->rent1=8500;
	iter->rent2=17000;
	iter->rent3=45000;
	iter->house_price=17000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	//Sarýyer
 	iter->block_id=i;
  	iter->name="Sariyer";
	iter->price=40000;
	iter->rent=1750;
	iter->rent1=9500;
	iter->rent2=19000;
	iter->rent3=48000;
	iter->house_price=19000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
 	//wait 1 turn    block5
 	iter->block_id=i;	
  	iter->name="Wait 1turn";
	iter->price=0;
	iter->rent=1;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=3;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
 	 i++;
	//Kadýköy
	iter->block_id=i;
  	iter->name="Kadikoy";
	iter->price=43000;
	iter->rent=1900;
	iter->rent1=11000;
	iter->rent2=21500;
	iter->rent3=55000;
	iter->house_price=23000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	//BEÞÝKTAÞ
	iter->block_id=i;
  	iter->name="Besiktas";
	iter->price=60000;
	iter->rent=2500;
	iter->rent1=15000;
	iter->rent2=28000;
	iter->rent3=60000;
	iter->house_price=30000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  
  	//fortune card  id 21
	iter->block_id=i;
	iter->name="FortuneCard";
	iter->price=0;
	iter->rent=0;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=4;
  	iter->house_count=0;
	iter->owner.type=none;

	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
  	
  	//Vacation
 	iter->block_id=i;	
  	iter->name="Vacation";
	iter->price=0;
	iter->rent=5000;
	iter->rent1=0;
	iter->rent2=0;
	iter->rent3=0;
	iter->house_price=0;
	iter->type=2;
  	iter->house_count=0;
	iter->owner.type=none;

  	iter->next=(block*)malloc(sizeof(block));
  	iter=iter->next;
  	i++;
	//Bebek
  	iter->block_id=i;
	iter->name="Bebek";
	iter->price=70000;
	iter->rent=3500;
	iter->rent1=20000;
	iter->rent2=35500;
	iter->rent3=64000;
	iter->house_price=35000;
	iter->type=1;
  	iter->house_count=0;
	iter->owner.type=none;

}

void fit_the_board(block *board){//duz cizgilerin alt alta fitlemeye calistik
int i;
	printf(" ");
	
	int namelength=strlen(board->name);
	int nextspaces=11-namelength;
	  printf("%s",board->name);
	for(i=0;i<nextspaces;i++){
	  printf(" ");
	}
printf("|");
}

int roll_dice(){
	int i=rand()%6+1;
    return i;
}


void show_board(block *board,player player_one,
player player_two){
	int i,j,l=23,k=7;
	int t,h;
	
	block *temp=board;
    temp=(block*)malloc(sizeof(block));
    temp=board;
	
	for(i=0;i<92;i++){
		printf("-");
	}
	printf("\n");
//ilk üçlü satýr*********************
	//1
  	printf("|");
	for(i=0;i<7;i++){
    fit_the_board(board);
    board=board->next;
	}
	printf("\n");
	
    
	board=temp;
	//2.satýr
	for(i=0;i<7;i++){
    
    	if(i!=0&&i!=2&&i!=6&&i!=3){
			
			
			printf("|  %d     ",board->price);
			board=board->next;
			
    	}
    
		if(i==0 ){
			printf("|            ");
			board=board->next;
		}
		if(i==3){
			printf("|            ");
			board=board->next;
		}
		if(i==6){
			printf("|            |");
		
		}
		
	
    	if(i==2){
	      	printf("|  %d      ",board->rent);
			board=board->next;
		}
	
	}
	printf("\n");

	//3.satýr
	printf("|");
	for(i=0;i<7;i++){
	  
    	if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
			printf("  %s %s   |",player_one.name,player_two.name);
		}
   		if(i==player_one.current_block_id &&i!=player_two.current_block_id){
		printf("  %s       |",player_one.name);
    	}
   		if(i==player_two.current_block_id &&i!=player_one.current_block_id){
		printf("  %s       |",player_two.name);
    	}

		if(i==6 && i!=player_one.current_block_id && i!=player_two.current_block_id){
			printf("            |");//6 de kimse yokken
		}
		if(i!=6&& i!=player_one.current_block_id && i!=player_two.current_block_id){
			printf("            |");//6in dýþýndakilerde kimse yokken
		}
	}
	printf("\n");
	for(i=0;i<92;i++){
		printf("-");
	}
		printf("\n");
		
//		orta satýrlar	k=7 l=23 **************************
		board=temp;
    for(i=0;i<5;i++){
	
		for(j=0;j<3;j++){//5 tane karþýlýklý 3 satýrlý blok olacak
		
	      if(j==0){//ilk satýrý 
	        printf("|");
	        for(h=0;h<l;h++){
	        	board=board->next;
				}
	        fit_the_board(board);
	        board=temp;
	        for(t=0;t<64;t++){//orta ara boþluk
	          printf(" ");
	        }
	        printf("|");
	        for(h=0;h<k;h++){
	        	board=board->next;
			}
			fit_the_board(board);
			board=temp;
	        printf("\n");
	      }
	      
		if(j==1){//ikinci satýr fiyatlar
	      
	    	if(k==9){
				printf("|            |");
		        board=temp;
		        for(t=0;t<64;t++){
		          printf(" ");
		        }
		        printf("|            |\n");
		        board=temp;
	        }
	      if(k==8){
	        	 for(h=0;h<l;h++){
		        	board=board->next;
				  }
				
		       printf("|   %d$    |",board->rent);
		        board=temp;
		        for(t=0;t<64;t++){
		          printf(" ");
		        }
		        
		        for(h=0;h<k;h++){
		        	board=board->next;
				}
		        
		        printf("|   %d$   |\n",board->price);
		        board=temp;
			  }
        if(k==10){
	        	 for(h=0;h<l;h++){
		        	board=board->next;
				  }
				
		       printf("|  %d$    |",board->price);
		        board=temp;
		        for(t=0;t<64;t++){
		          printf(" ");
		        }
		        
		        for(h=0;h<k;h++){
		        	board=board->next;
				}
		        
		        printf("|   %d$    |\n",board->rent);
		        board=temp;
			  }
        if( k!=8 && k!=10&& k!=9){
			         for(h=0;h<l;h++){
			        	board=board->next;
					  }  
            if(board->type==property){
              printf("|  %d$    |",board->price);
              board=temp;
            }
            if(board->type==tax){
              printf("|  %d$     |",board->rent);
              board=temp;
            }
            	for( t=0;t<64;t++){printf(" ");}
			        for(h=0;h<k;h++){
			        	board=board->next;
					  }
			        printf("|  %d$    |\n",board->price);
			        board=temp;
	        }
		}
		if(j==2){//3.satýr isimler
			
			if ((7+i)==player_one.current_block_id && (7+i)==player_two.current_block_id){//ikiside saðda bir bloktaysa
				printf("|            |");
				for( t=0;t<64;t++){//orta boþluk
		          printf(" ");
		        }
				printf("|  %s %s   |\n",player_one.name,player_two.name);
				}
			else if ((23-i)==player_one.current_block_id && (23-i)==player_two.current_block_id){//ikiside solda bir bloktaysa
				printf("|  %s %s   |",player_one.name,player_two.name);
				for( t=0;t<64;t++){//orta boþluk
		          printf(" ");
		        }
				printf("|            |\n");
				}
			
			//farklý yerlerdelerse ortada
   			else if((7+i)==player_one.current_block_id  && (7+i)!=player_two.current_block_id){//1. tekse saðda
				printf("|            |");
	    		for( t=0;t<64;t++){//orta boþluk
		          printf(" ");
		        }
				printf("|  %s       |\n",player_one.name);
			}
			else if((7+i)!=player_one.current_block_id  && (7+i)==player_two.current_block_id){//2.tekse saðda
				printf("|            |");
	    		for( t=0;t<64;t++){//orta boþluk
		          printf(" ");
		        }
				printf("|  %s       |\n",player_two.name);
			}
			
			
			
			
    		else if ((23-i)==player_one.current_block_id && (23-i)!=player_two.current_block_id){//1.solda tekse
				printf("|  %s       |",player_one.name);
				for( t=0;t<64;t++){//orta boþluk
		          printf(" ");
		        }
				printf("|            |\n");
				}
    		else if ((23-i)!=player_one.current_block_id && (23-i)==player_two.current_block_id){//2.solda tekse
				printf("|  %s       |",player_two.name);
				for( t=0;t<64;t++){//orta boþluk
		          printf(" ");
		        }
				printf("|            |\n");
				}
    		
    	else{//ortada kimse yoksa
	      printf("|            |");
	      for( t=0;t<64;t++){//orta boþluk
	          printf(" ");
	        }
			printf("|            |\n");
			  }
		  } 	
    }
		if(i==4){	
	  	for(i=0;i<92;i++){
				printf("-");
				}
	  }
		if(i<4){		
		printf("--------------");
	  	for( t=0;t<64;t++){
	          printf(" ");//orta bosluk
	        }
	        printf("--------------");
	  }
		
		printf("\n");
		k=k+1;
		l=l-1;
}

//				son 3lü satýrlar******************************
  //1
  board=temp;
 printf("|");
	for(i=18;i>11;i--){
		for(h=0;h<i;h++){
			board=board->next;
		}
	fit_the_board(board);
    board=temp;
	}
	
		printf("\n");
	//2.satýr
	for(i=18;i>11;i--){
	    if(i==18){board=temp;
        for(h=0;h<i;h++){
			board=board->next;
		  }
			printf("|            ");
		}
		if(i==15){board=temp;
        for(h=0;h<i;h++){
			board=board->next;
		  }
			printf("|            ");
		}
		if(i==12){
        board=temp;
			for(h=0;h<i;h++){
			board=board->next;
			}
			printf("| %d       |",board->rent);
			board=temp;
		}
		
		if(i==14){
      board=temp;
			for(h=0;h<i;h++){
			board=board->next;
			}
			printf("| %d       ",board->rent);
			board=temp;
		}
		if(i!=12&&i!=15&&i!=14&&i!=18){
      board=temp;
			for(h=0;h<i;h++){
			board=board->next;
			}
			printf("|   %d    ",board->price);
			board=temp;
		}
	}
	printf("\n");
	//3.satýr kullanýcý isimleri
   printf("|");
 	for(i=0;i<7;i++){
	  
    	if ((18-i)==player_one.current_block_id && (18-i)==player_two.current_block_id)
        {
			printf("  %s %s   |",player_one.name,player_two.name);
		}
   		if((18-i)==player_one.current_block_id  &&(18-i)!=player_two.current_block_id){
		printf("  %s       |",player_one.name);
    	}
   		if((18-i)==player_two.current_block_id &&(18-i)!=player_one.current_block_id){
		printf("  %s       |",player_two.name);
    	}

		if(i==6 && (18-i)!=player_one.current_block_id && (18-i)!=player_two.current_block_id){
			printf("            |");//6 de kimse yokken
		}
		if(i!=6&& (18-i)!=player_one.current_block_id && (18-i)!=player_two.current_block_id){
			printf("            |");//6in dýþýndakilerde kimse yokken
		}
	}
	printf("\n");
	for(i=0;i<92;i++){
			printf("-");
		}
  
}

void show_properties(struct block *board){
int secim=1,i;
	block *temp=board;
    temp=(block*)malloc(sizeof(block));
    temp=board;

printf("\nplease select property to see details:\n");

	for(i=0;i<24;i++){
		if(board->type==1){
		printf("\n%d-%s",board->block_id,board->name);
		}
		board=board->next;
	}
	
	
	
  printf("\nSECIM:");
	scanf("%d",&secim);
	board=temp;
			for (i = 0; i < secim; ++i) {
        	board=board->next;
			}
	if(secim>0 && secim<24 && board->type==property){
		for(i=0;i<21;i++){
				printf("-");
			}
			printf("\n");
			printf("|       ");
			
			
			fit_the_board(board);
			
			printf("\n");
			for(i=0;i<21;i++){
				printf("-");
			}
			
			
		printf("\n");
		printf("|Rent\t %d$\t    |\n",board->rent);
		printf("|Rent 1H %d$\t    |\n",board->rent1);
		printf("|Rent 2H %d$\t    |\n",board->rent2);
		printf("|Rent 3H %d$\t    |\n",board->rent3); 
		for(i=0;i<21;i++){
				printf("-");
			}
			printf("\n");
		printf("|House Price %d$ |\n",board->house_price);

		for(i=0;i<21;i++){
				printf("-");
			}
			printf("\n");
	}
	
	else
	printf("wrong choice");
		
		}
	
int build_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->house_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->house_count+=1;
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}

void show_player_properties(block *board,struct player current_player)
{	
	block *temp;
	temp=(block*)malloc(sizeof(block));
	temp=board;
    int i=0,counter=0,j,k;
        printf("----------------------------------------\n");
        printf("you have property:\n");
            while (current_player.owned_block_ids[i] != -1) {
            	
            	for(j =0;j <current_player.owned_block_ids[i] ; j++) {
                board=board->next;
            	}
            	if(board->type==property){
            	
            	printf("%d - %s\n", board->block_id,board->name);
                counter++;
                }
	            i++;
	        	
				board=temp;
				
        	}
        if (counter == 0){
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            
        }
        printf("\n\n");
	}



void add_to_owned(player* current_player)
{	int i;
    for (i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_block_ids[i]==-1) {
            current_player->owned_block_ids[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        } else
            printf("%d ",current_player->owned_block_ids[i]);
    }
    printf("\n");
}

void copy_owner(player * old, player * new)
{	int i;
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->name= new->name;
    old->current_block_id=new->current_block_id;
    for (i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_block_ids[i]=new->owned_block_ids[i];
    }
}

void buy_property(block *current_block, player *current_player)
{
    if (current_block->price<=current_player->account)
    {
        current_player->account-=current_block->price;
        copy_owner(&current_block->owner,current_player);
        add_to_owned(current_player);

        printf("Congratiulations! You have buy %s.\n",current_block->name);
        printf("You left %d$ in your account.\n",current_player->account);
  }
    else
        printf("You don't have enough money to buy this property!\n");
}



int count_properties(player current_player){
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_block_ids[i]!=-1)
            count++;
    }
    return count;
}

void sell_property(block *board, player* current_player)
{
    int property_id,flag=0,is_owned=-1,i,index,counter=0,j;
    block *temp;
	  temp=(block*)malloc(sizeof(block));
	  temp=board;

            j=count_properties(*current_player);
            if(j!=0){
            show_player_properties(board,*current_player);
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_block_ids[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                    current_player->owned_block_ids[index]=-1;
                    player temp;
                    for(j =0;j <property_id; j++) {
                	board=board->next;
            		}
                    board->owner.type=none;
                    if(board->house_count==0)current_player->account+=board->price/2;
                    if(board->house_count==1)
                    {
                        current_player->account+=(board->price+board->house_price)/2;
                    }
                    if(board->house_count==2)
                    {
                        current_player->account+=(board->price+(2*board->house_price))/2;
                    }
                    if(board->house_count==3)
                    {
                        current_player->account+=(board->price+(3*board->house_price))/2;
                    }
                }
                board=temp;
            }
         }else
        {
            printf("You don't have any property to sell.\n");
        }

}

int insufficient_fund(block *board, player* current_player,int required_money)//para azalmasý durumundaki yapýlcaklar
{
    int selection,flag=1;
    while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0 && flag!=0)
    {
        printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
        printf("1- Sell Property\n");
        printf("2- Show my Properties\n");
        printf("3- Show my Account\n");
        printf("0- Back\n");
        scanf("%d",&selection);
        switch (selection)
        {
            case 1:
                sell_property(board,current_player);
                break;
            case 2:
                show_player_properties(board,*current_player);
                break;
            case 3:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 0:
                flag=0;
                break;
            default:
                printf("You made a wrong selection!\n");
                break;

        }
    }
    return flag;

}

void pay_rent(block *board, player* current_player,player * owner)//kira ödeme
{	block *temp;
	temp=(block*)malloc(sizeof(block));
	temp=board;
  int rent=0,owned_property_count,j;
  for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
    
	  if(board->house_count==0){rent=board->rent;}
    if (board->house_count==1){rent=board->rent1;}
    if (board->house_count==2){rent=board->rent2;}
    if (board->house_count==3){rent=board->rent3;}
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(board,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
        
        board=temp;
}
void house_dialog(block *board, player* current_player)//tekrar üstüne gelirse
{
    int house_flag=1,selection,insuf_flag=1,build_flag=1,j;
    while (house_flag && build_flag&&board->house_count<4) {
    	//for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
        printf("Do you want to build house on %s ?\n",
               board->name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        if (selection == 1) {

            if (current_player->account < board->house_price) {
                while (count_properties(*current_player)!=0 && current_player->account<board->house_price && insuf_flag==1){
                    insuf_flag=insufficient_fund(board,current_player,board->house_price);}
            }
            if (current_player->account >= board->house_price)
                build_flag=build_house(board, current_player);
            else
                house_flag=0;
      } else
            house_flag=0;
    }
    
}

int roll_fortune(){//fortune cardlarý icin random
	
	int i=rand()%5+1;
    return i;
}
void after_dice_menu(block *board, player* current_player, player* other)//oyuncu için zar sonrasý iþlemleri
{	block *temp;
	temp=(block*)malloc(sizeof(block));
	temp=board;
    int selection,insuf_flag=1,j,f,id,i;
    for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
    switch (board->type)
    {
        case property:
            printf("%s has arrived %s \n",current_player->name,board->name);
            if (board->owner.type==none)
            {
                printf("Do you want to buy %s ?\n",board->name);
                printf("1- Yes\n");
                printf("2- No\n");
                scanf("%d",&selection);
                if (selection==1)
                {

                    if (current_player->account<board->price)
                    {
                        while (count_properties(*current_player)!=0 && current_player->account<board->price && insuf_flag==1 )
                        {	
                            insuf_flag=insufficient_fund(board,current_player,board->price);
                        }
                    }
                    buy_property(board,current_player);
                    
                    if (current_player->type==board->owner.type)
                    {	
                        house_dialog(board,current_player);
                    }
				}
			} 
			else{//baskasýnýnsa
                pay_rent(board,current_player,other);
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->name,board->name);
            while (count_properties(*current_player)!=0 && current_player->account<board->rent) {
                insuf_flag = insufficient_fund(board, current_player,
                                               board->price);
                if (insuf_flag == 0 && current_player->account < board->rent)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>board->rent)
                current_player->account=current_player->account-board->rent;
            else{
                current_player->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->name,board->rent);
            current_player->turn_to_wait+=board->rent;
            break;
        case fortune:
        	f=roll_fortune();
        	if(f==1){
        		printf("You win the free house from fortune card\n");
        		board=temp;
        		show_player_properties(board,*current_player);
        		if(count_properties(*current_player)!=0){
        		printf("Select property id to build a free house\n");
        		scanf("%d",&id);
        			for(j =0;j <id; j++) {board=board->next;}
	        		while(board->house_count>2){
	        			printf("that property is full,select another id from yours\n");
	        			scanf("%d",&id);
	        			board=temp;
        				for(j =0;j <id; j++) {board=board->next;}
	        			
					}
						board->house_count+=1;
	        			printf("you build a house for free on %d-%s\n",board->block_id,board->name);
	        		    board=temp;
	        	}
	        	printf("you cant build house boy,you dont have property\n");
	        }
        	if(f==2){
        		i=roll_dice();
        		if(i<4){
        			printf("(fortune card)you move forward 2 block\n");
        			current_player->current_block_id+=2;
				}
        		if(i>3){
        			printf("(fortune card)you move backward 2 block\n");
        			current_player->current_block_id-=2;
				}
        		
			}
			if(f==3){
				printf("(fortune card)Garnishment,Pay 5.000 to the bank.\n");
				current_player->account-=5000;
        	}
			if(f==4){
			printf("(fortune card)Generosity.Give 10.000 to the opponent.\n");
				current_player->account-=10000;	
        		other->account+=10000;	
			}
			if(f==5){
        		printf("(fortune card)Treasure Hunter,Take 20.000 from the bank.\n");
        		current_player->account+=20000;
			}
			break;
			
		case start:
			printf("You are on start,Take 10.000 from the bank.\n");
			current_player->account+=10000;

    }
}
int average_property_price(block *board,player *current_player){
			int i;
			double toplam=0,average;
			for(i=0;i<24;i++){
            		if(board->type==property){
            			toplam+=board->price;}
					board=board->next;
				} average=toplam/12;
				return average; 
}
void turn(block *board, player* current_player, player * other)//oyuncu için menü iþlemleri
{	block *temp;
	temp=(block*)malloc(sizeof(block));
	temp=board;
    int flag=1,next_block,j,dice;
    while(flag)
	{
        int selection;
        printf("1 - Roll the dice\n");
        printf("2 - Show my account\n");
        printf("3 - Show my properties\n");
        printf("4 - Show property deeds\n");
        printf("5 - Buy Property\n");
        printf("6 - Buy house \n");
        printf("7 - Sell property\n");
        printf("Please select an option to continue (%s):\n",current_player->name);
        scanf("%d",&selection);
        switch(selection)
        {
            case 1:
                if (current_player->turn_to_wait==0) {
                	dice=roll_dice();
                	printf("%s rolled dice:%d\n",current_player->name,dice);
                    next_block=(current_player->current_block_id +dice);
                    if (next_block>24){
					          current_player->account+=10000;}
                    current_player->current_block_id = next_block % 24;//oyuncu 23 den fazla id ye sahip olmasýn diye
					        after_dice_menu(board,current_player,other);
					        flag = 0;
                    board=temp;
                } 
				        else
                {
                    printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                    
                }
                break;
            case 2:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 3:
                show_player_properties(board,*current_player);
                board=temp;
                break;
            case 4:
                show_properties(board);
                board=temp;
                break;
            case 5:
            	for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
                if (board->type==property && board->owner.type==-1 && current_player->account>board->price){
                buy_property(board,current_player);
                board=temp;}
                else
                {

                    printf("You don't have permission to buy this block!\n");
                }

                break;
            case 6:
            	for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
                if (current_player->type==board->owner.type) {
                	house_dialog(board,current_player);
                    board=temp;
                }
				        else
                {
                    printf("You don't have permission to build house on this block!\n");
                }
                break;
            case 7:
                sell_property(board,current_player);
                break;
            default:
                printf("Wrong selection!\n");
        }
    }
}

void after_dice_menu_pc(block *board, player* current_player, player* other)//bilgisayar için zar sonrasý iþlemleri
{	block *temp;
	temp=(block*)malloc(sizeof(block));
	temp=board;
    int selection,insuf_flag=1,j,f,id,i,average,max,l=0;
    average=average_property_price(board,current_player);
    board=temp;
    for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
    switch (board->type)//gelinen yerlerin özellkiklerine göre davranýcaz
    {
        case property:
            printf("%s has arrived %s \n",current_player->name,board->name);
            if (board->owner.type==none){//üstüne gelinen boþsa
                if(board->price<average){
                	if (current_player->account<board->price)//parasý yetmiyorsa
                    {
                        return;
                    }
                	buy_property(board,current_player);
                	board=temp;
				}
			else{
					i=roll_dice();
					if(i<4){
						if (current_player->account<board->price)//parasý yetmiyorsa
                    	{
                        return;
                    	}
                    for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
                	buy_property(board,current_player);
                	board=temp;
					}
					if(i>3){//sýra geçsin
						return;
					}
				}
                
                
            
			if (current_player->type==board->owner.type)//kendisininse
                    {	
                    	if(count_properties(*current_player)==PROPERTY_COUNT/3){
                    		i=roll_dice();
                    		if(i<4){
                    			for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
			        			if(board->house_count>2){
			        				printf("pc can't built house because block full\n");
									return;
								}
								else{
								printf("pc built a house\n");
			        			board->house_count+=1;
			        			}
							}
			        		else{
			        			return;}
						}
						else
						return;
            }

                }
			else{//baskasýnýnsa
				board=temp;
				for(j =0;j <current_player->current_block_id ; j++) {board=board->next;}
                pay_rent(board,current_player,other);
            }
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->name,board->name);
            board=temp;
            for(j =0;j <current_player->current_block_id;j++) {board=board->next;}
            f=board->rent;
            while (count_properties(*current_player)!=0 && current_player->account<f) {//parasý yetmiyorsa
                	i=0;
                	max=current_player->owned_block_ids[i];
					while(current_player->owned_block_ids[i]!= -1){
						if(current_player->owned_block_ids[i]>max){
							max=current_player->owned_block_ids[i];
						}
					i++;
					}//max price en büyük id'lidedir
					board=temp;
                for(j =0;j<max; j++) {board=board->next;}
                
					board->owner.type=none;
                    if(board->house_count==0)current_player->account+=board->price/2;
                    if(board->house_count==1)
                    {
                        current_player->account+=(board->price+board->house_price)/2;
                    }
                    if(board->house_count==2)
                    {
                        current_player->account+=(board->price+(2*board->house_price))/2;
                    }
                    if(board->house_count==3)
                    {
                        current_player->account+=(board->price+(3*board->house_price))/2;
                    }
    		}
    		
            if (current_player->account>f)
                current_player->account=current_player->account-f;
            else
            {
                current_player->account=0;
            }
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->name,board->rent);
            current_player->turn_to_wait+=board->rent;
            break;
        case fortune:
        	f=roll_fortune();
        	if(f==1){
        		printf("You win the free house from fortune card\n");
        		board=temp;
        		show_player_properties(board,*current_player);
        		id=current_player->owned_block_ids[l];
        		if(count_properties(*current_player)!=0 && id!=-1){
        			for(j =0;j <id; j++) {board=board->next;}
	        		while(board->house_count>2){
	        			printf("that property is full,select another id from yours\n");
	        			l=l+1;
	        			board=temp;
	        			id=current_player->owned_block_ids[l];
        				for(j =0;j <id; j++) {board=board->next;}
                		}
						board->house_count+=1;
	        			printf("you build a house for free on %d-%s\n",board->block_id,board->name);
	        		    board=temp;
	        		}printf("you dont have a property comp\n");
	    	}
        	if(f==2){
        		i=roll_dice();
        		if(i<4){
        			printf("(fortune card)you move forward 2 block\n");
        			current_player->current_block_id+=2;
        			after_dice_menu_pc(board,current_player,other);
        			
				}
        		if(i>3){
        			printf("(fortune card)you move backward 2 block\n");
        			current_player->current_block_id-=2;
        			after_dice_menu_pc(board,current_player,other);
				}
        	}
			if(f==3){
				printf("(fortune card)Garnishment,Pay 5.000 to the bank.\n");
				current_player->account-=5000;
        	}
			if(f==4){
			printf("(fortune card)Generosity.Give 10.000 to the opponent.\n");
				current_player->account-=10000;	
        		other->account+=10000;	
			}
			if(f==5){
        		printf("(fortune card)Treasure Hunter,Take 20.000 from the bank.\n");
        		current_player->account+=20000;
			}
			break;
			
		case start:
			printf("You are on start,Take 10.000 from the bank.\n");
			current_player->account+=10000;
		}
}

int check_end(player current_player)
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)return 1;
    else return 0;
}

void play_game(block *board, player* player_one, player* player_two)
{	block *temp;//fonksiyonlar arasýnda boardý sýfýrlamak için temp açtýk	
	temp=(block*)malloc(sizeof(block));
	temp=board;
    int is_end=0,r,next_block;
    printf("\nWelcome to Monopoly! %s will roll the dice first.\n",player_one->name);
    while(is_end!=1){
        printf("\n%s :%d$ , %s(computer):%d$\n",player_one->name,player_one->account,player_two->name,player_two->account);
        turn(board,player_one,player_two);
        board=temp;
        show_board(board,*player_one,*player_two);
        board=temp;
        is_end=check_end(*player_one);
        if (is_end==0)
        {
            printf("\n%s :%d$ , %s(computer):%d$\n",player_one->name,player_one->account,player_two->name,player_two->account);
            
			r=roll_dice();
            
            if (player_two->turn_to_wait==0) {
            	printf("Computer rolled the dice: %d\n",r);
                    next_block=(player_two->current_block_id + r);
                    if (next_block>24){
					player_two->account+=10000;}
                    player_two->current_block_id = next_block % 24;
                    board=temp;
                    after_dice_menu_pc(board,player_two,player_one);
                    board=temp;
                }
            else{printf("pc must wait %d turn\n",player_two->turn_to_wait);
					player_two->turn_to_wait-=1;      	
					}
            show_board(board,*player_one,*player_two);
            is_end=check_end(*player_two);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_two->name,player_two->name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_one->name,player_one->name);
	}

}	
int main(){
	block *board;
	board=(block*)malloc(sizeof(block));
	block *temp;//fonksiyonlar arasýnda boardý sýfýrlamak için temp açtýk	
	temp=(block*)malloc(sizeof(block));
	temp=board;
	int i;
	
	srand(time(NULL));
  player player_one,player_two;

    player_one.name="Car";//person
	player_one.type=car;
	player_one.current_block_id=0;
    player_one.turn_to_wait=0;
  	player_one.account=100000;
	player_two.name="Cap";//computer
	player_two.type=cap;
	player_two.current_block_id=0;
    player_two.turn_to_wait=0;
	player_two.account=100000;
	
	for(i=0;i<12;i++){//baþlangýçta kimsenin bloðu yok
  	player_one.owned_block_ids[i]= -1;}
  	for(i=0;i<12;i++){
  	player_two.owned_block_ids[i]= -1;}
	printf("\n\n");
	init_the_board(board);
  	board=temp;
	show_board(board,player_one,player_two);
	board=temp;
	play_game (board,&player_one, &player_two);
	
	return 0;
}
