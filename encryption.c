#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to encrypt a message using a simple substitution cipher
void encrypt(char *file_name, int key) {
    int i = 0;
    char buffer[100];
    FILE *file = fopen(file_name, "r+");
    if(file==NULL){
            printf("File named: '%s'  NOT Found \n", file_name);
            printf("Encryption failed \n");

            exit(1);
        }
       
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
    }
        while (buffer[i] != '\0') {
            // Decrypt uppercase letters
            buffer[i] = (int)(buffer[i] - key);
            
            i++;
        }
        rewind(file);
        fprintf(file, "%s", buffer);
        fclose(file);
        printf("\n File Successfully Encrypted\n");
}

void decrypt(char *file_name, int key) {
        int i = 0;
        char buffer[100];
        FILE *file = fopen(file_name, "r+");
        if(file==NULL){
            printf("File named: %s  NOT Found \n", file_name);
            printf("Decryption failed \n");

            exit(1);
        }
       
         while (fgets(buffer, sizeof(buffer), file) != NULL) {
        
        while (buffer[i] != '\0') {
            
            buffer[i] = (int)(buffer[i] + key);
            i++;
        }
        rewind(file);
        fprintf(file, "%s", buffer);
        fclose(file);
        printf("\nFile Succesfully Decrepted\n ");
  
    }
}

int main(int argc, char* argv[]) {
    
    if(argc!=4){
        printf("Argument Error : Expected <action> <filename.extension> <private_key:num-exp0> \n");
        exit(1);
    }
 
    char *file_name = argv[2];
    int key = atoi(argv[3]);
    if(key==0){
        printf("Argument Error : Expected <action> <filename.extension> <private_key:num-exp0> \n");
        exit(1);
    }
    srand(key); 
    int random = rand() % 94; 

    if(argv[1][0]=='e'){
       
        encrypt(file_name, random );
        
    }else if(argv[1][0]=='d'){
decrypt(file_name, random );
    }
    return 0;
}

