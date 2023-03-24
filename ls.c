#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include<string.h>


//printing files and directories along with lists
void print_details(char *path) {
  	struct stat sb;  
  	if (stat(path, &sb) == -1) {
    	perror("stat");
    	return;
  	}

	//printing permissions
  	printf ((S_ISDIR(sb.st_mode)) ? "d" : "-");
  	printf ((sb.st_mode & S_IRUSR) ? "r" : "-");
  	printf ((sb.st_mode & S_IWUSR) ? "w" : "-");
  	printf ((sb.st_mode & S_IXUSR) ? "x" : "-");
  	printf ((sb.st_mode & S_IRGRP) ? "r" : "-");
  	printf ((sb.st_mode & S_IWGRP) ? "w" : "-");
  	printf ((sb.st_mode & S_IXGRP) ? "x" : "-");
  	printf ((sb.st_mode & S_IROTH) ? "r" : "-");
  	printf ((sb.st_mode & S_IWOTH) ? "w" : "-");
  	printf ((sb.st_mode & S_IXOTH) ? "x" : "-");
	
	//printing no of hard links
  	printf (" %ld", (long) sb.st_nlink);
  
	//printing user id and group id
	struct passwd *pw = getpwuid(sb.st_uid);
  	struct group *gr = getgrgid(sb.st_gid);
  	printf (" %s %s", pw->pw_name, gr->gr_name);
	
	//printing size in kbs
  	printf (" %5ld", (long) sb.st_size);
	
	//printing modify time and last status change time
  	char time_str[50];
  	strftime (time_str, sizeof time_str, "%b %d %H:%M", localtime(&sb.st_mtime));
  	printf (" %s", time_str);
	if(S_ISDIR(sb.st_mode)) {
  		printf ("\033[0;34m %s", path);
		printf("\n");
	} 
	if(!S_ISDIR(sb.st_mode)) {
		printf ("\033[0m %s\n", path);
	}
}

//main function
int main(int argc, char *argv[]) {
  	DIR *d;  //directory name
  	struct dirent *dir;  //dirent structure
	
	if (argc == 1) {     //printing ls
		d = opendir(".");
		while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
	            break;
            }

			printf ("%s ", dir->d_name);
		}
		closedir(d);
	} else if (argc == 2 && (strcmp(argv[1], "-l") == 0)) {
    	d = opendir(".");
      	while ((dir = readdir(d)) != NULL) {
			if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
            	break;
            }

       		print_details(dir->d_name);    //printing ls -l details in current directory
      	}
      	closedir(d);
  	} else if (argc == 2 && (strcmp (argv[1], "-a") == 0 )) {     //printing ls -a
		d = opendir(".");
		while ((dir = readdir(d)) != NULL) {
			printf ("%s ", dir->d_name);
		}
		closedir(d);
	} else if (argc == 2 && (strcmp(argv[1], "-al") == 0)) {
    	d = opendir(".");
      	while ((dir = readdir(d)) != NULL) {
        	print_details(dir->d_name);    //printing ls -al details in current directory
      	}
      	closedir(d);
  	} else {
    	for (int i = 1; i < argc; i++) {
      		d = opendir(argv[i]);
        	while ((dir = readdir(d)) != NULL) {
          		char path[1024];
          		snprintf (path, sizeof(path), "%s/%s", argv[i], dir->d_name);
          		print_details (path);   //printing another directory details
			}
        	closedir(d);
    	}
  	}
  	return 0;
}
