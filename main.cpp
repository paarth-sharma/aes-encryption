/*
Implementation of 128 bit AES encryption and decryption
-> key for encryption and decryption is stored in file key.txt

Encryption process-
-> reads plain text from input.txt
-> stores encrypted data in encryption.aes

Decryption process-
-> program reads encrypted data from encryption.text
-> decrypted data is stored in outputtext.txt file
*/

#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>
#include "key_expand.h"
#include "encoding.h"
#include "decoding.h"
#include <typeinfo>
#include<windows.h>
using namespace std;

int main(){
	//we will read from file input.txt
	int extendedlength=0;
	int choice;
	string myText;
	label:
	cout<<"Lets start with 128-bit AES encryption"<<endl;
	cout<<endl;
	cout<<"Enter you choice "<<endl;
	cout<<"Press 1 to encode your file"<<endl;
	cout<<"Press 2 to decode your file"<<endl;
	cin>>choice;

	switch(choice){
		case 1:{
		//encryption of text data
		ifstream File;
		string filepath = "encryption.aes";
		//clearing encryption.aes before editing

		File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc );
		if (!File.is_open() || File.fail()){
			File.close();
			printf("\nError : failed to erase file content !");
		}
		File.close();

		//reading plain text from input.txt 
		fstream newfile;
		newfile.open("input.txt",ios::in); //open a file to perform read operation using file object

		if (newfile.is_open()){   //checking whether the file is open
			cout<<"Reading plain text from input.txt .........\n";
			Sleep(1000);
			string tp;
			cout<<"Reading KEY from key.txt ......\n";
			Sleep(1000);
			cout<<"Now encrypting ....\n";
				Sleep(1000);
				cout<<"writing encrypted data in encryption.aes ..\n";
				Sleep(1000);
				cout<<endl;

			while(getline(newfile, tp)){ 
				//read data from file object and put it into string.
				int messlength=tp.length();
				int extendedlength;

				// making the blocks of data to be encrypted perfectly divisible
				if((messlength%16)!=0)
					extendedlength = messlength+(16-(messlength%16));
				
				else
					extendedlength = messlength;
					
					unsigned char* encryptedtext=new unsigned char[extendedlength];
					for(int i=0;i<extendedlength;i++){
					if(i<messlength)
					encryptedtext[i]=tp[i];
					else
					encryptedtext[i]=0;
					}

					//getting key from key.txt

					string k;
					ifstream infile;
					infile.open("key.txt");
					if (infile.is_open()){
						getline(infile, k); // The first line of file should be the key
						infile.close();
					}

				else cout << "Unable to open file";
				
					istringstream tempkey(k);
					unsigned char key[16];
					unsigned int x;
					for(int i=0;i<16;i++){
					tempkey>>hex>>x;
					key[i] = x;
					}

					//extending key

					unsigned char extendedkeys[176];
					Key_extenxion(key,extendedkeys);

			//encrypting our plain text
			for(int i=0;i<extendedlength;i+=16){
				unsigned char* temp=new unsigned char[16];
				for(int j=0;j<16;j++)
					temp[j]=encryptedtext[i+j];
						
				encryption(temp, extendedkeys);

				for(int j=0;j<16;j++)
					encryptedtext[i+j]=temp[j];
			}

			//storing our encrypted data in encryption.aes	 		 
			ofstream fout;  // Create Object of Ofstream
			ifstream fin;
			fin.open("encryption.aes");
			fout.open ("encryption.aes",ios::app); // Append mode
			if(fin.is_open())
				fout<<encryptedtext<<"\n"; // Writing data to file
			fin.close();
			fout.close(); 
		}
		cout<<"128-bit AES encryption is done sucessfully\n";
		cout<<"Data has been appended to file encryption.aes";
		newfile.close(); //close the file object.
   }
  break;
}
