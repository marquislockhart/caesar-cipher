#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char message[50], temp;
int shift, count;
int option;
int i = 0;

int main()
{
      while(1)
      {
            printf("Hello Julius Caesar! Please select a menu option.\n\n");
            printf("1. Encrypt a Message\n");
            printf("2. Decrypt a Message\n");
            printf("3. Exit\n");
            scanf("%d", &option);
            switch(option)
            {
                  case 1: encryptMessage();
                          break;
                  case 2: decryptMessage();
                          break;
                  case 3: printf("Goodbye Master Caesar!");
                          exit(0);
                  default: printf("This option does not exist. Please select an available menu option.\n\n");
            }
      }
      return 0;
}

void getmessage()
    {
          printf("\nEnter a message in all capitals with up to 20 characters: ");
          scanf("%s", message);
          while(strlen(message) > 20)
            {
            printf("Message must be no longer than 20 characters.");
            printf("Please try again: ");
            scanf("%s", message);
            }
          printf("Enter a number to shift: ");
          scanf("%d", &shift);
    }

void encryptMessage()
{
    getmessage();
      for(count = 0; message[count] != '\0'; count++)
      {
            temp = message[count];
            if(temp >= 'a' && temp <= 'z')
            {
                  temp = temp + shift;
                  if(temp > 'z')
                  {
                        temp = temp - 'z' + 'a' - 1;
                  }
                  message[count] = temp;
            }
            else if(temp >= 'A' && temp <= 'Z')
            {
                  temp = temp + shift;
                  if(temp > 'Z')
                  {
                        temp = temp - 'Z' + 'A' - 1;
                  }
                  message[count] = temp;
            }
      }
      for(i=0; i < sizeof(message); i++)
      {
          message[i] = toupper(message[i]);
      }
      printf("\nEncrypted Message: %s\n\n", message);
}

void decryptMessage()
{
    getmessage();
      for(count = 0; message[count] != '\0'; count++)
      {
            temp = message[count];
            if(temp >= 'a' && temp <= 'z')
            {
                  temp = temp - shift;
                  if(temp < 'a')
                  {
                        temp = temp + 'z' - 'a' + 1;
                  }
                  message[count] = temp;
            }
            else if(temp >= 'A' && temp <= 'Z')
            {
                  temp = temp - shift;
                  if(temp < 'A')
                  {
                        temp = temp + 'Z' - 'A' + 1;
                  }
                  message[count] = temp;
            }
      }
      for(i=0; i < sizeof(message); i++)
      {
          message[i] = toupper(message[i]);
      }
      printf("\nDecrypted Message:%s\n\n", message);
}
