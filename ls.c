#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void print_details(char *path) {
  struct stat sb;
  if (stat(path, &sb) == -1) {
    perror("stat");
    return;
  }

  printf((S_ISDIR(sb.st_mode)) ? "d" : "-");
  printf((sb.st_mode & S_IRUSR) ? "r" : "-");
  printf((sb.st_mode & S_IWUSR) ? "w" : "-");
  printf((sb.st_mode & S_IXUSR) ? "x" : "-");
  printf((sb.st_mode & S_IRGRP) ? "r" : "-");
  printf((sb.st_mode & S_IWGRP) ? "w" : "-");
  printf((sb.st_mode & S_IXGRP) ? "x" : "-");
  printf((sb.st_mode & S_IROTH) ? "r" : "-");
  printf((sb.st_mode & S_IWOTH) ? "w" : "-");
  printf((sb.st_mode & S_IXOTH) ? "x" : "-");
  printf(" %ld", (long) sb.st_nlink);
  
  struct passwd *pw = getpwuid(sb.st_uid);
  struct group *gr = getgrgid(sb.st_gid);
  printf(" %s %s", pw->pw_name, gr->gr_name);
  printf(" %5ld", (long) sb.st_size);
  
  char time_str[50];
  strftime(time_str, sizeof time_str, "%b %d %H:%M", localtime(&sb.st_mtime));
  printf(" %s", time_str);
  if(S_ISDIR(sb.st_mode)) {
	printf("\033[0;34m");
  	printf(" %s\n", path);
  } else {
  printf(" %s\n", path);
	}
}

int main(int argc, char *argv[]) {
  DIR *d;
  struct dirent *dir;
  if (argc == 1) {
    d = opendir(".");
    if (d) {
      while ((dir = readdir(d)) != NULL) {
        print_details(dir->d_name);
      }
      closedir(d);
    }
  } else {
    for (int i = 1; i < argc; i++) {
      d = opendir(argv[i]);
      if (d) {
        while ((dir = readdir(d)) != NULL) {
          char path[1024];
          snprintf(path, sizeof(path), "%s/%s", argv[i], dir->d_name);
          print_details(path);
        }
        closedir(d);
      }
    }
  }

  return 0;
}
