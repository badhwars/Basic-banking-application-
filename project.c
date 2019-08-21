#include <stdio.h>
#include <string.h>
#define NAME_LENGTH 25
#define ACCOUNT_NUM_START 15990
#define OPEN_BALANCE 0

struct customer{
	int accountNumber;
	char fullName[NAME_LENGTH+1] ;
	double amount;
	int nDeposit;
	int nWithdrawl;
	struct customer *next;
};
	
   
struct customer *head;           // start pointer declaration


//function to create new struct of type customer 
//and allocate memory for it 

struct customer * createNewAccount()
{
    struct customer *nn = (struct customer*) malloc(sizeof(struct customer));
    nn->next=NULL;
    return nn; 
}
//
// test udf only
// no implementaion in main method
//
//struct customer  createNewAccountA()
//{
//	//printf("1\n");
////    struct customer *nn = (struct customer*) malloc(sizeof(struct customer));
////    //	printf("2\n");
////    //nn->next=NULL;
////    //	printf("3\n");
////    return nn; 
//}

/*
counts number of elements in the lonkedlist
used for converting linkedlist to array
for bubble sort 

*/
int linkedListCount(){
int ctr=0;
struct customer * t =head;
while(t){
	ctr++;
	t=t->next;
}	
return ctr;
}


void swap(struct customer *xp, struct customer *yp) 
{ 
    struct customer temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 


char * prepString(char fname[], int n){ // makes sure that every string is of equal length when written to file
	int length=strlen(fname);
	int x=n-length;
	int i;
	char tmp[] =" ";
	for(i=1;i<x;i++){
		strcat(fname,tmp);
		
	}
	return fname;
}
/*
Method Utilisex linkedlistcount() method
to convert linkedlist to array 
thereby sorting it and printing it
using linear sort bubble sort method
*/
 BubbleSortArray(){
 	int n=linkedListCount() ;
 	printf("n%d",n);
	struct customer arr[n];
	struct customer nn ;
	int ctr=0;
	
	struct customer *t =head;
	while(t){
		nn.accountNumber=t->accountNumber;
	//	printf("-----%d\n", nn.accountNumber);
		strcpy(nn.fullName,t->fullName);
	//	nn.fullName=t->fullName;
	  //  printf("----name---%s", nn.fullName);
		nn.amount=t->amount;
	//	printf("--amount---%lf\n", nn.amount);
		nn.nDeposit=t->nDeposit;
		nn.nWithdrawl=t->nWithdrawl;
		arr[ctr]=nn;
		ctr++;
		t=t->next;
		
		  //  printf("----name from array---%d\n", arr[ctr].accountNumber);
	}
	/// bubblesort
	int i, j; 
     for (i = 0; i < n ; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j].accountNumber > arr[j+1].accountNumber) 
              swap(&arr[j], &arr[j+1]); 
    
 	printf("\nAfter sorting the list according to account number  \n\n");
 	printf("---------------------------------------------------------------------------\n");
   	printf("|%-10s %-25s %10s %10s %11s   |\n","Acc. No.","Customer Full Name","Balance","Deposit","Withdrawl");
   		printf("---------------------------------------------------------------------------\n\n");
	   for (i=0; i < n; i++) {
   		printf("|%-10d | %25s | %-10.2f | %-8d | %-8d|\n",arr[i].accountNumber,prepString(arr[i].fullName,NAME_LENGTH+1),arr[i].amount,arr[i].nDeposit,arr[i].nWithdrawl);

		}
		
	printf("---------------------------------------------------------------------------\n");
   
//	return arr;
}


int cmpfunc(const void* a, const void* b) {
    int accN = ((struct customer*)a)->amount;  // Get the price of item 'a'
    int accNB = ((struct customer*)b)->amount;  // Get the price of item ''
    if (accN == accNB) {
    	return 0;
	}
	else if (accN > accNB) {
		return 1;
	}
	else {
		return -1;
	}
}

/*
prints array using in built quicksort method
uses cmpfunc to 
sort array on the basis of balance
*/
qSortPrint(){
 	int n=linkedListCount() ;
 	printf("n%d",n);
	struct customer arr[n];
	struct customer nn ;
	int ctr=0;
	
	struct customer *t =head;
	while(t){
		nn.accountNumber=t->accountNumber;
	//	printf("-----%d\n", nn.accountNumber);
		strcpy(nn.fullName,t->fullName);
	//	nn.fullName=t->fullName;
	  //  printf("----name---%s", nn.fullName);
		nn.amount=t->amount;
	//	printf("--amount---%lf\n", nn.amount);
		nn.nDeposit=t->nDeposit;
		nn.nWithdrawl=t->nWithdrawl;
		arr[ctr]=nn;
		ctr++;
		t=t->next;
		
		  //  printf("----name from array---%d\n", arr[ctr].accountNumber);
	}

//	
   const int size = sizeof(arr)/sizeof(struct customer);
 qsort(arr, size, sizeof(struct customer), cmpfunc);
int i;

    printf("\nAfter sorting the list according to balance:  \n");

     	printf("---------------------------------------------------------------------------\n");
    printf("|%-10s %-25s %10s %10s %11s   |\n","Acc. No.","Customer Full Name","Balance","Deposit","Withdrawl");
    		printf("---------------------------------------------------------------------------\n\n");
   for (i=0; i < n; i++) {
   	printf("|%-10d | %25s | %-10.2f | %-8d | %-8d|\n",arr[i].accountNumber,prepString(arr[i].fullName,NAME_LENGTH+1),arr[i].amount,arr[i].nDeposit,arr[i].nWithdrawl);

}
	printf("---------------------------------------------------------------------------\n\n");

}

  
// A function to implement bubble sort 

  
/* Function to print an array */
//void printArray(struct customer arr[], int size) 
//{ 
//} 

int isEmpty()
{
    return head==NULL;
}

/*
Generates account number
such that there is always a 
difference of two. starts account number from either
1. ACCOUNT_NUM_START DEFINED at TOP if linkedlist is empty
2. 2+last account number in list
*/
int GenerateAccountNumber(){
	int account;
	if(isEmpty()){
		account= ACCOUNT_NUM_START;
		return account;
	}

	struct customer *t=head;
	while(t->next){
		t=t->next;
	}

    account=t->accountNumber;
	return account+2;
}

// writes data to file


writeToFile(FILE *fp,FILE *fp1){
	struct customer * t=head;
	while(t->next){
		 fprintf(fp,"%s",prepString(t->fullName,NAME_LENGTH+1));
       fprintf(fp,"%c",' ');
       fprintf(fp,"%d",t->accountNumber);
        
      
       fprintf(fp,"%c",' ');
        fprintf(fp,"%lf",t->amount);
         fprintf(fp,"%c",' ');
         fprintf(fp,"%d",t->nDeposit);
          fprintf(fp,"%c",' ');
         fprintf(fp,"%d",t->nWithdrawl);
          fprintf(fp,"%s","\n");
          t=t->next;
	}
}

// creates new node and adds to the linkedlist

insertCustomer1(FILE *fp,FILE *fp1){

    //int accountNumber=GenerateAccountNumber();
    struct customer *t=head;
	
	 
	double openBal;
	int nDeposit=0;
	int nWithdrawl=0;
    int accountN=GenerateAccountNumber();
    
    struct customer *nc = createNewAccount();
   
   printf("acc num %d\n",accountN);
   printf("Enter Customer Name\n");
   // optimize for full name
   char fname[NAME_LENGTH+1];
   fflush(stdin);
   gets(fname);
   
   // scanf("%s",fname);
   strcpy(nc->fullName,fname);
   //fp.fputs(nc->fullName);
   printf("Enter opening Balance\n");
 
   scanf("%lf",&openBal);
   while(openBal < OPEN_BALANCE){
   	printf("OPEN balance needs to be atleast %d", OPEN_BALANCE);
	   
   		scanf("%lf",&openBal);
	   }
   //printf("here1");
   nc->amount=openBal;
   nc->accountNumber=accountN;
   nc->nWithdrawl=0;
   nc->nDeposit=0;
	

   
    if(isEmpty()){
    //	printf("empty checked\n");
    	head=nc;

        
    	return 0 ;
	}
	
	else{
		if(nc->accountNumber < t->accountNumber){
			nc->next=head;
			head=nc;
			return;
		}
		while( t->next != NULL){
			if(nc->accountNumber > t->next->accountNumber){
				t=t->next;
			}
			else{
				nc->next=t->next;
				t->next=nc;
				return;
			}
			
		
}
if(nc->accountNumber > t->accountNumber){
	t->next=nc;
}
  fprintf(fp1,"%s",prepString(nc->fullName,NAME_LENGTH+1));
       fprintf(fp1,"%c",' ');
 fprintf(fp1,"%d",nc->accountNumber);
        fprintf(fp1,"%c",' ');
        
        
      
        fprintf(fp1,"%lf",nc->amount);
         fprintf(fp1,"%c",' ');
         fprintf(fp1,"%d",nc->nDeposit);
          fprintf(fp1,"%c",' ');
         fprintf(fp1,"%d",nc->nWithdrawl);
          fprintf(fp1,"%s","\n");
          printf("I rezched here\n");
	}
	

	printf("Insertion successful\n");
	
		 
	}
	// reads the file
readFile(FILE *fp){	
	//printf("%s%20s%10s%12s%14s\n","Account No.","Customer Full Name","Balance","Deposit","Withdrawl");
	char str[NAME_LENGTH+1];
	char str2[NAME_LENGTH+1];
	int tup;
	int acc;
	int nd;
	int nw;
	double amt;

;
 

   // 	printf("inside while\n");
    while( fscanf(fp,"%d%lf%d%d",&tup,&amt,&nd,&nw)!=EOF){
	
    fgets(str,NAME_LENGTH+1,fp);
     
       
        fscanf(fp,"%d%lf%d%d",&tup,&amt,&nd,&nw);
        //printf("-----\n");
       // printf("%lf\n",amt);
       // printf("%s",str);
       // printf("----\n");
        printf("%s%d\t%lf\t%d\t%d\n",str,tup,amt,nd,nw);
    }
        //fseek(fp, 0, SEEK_SET);

}
printFirst(){

struct customer *t=head->next->next;

	printf("%s%20s%10s%12s%14s\n","Account No.","Customer Full Name","Balance","Deposit","Withdrawl");
	
		printf("%7d%25s%14.2f%12d%12d\n",t->accountNumber,t->fullName,t->amount,t->nDeposit,t->nWithdrawl);
		
	
	}


loadFile(FILE *fp){
	fseek(fp, 0, SEEK_SET);
		char str[NAME_LENGTH+1];
	char str2[NAME_LENGTH+1];
	struct customer *t=head;
	struct customer *temp;
	int tup;
	int acc;
	int nd;
	int nw;
	double amt;

//	struct customer *t=head;
int i=0;
    while( fscanf(fp,"%d%lf%d%d",&tup,&amt,&nd,&nw)!=EOF){
    		struct customer *nn=createNewAccount();
	if( fscanf(fp,"%d%lf%d%d",&tup,&amt,&nd,&nw)==EOF){
		return 1; 
	}
    fgets(str,NAME_LENGTH+1,fp);
     strcpy(nn->fullName,str);
      /// printf("-----\n");
     //  printf("str: %s \n",str);
       
        fscanf(fp,"%d%lf%d%d",&tup,&amt,&nd,&nw);
       //  printf("accnu: %d \n",tup);
        //printf("-----\n");
         //printf("deposit: %d \n",nd);
          //printf("with %d \n",nw);
          //printf("bal %lf \n",amt);
       
       nn->accountNumber=tup;
       nn->amount=amt;
       nn->nDeposit=nd;
       nn->nWithdrawl=nw;
     //  strcpy(nn->fullName,str);
//       
       if(isEmpty()){
       head=nn;
      // temp=nn;
      // head=temp;
       	//printf("inside empty\n");
	   }
	   
	   else {
	  // 	printf("--------inside else \n");
	   
	   	nn->next=head;
	   	head=nn;
	   //	nn->next=head;
	   	//head=nn;
	   }
	   

       i=i+1;
     //  readFile(fp);
}
}
search(){
	int fAcc;
	printf("Enter account number to know details\n");
	scanf("%d",&fAcc);
	struct customer * t=head;
	int exists=0;
	while(t && exists==0){
		if (t->accountNumber==fAcc){
			printf("---------------------------------------------------------------------------\n");
		printf("|%-10s %-25s %10s %10s %11s   |\n","Acc. No.","Customer Full Name","Balance","Deposit","Withdrawl");
		printf("---------------------------------------------------------------------------\n\n");
//	printf("---------%7d%25s%14.2f%12d%12d\n",head->accountNumber,head->fullName,head->amount,head->nDeposit,head->nWithdrawl);

		printf("|%-10d | %25s | %-10.2f | %-8d | %-8d|\n",t->accountNumber,prepString(t->fullName,NAME_LENGTH+1),t->amount,t->nDeposit,t->nWithdrawl);
			
		printf("---------------------------------------------------------------------------\n");
		 exists=1;
	}
	
		t=t->next;
		
	}
	
	if(exists==0){
		printf("\n No account details found for account number : %d\n", fAcc);
	}
}

removeAccount(){
	printf("Enter Account Number you want to delete\n");
	int accNumber;
	struct customer * t=head;
	struct customer * pre=head;
	t=t->next;
	struct customer *dn;
	int aN=t->accountNumber;
	scanf("%d",&accNumber);
//	printf("acc%d",accNumber);
	//	printf("acc%d",aN);
		if(pre->accountNumber ==accNumber){
			dn=head;
			head=head->next;
			free(dn);
			return ;
		}
	while(t&&accNumber!=t->accountNumber){
		t=t->next;
		pre=pre->next;
	}
	if(t!=NULL){
		//printf("fu=oun node\n");
	             	dn=t;
                    pre->next = dn->next;
                    free(dn);
                    printf("Deletion successful\n");
	}
	else{
		printf("\n Account Number %d does not exists\n",accNumber);
	}
}

printAll(){
	struct customer *t=head;
	if(isEmpty()){
		printf("Empty");
		return;
	}
		printf("---------------------------------------------------------------------------\n");
		printf("|%-10s %-25s %10s %10s %11s   |\n","Acc. No.","Customer Full Name","Balance","Deposit","Withdrawl");
		printf("---------------------------------------------------------------------------\n\n");
//	printf("---------%7d%25s%14.2f%12d%12d\n",head->accountNumber,head->fullName,head->amount,head->nDeposit,head->nWithdrawl);
	while(t!=NULL){
	
		printf("|%-10d | %25s | %-10.2f | %-8d | %-8d|\n",t->accountNumber,prepString(t->fullName,NAME_LENGTH+1),t->amount,t->nDeposit,t->nWithdrawl);
			
		
			t=t->next;
	}
	printf("---------------------------------------------------------------------------\n");
}
modify(){
	struct customer *t=head;
	int acc;
	printf("Enter account Number\n");
	scanf("%d",&acc);
	char str[NAME_LENGTH+1];
	int exists=0;
	while(t){
		if (t->accountNumber==acc){
		      printf("Enter new full Name\n");
		      fflush(stdin);
		        gets(str);
                strcpy(t->fullName,str);
                exists=1;
                printf("Account Details successfully updated \n");
		}
		t=t->next;
	}
	
	if(exists==0){
		printf("\n Account Number not found !! please try again !\n");
	}
}
depositMoney(){
	if(isEmpty()){
		printf("No account");
		return;
	}
	printf("Enter account number for deposit money\n");
	int acc;
	double money;
	scanf("%d",&acc);
    int found=0;
    double amount;
    int depTrans;
	struct customer * t =head;
	while(t)
	{
		if(t->accountNumber==acc){
			printf("Enter money you want to deposit\n");
			scanf("%lf", &money);
			depTrans=t->nDeposit;
			depTrans++;
		amount=t->amount;
		amount=amount+money;
			t->amount=amount;
			t->nDeposit=depTrans;
			found=1;
			printf("Money deposited");
			break;
		}
		
		
		t=t->next;
	
	}
	if(found==0){
		printf("Transaction unsuccessful ! No account number associated with your account\n");
	}
}
withdrawMoney(){
	printf("Enter account number money\n");
	int acc;
	double money;
	double balance;
	scanf("%d",&acc);
    int found=0;
    double amount;
    int depWith;
	struct customer * t =head;
	while(t)
	{
		if(t->accountNumber==acc){
			balance=t->amount;
			printf("Enter money you want to Withdraw\n");
			scanf("%lf", &money);
			while(money > balance){
				printf("Balance is low! Cannot withdraw \n");
				scanf("%lf", &money);
			}
				
			depWith=t->nWithdrawl;
			depWith++;
		    amount=t->amount;
		    amount=amount-money;
			t->amount=amount;
			t->nWithdrawl=depWith;
			found=1;
			printf("Money withdrawn\n");
			break;
		}
		
		t=t->next;

	}
	if(found==0){
		printf("Transaction unsuccessful ! No account number associated with your account\n");
	}
}


//*****************************************************************
//                    MAIN METHOD
//*****************************************************************

int main(){
	head=NULL;
//	FILE *fp = fopen("tmp/test.txt", "w+");
	
			FILE *fp2 = fopen("tmp/test.txt", "r+");
		
	
	loadFile(fp2);
	FILE *fp1 = fopen("tmp/test.txt", "w");
	char input;

	struct customer *t;
	do{
		printf("\n");
		printf("(a) Create Account \n");
		printf("(b) Deposit Money \n");
		printf("(c) Withdraw Money \n");
		printf("(d) Print all accounts \n");
		printf("(e) search customer \n");
		printf("(f) Modify account \n");
		printf("(g) Delete customer \n");
		printf("(h) BubbleSort Print\n");
		printf("(i) QSort Print\n");
		printf("(q) Quit \n");
			printf("\n");
\
	printf("Enter your option:\n");
        scanf("%s", &input);
		switch(input){
		case 'a': insertCustomer1(fp1,fp1);
		break;
		case 'b' : depositMoney() ;
		break;
		case 'd' : printAll();
		break;
		case 'c': withdrawMoney() ;
		break;
		case 'e' : search();
		break;
		case 'f':modify();
		break;
		case 'g': removeAccount() ;
		break;
		case 't' : readFile(fp2);
		break;
		case 'h' : BubbleSortArray();
		break;
		case 'i':qSortPrint();
			break;
		case 'q' :printf("\nBye!\n");
		break;
		default : printf("\nPlease try again\n");
	}
	
	}while(input!='q');   // do-while ends
	
		
    writeToFile(fp1,fp1);
	// freeing up the space 
	 while(head)
    {
        t=head;
        head=head->next;
        free(t);
     
    }
    
  //  fclose(fp);
    fclose(fp1);
    fclose(fp2);
     
}
