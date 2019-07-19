/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** new_try
*/

#include "get_next_line.h"

int is_n(char *buf, int len, int func)
{
    int i = 0;

    if (func == 1) {
        if (!buf)
            return (0);
        while (buf[i] != '\0')
            i++;
        return (i);
    }
    for (i = 0; i < len; i++)
        if (buf[i] == '\n' || buf[i] == '\0') {
            return (i);
        }
    return (-1);
}

char *concat_str(char *ret, char *src)
{
    int len_ret = is_n(ret, 0, 1);
    int len_src = is_n(src, 0, 1);
    char *temp = malloc(sizeof(char) * (len_ret + len_src + 1));

    for (int i = 0; i < len_ret; i++)
        temp[i] = ret[i];
    free(ret);
    for (int i = 0; i < len_src; i++)
        temp[len_ret + i] = src[i];
    temp[len_ret + len_src] = '\0';
    return (temp);
}

char *my_strdup(char *src, int len)
{
    char *ret = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        ret[i] = src[i];
    ret[len] = '\0';
    return (ret);
}

char *next_part(int fd, char **rest, char *ret, int *len)
{
    int rd;
    char *buf = malloc(sizeof(char) * READ_SIZE);

    while (1) {
        rd = read(fd, buf, READ_SIZE);
        if (rd == 0 && !ret)
            return (NULL);
        if (rd != READ_SIZE && is_n(buf, rd, 0) == -1) {
            *rest = NULL;
            return (concat_str(ret, my_strdup(buf, rd)));
        }
        if (is_n(buf, rd, 0) != -1) {
            len[0] = rd - is_n(buf, rd, 0) - 1;
            *rest = my_strdup(buf + 1 + is_n(buf, rd, 0), len[0]);
            return (concat_str(ret, my_strdup(buf, is_n(buf, rd, 0))));
        } else
            ret = concat_str(ret, buf);
    }
}

char *get_next_line(int fd)
{
    static char *rest = NULL;
    static int len[1] = {0};
    char *buf = malloc(sizeof(char) * READ_SIZE);
    char *ret = NULL;

    if (fd < 0 || READ_SIZE < 1)
        return (NULL);
    if (rest && rest[0]) {
        buf = my_strdup(rest, len[0]);
        if (is_n(buf, len[0], 0) != -1) {
            len[0] = is_n(buf, len[0], 0);
            ret = my_strdup(rest, len[0]);
            rest = my_strdup(rest + len[0] + 1, len[0]);
            return (ret);
        }
        ret = my_strdup(buf, len[0]);
    }
    return (next_part(fd, &rest, ret, len));
}