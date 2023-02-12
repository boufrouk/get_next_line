#include <fcntl.h>
#include <stdio.h>
#include"get_next_line.h"

char *get_next_line(int fd)
{
    char *str;
    char *buf;
    int i = 0;
	int j = 1;
	buf = malloc(2);
    str = ft_strdup("");
    while(i == 0)
    {
        j = read(fd,buf,1);
		buf[1] = '\0';
        if (ft_strchr(buf, '\n') == 0 && j != 0)
        {
            str = ft_strjoin(str,buf);
        }
        else
        {
            i = 1; 
			str = ft_strjoin(str,buf);
            break ;
        }
    }
    return str;
}

/*int main(){
	int fd ;
	fd = open("hH",O_RDONLY,777);
	 //char *tan = get_next_line(fd);
	 //while (get_next_line(fd))
	 //{
	 	printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
	 //}
	return 0;
}*/
