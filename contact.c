/*
Name : Purushotham D
Date : 17-10-2024
Description : To develop an AddressBook which is used to create,display,edit,delete and list the contacts*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include<ctype.h>


void initialize(AddressBook *addressBook)
{
    addressBook->contactCount = 0;
   // populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);

}
int validate_name(char *name)
{
    //STEP1: Fetch one by one character till null character
    for(int i=0;name[i] !='\0'; i++)
    {
        if(!isalpha(name[i])&& name[i]!=' ')
        {
            return 1;
            //STEP 2: check the character is alphabet or not
            //Yes-> move to next character , NO -> stop process
        }
    }
    return 0;
}
    


int validate_phone(AddressBook *addressBook, char *phonenum)
{
    //STEP1: Fetch one by one character till null character
    
    int len=strlen(phonenum);
   for(int i=0;phonenum[i] !='\0';i++)
    {
        if(!isdigit(phonenum[i])|| len!= 10)
        {
            printf("Phone number must contain 10 digits\n");
            return 1;
            //STEP 4: check the character is digit & 10digits & unique
            //Yes-> move to next character , NO -> stop process
        }

    }
    //STEP4:Validate the mobile number -> Digit & 10 Digits
    //True -> goto STEP5,False -> print error,goto STEP3
    
    /*If the phone number is not found in the dummyContacts,
    the function then checks the AddressBook, which contains the contacts added dynamically by the user.*/
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].phone,phonenum) == 0)
        {
            printf("Phone number already exists in the address book \n");
            return 1; 
        }
    }

    return 0; 
}


int validate_email(AddressBook *addressBook,char *Emailid)
{
    //STEP1: Fetch one by one character till null character
     
    if(!strstr(Emailid,"@gmail.com"))
    {
        printf("Invalid emailid please try again\n");
       return 1;
    }
    for (int i = 0;i < addressBook->contactCount;i++)
    {
        if (strcmp(addressBook->contacts[i].email,Emailid) ==0)
        {
            printf("Email ID already exists in the address book.\n");
            return 1; // Return 1 if email is already present.
        }
    }
    return 0;

}


void createContact(AddressBook *addressBook)
{
    char name[50];
    //step1: read the name from user
    printf("Enter the name : ");
    // __fpurge(stdin);
    // getchar();
    scanf(" %[^\n]",name);

    //step2: validate the nam -> address
  while(validate_name(name) == 1)
   {
        printf("INFO: Name validation not done, Please enter valid name....\n");
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
    //True ->goto step3,false ->prin error ,goto step1
   }


    char phonenum[20];
    printf("Enter the phone number : ");
    //step3: read a mobile number from user
    scanf(" %[^\n]", phonenum);
    
    while(validate_phone(addressBook,phonenum) == 1)
   {
        printf("INFO: phone no validation not done, Please enter valid number....\n");
        printf("Enter the phone number: ");
        scanf(" %[^\n]", phonenum);
    //True ->goto step5,false ->print error ,goto step3
   }

    char Emailid[50];
    //step5: Read a email id from the use
    printf("Enter the Email id : ");
    scanf(" %[^\n]",Emailid);
    //step6: validate the email id -> 
    while(validate_email(addressBook,Emailid) == 1)
   {
        printf("INFO: email validation not done, Please enter valid email....\n");
        printf("Enter the Email id: ");
        scanf(" %[^\n]", Emailid);
    //True ->goto step5,false ->print error ,goto step3
   }
	/* Define the logic to create a Contacts */
    if (addressBook->contactCount >= MAX_CONTACTS) 
    {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phonenum);
    strcpy(addressBook->contacts[addressBook->contactCount].email, Emailid);
    addressBook->contactCount++;

}

void name_display(AddressBook *addressBook,int *flag)
{ 
    char name2[50];
    printf("Enter the name : ");
    scanf(" %[^\n]",name2);
    for(int i=0;i<addressBook->contactCount;i++)
    {

        if(strcasestr(addressBook->contacts[i].name,name2) != NULL)
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            *flag = 1;
        }
    }
    if(*flag == 0)
    printf("Contacts Details not found. Please try again.\n");
}
    //2 Mobile no
    //read the mobile no
    //search the entered number is present in the database or not
    //present -> print the details of the contact  ,no-> print error message, goto step1
void phoneno_display(AddressBook *addressBook,int *flag)
{ 
    char phoneno1[50];
    printf("Enter the phone number : ");
    scanf(" %[^\n]",phoneno1);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].phone,phoneno1) != NULL)
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            *flag = 1;
        }
    }
    if(*flag == 0)
    printf("Contacts Details not found. Please try again.\n");
}
    //3 emailid
    //search the entered email id is present in the database or not
    //present -> print the details of the contact  ,no-> print error message, goto step1
void emaildid_display(AddressBook *addressBook,int *flag)
{ 
    char emailid1[20];
    printf("Enter the Email Id : ");
    scanf(" %[^\n]",emailid1);
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcasestr(addressBook->contacts[i].email,emailid1) != NULL)
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            *flag = 1;
        }
    }
    if(*flag == 0)
    printf("Contacts Details not found. Please try again.\n");
}
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    //step1: print the menu based on what searching
    //step2: choose the menu
    int choice,flag=0;
    printf("Search the contacts by\n");
    printf("1.Name \n");
    printf("2.Mobile number\n");
    printf("3.Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:name_display(addressBook,&flag);
    break;
    case 2:phoneno_display(addressBook,&flag);
    break;
    case 3:emaildid_display(addressBook,&flag);
    break;
    default:printf("Invalid choice....");
    }
}

void edit_name(AddressBook *addressBook)
{
    char newname[50];
    char oldname[50];
    printf("Enter the Old name :");
    scanf(" %[^\n]",oldname);
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
    if (strcmp(addressBook->contacts[i].name, oldname) == 0)
    {
        printf("Enter the new Name : ");
        scanf(" %[^\n]",newname); 
        strcpy(addressBook->contacts[i].name, newname);
        printf("Name updated from %s to %s successfully.\n",oldname,newname);
        return;
    }
    }
}



void edit_phoneno(AddressBook *addressBook)
{
    char newphone[50];
    char oldphone[50];
    printf("Enter the Old Phone Number :");
    scanf(" %[^\n]",oldphone);
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
    if (strcmp(addressBook->contacts[i].phone, oldphone) == 0)
    {
        printf("Enter the New Phone Number : ");
        scanf(" %[^\n]",newphone); 
        strcpy(addressBook->contacts[i].phone, newphone);
        printf("Phone Number updated from %s to %s successfully.\n",oldphone,newphone);
        return;
    }
    }
}


void edit_emailid(AddressBook *addressBook)
{
    char newemail[50];
    char oldemail[50];
    printf("Enter the Old Email Id :");
    scanf(" %[^\n]",oldemail);
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
    if (strcmp(addressBook->contacts[i].email, oldemail) == 0)
    {
        printf("Enter the New Email Id : ");
        scanf(" %[^\n]",newemail); 
        strcpy(addressBook->contacts[i].email, newemail);
        printf("Email Id updated from %s to %s successfully.\n",oldemail,newemail);
        return;
    }
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice,flag=0;
    while(1)
    {
    printf("Search the contacts by\n");
    printf("1. Name\n");
    printf("2. Mobile Number\n");
    printf("3. Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:name_display(addressBook,&flag);
        break;
        case 2:phoneno_display(addressBook,&flag);
        break;
        case 3:emaildid_display(addressBook,&flag);
        break;
        default:printf("Invalid choice....");
        continue;
    }
    if(flag != 0)
    break;
    }
    //Please select on what are you going to edit
    //1. name
    //2. mobile no
    //3. email
    int choice1;
        printf("\nWhat would you like to edit?\n");
        printf("1. Name\n");
        printf("2. Mobile Number\n");
        printf("3. Email\n");
        printf("Enter your choice: ");
        scanf("%d", &choice1);
    switch(choice1)
    {
        case 1:edit_name(addressBook);
        break;
        case 2:edit_phoneno(addressBook);
        break;
        case 3:edit_emailid(addressBook);
        break;
        default:printf("Invalid choice Thank You...");
    }
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    int choice,flag=-1,i;
    char del[50];
    printf("Delete the contats by\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email Id\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter the Name : ");
        scanf(" %[^\n]",del);
        for(i=0;i<addressBook->contactCount;i++)
        {
            if(strcmp(addressBook->contacts[i].name,del)==0)
            {
                flag=i;
                break;
            }
        }
            break;
            case 2:printf("Enter the Phone Number : ");
            scanf(" %[^\n]",del);
            for(i=0;i<addressBook->contactCount;i++)
            {
            if(strcmp(addressBook->contacts[i].phone,del)==0)
            {
                flag=i;
                break;
            }
            }
            break;
            case 3:printf("Enter the Email Id : ");
            scanf(" %[^\n]",del);
            for(i=0;i<addressBook->contactCount;i++)
            {
            if(strcmp(addressBook->contacts[i].email,del)==0)
            {
                flag=i;
                break;
            }
            }
            break;
            default :printf("Inavlid choice...");
            return;
        }
        if (flag != -1)
         {
        // Shift the contacts up one position to remove the contact
        for (int i = flag; i < addressBook->contactCount - 1; i++) 
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }

        // Decrement contact count
        addressBook->contactCount--;

        printf("Contact deleted successfully.\n");
         } 
        else
        {
            printf("Contact not found.\n");
        }
   
}



void listContacts(AddressBook *addressBook) 
{
 printf("Number of contacts: %d\n", addressBook->contactCount);  // Check contact count

    // Check if the sorting is happening correctly
     for (int i = 0; i < addressBook->contactCount - 1; i++) 
    {
        for (int j = 0; j < addressBook->contactCount - i - 1; j++) 
        {
            if (strcmp(addressBook->contacts[j].name, addressBook->contacts[j + 1].name) > 0) 
            {
                // Swap the contacts if they are in the wrong order
                Contact temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
    
    // Debug output before the loop
    printf("Listing contacts...\n");
    
    // Print each contact in a simplified way for debugging
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        printf("Contact %d: Name: %s, Phone: %s, Email: %s\n", 
               i+1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}