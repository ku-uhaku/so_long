#include "so_long.h"

static int count_words(const char *str, char c)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;
        if (str[i])
            count++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (count);
}

static int word_length(const char *str, char c)
{
    int len;

    len = 0;
    while (str[len] && str[len] != c)
        len++;
    return (len);
}

static char *word_dup(const char *str, int len)
{
    char *word;
    int i;

    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

static void free_split(char **split, int word_count)
{
    int i;

    i = 0;
    while (i < word_count)
    {
        free(split[i]);
        i++;
    }
    free(split);
}

char **ft_split(char const *s, char c)
{
    char **split;
    int word_count;
    int i;
    int j;

    if (!s)
        return (NULL);
    word_count = count_words(s, c);
    split = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!split)
        return (NULL);
    i = 0;
    j = 0;
    while (i < word_count)
    {
        while (s[j] && s[j] == c)
            j++;
        split[i] = word_dup(&s[j], word_length(&s[j], c));
        if (!split[i])
        {
            free_split(split, i);
            return (NULL);
        }
        j += word_length(&s[j], c);
        i++;
    }
    split[i] = NULL;
    return (split);
} 