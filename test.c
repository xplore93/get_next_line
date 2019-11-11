char    *find_n(char **text)
{
    char    *line;
    char    *n;

    if ((n = ft_strchr(*text, '\n')))
    {
        *n = '\0';
        line = ft_strdup(*text);
        *text = ft_strcpy(*text, ++n);
    }
    else
    {
        line = ft_strdup(*text);
        ft_strclr(*text);
    }
    return (line);
}

int     get_next_line(const int fd, char **line)
{
    char            buf[BUFF_SIZE + 1];
    char            *n;
    char    static  *text;
    int             num_read;
    char            *tmp;

    if (text)
        *line = find_n(&text);
    else
        *line = ft_strnew(1);
    while ((num_read = read(fd, buf, BUFF_SIZE)))
    {
        buf[num_read] = '\0';
        if ((n = ft_strchr(buf, '\n')))
        {
            *n = '\0';
            tmp = *line;
            *line = ft_strjoin(*line, buf);
            free(tmp);
            text = ft_strdup(++n);
            break ;
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    return (ft_strlen(*line) ? 1 : 0);
}