#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *ptr; char rando[20],tempo[5];
char login(char); void adminfunc(); int Calcbalance(char); void balanceupd(char,int,int); void revfunc();
int flag,cou=-1; //flag here identity of admin or user (1 or 2)

struct reci{
	int pri[10],quan[10];
	char name[10][25];
};
int main()
{  
int feedback, balance, amount=0, newb=0;
struct reci r;
char ch1,yesorno,feedname[20],review[200],reci,itemrev;
 printf("Enter \'a\' to login as admin, any other key to login as user\n");
    ch1= getch();
    char id=login(ch1);
	if(ch1=='a')
	adminfunc();  //not passing id since all admins work with the same data
	else if(id=='0') 
	printf("\nFATAL ERROR");
	else 
	balance=Calcbalance(id); 
	
	char choice, subChoice, cakeChoice, extraChoice, breadChoice, dealChoice;
    int quantity , biscuitQuantity, breadQuantity,mytot=0;
    flag = 1;  

	int extrasQuantity,bread_amount=0, extras_amount=0, cake_amount=0, biscuit_amount=0,deal_amount=0;
	char customerReview[100] ;

printf("\nWelcome to the Heavenly Bites Bakery\n");
    while (flag) {
    	amount+=bread_amount + extras_amount + cake_amount + biscuit_amount+deal_amount;
    	 bread_amount=0; extras_amount=0; cake_amount=0; biscuit_amount=0,deal_amount=0;
        printf("\n\nEnter 1 to 7 to navigate the shop.\n");
        printf("1. Menu\n");
        printf("2. Deals\n");
        printf("3. View Balance\n");
        printf("4. Place Review\n");
        printf("5. Help\n");
        printf("6. Finalize\n");
        printf("7. View reviews\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("\nMenu:\n");
                printf("1. Cakes\n");
                printf("2. Bakery Biscuits\n");
                printf("3. Bread\n");
                printf("4. Extras\n");
                printf("Enter your choice: ");
                scanf(" %c", &subChoice);

                switch (subChoice) {
                    case '1':
                    	cou+=1;
                        printf("\nCakes Menu:\n");
                        printf("1. Chocolate Cake (Rs 450) per pound\n");
                        printf("2. Pineapple Cake (Rs 300) per pound\n");
                        printf("3. Strawberry Cake (Rs 250) per pound\n");
                        printf("4. Red Velvet Cake (Rs 500) per pound\n");
                        printf("5. Coffee Cake (Rs 400) per pound\n");
                        printf("Enter your choice: ");
                        scanf(" %c", &cakeChoice);
                        printf("\nEnter quantity in pounds (1,2,4 etc) ");
                        scanf("%d", &quantity);


                        switch (cakeChoice) {
                            case '1':
                            	cake_amount = 450*quantity;
                                printf("%d pound Chocolate Cake order Added to Cart. Price: Rs %d\n", quantity ,cake_amount);
                                strcpy(r.name[cou],"Pound(s) Chocolate Cake");  r.pri[cou]=cake_amount; r.quan[cou]=quantity;
                                
                                break;
                            case '2':
                            	cake_amount = 300*quantity;
                                printf("%d pound Pineapple Cake order Added to Cart. Price: Rs %d\n", quantity, cake_amount);
                                strcpy(r.name[cou],"Pound(s) Pineapple Cake"); r.pri[cou]=cake_amount; r.quan[cou]=quantity;
                                break;
                            case '3':
                            	cake_amount = 250*quantity;
                                printf("%d pound Strawberry Cake order Added to Cart. Price: Rs %d\n", quantity, cake_amount);
                              strcpy(r.name[cou],"Pound(s) Strawberry Cake"); r.pri[cou]=cake_amount; r.quan[cou]=quantity;
                                break;
                            case '4':
                            	cake_amount = 500*quantity;
                                printf("%d pound Red Velvet Cake order Added to Cart. Price: Rs %d\n", quantity, cake_amount);
                                strcpy(r.name[cou],"Pound(s) Red Velvet Cake"); r.pri[cou]=cake_amount; r.quan[cou]=quantity;
                                break;
                            case '5':
                            	cake_amount = 400*quantity;
                                printf("%d pound Coffee Cake order Added to Cart. Price: Rs %d\n", quantity, cake_amount);
                               strcpy(r.name[cou],"Pound(s) Coffee Cake");  r.pri[cou]=cake_amount; r.quan[cou]=quantity;
                                break;
                            default:
                                printf("Invalid choice\n"); cou-=1;
                        }
                       
                        break;

                    case '2':
                    	cou+=1;
                        printf("\n Bakery Biscuits Menu:\n");
                        printf("\nprice of Biscuits is 300 per kg\n");
                        printf("Enter quantity in kg (1,2,3 etc): ");
                        scanf("%d", &biscuitQuantity);
                        biscuit_amount =  300 * biscuitQuantity;
                        printf("%d kg Biscuits order Added to Cart. Price: Rs %d\n", biscuitQuantity, biscuit_amount);
                       strcpy(r.name[cou],"Kg Biscuits"); r.pri[cou]=biscuit_amount; r.quan[cou]=biscuitQuantity;
                        break;

                    case '3':
                    	cou+=1;
                        printf("\nBread Menu:\n");
                        printf("1. Large Bread\n");
                        printf("2. Small Bread\n");
                        printf("Enter your choice: ");
                        scanf(" %c", &breadChoice);

                        if (breadChoice == '1' || breadChoice == '2') {
                            printf("\nEnter quantity (1 to 10): ");
                            scanf("%d", &breadQuantity);
                            
                            switch (breadChoice) {
                                case '1':
                                	bread_amount =  100 * breadQuantity;
                                    printf("%d Large Bread order Added to Cart. Price: Rs %d\n", breadQuantity, bread_amount);
                                   strcpy(r.name[cou],"Large Bread"); r.pri[cou]=bread_amount; r.quan[cou]=breadQuantity;
                                    break;
                                case '2':
                                	bread_amount =  60 * breadQuantity;
                                    printf("%d Small Bread order Added to Cart. Price: Rs %d\n", breadQuantity, bread_amount);
                                  strcpy(r.name[cou],"Small Bread"); r.pri[cou]=bread_amount; r.quan[cou]=breadQuantity;
                                    break;
                                default:
                                    printf("Invalid choice\n"); cou-=1;
                            }
                            
                        } else {
                            printf("Invalid choice\n");
                        }
                        break;

                    case '4':
                    	cou+=1;
                        printf("\nExtras Menu:\n");
                        printf("1. Water (Rs 100)\n");
                        printf("2. crisps (Rs 50 per pack) \n");
                        printf("3. balloons (Rs 100 per packet) \n");
                        printf("4. nimco (Rs 100 per packet)");
                        printf("Enter your choice: ");
                        scanf(" %c", &extraChoice);
                        
                        printf("Enter quantity: ");
                        scanf("%d", &extrasQuantity);
                        
                          switch (extraChoice) {
                                case '1':
                                	extras_amount =  100 * extrasQuantity;
                                    printf("water order Added to Cart. Price: Rs %d\n" , extras_amount);
                                   strcpy(r.name[cou],"water"); r.pri[cou]=extras_amount; r.quan[cou]=extrasQuantity;
                                    break;
                                case '2':
                                	extras_amount =  50 * extrasQuantity;
                                    printf("%d crisps order Added to Cart. Price: Rs %d\n", extrasQuantity, extras_amount);
                                  strcpy(r.name[cou],"crips"); r.pri[cou]=extras_amount; r.quan[cou]=extrasQuantity;
                                    break;
                                case '3':
                                	extras_amount =  100 * extrasQuantity;
                                    printf("%d balloon packets order Added to Cart. Price: Rs %d\n", extrasQuantity, extras_amount);
                                    strcpy(r.name[cou],"balloon packets");  r.pri[cou]=extras_amount; r.quan[cou]=extrasQuantity;
                                    break;
                                case '4':
                                	extras_amount =  100 * extrasQuantity;
                                    printf("%d nimco packets order Added to Cart. Price: Rs %d\n", extrasQuantity, extras_amount);
                                  strcpy(r.name[cou],"nimco packets");  r.pri[cou]=extras_amount; r.quan[cou]=extrasQuantity;
                                    break;
                                default:
                                    printf("Invalid choice\n"); cou-=1;
                            }
                        break;

                    default:
                        printf("Invalid choice\n");
                }
                break;

            case '2':
            	cou+=1;
                printf("\nDeals:\n");
                printf("1. Birthday Deal: Buy two pound chocolate cake \n and two packets of balloon in just Rs 1000 \n\n");
                printf("2. Heavenly Bites Special Offer: Buy pineapple three pound cake  \n and get 1 kg biscuits free \n\n");
                printf("3. Crumbly Delights: Buy two kg biscuits \n  and get 1 packet of nimco free \n\n");
                printf("4. Cake Couture: Buy 1 pound chocolate cake \n  and 1 pound pineapple cake in just Rs 650 \n\n");
                printf("Enter the Choice: ");
                scanf(" %c",&dealChoice);
            
                 switch (dealChoice) {
                                case '1':
                                	deal_amount = 1000;
                                    printf("Birthday Deal order Added to Cart. Price: Rs %d\n" , deal_amount);
                                   strcpy(r.name[cou],"Birthday Deal");  r.pri[cou]=deal_amount; r.quan[cou]=1;
                                    break;
                                case '2':
                                	deal_amount = 900;
                                    printf("Heavenly Bites Special Offer order Added to Cart. Price: Rs %d\n",deal_amount);
                                  strcpy(r.name[cou],"Special Offer"); r.pri[cou]=deal_amount; r.quan[cou]=1;
                                    break;
                                case '3':
                                	deal_amount = 600;
                                    printf("Crumbly Delights order Added to Cart. Price: Rs %d\n",deal_amount);
                                    strcpy(r.name[cou],"Crumbly Delights"); r.pri[cou]=deal_amount; r.quan[cou]=1;
                                    break;
                                case '4':
                                	deal_amount = 650;
                                    printf(" Cake Courture order Added to Cart. Price: Rs %d\n",deal_amount);
                                    strcpy(r.name[cou],"Cake Courture"); r.pri[cou]=deal_amount; r.quan[cou]=1;
                                    break;
                                default:
                                    printf("Invalid choice\n"); cou-=1;
                            }
                break;

            case '3':
                Calcbalance(id);
                break;

            case '4':
            review_again:
                printf("\nPlace Review:\n");
                printf("Enter the name you want to appear as: ");   /*this ensure anonymousity so user does not 
				                                                     feel pressured to give good a review*/
				fflush(stdin);                                                     
                scanf("%[^\n]",&feedname);
                printf("\n\n\t\tIndex of reviews\n");
                printf("1. Chocolate Cake\n");
                printf("2. Pineapple Cake\n");
                printf("3. Strawberry Cake\n");
                printf("4. Red Velvet Cake\n");
                printf("5. Coffee Cake\n");
                printf("6. Biscuits\n");
                printf("7. Large Bread\n");
                printf("8. Small Bread\n");
                printf("9. Water \n");
                printf("10. Nimko \n");
                printf("11. Balloons\n");
                printf("12. Bakery Management\n");
                printf("13. Delivery service\n");
                printf("14. Other\n");

                printf("Enter what you are reviewing: ");  
                scanf(" %c",&itemrev);
                if(itemrev>'14' || itemrev<'1')
                {
                	printf("Invalid choice.");
                	goto review_again;
				}
                printf("Enter the review (max 200 words)\n");
                fflush(stdin);
                fgets(review, sizeof(review), stdin);
                printf("\nReview placed successfully.\n");
                ptr=fopen("myrev.txt","a+");
                if (ptr == NULL)
				 {
        printf("Error opening the file.\n");
        return;
                 }
                 
fprintf(ptr,"\n** %c\n",itemrev);
fprintf(ptr,"%s says\n",feedname);
fprintf(ptr,"%s^\n",review);
fclose(ptr); 
               
                break;

            case '5':
                printf("\n\t\t\tHELP\n");
                printf("\t\t *************** ABOUT US *************** \n\n Welcome to our bakery, where passion meets pastry perfection. Nestled in the heart of Karachi, our shop is a delightful\n");
				 printf("haven for those with a sweet tooth and a penchant for artisanal treats. With a commitment to quality ingredients and time-honored recipes, we strive to create an array of \n");
				 printf("delectable delights that tantalize the taste buds. From flaky croissants to rich, velvety cakes, each creation is crafted with care and a dash of creativity. Our cozy atmosphere\n");
				  printf("invites you to savor the aroma of freshly baked goods while enjoying a moment of indulgence. Join us on a culinary journey where every bite tells a story of dedication to the art\n");
				   printf("of baking.\n\n\t\t*************** General Info *************** \n\n");
    
                printf("Contact Us for any queries:\nCell# +92 3318406464 \nTel# 021 36350072 \n\nEmail:\nk232008@nu.edu.pk \nk232003@nu.edu.pk \nk232031@nu.edu.pk");
                printf("\n\nAdress: R3F6+CW7, D.H.A. Phase 4 Defence Housing Authority, Karachi, Karachi City, Sindh 75500");
                printf("\n\nDelivery Updates\n+92 316587328 (phone)\n+92 331456266 (whatsapp only)\n\n");
                break;
            case '6':
            	
            printf("\nAre you sure you want to finalize order? (press 0 to confirm)\n");
            	scanf("%d",&flag);
            	if(!flag)
				{
                printf("\nFinal Order:\n");
                 printf("Your ordered amount : %d Rs\n", amount);
                if (amount>balance)
              {  printf("You are %d Rs short in wallet balance, please have your balance updated by the admins\n",balance - amount);
                exit(1); }
                else
                newb= balance - amount;
                balanceupd(id,newb,amount);
                printf("\nyou have ordered!\n");
                if (quantity > 0){
				}
				printf("Would you answer a quick question before you leave? (y if yes): ");
				scanf(" %c",&yesorno);
				
				if(yesorno=='y'){
			    printf("Enter the name you want to appear as: ");   /*this ensure anonymousity so user does not 
				                                                     feel pressured to give good a feedback*/
                fflush(stdin);  
                scanf("%[^\n]",&feedname);
                printf("how satisfied are you with our customer service (rate out of 100): ");
                scanf("%d",&feedback);
                fflush(stdin);
                if(!(feedback > 0 && feedback < 100))
				{feedback = 100;} //if user does not give proper rating, we assume it to be full
				   ptr=fopen("myusers.txt","a+");
                   if (ptr == NULL) {
                   printf("Error opening the file.\n");
                   return;
                       }
                fprintf(ptr,"%s rated the service %d/100\n",feedname,feedback);
                fclose(ptr);
			    }
                
                printf("Would you like to view receipt? (y if yes): ");
				scanf(" %c",&reci);
				if(reci=='y')
				{
					printf("\n\n*******************************RECEIPT*******************************\n\n");
					printf("\t\t\tHeavenly Bites\n\n");
					for(int i=0;i<=cou;i++)
				{
					printf("\t%-5d %-30s       Price: %-5d\n",r.quan[i],r.name[i],r.pri[i]);
					mytot+= r.pri[i];
				}
				    printf("\n\t\t\t\t TOTAL: %-5d\n",mytot);
					printf("\n\n*********************************************************************\n\n");
				}
				ptr=fopen("myadm.txt","a+");
				fprintf(ptr,"\n*********************************************************************\n");
				for(int i=0;i<=cou;i++)
				{
					fprintf(ptr,"\t%-5d %s\n",r.quan[i],r.name[i]);
				}
                fprintf(ptr,"\n");
                fclose(ptr); 
				
				
                printf("\nExiting the Online Bakery Shop. Thank you for shopping.\nBE back soon!\n");
                }
                break;
                
    case '7':
    revfunc();
	break;            
    default:
    printf("\nInvalid input, expect errors.\n");
        }
    }
	 
	return 0;
}

// all other functions start here

//the login function
char login(char ch1)   
{
	struct creds{
	
 char uname[20], pass[20], ans[20], ans2[20];
}cr;

 char iden;
 

    for(;;){
    iden='0';
    flag=1;
    if(ch1=='a')
    {
printf("\nLogin as admin\n");
    ptr=fopen("myadm.txt","r+"); }
    else
    {
printf("\nLogin as user\n");
    ptr=fopen("myusers.txt","r+"); }
   
if (ptr == NULL) {
        printf("Error opening the file.\n");
        return '0';
    }
       
        while(flag)
        {
          fscanf(ptr,"%s",rando);
          if(strcmp(rando,"-USER/PASS-")==0)
          break;
}
   

    printf("Enter the username: ");
    gets(cr.uname);
    printf("Enter the pasword: ");
    gets(cr.pass);
 
 while (flag){
    fscanf(ptr,"%s %s",cr.ans,cr.ans2);
    iden++;
    if(strcmp(cr.ans,cr.uname)==0 && strcmp(cr.ans2,cr.pass)==0){
    printf("\n\n\t\tWelcome %s!\n\n",cr.uname);
    fclose(ptr);
    return iden;
    }
    else if(strcmp(cr.ans,"***")==0 && strcmp(cr.ans2,"***")==0){

    printf("Invalid username or password. try again\n");
    fclose(ptr);
    flag=0;
         }
    }
  }
    return '0';
}
 //the admin function
void adminfunc() 
{  char cho,feed;
while(1){

printf("\n\nWhat do you want to do.\n");
        printf("1. View profits\n");
        printf("2. View reviews\n");
        printf("3. View Feedbacks\n");
        printf("Or enter any other key to Exit\n");
        printf("Enter your choice: ");
        cho=getche();

if(cho=='1'){
char tprof[10];
ptr=fopen("myadm.txt","r+");
if (ptr == NULL) {
        printf("Error opening the file.\n");
        return;
    }
        while(1)
        {
          fscanf(ptr,"%s",rando);
          if(strcmp(rando,"-PROFIT_EARNED-")==0)
          break;
}
fscanf(ptr,"%s",tprof);
printf("\nProfit accummilated so far: %s Rs",tprof);
fclose(ptr);
printf("\n\nPress any key to continue..\n");
            getch();
}

else if(cho=='2'){
revfunc();
}
else if(cho=='3'){
	printf("\n");
ptr=fopen("myusers.txt","r+");
        while(1)
        {
          fscanf(ptr,"%s",rando);
          if(strcmp(rando,"-Feedback-")==0)
          break;
}
while(!feof(ptr)){
	feed=fgetc(ptr);
putchar(feed);
}
fclose(ptr); 
printf("\n\nPress any key to continue..\n");
            getch();
}
else
exit(1);
}

}
// balance updater after order has been finalized
void balanceupd(char id, int newb,int amount) {  
    char bal[9], index = '0', newb2[9];
char prof[13];
    sprintf(newb2, "%d", newb);  //using function that converts int to string

    ptr = fopen("myusers.txt", "r+");

    if (ptr == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (1) {
        fscanf(ptr, "%s", rando);
        if (strcmp(rando, "-WalletRs-") == 0) {
            break;
        }
    }

    while (index != id+1) { //id+1 because we move back after finding the string
    index++;
       
        if (index == id+1)
{
            fseek(ptr, -strlen(bal), SEEK_CUR); // Moving pointer back to the beginning of the balance
            fprintf(ptr, "%-*s", (int)strlen(newb2), newb2); // Writing the new balance with proper width (in case the new balance differs in length)
            break;
        }
else
        fscanf(ptr, "%s", bal);
    }
   
    fclose(ptr);
ptr=fopen("myadm.txt","r+");
   
        while(1)
        {
          fscanf(ptr,"%s",rando);
          if(strcmp(rando,"-PROFIT_EARNED-")==0)
          break;
}

          fscanf(ptr,"%s",prof);
int newprof=atoi(prof) +amount;  //using 'ascii to int' function of stdlib

fseek(ptr, -strlen(prof), SEEK_CUR);  //moving cursor back
fprintf(ptr,"%d",newprof);
fclose(ptr);
}

//balance viewing function
int Calcbalance(char id) 
{
int balance;
char bal[9],index='0';

printf(" Your id no: %c \t\t\t",id);

ptr=fopen("myusers.txt","r+");
       
        while(1)
        {
          fscanf(ptr,"%s",rando);
          if(strcmp(rando,"-WalletRs-")==0)
          break;
}
while(index!=id)
        {
        index++;
          fscanf(ptr,"%s",bal);
}
balance=atoi(bal);  //using 'ascii to int' function of stdlib
printf("Current Wallet Balance: %d Rs",balance);
fclose(ptr);
return balance;
}
void revfunc()  //the review function
{
	char line[200];
	int revind,currentRe=0,currentRat;;
                rev_again:
                printf("\n\n\t\tIndex of reviews\n");
                printf("1. Chocolate Cake\n");
                printf("2. Pineapple Cake\n");
                printf("3. Strawberry Cake\n");
                printf("4. Red Velvet Cake\n");
                printf("5. Coffee Cake\n");
                printf("6. Biscuits\n");
                printf("7. Large Bread\n");
                printf("8. Small Bread\n");
                printf("9. Water \n");
                printf("10. Nimko \n");
                printf("11. Balloons\n");
                printf("12. Bakery Management\n");
                printf("13. Delivery service\n");
                printf("14. Other\n");
				printf("Enter the review you want to see: ");
				scanf(" %d",&revind);
				if(revind>14 || revind<1)
                {
                	printf("Invalid choice.");
                	goto rev_again;
				}
				
ptr=fopen("myrev.txt","r+");
if (ptr == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    printf("\n"); 
         while (fgets(line,sizeof(line),ptr)!=0) 
		 {
		 	
            if (sscanf(line,"** %d", &currentRat)==1)
		  { //sscanf scans strings
            if (currentRat==revind) 
			{
                currentRe=1;
                continue;
            } 
			else currentRe=0;
          }
        if (currentRe==1&&line[0]!='^') 
            printf("%s",line);
        else if(currentRe==1) printf("\n");   
         }
    fclose(ptr);
    
				skip:	
printf("\n\nPress any key to continue..\n");
            getch();
}



