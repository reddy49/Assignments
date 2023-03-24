#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int main(int argc, char *argv[]) {

  struct stat sb;
//  if (stat(path, &sb) == -1) {
//    perror("stat");
//    return;
//  }
  DIR *d;
  struct dirent *dir;
  if (argc == 1) {
    d = opendir(".");
    if (d) {
      while ((dir = readdir(d)) != NULL) {
        printf("%s  ",dir->d_name);
      }
      closedir(d);
    }
}
}

