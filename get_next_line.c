#include "get_next_line.h"

char *ft_extract(int fd, char *line)
{
    char *buff;
    ssize_t rd;

    rd = 1;
    buff = (char *)malloc(BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while (!ft_strchr(line ,'\n') && rd > 0)
    {
        rd = read(fd, buff, BUFFER_SIZE);
        if (rd == -1)
        {
            free(buff);
            return (NULL);
        }
        buff [rd] = '\0';
        line = ft_strjoin(line, buff);
    }
    free(buff);
    return (line);
}

char    *ft_cut_first(char *line)
{
    char *str;
    int i;

    i = 0;
    while (line[i] && line[i] != '\n')
        i++;
    str = (char *)malloc(i + 2);
    i = 0;
    while (line[i] && line[i] != '\n')
    {
        str[i] = line[i];
        i++;
    }
    if (line[i] == '\n')
    {
        str[i] = line[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_cut_last(char *line)
{
    char *str;
    int i;
    int j;

    i = 0;
    while (line[i] != '\0' && line[i] != '\n')
        i++;
    str = (char *)malloc(ft_strlen(line) - i + 1);
    if (! str)
        return (NULL);
    i++;
    j = 0;
    while (line[i] != '\0')
    {
        str[j] = line[i];
        i++;
        j++;
    }
    str[j] = '\0';
    free(line);
    return (str);
}

char    *get_next_line(int fd)
{
    static char *line;
    char *next;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = ft_extract(fd, line);
    if(!line)
        return(NULL);
    next = ft_cut_first(line);
    line = ft_cut_last(line);
    return (next);
}

int main ()
{
    char *zz;
    char *ss;
    int fd = open ("text.txt", O_RDONLY);
    zz = get_next_line(fd);
    printf("%s", zz);
    ss = get_next_line(fd);
    printf("%s", ss);
    ss = get_next_line(fd);
    printf("%s", ss);
        ss = get_next_line(fd);
    printf("%s", ss);

}