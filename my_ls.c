#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <string.h>
#define SIZE 100

//function declarations
int block(DIR *);
void display(unsigned int num);
unsigned int type(unsigned int);
unsigned int user(unsigned int);
unsigned int group(unsigned int);
unsigned int oth(unsigned int);
void get_month(int );
int print_details(char *);

struct dirent *dir;  //directory structure
struct stat st;      //return 0 succ, -1 error

//main function
int main(int argc, char *argv[])
{
	DIR *d;
	d = opendir("."); //open dir
	int total;
	char path[1024];
	//if argv is wrong
	if (argc > 2) {
		printf("Wrong input\n");
		exit(0);
	}
	
	//only print ls
	if (argc == 1) {
		while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
				break;
			}
			printf("%s\t", dir->d_name);
		}
		printf("\n");
		closedir(d);
	} else if((strcmp(argv[1], "-l") == 0) && argc == 2) { //printf ls -l
		total = block(d);
		printf("total  %d\n", total); //total bloc in pwd
		while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
					break;
			}
			print_details(dir->d_name);
		}
		closedir(d);
	} else if (argc == 2 && (strcmp(argv[1], "-a") == 0)) { //print ls -a
		while ((dir = readdir(d)) != NULL) {
			printf("%s\t", dir->d_name);
		}
		printf("\n");
		closedir(d);
	} else if((strcmp(argv[1], "-al") == 0) && argc == 2) { //printf ls -al
		total = block(d);
		printf("total  %d\n", total); //total bloc in pwd
		while ((dir = readdir(d)) != NULL) {
			print_details(dir->d_name);
		}
		closedir(d);
	} else {
		for (int i = 1; i < argc; i++) {
			d = opendir(argv[i]);
			while ((dir = readdir(d)) != NULL) {
				snprintf(path, sizeof(path), "%s/%s", argv[i], dir->d_name); //print another directory files
				print_details (path);
			}
		}
		closedir(d);
	}
}

//function for printing long listing details
int print_details(char *path) {
	
	struct tm dt;
	struct passwd *uname;
	struct group *gname;
	unsigned int num;
	int total;
	int m_store;
	
	stat(dir->d_name, &st); //get file information struct
	//struct of mode
	num = st.st_mode;
	type(num);
	num = st.st_mode;
	user(num);
	num = st.st_mode;
	group(num);
	num = st.st_mode;
	oth(num);
		
	//print link file and folder
	printf("  %-2ld", st.st_nlink);
			
	//get username
	if ((uname = getpwuid(st.st_uid)) != NULL) {
		printf("  %-2s", uname->pw_name);
	}
		
	//get guest name
	if ((gname = getgrgid(st.st_gid)) != NULL) {
		printf("  %-2s ", gname->gr_name);
	}
			
	//file size
	printf(" %-5ld", st.st_size);
	//get modify time
			
	dt = *(gmtime(&st.st_mtime));
	m_store = dt.tm_mon;
 
	//print month	
	get_month(m_store);
		
	//print days
	printf(" %d \t", dt.tm_mday);

	int hr = dt.tm_hour + 5;
	int min = dt.tm_min + 30;
	hr = hr + (min / 60);
	min = min % 60;

	//print modify time hour and min
	printf("%02d:%02d", hr, min);
//	printf("%02d:%02d",dt.tm_hour,dt.tm_min);
	//print files namer
	printf(" %-2s", path);

	printf("\n");
}


#if 1
int block(DIR *d)
{
	d = opendir(".");
	int total = 0;
	int blk;
	while ((dir = readdir(d)) != NULL) {
		if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
			break;
		}
		stat(dir->d_name, &st);
		blk = st.st_blocks;
		total = total + (blk /2);
	}
	return total;
}
#endif

//get month
void get_month(int dt)
{
	switch(dt) {
		case 0:
			printf(" Jan");
		break;

		case 1:
			printf(" Feb");
		break;

		case 2:
			printf(" Mar");
		break;

		case 3:
			printf(" Apr");
		break;

		case 4:
			printf(" May");
		break;

		case 5:
			printf(" Jun");
		break;

		case 6:
			printf(" Jul");
		break;

		case 7:
			printf(" Aug");
		break;

		case 8:
			printf(" Sep");
		break;

		case 9:
			printf(" Oct");
		break;

		case 10:
			printf(" Nov");
		break;

		case 11:
			printf(" Dec");
		break;

		default:
			exit(0);

	}
}

//extract value and get permission
unsigned int type(unsigned int num)
{
	num = (num >> 9);
	if (num == 0100) {
		printf("-");
	} else {
		printf("d");
	}
}

//extract user value and get permissions
unsigned int user(unsigned int num)
{
	num = (num >> 6);
	if (num & 04) {
		printf("r");
	} else {
		printf("-");
	}
	if (num & 02) {
		printf("w");
	} else {
		printf("-");
	}
	if (num & 01) {
		printf("x");
	} else {
		printf("-");
	}
}

//extract group value and get permissions
unsigned int group(unsigned int num)
{

	num = (num >> 3);
	if (num & 04) {
		printf("r");
	} else {
		printf("-");
	}
	if (num & 02) {
		printf("w");
	} else {
		printf("-");
	}
	if (num & 01) {
		printf("x");
	} else {
		printf("-");
	}
}

//extract others value and get permissions
unsigned int oth(unsigned int num)
{

	if (num & 04) {
		printf("r");
	} else {
		printf("-");
	}
	if (num & 02) {
		printf("w");
	} else {
		printf("-");
	}
	if (num & 01) {
		printf("x");
	} else {
		printf("-");
	}
}

