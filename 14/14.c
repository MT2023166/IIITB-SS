#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc !=2){
		printf("usage: %s <filename>\n", argv[0]);
		return 1;
	}

	const char* file_name=argv[1];

	struct stat file_stat;
	if(stat(file_name, &file_stat)==-1){
		perror("ERROR No Information available");
		return 1;
	}

	if(S_ISREG(file_stat.st_mode)){
		printf("%s is a regular file. \n", file_name);
	}
	else if (S_ISDIR(file_stat.st_mode)){
		printf("%s is a directory.\n", file_name);
	}
	else if(S_ISLNK(file_stat.st_mode)){
		printf("%s is a symbolic link.\n", file_name);
	}
	else if(S_ISFIFO(file_stat.st_mode)){
		printf("%s is a FIFO/pipe.\n", file_name);
	}
	else if(S_ISSOCK(file_stat.st_mode)){
		printf("%s is a socket.\n", file_name);
	}
	else if(S_ISBLK(file_stat.st_mode)){
		printf("%s is a block special file.\n" , file_name);
	}
	else if(S_ISCHR(file_stat.st_mode)){
		printf("%s is a charcter special file.\n" , file_name);
	}
	else{
		printf("%s is of an unknown type.\n" , file_name);
	}
	return 0;
}
